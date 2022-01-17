#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nume[35];
    int an;
    int premii; //0 pt nu, 1 pt da
}film;

film filme[100];

void swap(film *f1, film *f2)
{
    film temp = *f1;
    *f1 = *f2;
    *f2 = temp;
}

void moveToFront(film array[], int n)
{
    int i=0, j=n-1;
    while(i<j)
        {
            while(i<j && array[i].premii == 1)
                i++;
            if(array[j].premii == 1)
                {
                    film temp;
                    temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                }
                /* sau faci cu swap(&array[j],&array[i]) */
            j--;
        }
}

void sortareInversa(film array[], int n)
{
    char temp[35];
    for(int i=0;i<n;i++)
        {
            if(array[i].premii == 1)
                {
                    for(int j=n-1;j>i;j--)
                        {
                            if(strcmp(array[j-1].nume,array[j].nume) < 0)
                                {
                                    swap(&array[j-1],&array[j]);
                                }
                        }
                }
        }
}

void citire()
{
    int n;
    printf("Dati numarul de filme: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            printf("Dati numele filmului: \n");
            scanf("%s", &filme[i].nume);
            printf("Dati anul aparitiei: \n");
            scanf("%d", &filme[i].an);
            printf("Daca este sau nu premiat (0-pentru NU, 1-pentru DA): \n");
            scanf("%d", &filme[i].premii);
        }
}

int main()
{
    int n;
    printf("Dati numarul de filme: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            printf("Dati numele filmului: \n");
            scanf("%s", &filme[i].nume);
            printf("Dati anul aparitiei: \n");
            scanf("%d", &filme[i].an);
            printf("Daca este sau nu premiat (0-pentru NU, 1-pentru DA): \n");
            scanf("%d", &filme[i].premii);
        }
    
    sortareInversa(filme,n);
    //moveToFront(filme,n);

    for(int i=0;i<n;i++)
        printf("%s %d %d \n", filme[i].nume, filme[i].an, filme[i].premii);
}