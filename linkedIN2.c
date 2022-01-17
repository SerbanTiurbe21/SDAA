#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct conexiuni{
    char colegiDeEchipa[30][30];
    char persoaneResurseUmane[30][30];
    int ultim;
}conexiuni;

typedef struct persoana{
    int id;
    char nume[35];
    conexiuni conex[100];
}persoana;

typedef struct lista{
    persoana persons[100];
    struct lista *next;
}lista;

void insert_in_lista(lista **head_ref, int n)
{
    lista *new_node = (lista*)malloc(sizeof(lista));
    if(!new_node)
        {
            printf("Eroare!\n");
            exit(EXIT_FAILURE);
        }
    new_node->persons->conex->ultim=0;
    for(int i=0;i<n;i++)
        {
            scanf("Dati id-ul[%d] persoanei cu nunele[]");
            new_node->persons[i].id = 0;
        }
}