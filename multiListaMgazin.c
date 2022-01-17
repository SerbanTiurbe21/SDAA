#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct produs{
    long int codNumeric;
    int stoc;
    int ultim;
}produs;

typedef struct magazin{
    char nume[15];
    produs products[100];
    struct magazin *next;
}magazin;

void adauga_in_lista(magazin **head_ref, char nume[], int n, int m)
{
    magazin *new_node = (magazin*)malloc(sizeof(magazin));
    if(!new_node)
        {
            printf("Eroare la alocarea memoriei!\n");
            exit(EXIT_FAILURE);
        }
    strcpy(new_node->nume,nume);
    new_node->products->ultim = 0;
    int tineMinte;
    for(int i=0;i<n;i++)
        {
            long int code;
            //int stock;
            printf("Dati codul[%d] - produsului din magazinul[%s]: \n",i,new_node->nume);
            scanf("%ld",&code);
            new_node->products[i].codNumeric = code;
            //printf("Dati stocul[%d] - produsului din magazinul[%s]: \n",i,new_node->nume);
            //scanf("%d",&stock);
            //new_node->products->stoc = stock;
            new_node->products->ultim++;
        }
        
    for(int i=0;i<m;i++)
        {
            int stock;
            printf("Dati stocul[%d] - produsului din magazinul[%s]: \n",i,new_node->nume);
            scanf("%d",&stock);
            new_node->products[i].stoc = stock;
            tineMinte++;
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

void afiseaza_lista(magazin *head_ref)
{
    magazin *p = head_ref;
    while(p != NULL)
        {
            printf("%s ",p->nume);
            for(int i=0;i<p->products->ultim;i++)
                printf("%ld %d ",p->products[i].codNumeric, p->products[i].stoc);
            p = p->next;
        }
}

void modificare_stoc(magazin **head_ref,char nume_magazin[], int cod_produs, int stoc_nou)
{
    magazin *p = *head_ref;
    int *pointer;
    while(p != NULL)
        {
            if(strcmp(p->nume,nume_magazin) != 0)
                {
                    printf("\nNot found!\n");
                    return;
                }
            for(int i=0;i<p->products->ultim;i++)
                if(p->products[i].codNumeric == cod_produs)
                    {
                        pointer = &p->products[i].stoc;
                        *pointer = stoc_nou;
                    }
            p = p->next;
        }
}

int main()
{
    magazin *my_mag = NULL;
    adauga_in_lista(&my_mag,"MIRUS",1,1);
    afiseaza_lista(my_mag);

    modificare_stoc(&my_mag,"MIRUS",1,13);
    printf("\n DUPA \n");
    afiseaza_lista(my_mag);
    free(my_mag);
}