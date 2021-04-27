#!/bin/bash

read nbr

entries=($(shuf -i 0-$nbr -n $nbr))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt
value=$(<./test_dir/input_pushswap.txt)

echo '-------------- random values : --------------'
echo $value
echo '-------------- result push_swap raw : --------------'
./push_swap $value
echo '-------------- number of operations : --------------'
./push_swap $value | wc -l
echo '-------------- result push_swap | checker : --------------'
./push_swap $value | ./checker $value