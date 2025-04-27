#!/bin/bash
#Bismillahir_rahmanir_rahim
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
RESET='\033[0m'

echo -e "${BLUE}====================================="
echo -e "${BLUE}        C/C++ File Runner Tool      "
echo -e "${BLUE}       --------------------------   "
echo -e "${YELLOW} A tool to find, compile, and run C/C++ files"
echo -e "${GREEN} Created by LunarLumos"
echo -e "${BLUE}=====================================${RESET}"

cleanup() {
    if [ -f lol ]; then
        rm lol
    fi
}

while getopts ":s:c:" opt; do
    case ${opt} in
        s)
            search_term="$OPTARG"
            ;;
        c)
            compile_and_run=true
            c_file="$OPTARG"
            ;;
        \?)
            echo -e "${RED}Usage: $0 -s <search_term> [ -c <filename> ]${RESET}"
            exit 1
            ;;
    esac
done

if [ -n "$search_term" ]; then
    loc="search"
    if [ -d "$loc" ]; then
        IFS=' ' read -r -a search_words <<< "$search_term"

        count_filename_matches() {
            local file=$1
            local match_count=0
            for word in "${search_words[@]}"; do
                if echo "$(basename "$file")" | grep -iq "$word"; then
                    ((match_count++))
                fi
            done
            echo $match_count
        }

        count_content_matches() {
            local file=$1
            local match_count=0
            while read -r line; do
                for word in "${search_words[@]}"; do
                    if echo "$line" | grep -iq "$word"; then
                        ((match_count++))
                    fi
                done
            done < "$file"
            echo $match_count
        }

        max_matches=0
        best_file=""
        best_file_content=""

        for file in "$loc"/*.c "$loc"/*.cpp; do
            filename_matches=$(count_filename_matches "$file")
            content_matches=$(count_content_matches "$file")
            total_matches=$((filename_matches + content_matches))

            if [ $total_matches -gt $max_matches ]; then
                max_matches=$total_matches
                best_file=$file
                best_file_content=$(cat "$file")
            fi
        done

        if [ $max_matches -gt 0 ]; then
            echo -e "${GREEN}File content for '$best_file':${RESET}"
            # Print content without any color codes
            echo "$best_file_content"
        else
            echo -e "${RED}No matches found for '$search_term' in any C/C++ files.${RESET}"
        fi
    else
        echo -e "${YELLOW}Core directory not found. Skipping search.${RESET}"
    fi
fi

if [ "$compile_and_run" = true ]; then
    if [ -z "$c_file" ]; then
        echo -e "${RED}Error: You must provide a filename to compile using -c.${RESET}"
        exit 1
    fi

    c_file=$(echo "$c_file" | sed 's/^[[:space:]"'\''"]*//;s/[[:space:]"'\''"]*$//')

    if [ -f "$c_file" ]; then
        echo -e "${GREEN}Compiling and running '$c_file'...${RESET}"

        if [[ "$c_file" == *.c ]]; then
            gcc "$c_file" -o lol -lm
        elif [[ "$c_file" == *.cpp ]]; then
            g++ "$c_file" -o lol -lm
        else
            echo -e "${RED}Error: Unsupported file type. Please provide a .c or .cpp file.${RESET}"
            exit 1
        fi

        if [ $? -eq 0 ]; then
            echo -e "\n${GREEN}Compilation successful! Running the program...${RESET}\n"
            ./lol
            cleanup
        else
            echo -e "${RED}Error: Compilation failed.${RESET}"
            cleanup
        fi
    else
        echo -e "${RED}Error: File '$c_file' not found in the current directory.${RESET}"
    fi
fi
