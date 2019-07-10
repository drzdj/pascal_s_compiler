#!/bin/bash
./gen > data.txt
./qs1 < data.txt >res1.txt
./qs2 < data.txt >res2.txt
if diff res1.txt res2.txt -Z ;then
		find . -name 'res*.txt' -print -exec cat {} \;
        echo "RIGHT"
else
        echo "WRONG"
fi
