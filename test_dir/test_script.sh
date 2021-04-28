#!/bin/bash

read input

echo '-------------- result push_swap raw : --------------'
./push_swap $input > tmp.txt
cat tmp.txt
echo '-------------- number of operations : --------------'
cat tmp.txt | wc -l
echo '-------------- result push_swap | checker : --------------'
cat tmp.txt | ./checker $input
rm tmp.txt