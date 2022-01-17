#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nume[35];
    int an;
    int premii;
}film;

void citire(film *filme, int n)
{
    for(int i=0;i<n;i++)
        {
            printf("Dati numele filmului:\n");
            scanf("%s",&filme[i].nume);
            printf("Dati anul fimlului:\n");
            scanf("%d",&filme[i].an);
            printf("Are sau nu premiu? 1-pt DA, 0-pt NU\n");
            scanf("%d",&filme[i].premii);
        }
}

void afisare(film array[], int n)
{
    for(int i=0;i<n;i++)
        printf("%s %d %d \n",array[i].nume, array[i].an, array[i].premii);
}

void swap(film *f1, film *f2)
{
    film temp;
    temp = *f1;
    *f1 = *f2;
    *f2 = temp;
}

void muta(film array[], int n)
{
    int i=0, j=n-1;
    while(i<j)
        {
            while(i<j && array[i].premii == 1)
                i++;
            if(array[j].premii == 1)
                swap(&array[j],&array[i]);
            j--;
        }
}

void sorteazaAlfabetic(film *filme, int n)
{
    int i, j;
    char temp[35];
    for(i=0;i<n;i++)
        {
            for(j=n-1;j>i;j--)
                {
                    if(filme[i].premii == 1)
                        {
                            if(strcmp(filme[j-1].nume,filme[j].nume) < 0)
                                {
                                    strcpy(temp,filme[j-1].nume);
                                    strcpy(filme[j-1].nume,filme[j].nume);
                                    strcpy(filme[j].nume,temp);
                                }
                        }
                }
        }
}

int main()
{
    int n;
    printf("Dati numarul de filme: ");
    scanf("%d",&n);

    film *filme;
    filme = (film*)malloc(n*sizeof(film));
    if(filme == NULL)
        {
            printf("Eroare la alocarea memoriei!\n");
            exit(EXIT_FAILURE);
        }

    printf("Inainte de mutare\n");
    citire(filme,n);
    afisare(filme,n);
    printf("Dupa sortare\n");
    sorteazaAlfabetic(filme,n);
    afisare(filme,n);
}