#ifndef LAB1LIB_H_
#define LAB1LIB_H_

/*
        dh.c
*/
#include "time.h"

#define R32M 4294967296
#define R32A 1103515245
#define R32C 12345

long long Random32();
long long Random32_1(long long x);
long long Random32_Prime();
long long CountingBit(long long number);
long long Generate_P(long long q);
long long Generate_G(long long p, long long q);
long long Generate_X();
long long Generate_Y(long long g, long long p, long long X);
long long Generate_Z(long long Yb, long long X, long long p);

/*
        dh.c
*/
/*
        steps.c
*/
#include "stdio.h"
#include "stdlib.h"

#define CTRASH_NODE struct CalculatedTrash
#define CTN_I 1
#define CTN_J 2
#define CTN_TRUE 1
#define CTN_FALSE 2

CTRASH_NODE {
        char i; //Флаг i/j
        long long num; //Номер i/j
        long long id; //Значение
        CTRASH_NODE *left;
        CTRASH_NODE *right;
        CTRASH_NODE *next;
};

long long CalculateLog_BabyStep(long long a, long long y, long long p);
long long SQRT_Long(long long a);
/*
        steps.c
*/
/*
        pow_mod.c
*/
long long PowMod(long long base, long long p, long long mod);
/*
        pow_mod.c
*/
/*
        evklid.c
*/
int Evklid_GCD(long long a, long long b, long long *U);
/*
        evklid.c
*/

#endif
