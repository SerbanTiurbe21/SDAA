#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nume[25];
    char telefon[10];
    int an;
    int venit;
}agenda;

void afisare(agenda array[], int n)
{
    for(int i=0;i<n;i++)
        printf("%s %s %d %d \n",array[i].nume, array[i].telefon, array[i].an, array[i].venit);
}

void citire(agenda array[], int n)
{
    for(int i=0;i<n;i++)
        {
            printf("Dati numele:\n");
            scanf("%s",&array[i].nume);
            printf("Dati telefonul:\n");
            scanf("%s",&array[i].telefon);
            printf("Dati anul:\n");
            scanf("%d",&array[i].an);
            printf("Dati venitul:\n");
            scanf("%d",&array[i].venit);
        }
}

void swap(agenda *a1, agenda *a2)
{
    agenda temp;
    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void afiseazaPrimeleMaiMici1000(agenda *array, int n)
{
    int minim = array[0].venit;
    for(int i=0;i<n;i++)
        if(array[i].venit < minim)
            minim = array[i].venit;
    printf("%d",minim);
}

void dosmth(agenda array[], int n)
{
    int countMaiMicDecat1000 = 0;
    int i, j=n-1;
    while(i<j)
        {
            if(array[i].venit < 1000)
                countMaiMicDecat1000++;
            if(countMaiMicDecat1000 >= 2)
                break;
            while(i<j && array[i].venit >= 1000 && )
                i++;
            if(array[j].venit >= 1000)
                swap(&array[j],&array[i]);
            j--;
        }
}

int main()
{
    int n;
    printf("Dati numarul de persoane:\n");
    scanf("%d",&n);

    /*
    agenda Serban;
    strcpy(Serban.nume,"Serbanel");
    strcpy(Serban.telefon,"Samsung");
    Serban.an = 2001;
    Serban.venit = 1000;

    agenda Dusan;
    strcpy(Dusan.nume,"Dushanell");
    strcpy(Dusan.telefon,"S21");
    Dusan.an = 2001;
    Dusan.venit = 100;

    agenda Alin;
    strcpy(Alin.nume,"Alinel");
    strcpy(Alin.telefon,"S20");
    Alin.an = 2000;
    Alin.venit = 90;

    agenda Catalin;
    strcpy(Catalin.nume,"Cata");
    strcpy(Catalin.telefon,"Iphone");
    Catalin.an = 1997;
    Catalin.venit = 1000;

    agenda agendaa[] = {Serban, Dusan, Alin, Catalin};
    int n = sizeof(agendaa)/sizeof(agendaa[0]);
    */

    agenda agendaa[100];
    citire(agendaa,n);
    afisare(agendaa,n);
    printf("--- DUPA ---\n");
    dosmth(agendaa,n);
    afisare(agendaa,n);
}