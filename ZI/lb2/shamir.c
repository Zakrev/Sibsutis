#include "stdio.h"
#include "../lb1/lab1lib.h"

int Generate_CD(long long P, long long *C, long long *D)
{
        long long rnd, U[3];
        
        do{                
                rnd = Random32() / (P - 1) + 1;
                if(Evklid_GCD((P - 1), rnd, U) != 0)
                        return -1;
        }while(U[0] != 1 || U[2] < 0);
        
        *C = rnd;
        *D = U[2];
        
        return 0;
} 

long long Shamir_step_1(long long P, long long C, long long X)
{
        return PowMod(X, C, P);
}

long long Shamir_step_2(long long P, long long D, long long X)
{
        return PowMod(X, D, P);
}

int main()
{
        long long P = 82981;
        long long AC, AD, BC, BD, M = 15, AX, BX;
        
        Generate_CD(P, &AC, &AD);
        Generate_CD(P, &BC, &BD);
        
        printf("A:\nP:%lld\tC:%lld\tD:%lld\t%lld\n", P, AC, AD, (AC * AD) % (P - 1));
        printf("B:\nP:%lld\tC:%lld\tD:%lld\t%lld\n", P, BC, BD, (BC * BD) % (P - 1));
        /*
                Step 1: A send X1 to B
        */
        AX = Shamir_step_1(P, AC, M);
        /*
                Step 2: B receive A, and send X2 to A
        */
        BX = Shamir_step_1(P, BC, AX);
        /*
                Step 3: A receive B, and send X3 to B
        */
        AX = Shamir_step_2(P, AD, BX);
        /*
                Step 4: B receive A
        */
        BX = Shamir_step_2(P, BD, AX);
        
        printf("%lld - %lld\n", M, BX);
        

        return 0;
}
