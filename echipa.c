#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char nume[25];
    int puncte;
    int buget;
    char oras[25];
}echipa;

void citire(echipa array[], int n)
{
    for(int i=0;i<n;i++)
        {
            printf("Dati numele: \n");
            scanf("%s",&array[i].nume);
            printf("Dati punctele: \n");
            scanf("%s",&array[i].puncte);
            printf("Dati bugetul: \n");
            scanf("%d",&array[i].buget);
            printf("Dati orasul: \n");
            scanf("%d",&array[i].oras);
        }
}

void afisare(echipa array[], int n)
{
    for(int i=0;i<n;i++)
        {
            printf("%s %d %d %s \n",array[i].nume, array[i].puncte, array[i].buget, array[i].oras);
        }
}

void muta_eficient(echipa *array, int n)
{
    int i = 0, j = n - 1;
    while(i < j)
        {
            
        }
}

int main()
{

}