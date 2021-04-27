#!/bin/bash

read nbr

for i in {0..99}
do
entries=($(shuf -i 0-$nbr -n $nbr))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt
value=$(<./test_dir/input_pushswap.txt)
./push_swap $value | ./checker $value 
done
