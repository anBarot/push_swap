#!/bin/bash

# for i in {1..100}
# do
# echo "test number : " $i
entries=($(shuf -i 0-99 -n 10))
echo "${entries[@]}" > ./test_dir/input_pushswap.txt
chmod 777 ./test_dir/input_pushswap.txt

value=$(<./test_dir/input_pushswap.txt)
# value="98 76 22 26 72 64 33 15 40 77"
echo $value
# ./push_swap $value | wc -l
./push_swap $value | ./checker $value
# ./push_swap $value | ./checker_2 $value

# ./push_swap_2 $value | wc -l
# ./push_swap_2 $value | ./checker $value
# ./push_swap_2 $value | ./checker_2 $value
# done
 
# check KO's number :
# make test > test_result.txt; cat test_result.txt |grep KO |wc -l

# get mean for multiple testing :
# make test > test_result.txt ;  awk '{ total += $1; count++ } END { print total/count }' test_result.txt