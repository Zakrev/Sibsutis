#include "stdio.h"
#include "../lb1/lab1lib.h"

/*
        Функция шифрует сообщение m, отдает пару m2[2]{r,e}
        При m >= p  возвращает ошибку
*/
int eg_send(long long P, long long g, long long open_key, long long m, long long *m2)
{
        long long k;
        
        if(m >= P)
                return -1;
        
        k = Random32() % (P - 2) + 1;
        
        m2[0] = PowMod(g, k, P);
        m2[1] = (m * PowMod(open_key, k, P)) % P;
        
        return 0;
}

/*
        Функция дешифрует сообщение, принимает пару m2[2]{r,e}
        Возвращает сообщение m
*/
long long eg_rec(long long P, long long close_key, long long *m2)
{
        return (m2[1] * PowMod(m2[0], P - 1 - close_key, P)) % P;
}

int main()
{
        long long q = 11, p,  g, X, Y;
        long long mA = 10, mB;
        long long m2[2];
        
        p = Generate_P(q);
        g = Generate_G(p, q);
        X = Random32() % (p - 1) + 2;
        Y = Generate_Y(g, p, X);
        printf("P: %lld\nG: %lld\nX: %lld\nY: %lld\n", p, g, X, Y);
        
        if(eg_send(p, g, Y, mA, m2) != 0){
                fprintf(stderr, "eg_send: error/n"); 
        } else {
                printf("mA: %lld\nm2: %lld %lld\n", mA, m2[0], m2[1]);
                mB = eg_rec(p, X, m2);
                printf("mB: %lld\nm2: %lld %lld\n", mB, m2[0], m2[1]);
        }
        
        return 0;
}
