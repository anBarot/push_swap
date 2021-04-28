#!/bin/bash

for i in {0..100}
do
echo "test number : " $i
entries=($(shuf -i 0-100 -n 3))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt

value=$(<./test_dir/input_pushswap.txt)
echo $value
# ./push_swap $value | wc -l
./push_swap $value | ./checker $value

# ./push_swap_2 $value | wc -l
# ./push_swap_2 $value | ./checker $value

echo '--------------------------------------------------'
done
 
# check KO's number :
# make test | grep KO |wc -l

# get mean for multiple testing :
# make test > test_result.txt ;  awk '{ total += $1; count++ } END { print total/count }' test_result.txt

# ./push_swap 13 94 40 5 97 88 64 33 41 93 0 58 6 35 12 42 68 27 95 7 17 85 67 96 49 > test \
# && cat test | ./checker 13 94 40 5 97 88 64 33 41 93 0 58 6 35 12 42 68 27 95 7 17 85 67 96 49