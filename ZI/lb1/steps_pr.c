#include "stdio.h"
#include "stdlib.h"

long long PowMod(long long base, long long p, long long mod);

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

/*
        Функция добавляет новое значение в дерево
        Возвращает указатель на последний созданный лист (для удаления), либо начало дерева (при head == NULL)
        В переменную rez пишется STN_TRUE, а в rez_node - лист с которым совпало значение, если нашлось совпадение
        При совпадении новый лист не добавляется, но записывается в список и возвращается как последний
*/
CTRASH_NODE *AddToTrash(CTRASH_NODE *head, CTRASH_NODE *last, char i, long long num, long long id, char *rez, CTRASH_NODE **rez_node)
{
        CTRASH_NODE *node;
        CTRASH_NODE *next;

        *rez = CTN_FALSE;
        node = malloc(sizeof(CTRASH_NODE));
        if(node != NULL){
                node->i = i;
                node->num = num;
                node->id = id;
                node->next = NULL;              
                
                if(head == NULL){
                        return node;
                }
                
                if(last != NULL){
                        last->next = node;
                }
                
                next = head;
                
                while(1){
                        if(next->id == node->id){
                                *rez = CTN_TRUE;
                                *rez_node = next;
                                
                                return node;
                        }
                        if(next->id > node->id){
                                if(next->left != NULL) {
                                        next = next->left;
                                        
                                        continue;
                                } else {
                                        next->left = node;
                                        
                                        return node;
                                }
                        }
                        if(next->id < node->id){
                                if(next->right != NULL)
                                        next = next->right;
                                else {
                                        next->right = node;
                                        
                                        return node;
                                }
                        }
                }
        }    
        
        fprintf(stderr, "Error on create node\n");
        
        return last;
}

void DestroyTrash(CTRASH_NODE *head)
{
        CTRASH_NODE *node;
        
        while(head != NULL){
                node = head;
                head = head->next;
                
                free(node);
        }
}

long long SQRT_Long(long long a)
{
        int i;
        long long x1, x2;
        
        x1 = a;
        while(x1 > 0){
                /*
                        Считаем кол-во бит в числе
                */
                x1 = x1 >> 1;
                i++;
        }
        x2 = (long long)1 << (i / 2);
        
        i = 0;
        while(1){
                x1 = (x2 + a / x2) >> 1;
                if( x1 == x2 || (x1 > x2 && i == 1) )
                        break;
                if(x1 < x2)
                        i = 1;
                x2 = x1;
        }
        
        return x1;
        
}

long long CalculateLog_BabyStep(long long a, long long y, long long p)
{
        long long x;
        long long m, k, i, j;
        CTRASH_NODE *trash, *last;
        CTRASH_NODE *I, *J;
        long long id;
        char rez;
        
        trash = NULL;
        last = NULL;
        I = NULL;
        J = NULL;
        
        m = k = SQRT_Long(p);
        while( (m * k) <= p ){
                m++;
        } 
        printf("m:%lld\nk:%lld\nm*k:%lld\np:%lld\n", m, k, m * k, p);/*!!!!!!!!!*/

        for(i = 1, j = 0; j < m || i <= k;){               
                if(j < m){
                        id = (PowMod(a, j, p) * y) % p;
                        if(trash == NULL){
                                trash = AddToTrash(NULL, NULL, CTN_J, j, id, &rez, &I);
                        } else {
                                last = AddToTrash(trash, last, CTN_J, j, id, &rez, &I);                        
                        }
                        if(rez == CTN_TRUE){
                                /*
                                        Совпадение J с I
                                */
                                J = last;
                                
                                break;
                        }
                        j++;
                }
                if(i <= k){
                        id = PowMod(a, i * m, p);
                        last = AddToTrash(trash, last, CTN_I, i, id, &rez, &J);
                        if(rez == CTN_TRUE){
                                /*
                                        Совпадение I с J
                                */
                                I = last;
                                
                                break;
                        }
                        i++;
                }
        }

        if(j >= m)
                fprintf(stderr, "Warning: j >= m\n");
        if(i > k)
                fprintf(stderr, "Warning: i > k\n");

        if(J == NULL){
                fprintf(stderr, "Calculating error: J is NULL\n");
                DestroyTrash(trash);
                return -1;
        }
        if(I == NULL){
                fprintf(stderr, "Calculating error: I is NULL\n");
                DestroyTrash(trash);
                return -1;
        }
        
        if(J->i != CTN_J)
                fprintf(stderr, "Calculating error: J not J\n");
        if(I->i != CTN_I)
                fprintf(stderr, "Calculating error: I not I\n");
                
        printf("I(%lld):%lld\nJ(%lld):%lld\n", I->num, I->id, J->num, J->id);
        
        x = I->num * m - J->num;
        
        DestroyTrash(trash);
        return x;
}

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
