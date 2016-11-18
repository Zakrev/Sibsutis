#include "stdio.h"

#include "time.h"

long long PowMod(long long base, long long p, long long mod);

#define R32M 4294967296
#define R32A 1103515245
#define R32C 12345

long long R32X = 0;

long long Random32()
{
        long long x = time(NULL) + clock() + R32X;
        
        return R32X = (R32A * x + R32C) % R32M;
}

long long Random32_1(long long x)
{       
        return (R32A * x + R32C) % R32M;
}

/*
        Функция получения p
        На вход q - простое число
        На выход p = 2*q + 1
*/
long long Generate_P(long long q)
{
        return 2 * q + 1;
}
/*
        Получение g
        На вход p и q
        Цикл
        Генерируем g, 1 < g < p - 1
        Если g^q (mod p) != 1
                возвращаем g
        Либо
                Повторяем
*/
long long Generate_G(long long p, long long q)
{
        long long g;
        
        do {
                g = Random32() % (p - 1) + 1;
        } while(PowMod(g, q, p) == 1);
        
        return g;
}
/*
        Получение X
        Генерируем X и возвращаем
*/
long long Generate_X()
{
        return Random32();
}
/*
        Получение Y
        На вход g, X, p
        Возвращаем Y = g^X (mod p)
*/
long long Create_Y(long long g, long long p, long long X)
{
        return PowMod(g, X, p);
}
/*
        Получение Z
        На вход Y', X, p
        Возвращаем Z = Y'^X (mod p)
*/
long long Create_Z(long long Yb, long long X, long long p)
{
        return PowMod(Yb, X, p);
}


int main()
{
        long long q, g, p;
        long long X1, Y1, Z1;
        long long X2, Y2, Z2;
        
        q = 431;
        p = Generate_P(q);
        g = Generate_G(p, q);
        
        printf("q: %lld\np: %lld\ng: %lld\n", q, p, g);
        
        X1 = Generate_X();
        X2 = Generate_X();
        
        Y1 = Create_Y(g, p, X1);
        Y2 = Create_Y(g, p, X2);
        
        printf("X1: %lld\nY1: %lld\n", X1, Y1);
        printf("X2: %lld\nY2: %lld\n", X2, Y2);
        
        Z1 = Create_Z(Y2, X1, p);
        Z2 = Create_Z(Y1, X2, p);
        
        printf("%lld ", Z1);
        if(Z1 == Z2)
                printf("=");
        printf(" %lld\n", Z2);
        
        return 0;
}
