#!/bin/bash
../../ret < quicksort.txt >quicksort.c
gcc quicksort.c -o qs1
g++ quicksort1.cpp -o qs2
g++ gen.cpp -o gen
