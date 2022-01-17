#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct angajat{
    char nume[35];
    int salar;
    int bonus;//se pune pe 1 doar daca a primit bonus, altfel e 0
}angajat;

void swap(angajat *a1, angajat *a2)
{
    angajat temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void muta_la_inceput(angajat *array, int n)
{
    int i=0, j=n-1;
    while(i<j)
        {
            while(i<j && array[j].bonus == 0)
                j--;
            if(array[i].bonus == 0)
                swap(&array[i],&array[j]);
            i++;
        }
}

void sortare_invers_alfabetica(angajat *array, int n)
{
    for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
                {
                    if(array[i].bonus == 0)
                        if(array[j].salar < array[j-1].salar)
                            {
                                angajat temp = array[j-1];
                                array[j-1] = array[j];
                                array[j] = temp;
                            }
                }  
        }
}       

void sortare_dupa_salar(angajat *array, int st, int dr)
{
    int i = st, j = dr;
    angajat pivot, temp;
    for(int k=i;j<=j;k++)
        {
            if(array[k].bonus == 0)
                {
                    pivot = array[k];
                    break;
                }
        }
    do{
        while(array[i].bonus == 1 || (array[i].salar > pivot.salar)) i++; //face swap descrescator doar pentru cei cu campul bonus = 0
        while(array[j].bonus == 1 || (array[j].salar < pivot.salar)) j--;
        while(i <= j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
    }while(i <= j);
    if(st < j) sortare_dupa_salar(array, st, j);
    if(dr > i) sortare_dupa_salar(array, i, dr);
}

void citire(angajat *array, int n)
{
    for(int i=0;i<n;i++)
        {
            printf("Dati numele: \n");
            scanf("%s",array[i].nume);
            printf("Dati salariul: \n");
            scanf("%d",&array[i].salar);
            printf("Are sau nu bonus: \n");
            scanf("%d",&array[i].bonus);
        }
}

void afisare(angajat *array, int n)
{
    for(int i=0;i<n;i++)
        printf("%s %d %d \n",array[i].nume, array[i].salar, array[i].bonus);
    printf("\n");
}

int main()
{
    int nr;
    printf("Dati nr de pers: \n");
    scanf("%d",&nr);

    angajat *my_array = (angajat*)malloc(nr*sizeof(angajat));
    if(!my_array)
        {
            printf("Eroare la alocare!\n");
            exit(EXIT_FAILURE);
        }
    citire(my_array,nr);
    afisare(my_array,nr);
    printf("\nDupa Sortare\n");
    sortare_dupa_salar(my_array,0,nr-1);
    afisare(my_array,nr);
    free(my_array);
} 