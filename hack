#!/bin/bash

# Function to handle cleanup
cleanup() {
    if [ -f lol ]; then
        rm lol
    fi
}

# Parse command arguments
while getopts ":s:c:" opt; do
    case ${opt} in
        s)
            search_term="$OPTARG"
            ;;
        c)
            compile_and_run=true
            c_file="$OPTARG"  # Get the filename for compilation
            ;;
        \?)
            echo "Usage: $0 -s <search_term> [ -c <filename> ]"
            exit 1
            ;;
    esac
done

# Check if the core directory exists
if [ ! -d "/bin/core" ]; then
    exit 1
fi

# Prepare the search terms for splitting into individual words
IFS=' ' read -r -a search_words <<< "$search_term"

# Function to count fuzzy matches in the filename (case insensitive)
count_filename_matches() {
    local file=$1
    local match_count=0
    for word in "${search_words[@]}"; do
        # Perform case insensitive matching with grep
        if echo "$(basename "$file")" | grep -iq "$word"; then
            ((match_count++))
        fi
    done
    echo $match_count
}

# Function to count fuzzy matches in the content (case insensitive)
count_content_matches() {
    local file=$1
    local match_count=0
    while read -r line; do
        for word in "${search_words[@]}"; do
            # Perform case insensitive matching in the content
            if echo "$line" | grep -iq "$word"; then
                ((match_count++))
            fi
        done
    done < "$file"
    echo $match_count
}

# Variables to track the best file
max_matches=0
best_file=""
best_file_content=""

for file in /bin/core/*.c; do
    # Count fuzzy matches in filename and content
    filename_matches=$(count_filename_matches "$file")
    content_matches=$(count_content_matches "$file")
    total_matches=$((filename_matches + content_matches))

    # If this file has more matches, it becomes the best match
    if [ $total_matches -gt $max_matches ]; then
        max_matches=$total_matches
        best_file=$file
        best_file_content=$(cat "$file")
    fi
done

# Print the best file content, if there was a match
if [ $max_matches -gt 0 ]; then
    echo " $best_file"
    echo "$best_file_content"
else
    echo "No matches found for '$search_term' in any C files."
fi

# If -c flag is used, compile and run the C file in the current directory
if [ "$compile_and_run" = true ]; then
    if [ -z "$c_file" ]; then
        echo "Error: You must provide a filename to compile using -c."
        exit 1
    fi

    # Clean up any leading/trailing whitespace or quotes from the filename
    c_file=$(echo "$c_file" | sed 's/^[[:space:]"'\''"]*//;s/[[:space:]"'\''"]*$//')

    # Check if the file exists in the current directory
    if [ -f "$c_file" ]; then
        echo "Compiling and running '$c_file'..."

        # Compile the C file with gcc
        gcc "$c_file" -o lol -lm

        if [ $? -eq 0 ]; then
            echo -e "\nCompilation successful! Running the program...\n"
            ./lol  # Run the compiled program
            cleanup  # Clean up the compiled executable
        else
            echo "Error: Compilation failed."
            cleanup  # Clean up even if compilation fails
        fi
    else
        echo "Error: File '$c_file' not found in the current directory."
    fi
fi
