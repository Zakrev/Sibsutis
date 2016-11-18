long long PowMod(long long base, long long p, long long mod)
{
        long long tmp;
        
        if(p == 0)
                return 1;
        
        if( p == 1 )
                return base;
                
        if(p % 2 == 0){
                tmp = PowMod(base, p / 2, mod);
                
                return tmp * tmp % mod;
        }

        return PowMod(base, p - 1, mod) * base % mod;
}
