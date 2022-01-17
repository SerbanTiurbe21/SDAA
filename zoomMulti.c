#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
    char nume[25];
}student;

typedef struct conferinta{
    int id;
    char parola[25];
    int ultim;
    student studneti[100];
    struct conferinta *next;
}conferinta;

void adauga_in_lista(conferinta **head_ref, int idd, char pass[],int n)
{
    conferinta *new_node = (conferinta*)malloc(sizeof(conferinta));
    if(!new_node)
        {
            printf("Eroare la alocare!\n");
            exit(EXIT_FAILURE);
        }
    new_node->ultim=0;
    new_node->id = idd;
    strcpy(new_node->parola,pass);
    for(int i=0;i<n;i++)
        {
            printf("Dati numele studentului[%d] din coferinta cu id-ul [%d]: \n",i,new_node->id);
            scanf("%s", new_node->studneti[i].nume);
            new_node->studneti[new_node->ultim++];
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

void afisare(conferinta *head_ref)
{
    conferinta *p = head_ref;
    while(p != NULL)
        {
            printf("ID: %d\n",p->id);
            printf("PAROLA: %s\n",p->parola);
            for(int i=0;i<p->ultim;i++)
                printf("NUME student[%d]: %s\n",i,p->studneti[i].nume);
            printf("\n");
            p = p->next;
        }
}

void remove_din_lista(conferinta **head_ref, char litera)
{
    conferinta *p = *head_ref;
    while(p != NULL)
        {
            for(int i=0;i<p->ultim;i++)
                {
                    if(litera == p->studneti[i].nume[0])
                        {
                            for(int j = i;j<p->ultim-1;j++)
                                p->studneti[j] = p->studneti[j+1];
                            i--;
                            p->studneti[p->ultim--];
                        }
                }
            p = p->next;
        }
}

int main()
{
    conferinta *my_conf = NULL;
    adauga_in_lista(&my_conf,10,"alin",1);
    adauga_in_lista(&my_conf,20,"serban",1);
    afisare(my_conf);
    printf("\nDUPA\n");
    remove_din_lista(&my_conf,'A');
    afisare(my_conf);
    free(my_conf);
}