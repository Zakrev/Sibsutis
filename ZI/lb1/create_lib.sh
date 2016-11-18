#!/bin/bash

gcc -Wall -c dh.c evklid.c pow_mod.c steps.c && ar rc liblab1lib.a dh.o evklid.o pow_mod.o steps.o && echo "Succes!"

rm dh.o evklid.o pow_mod.o steps.o 2> /dev/null
