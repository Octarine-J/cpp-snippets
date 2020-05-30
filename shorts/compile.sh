#!/bin/bash

filename=$(basename "$1")
include_dir="."
output_dir="build"
output_name="${filename%.*}"
echo "compiling '$output_name'..."
g++ -std=c++17 -Wall $1 -o $output_dir/$output_name -I $include_dir
