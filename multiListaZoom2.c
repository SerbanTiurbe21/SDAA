#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct student{
    char nume[25];
    int ultim;
}student;

typedef struct conferinta{
    int id;
    char parola[20];
    student students[100];
}conferinta;

typedef struct lista{
    conferinta conferinte[100];
    struct lista *next;
}lista;

void adauga_in_lista(lista **head_ref, int n,int m)
{
    lista *new_node = (lista*)malloc(sizeof(lista));
    if(!new_node)
        {
            printf("Eroare la alocare!\n");
            exit(EXIT_FAILURE);
        }
    //new_node->conferinte->students->ultim = 0;
    for(int i=0;i<n;i++)
        {
            new_node->conferinte[i].students->ultim = 0;
            int id;
            char pass[20], name2[25];
            printf("Dati id-ul conferintei[%d]: \n",i);
            scanf("%d",&id);
            new_node->conferinte[i].id = id;
            printf("Dati parola conferintei[%d]: \n",i);
            scanf("%s", pass);
            strcpy(new_node->conferinte[i].parola,pass);
            for(int j=0;j<m;j++)
                {
                    new_node->conferinte[i].students[j].ultim = 0;
                    printf("Dati numele studentului[%d]: \n",j);
                    scanf("%s",&name2);
                    strcpy(new_node->conferinte[i].students[j].nume,name2);
                    new_node->conferinte[i].students[j].ultim++;
                }
            new_node->conferinte[i].students->ultim++;
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

void afiseaza_lista(lista *head_ref)
{
    lista *p = head_ref;
    while(p != NULL)
        {
            for(int i=0;i<p->conferinte->students->ultim;i++)
                {
                    printf("ID conferinta[%d]: %d \n",i,p->conferinte[i].id);
                    printf("Parola conferinta[%d]: %s\n",i,p->conferinte[i].parola);
                    for(int j=0;j<p->conferinte[i].students->ultim;j++)
                        {
                            printf("Nume student[%d]: %s \n",i,p->conferinte[i].students[j].nume);
                        }
                    printf("\n");
                }
            p = p->next;
        }
}

int main()
{
    lista *my_list = NULL;
    adauga_in_lista(&my_list,1,1);
    afiseaza_lista(my_list);
}