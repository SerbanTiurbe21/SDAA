#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct recomandare{
    char text[100];
    //int ultim;
}recomandare;

typedef struct persoana{
    int ID;
    char nume[35];
    char ocupatie[35];
    recomandare recomandari[100];
    int ultim;
    struct persoana *next;
}persoana;

void adauga(persoana **head_ref, int id, char nume[], char ocupatie[], int n)
{
    persoana *new_node = (persoana*)malloc(sizeof(persoana));
    if(!new_node)
        {
            printf("Eroare!\n");
            exit(EXIT_FAILURE);
        }
    new_node->ID = id;
    strcpy(new_node->nume,nume);
    strcpy(new_node->ocupatie,ocupatie);
    new_node->ultim = 0;
    for(int i=0;i<n;i++)
        {
            char string[100];
            printf("Dati textul - pt recomandarea[%d] - a persoanei[%s] \n",i,new_node->nume);
            fgets(string,99,stdin);
            string[strcspn(string,"\n")] = '\0';
            strcpy(new_node->recomandari[i].text,string);
            new_node->recomandari[new_node->ultim++];
        }
    if(*head_ref == NULL)
        {
            *head_ref = new_node;
            new_node->next = NULL;
        }
    else
        {
            new_node->next = *head_ref;
            *head_ref = new_node;
        }
}

void display(persoana *head_ref)
{
    persoana *p = head_ref;
    while(p != NULL)
        {
            printf("%d ",p->ID);
            printf("%s ",p->nume);
            printf("%s ",p->ocupatie);
            for(int i=0;i<p->ultim;i++)
                printf("%s \t",p->recomandari[i].text);
            printf("\n");
            p = p->next;
        }
}

void alta_cautare(persoana *head_ref)
{
    persoana *p = head_ref;
    while(p != NULL)
        {
            if(strcmp(p->ocupatie,"profesionist IT") == 0 && p->ultim > 1)
                printf("%d %s %s",p->ID,p->nume,p->ocupatie);
            printf("\n");
            p = p->next;
        }
}

int main()
{
    persoana *lol;
    persoana *my_person = NULL;
    adauga(&my_person,10,"Serban","profesionist IT",1);
    adauga(&my_person,10,"Dusan","profesionist IT",2);
    display(my_person);
    printf("Dupa cautare: \n");
    alta_cautare(my_person);
}
