#!/bin/bash

runs=$1
mode=$2
program_input_d=$3

# If mode is 0, get program_input_d to the last argument
if [ "$mode" -eq 0 ]; then
    program_input_d=${!#}  # Get the last argument
fi

# Compile the program
g++ -o lpsw lpsw.cpp -std=c++17 -O3
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Compilation successful."

if [ "$mode" -eq 0 ]; then
    
    echo "Running the program $runs times for $program_input_d."

    # Run in parallel using `xargs`
    results=$(seq 1 "$runs" | xargs -P 0 -I {} ./lpsw "$program_input_d")

    # Calculate total and average
    total=$(echo "$results" | paste -sd+ - | bc)
    average=$(echo "scale=6; $total / $runs" | bc)

    echo "Average number of Basis Changes for d=$program_input_d: $average"

elif [ "$mode" -eq 1 ]; then
    echo "Running the program $runs times for each d in 10, 20, 50, 100, 200, 400, 600, 800, 1000."
    
    for d in 10 20 50 100 200 400 600 800 1000; do
        
        # Run in parallel using `xargs`
        results=$(seq 1 "$runs" | xargs -P 0 -I {} ./lpsw "$d")
        
        # Calculate total and average for each d
        total=$(echo "$results" | paste -sd+ - | bc)
        average=$(echo "scale=6; $total / $runs" | bc)
        
        echo "Average number of Basis Changes for d=$d: $average"
    done
else
    echo "Invalid mode! Mode must be either 0 or 1."
    exit 1
fi
