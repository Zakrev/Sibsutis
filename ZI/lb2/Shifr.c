#include "stdio.h"
#include "../lb1/lab1lib.h"

#include "unistd.h"
#include "fcntl.h"

/*
        Функция шифрует сообщение m, отдает пару m2[2]{r,e}
        При m >= p  возвращает ошибку
*/
int eg_send(long long P, long long g, long long key, long long m, long long *m2)
{
        long long k;
        
        if(m >= P)
                return -1;
        
        k = Random32() / (P - 2) + 1;
        
        m2[0] = PowMod(g, k, P);
        m2[1] = m * PowMod(key, k, P);
        
        return 0;
}

/*
        Функция дешифрует сообщение, принимает пару m2[2]{r,e}
        Возвращает сообщение m
*/
long long eg_rec(long long P, long long key, long long *m2)
{
        return m2[1] * PowMod(m2[0], P - 1 - key, P);
}

int main()
{
        long long P = 82981;
        int in, out;
        long long data = 0, lenght;
        
        in = open("text.txt", O_RDONLY);
        out = open("retext.txt", O_CREAT | O_RDWR, S_IRWXU);
        
        if(!in)
                return -1;
        
        lenght = CountingBit(P);
        //printf("%lld - %lld - %lld\n", P, lenght, (lenght - 1)/8 );
        
        while(read(in, &data, (lenght - 1) / 8) > 0){
                //printf("%lld - %lld\n", data, CountingBit(data));
                write(out, &data, 2);
                data = 0;
        }
        
        close(in);
        close(out);
        
        return 0;
}
