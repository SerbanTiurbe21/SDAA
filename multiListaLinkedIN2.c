#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct conexiune{
    char nume[35];
}conexiune;

typedef struct persoana{
    int id;
    char ocupatie[35];
    char nume[35];
    conexiune conexiuni[100];
    int ultim;
    struct persoana *next;
}persoana;

void afisare(persoana *head_ref)
{
    persoana *p = head_ref;
    while(p != NULL)
        {
            printf("ID: %d\n",p->id);
            printf("OCUPATIE: %s\n",p->ocupatie);
            printf("NUME: %s\n",p->nume);
            for(int i=0;i<p->ultim;i++)
                printf("Nume recomandare: %s\n",p->conexiuni[i].nume);
            printf("\n");
            p = p->next;
        }
}

void adauga_in_lista_secundara(persoana *pers, conexiune con)
{
    pers->conexiuni[pers->ultim] = con;
} 

void insert_lista_mare(persoana **head_ref, int id, char occ[], char name[])
{
    persoana *new_node = (persoana*)malloc(sizeof(persoana));
    if(!new_node)
        {
            printf("Eroare!\n");
            exit(EXIT_FAILURE);
        }
    new_node->ultim = 0;
    new_node->id = id;
    strcpy(new_node->ocupatie,occ);
    strcpy(new_node->nume,name);
    /*
    for(int i=0;i<n;i++)
        {
            printf("Dati numele[%d] al conexiunii persoanei[%s]: \n",i,new_node->nume);
            scanf("%s",new_node->conexiuni[i].nume);
            new_node->conexiuni[new_node->ultim++];
    */
    if(*head_ref == NULL)
        {
            new_node->next = NULL;
            *head_ref = new_node;
        }
    else
        {
            new_node->next = *head_ref;
            *head_ref = new_node;
        }
}

void insert_lista_mica(persoana *head_ref, conexiune conn, int id1)
{
    persoana *p = head_ref;
    while(p != NULL)
        {
            if(p->id == id1)
                {
                    p->conexiuni[p->ultim++] = conn;
                }
            p = p->next;
        }
}

int main()
{
    persoana *my_person = NULL;
    conexiune con = {"Serban"};
    insert_lista_mare(&my_person,10,"fotbalist","gabi");
    insert_lista_mare(&my_person,11,"sofer","alin");
    insert_lista_mica(my_person,con,10);
    afisare(my_person);
}