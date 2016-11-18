#!/bin/bash

gcc -c dh.c
gcc -c evklid.c
gcc -c pow_mod.c
gcc -c steps.c

ar rc liblab1lib.a dh.o evklid.o pow_mod.o steps.o

rm dh.o evklid.o pow_mod.o steps.o
