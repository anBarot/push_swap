#!/bin/bash

echo '---------- array size : 5 ----------'
for i in {0..99}
do
entries=($(shuf -i 0-100 -n 5))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt
value=$(<./test_dir/input_pushswap.txt)
echo $value
./push_swap $value | wc -l
./push_swap $value | ./checker $value
done

echo '---------- array size : 10 ----------'
for i in {0..99}
do
entries=($(shuf -i 0-100 -n 10))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt
value=$(<./test_dir/input_pushswap.txt)
echo $value
./push_swap $value | wc -l
./push_swap $value | ./checker $value
done

echo '---------- array size : 100 ----------'
for i in {0..99}
do
entries=($(shuf -i 0-1000 -n 100))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt
value=$(<./test_dir/input_pushswap.txt)
echo $value
./push_swap $value | wc -l
./push_swap $value | ./checker $value
done

echo '---------- array size : 500 ----------'
for i in {0..9}
do
entries=($(shuf -i 0-1000 -n 500))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt
value=$(<./test_dir/input_pushswap.txt)
echo $value
./push_swap_2 $value | wc -l
./push_swap_2 $value | ./checker $value
done
