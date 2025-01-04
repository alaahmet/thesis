#!/bin/bash

runs=$1
mode=$2
program_input_d=$3

# If mode=0, we'll interpret the last argument as d
if [ "$mode" -eq 0 ]; then
    program_input_d=${!#}
fi

# Helper function: compute average and std dev from an array of results
calculate_stats() {
    local results=("$@")
    local n=${#results[@]}
    local sum=0
    local sum_sq=0

    for result in "${results[@]}"; do
        sum=$(echo "$sum + $result" | bc)
        sum_sq=$(echo "$sum_sq + $result * $result" | bc)
    done

    local average=$(echo "scale=6; $sum / $n" | bc)
    local variance=$(echo "scale=6; ($sum_sq - $sum * $sum / $n) / ($n - 1)" | bc)
    local std_dev=$(echo "scale=6; sqrt($variance)" | bc)

    echo "$average $std_dev"
}

if [ "$mode" -eq 0 ]; then
    # Single d => compile once, run many times
    echo "Compiling with d=$program_input_d at compile time..."
    g++ -o fastlpswop fastlpswop.cpp -std=c++17 -O3 -D DVAL=$program_input_d
    if [ $? -ne 0 ]; then
        echo "Compilation failed!"
        exit 1
    fi
    echo "Compilation successful."

    echo "Running $runs times for d=$program_input_d..."
    mapfile -t results < <(seq 1 "$runs" | xargs -P 0 -I {} ./fastlpswop)

    # Compute statistics
    read -r average std_dev <<< "$(calculate_stats "${results[@]}")"
    echo "For d=$program_input_d:"
    echo "Average number of Basis Changes: $average"
    echo "Standard Deviation: $std_dev"

elif [ "$mode" -eq 1 ]; then
    # Multiple compiled d's
    d_values=(5 10 20 50 100 150 200 250 300)
    echo "Running $runs times for each d in: ${d_values[*]}"
    echo "| **Number of Repeats** | **d** | **Average Number of Basis Changes** | **Standard Deviation** |"
    echo "|------------------------|-------|-------------------------------------|------------------------|"

    for d in "${d_values[@]}"; do
        g++ -o fastlpswop fastlpswop.cpp -std=c++17 -O3 -D DVAL=$d
        if [ $? -ne 0 ]; then
            echo "Compilation failed for d=$d!"
            exit 1
        fi

        mapfile -t results < <(seq 1 "$runs" | xargs -P 0 -I {} ./fastlpswop)

        read -r average std_dev <<< "$(calculate_stats "${results[@]}")"
        formatted_average=$(printf "%.2f" "$average")
        formatted_std_dev=$(printf "%.2f" "$std_dev")

        echo "| $runs | $d | $formatted_average | $formatted_std_dev |"
    done
else
    echo "Invalid mode! Must be 0 or 1."
    exit 1
fi
