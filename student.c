#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct student{
    char nume[35];
    int varsta;
    int premii;
}student;

void citire(student *array, int n)
{
    for(int i=0;i<n;i++)
        {
            printf("Dati numele: \n");
            scanf("%s",array[i].nume);
            printf("Dati varsta: \n");
            scanf("%d",&array[i].varsta);
            printf("Daca are sau nu premiu: \n");
            scanf("%d",&array[i].premii);
        }
}

void afisare(student *array, int n)
{
    for(int i=0;i<n;i++)
        printf("%s %d %d \n",array[i].nume, array[i].varsta, array[i].premii);
    printf("\n");
}

void swap(student *s1, student *s2)
{
    student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void muta_la_sfarsit(student *array, int n)
{
    int i=0, j = n - 1;
    while(i<j)
        {
            while(i<j && array[j].premii == 0)
                j--;
            if(array[i].premii == 0)
                swap(&array[i],&array[j]);
            i++;
        }
}

void sortare_invers_alfabetica(student *array, int st, int dr)
{
    int i = st, j = dr;
    student pivot, temp;
    for(int k=i;k<=j;k++)
        {
           if(array[k].premii == 1)
            {
                pivot = array[k];
                break;
            } 
        }
    do{
        while(array[i].premii == 0 || (strcmp(array[i].nume,pivot.nume) > 0)) i++;
        while(array[j].premii == 0 || (strcmp(array[j].nume,pivot.nume) < 0)) j--;
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
    int n;
    printf("Dati nr de elemente: \n");
    scanf("%d",&n);

    student *my_student = (student*)malloc(n*sizeof(student));
    if(!my_student)
        {
            printf("Eroare la alocare!\n");
            exit(EXIT_FAILURE);
        }
    citire(my_student,n);
    afisare(my_student,n);
    printf("\n DUPA\n");
    //muta_la_sfarsit(my_student,n);
    sortare_invers_alfabetica(my_student,0,n-1);
    afisare(my_student,n);
}