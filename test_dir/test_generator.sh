#!/bin/bash

entries=($(shuf -i 0-149 -n 15))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt

value=$(<./test_dir/input_pushswap.txt)
./push_swap $value | wc -l
./push_swap $value | ./checker $value
