#!/bin/bash
crunch 4 6 -p raz 241199 >> raz.txt
crunch 4 6 -p raz chloe >> raz.txt
crunch 4 6 -p chloe 241199 >> raz.txt
crunch 4 6 -p raz 241199 chloe >> raz.txt
echo raz >> raz.txt
echo chloe >> raz.txt
echo 241199 >> raz.txt
