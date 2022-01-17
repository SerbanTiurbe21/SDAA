#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//avem multimea M = {a,b,c}. Sa se genereze toate cuvintele de lungime 10 care sa contina 3 a, 4 b si 3 c

char sol[11];
int counta, countb, countc;

int countA(int k, char cuvant[])
{
    int count = 0;
    for(int i=0;i<=k;i++)
        {     
            //printf("%c ",cuvant[i]); 
            if(cuvant[i] == 'a')
            count++;
        }
    return count;
}

int countB(int k, char cuvant[])
{
    int count = 0;
    for(int i=0;i<=k;i++)
        if(cuvant[i] == 'b')
            count++;
    return count;
}

int countC(int k, char cuvant[])
{
    int count = 0;
    for(int i=0;i<=k;i++)
        if(cuvant[i] == 'c')
            count++;
    return count;
}

void afisare(int k)
{
    for(int i=0;i<=k;i++)
        printf("%c ",sol[i]);
    printf("\n");
}

bool ok(int k)
{
    //printf("%d %d %d \n",countA(sol), countB(sol), countC(sol));
    if(countA(k,sol) > 3)
        return false;
    if(countB(k,sol) > 4)
        return false;
    if(countC(k,sol) > 3)
        return false;
    return true;
}

int solutie(int k)
{
    if(k == 10)
        return true;
    else
        return false;
}

void back(int k)
{
    for(char i='a';i<='c';i++)
        {
            sol[k] = i;
            //afisare(k);
            if(ok(k))
                {
                    if(solutie(k))
                        afisare(k);
                    else
                        back(k+1);
                }
        }
    sol[k] = '\0';
}

int main()
{
    back(1);
}