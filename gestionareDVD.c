#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned boolean;

typedef struct film{
    char titlu[35];
    int anAparitie;
    int durata;
    int ultim1;
}film;

typedef struct lista{
    int an;
    film filme[100];
    int ultim;
}lista;

void insereaza_in_lista(lista *head_ref, int n)
{
    int year;
    printf("Dati anul: \n");
    scanf("%d",&year);
    head_ref->an = year;
    head_ref->ultim = 0;
    for(int i=0;i<n;i++)
        {
            int year1, duration1;
            char title1[35];
            printf("Dati titlul filmului - pt anul scanat[%d]: \n",year);
            scanf("%s",&title1);
            // fgets(title1,34,stdin);
            // title1[strcspn(title1,"\n")] = '\0';

            printf("Dati anul filmului: \n");
            scanf("%d",&year1);

            printf("Dati durata filmului: \n");
            scanf("%d",&duration1);

            if(year1 == head_ref->an)
                {
                    head_ref->filme[i].anAparitie = year;
                    strcpy(head_ref->filme[i].titlu,title1);
                    head_ref->filme[i].durata = duration1;
                    head_ref->filme->ultim1++;
                }
            head_ref->ultim++;
        }
}

void adaugare_an(lista *head_ref, int year)
{
    
}

void afiseaza_lista(lista head_ref)
{
    for(int i=0;i<head_ref.ultim;i++)
        printf("%s %d %d \n",head_ref.filme[i].titlu,head_ref.filme[i].anAparitie,head_ref.filme[i].durata);
    printf("\n");
}

int main()
{

    lista my_list;
    film my_movie = {"Titanic",1970,30};
    
    insereaza_in_lista(&my_list,1);
    insereaza_in_lista(&my_list,1);
    afiseaza_lista(my_list);
}