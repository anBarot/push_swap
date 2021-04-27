#!/bin/bash

read input

echo '-------------- result push_swap raw : --------------'
./push_swap $input 
echo '-------------- number of operations : --------------'
./push_swap $input | wc -l
echo '-------------- result push_swap | checker : --------------'
./push_swap $input | ./checker $input
