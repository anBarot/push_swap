#!/bin/bash

entries=($(shuf -i 0-99 -n 6))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt

value=$(<./test_dir/input_pushswap.txt)
./push_swap $value | wc -l
./push_swap $value | ./checker $value

./push_swap_2 $value | wc -l
./push_swap_2 $value | ./checker $value
#40 113 104 22 6