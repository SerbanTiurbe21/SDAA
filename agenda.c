#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char nume[25];
    char telefon[10];
    int an;
    int venit;
}agenda;

void swap(agenda *a1, agenda *a2)
{
    agenda temp;
    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void muta_la_sfarsit(agenda *array, int n)
{
    int i = 0, j = n - 1, count = 0;
    while(i<j)
        {
            if(array[i].venit < 1000)
                count++;
            if(count > 2)
                break;
            while(i<j && array[j].venit < 1000)
                j--;
            if(array[i].venit < 1000)
                {
                    agenda temp;
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            i++;
        }
}

void q_sort(agenda *array, int st, int dr)
{
    int i = st, j = dr;
    agenda pivot, temp;
    for(int k = i;k<=j;k++)
            if((((2022-array[k].an)<=40) && ((2022-array[k].an)>=30)))
                {
                    pivot = array[k]; 
                    break;
                }
    do{
        while((strcmp(array[i].nume,pivot.nume)<0) || ((2022-array[i].an)>40 || (2022-array[i].an)<30)) i++;
        while((strcmp(array[j].nume,pivot.nume)>0) || ((2022-array[j].an)>40 || (2022-array[j].an)<30)) j--;
        if(i <= j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
    }while(i <= j);
    if(st < j) q_sort(array,st,j);
    if(dr > i) q_sort(array,i,dr);
}

//varianta lu tudor
void muta_persoane(agenda *array, int n)
{
    int c=0,j;
    for(int i=0;i<n;i++)
        {
            if(array[i].venit < 1000)
                {
                    agenda temp = array[i];
                    for(j = i;j<n;j++)
                        array[j] = array[j+1];
                    array[n-1] = temp;
                    c++;
                }
            if(c==2) return;
        }
}

void citire(agenda array[], int n)
{
    for(int i=0;i<n;i++)
        {
            printf("Dati numele: \n");
            scanf("%s",&array[i].nume);
            printf("Dati telefonul: \n");
            scanf("%s",array[i].telefon);
            printf("Dati anul: \n");
            scanf("%d",&array[i].an);
            printf("Dati venitul: \n");
            scanf("%d",&array[i].venit);
        }
}

void afisare(agenda array[], int n)
{
    for(int i=0;i<n;i++)
        {
            printf("%s %s %d %d \n",array[i].nume, array[i].telefon, array[i].an, array[i].venit);
        }
}

int main()
{
    int n;
    agenda *my_agenda = (agenda*)malloc(n*sizeof(agenda));
    if(!my_agenda)
        {
            printf("Eroare la aloacarea memoriei!\n");
            exit(EXIT_FAILURE);
        }
    
    printf("Dati numarul de oameni in agenda: \n");
    scanf("%d",&n);

    citire(my_agenda,n);
    afisare(my_agenda,n);
    
    printf("\n Dupa Sortare: \n");
    //q_sort(my_agenda,0,n-1);
    muta_la_sfarsit(my_agenda,n);
    afisare(my_agenda,n);
}