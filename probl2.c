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

void negSiPoz(int array[], int n)
{
    int j=0;
    for(int i=0;i<n;i++)
        {
            if(array[i] < 0)
                {
                    if(i != j)
                        swap(&array[i],&array[j]);
                    j++;
                }
        }
    for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
                {
                    if(array[i] > 0)
                        {
                            if(array[j-1] > array[j])
                                swap(&array[j-1],&array[j]);
                        }
                } 
        }
}

void afisareArr(int array[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",array[i]);
}

int main()
{
    int arr[] = {3,1,2,-1,-2,-3};
    int n = sizeof(arr)/sizeof(arr[0]);

    negSiPoz(arr,n);
    afisareArr(arr,n);
}