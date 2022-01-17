#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct film{
    char nume[35];
    int an;
    int premii;//1 daca are, 0 daca nu are
}film;

void swap(film *f1, film *f2)
{
    film temp = *f1;
    *f1 = *f2;
    *f2 = temp;
}

void muta_cele_premiate(film *array, int n)
{
    int i=0,j=n-1;
    while(i<j)
        {
            while(i<j && array[j].premii == 0)
                j--;
            if(array[i].premii == 0)
                swap(&array[i],&array[j]);
            i++;
        }
}

void citire(film *array, int n)
{
    for(int i=0;i<n;i++)
        {
            printf("Dati numele: \n");
            scanf("%s",&array[i].nume);
            printf("Dati anul: \n");
            scanf("%d",&array[i].an);
            printf("Daca are premii sau nu: \n");
            scanf("%d",&array[i].premii);
        }
}

void afisare(film *array, int n)
{
    for(int i=0;i<n;i++)
        printf("%s %d %d \n",array[i].nume,array[i].an,array[i].premii);
    printf("\n");
}

void sortare_invers_alfabetica(film *array, int st, int dr)
{
    int i = st, j = dr;
    film pivot, temp;
    for(int k=i;k<=j;k++)
        {
            if(array[k].premii == 1)
                {
                    pivot = array[k];
                    break;
                }
        }
    do{
        while(array[i].premii == 0 || (strcmp(array[i].nume,pivot.nume) > 0 )) i++; //mereu conditia din stanga tre sa fie opusu la ce camp iti cere si a doua conditie tre sa fie sortarea cresc sau desc
        while(array[j].premii == 0 || (strcmp(array[j].nume,pivot.nume) < 0 )) j--;
        while(i <= j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
    }while(i <= j);
    if(st < j) sortare_invers_alfabetica(array,st,j);
    if(dr > i) sortare_invers_alfabetica(array,i,dr);
}

int main()
{
    int nr;
    printf("Dati numarul de filme: \n");
    scanf("%d",&nr);
    film *my_movie = (film*)malloc(nr*sizeof(film));
    if(!my_movie)
        {
            printf("Eroare la alocare!\n");
            exit(EXIT_FAILURE);
        }
    citire(my_movie,nr);
    afisare(my_movie,nr);

    printf("\nDUPA SORTARE\n");
    sortare_invers_alfabetica(my_movie,0,nr-1);
    afisare(my_movie,nr);
    free(my_movie);
}

