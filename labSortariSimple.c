#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct student{
    int nota;
    char gen;
    char numePrenume[20];
}student;

void insertie(student a[],int n)
{
    int i,j;
    for( i=n-2;i>=0;i--)
        {
            a[n]=a[i];
            j=i+1;
            while(strcmp(a[j].numePrenume,a[n].numePrenume) < 0) 
                {
                    a[j-1]=a[j]; 
                    j++;                       
                }
            a[j-1]=a[n];
        }
}

int findIndex(student a[], int n, char *nume)
{
    for(int i=0;i<n;i++)
        if(strcmp(a[i].numePrenume,nume) == 0)
            return i;
    return -1;//inseamna not found
}

void citire(student a[], int n)
{
    for(int i=0;i<n;i++)
        {
            //printf("Dati nota: ");
            scanf("%d",&a[i].nota);
            //printf("Dati genul: ");
            scanf("%s",&a[i].gen);
            getchar();
            //printf("Dati numele: ");
            fgets(a[i].numePrenume,20,stdin);
            a[i].numePrenume[strcspn(a[i].numePrenume,"\n")] = '\0';
        }
}

void afisare(student a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d %c %s \n",a[i].nota, a[i].gen, a[i].numePrenume);
}

void swap(student *s1, student *s2)
{
    student temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void sortare2(student studenti[], int n)
{
    for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
                {
                    if((studenti[j-1].nota >=5 && studenti[j].nota < 5) || ((studenti[j-1].nota >= 5 && studenti[j].nota >= 5) || (studenti[j-1].nota < 5 && studenti[j].nota < 5) && studenti[j-1].gen == 'M' && studenti[j].numePrenume == 'F') || 
                    ((studenti[j-1].nota > 5 && studenti[j].nota > 5 || studenti[j-1].nota >=5 && studenti[j].nota >=5) && studenti[j-1].gen == studenti[j].gen && strcmp(studenti[j-1].numePrenume,studenti[j].numePrenume) > 0))
                            {
                                swap(&studenti[j-1],&studenti[j]);
                            }
                }
        }
}

int main()
{
    student studenti[100], studentiAuxiliar[100];
    
    int n;
    char nume1[25], nume2[25];

    printf("Dati numarul de studenti: \n");
    scanf("%d",&n);

    citire(studenti,n);
    for(int i=0;i<n;i++)
        studentiAuxiliar[i] = studenti[i];
    
    insertie(studenti,n);
    afisare(studenti,n);

    printf("Dati numele: \n");
    fgets(nume1,24,stdin);
    nume1[strcspn(nume1,"\n")] = '\0';
    printf("Indexul este: %d",findIndex(studenti,n,nume1));

    for(int i=0;i<n;i++)
        studenti[i] = studentiAuxiliar[i];
    sortare2(studenti,n);

    printf("Dati numele: \n");
    fgets(nume2,24,stdin);
    nume2[strcspn(nume2,"\n")] = '\0';
    printf("Indexul este: %d",findIndex(studenti,n,nume2));

    return 0;
}