int Evklid_GCD(long long a, long long b, long long *U)
{
        long long V[3] = {b, 0, 1};
        long long T[3];
        long long q;
        
        if(a < b)
                return -1;
        
        U[0] = a;
        U[1] = 1;
        U[2] = 0;
        
        while(V[0] != 0){
                q = U[0] / V[0];
                T[0] = U[0] % V[0];
                T[1] = U[1] - q * V[1];
                T[2] = U[2] - q * V[2];
                
                U[0] = V[0];
                U[1] = V[1];
                U[2] = V[2];
                
                V[0] = T[0];
                V[1] = T[1];
                V[2] = T[2];
        }
        
        return 0;
}
