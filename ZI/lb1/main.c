#include "lab1lib.h"

int main()
{
        long long p, a, y, x;
        
        //X = 2978041613
        a = 346;
        y = 303;
        p = 863;

        x = CalculateLog_BabyStep(a, y, p);
        
        printf("X: %lld\nPowMod\tY\n%lld\t%lld\n", x, PowMod(a, x, p), y);

        return 0;
}
