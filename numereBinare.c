#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int sol[6];

void afiseaza(int k)
{
    for(int i=0;i<=k;i++)
        printf("%d ",sol[i]);
    printf("\n");
}

int countZeros(int array[], int k)
{
    int count = 0;
    for(int i=0;i<=k;i++)
        if(array[i] == 0)
            count++;
    return count;
}

int countOnes(int array[], int k)
{
    int count = 0;
    for(int i=0;i<=k;i++)
        if(array[i] == 1)
            count++;
    return count;
}

bool isOne(int cifra)
{
    return (cifra == 1);
}

int ok(int k)
{
    if(k==1)
        {
            if(isOne(sol[k-1]) && isOne(sol[k]))
                return false;
        }
    if(k==5)
        {
            if(sol[k] == 0)
                return false;
        }
    if(countZeros(sol,k) > 2)
        return false;
    if(countOnes(sol,k) > 4)
        return false;
    return true;
}

int solutie(int k)
{
    return (k == 5);
}

void back(int k)
{
    for(int i=0;i<2;i++)
        {
            sol[k] = i;
            if(ok(k))
            {
                if(solutie(k))
                    afiseaza(k);
                else
                    back(k+1);
            }
        }
    
}

int main()
{
    back(0);
}