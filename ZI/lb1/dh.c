#include "lab1lib.h"

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

long long Random32_Prime()
{
        return 99991;
}

long long Generate_P(long long q)
{
        return 2 * q + 1;
}

long long Generate_G(long long p, long long q)
{
        long long g;
        
        do {
                g = Random32() % (p - 1) + 1;
        } while(PowMod(g, q, p) == 1);
        
        return g;
}

long long Generate_X()
{
        return Random32();
}

long long Create_Y(long long g, long long p, long long X)
{
        return PowMod(g, X, p);
}

long long Create_Z(long long Yb, long long X, long long p)
{
        return PowMod(Yb, X, p);
}
