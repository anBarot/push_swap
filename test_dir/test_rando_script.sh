#!/bin/bash

read nbr

entries=($(shuf -i 0-$nbr -n $nbr))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt
value=$(<./test_dir/input_pushswap.txt)

echo '-------------- random values : --------------'
echo $value
echo '-------------- result push_swap raw : --------------'
./push_swap $value > tmp_rando.txt
cat tmp_rando.txt
echo '-------------- number of operations : --------------'
cat tmp_rando.txt | wc -l
echo '-------------- result push_swap | checker : --------------'
cat tmp_rando.txt | ./checker $value
rm tmp_rando.txt