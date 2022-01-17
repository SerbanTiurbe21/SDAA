#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pasager{
    long int cod;
    int ultim;
}pasager;

typedef struct zbor{
    char nume[10];
    pasager pasageri[100];
    struct zbor *next;
}zbor;

void adauga_in_lista(zbor **head_ref, char nume[], int n)
{
    zbor *new_node = (zbor*)malloc(sizeof(zbor));
    if(!new_node)
        {
            printf("Eroare!\n");
            exit(EXIT_FAILURE);
        }
    strcpy(new_node->nume,nume);
    new_node->pasageri->ultim = 0;
    for(int i=0;i<n;i++)
        {
            long int code;
            printf("Dati codul pasagerului[%d] - din zborul cu numele[%s]: \n",i,new_node->nume);
            scanf("%li",&code);
            new_node->pasageri[i].cod = code;
            new_node->pasageri->ultim++;
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

void afiseaza_lista(zbor *head_ref)
{
    zbor *p = head_ref;
    while(p != NULL)
        {
            printf("%s ",p->nume);
            for(int i=0;i<p->pasageri->ultim;i++)
                {
                    printf("%li ",p->pasageri[i].cod);
                }
            printf("\n");
            p = p->next;
        }
}

void remove_pasager(zbor **head_ref, long int cod)
{
    zbor *p = *head_ref;
    while(p != NULL)
        {
            for(int i=0;i<p->pasageri->ultim;i++)
                {
                    if(p->pasageri[i].cod == cod)
                    //printf("%d lol",i);
                        {
                            for(int j=i;j<p->pasageri->ultim-1;j++)
                                p->pasageri[j] = p->pasageri[j+1];
                            //i--;
                            p->pasageri->ultim--;
                        }
                }
            p = p->next;
        }
}

int main()
{
    zbor *my_zbor = NULL;
    adauga_in_lista(&my_zbor,"AVION",3);
    afiseaza_lista(my_zbor);
    printf("\n DUPA \n");
    remove_pasager(&my_zbor,2);
    afiseaza_lista(my_zbor);
}