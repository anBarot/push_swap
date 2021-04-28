#!/bin/bash

read nbr

entries=($(shuf -i 0-$nbr -n $nbr))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt
value=$(<./test_dir/input_pushswap.txt)

echo '-------------- random values : --------------'
echo $value
echo '-------------- result push_swap raw : --------------'
./push_swap $value > tmp.txt
cat tmp.txt
echo '-------------- number of operations : --------------'
cat tmp.txt | wc -l
echo '-------------- result push_swap | checker : --------------'
cat tmp.txt | ./checker $value
rm tmp.txt