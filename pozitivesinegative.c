#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void muta(int *array, int n)
{
    int j = 0;
    for(int i=0;i<n;i++)
        {
            if(array[i] < 0)
                {
                    if(i != j)
                        swap(&array[i],&array[j]);
                    j++;
                }
        }
}
