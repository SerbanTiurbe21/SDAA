#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct palet{
    int cod;
}palet;

typedef struct depozit{
    char nume[20];
    int ultim;
    palet paleti[100];
    struct depozit *next;
}depozit;

int binary_search(int jos, int sus, palet *p, int id)
{
    if(sus > jos)
        return -1;
    int mijloc = (jos+sus)/2;
    if(p[mijloc].cod == id)
        return mijloc;
    if(p[mijloc].cod < id)
        binary_search(mijloc+1, sus, p, id);
    else
        binary_search(jos,mijloc-1,p,id);
}

/*
int cautare(palet array[], int cod)
{
    for(int i=0;i<array->cod;i++)
        if(array[i].cod == cod)
            return i;
    return -1;//daca nu l-a gasit
}
*/

void remove_palet(depozit **head_ref, int cod)
{
    depozit *p = *head_ref;
    while(p != NULL)
        {
            for(int i=0;i<p->ultim;i++)
                {
                    if(p->paleti[i].cod == cod)
                        {
                            for(int j=i;j<p->ultim-1;j++)
                                p->paleti[j] = p->paleti[j+1];
                            i--;
                            p->paleti[p->ultim--];
                        }
                }
            p = p->next;
        }
}

void insert(depozit **head_ref, char nume[], int n)
{
    depozit *new_node = (depozit*)malloc(sizeof(depozit));
    if(!new_node)
        {
            printf("Eroare la alocare!\n");
            exit(EXIT_FAILURE);
        }
    //new_node->paleti->ultim = 0;
    strcpy(new_node->nume,nume);
    new_node->ultim = 0;
    for(int i=0;i<n;i++)
        {
            int cod;
            printf("Dati codul - pt paletul[%d] - din depozitul[%s]: \n",i,new_node->nume);
            scanf("%d",&cod);
            new_node->paleti[i].cod = cod;
            new_node->paleti[new_node->ultim++];
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

void afisare(depozit *head_ref)
{
    depozit *p = head_ref;
    while(p != NULL)
        {
            printf("%s ",p->nume);
            for(int i=0;i<p->ultim;i++)
                printf("%d ",p->paleti[i].cod);
            printf("\n");
            p = p->next;
        }
}

int main()
{
    depozit *lista = NULL;
    insert(&lista,"DEP0ZIT-2",2);
    //insert(&lista,"DEP0ZIT-1",3);
    afisare(lista);

    //printf("%d ",cautare(lista->paleti,101));
    printf("\n AFTER \n");
    remove_palet(&lista,100);
    afisare(lista);
    
}