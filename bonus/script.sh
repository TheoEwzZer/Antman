#!/bin/bash

num_files=0
num_success=0
num_errors=0

for file in $(find files -type f); do
    temp_file_antman=$(mktemp)

    if ./antman/antman "$file" 1 > $temp_file_antman; then
        original_size=$(wc -c < "$file")
        compressed_size=$(wc -c < $temp_file_antman)

        compression_percentage=$((100 * $compressed_size / $original_size))

        echo "The file $file was compressed and reduced to $compression_percentage% of its original size."

        temp_file_giantman=$(mktemp)

        if ./giantman/giantman "$temp_file_antman" 1 > $temp_file_giantman; then

            if cmp -s $temp_file_giantman "$file"; then
                echo "The output of 'giantman' for $file matches the original file."
                num_success=$((num_success + 1))
            else
                echo "The output of 'giantman' for $file does not match the original file."
                num_errors=$((num_errors + 1))
            fi
            echo ""
        else
            echo "An error occurred while executing 'giantman' for $file."
            num_errors=$((num_errors + 1))
        fi

        rm $temp_file_antman $temp_file_giantman
    else
        echo "An error occurred while executing 'antman' for $file."
        num_errors=$((num_errors + 1))
    fi

    num_files=$((num_files + 1))
done

echo "Processed $num_files files."
echo "Successfully compressed $num_success files."
echo "Encountered $num_errors errors."

success_rate=$((100 * num_success / num_files))

echo "Overall success rate: $success_rate%."
