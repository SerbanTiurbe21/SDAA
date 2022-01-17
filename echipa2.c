#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct echipa{
    char nume[25];
    int puncte;
    int buget;
    char oras[25];
}echipa;

void citire(echipa *array, int n)
{
    for(int i=0;i<n;i++)
        {
            printf("Dati numele: \n");
            scanf("%s",&array[i].nume);
            printf("Dati punctele: \n");
            scanf("%d",&array[i].puncte);
            printf("Dati bugetul: \n");
            scanf("%d",&array[i].buget);
            printf("Dati orasul: \n");
            scanf("%s",&array[i].oras);
        }
}

void swap(echipa *e1, echipa *e2)
{
    echipa temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

void afisare(echipa *array, int n)
{
    for(int i=0;i<n;i++)
        printf("%s %d %d %s \n",array[i].nume,array[i].puncte,array[i].buget,array[i].oras);
    printf("\n");
}

void muta_primelePoz(echipa *array, int n)
{
    int i=0, j=n-1;
    while(i<j)
        {
            while(i<j && array[j].puncte < 45)
                j--;
            if(array[i].puncte < 45)
                swap(&array[i],&array[j]);
            i++;
        }
    i = 0, j = n-1;
    while(i<j)
        {
            while(i<j && array[j].puncte < 20)
                j--;
            if(array[i].puncte < 20)
                swap(&array[i],&array[j]);
            i++;
        }
}

void sortare_eficienta(echipa *array, int st, int dr)
{
    echipa pivot, temp;
    int i=st, j=dr;
    for(int k=i;k<=j;k++)
        {
            if(array[k].buget > 10000)
                {
                    pivot = array[k];
                    break;
                }
        }
    do{
        while(array[i].buget < 10000 || (array[i].puncte > pivot.puncte)) i++; //mereu semnu asta arata daca e cresc sau desc
        while(array[j].buget < 10000 || (array[j].puncte < pivot.puncte)) j--;
        while(i<=j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
    }while(i<=j);
    if(st < j) sortare_eficienta(array,st,j);
    if(dr > i) sortare_eficienta(array,i,dr);
}

int main()
{
    int nr;
    printf("Dati nr: \n");
    scanf("%d",&nr);
    echipa *my_team = (echipa*)malloc(nr*sizeof(echipa));
    if(!my_team)
        {
            printf("Rroare la alocare!\n");
            exit(EXIT_FAILURE);
        }
    citire(my_team, nr);
    afisare(my_team, nr);
    printf("\n DUPA \n");
    //muta_primelePoz(my_team,nr);
    sortare_eficienta(my_team,0,nr-1);
    afisare(my_team,nr);
}