#!/bin/bash

runs=$1
mode=$2
program_input_d=$3

# If mode is 0, get program_input_d to the last argument
if [ "$mode" -eq 0 ]; then
    program_input_d=${!#}  # Get the last argument
fi

# Compile the program
g++ -o lpswop lpswop.cpp -std=c++17 -O3
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Compilation successful."

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
    echo "Running the program $runs times for $program_input_d."

    # Run in parallel using `xargs` and store results in an array
    mapfile -t results < <(seq 1 "$runs" | xargs -P 0 -I {} ./lpswop "$program_input_d")

    # Calculate average and standard deviation
    read -r average std_dev <<< $(calculate_stats "${results[@]}")

    echo "For d=$program_input_d:"
    echo "Average number of Basis Changes: $average"
    echo "Standard Deviation: $std_dev"

elif [ "$mode" -eq 1 ]; then
    d_values=(5 10 20 50 100 150 200 250 300)
    echo "Running the program $runs times for each d equal to ${d_values[*]}."
    
    # Print table header
    echo "| **Number of Repeats** | **d** | **Average Number of Basis Changes** | **Standard Deviation** |"
    echo "|------------------------|-------|-------------------------------------|------------------------|"
    
    for d in "${d_values[@]}"; do
        # Run in parallel using `xargs` and store results in an array
        mapfile -t results < <(seq 1 "$runs" | xargs -P 0 -I {} ./lpswop "$d")
        
        # Calculate average and standard deviation
        read -r average std_dev <<< $(calculate_stats "${results[@]}")
        
        # Format numbers with 6 decimal places
        formatted_average=$(printf "%.2f" "$average")
        formatted_std_dev=$(printf "%.2f" "$std_dev")
        
        # Print table row
        echo "| $runs | $d | $formatted_average | $formatted_std_dev |"
    done
else
    echo "Invalid mode! Mode must be either 0 or 1."
    exit 1
fi
