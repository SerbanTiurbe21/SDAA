#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
    char nume[15];
    char email[20];
    int ultim;
}student;

typedef struct conferinta{
    int ID;
    char data[15];
    char numeGazda[15];
    student students[100];
    struct conferinta *next;
}conferinta;

void adauga_in_lista(conferinta **head_ref, int id, char date[], char name[], int n)
{
    conferinta *new_node = (conferinta*)malloc(sizeof(conferinta));
    if(!new_node)
        {
            printf("Eroare!");
            exit(EXIT_FAILURE);
        }
    new_node->ID = id;
    strcpy(new_node->data,date);
    strcpy(new_node->numeGazda,name);
    new_node->students->ultim=0;
    for(int i=0;i<n;i++)
        {
            char name1[15], email1[20];
            printf("Dati numele participantului[%d] - al gazdei[%s] \n",i,new_node->numeGazda);
            fgets(name1,14,stdin);
            name1[strcspn(name1,"\n")] = '\0';
            strcpy(new_node->students[i].nume,name1);
            printf("Dati emailul participantului[%d] - al persoanei[%s] \n",i,new_node->numeGazda);
            fgets(email1,19,stdin);
            email1[strcspn(email1,"\n")] = '\0';
            strcpy(new_node->students[i].email,email1);
            new_node->students->ultim++;
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

void afiseaza_lista(conferinta *head_ref)
{
    conferinta *p = head_ref;
    while(p != NULL)
        {
            printf("ID:%d \n",p->ID);
            printf("DATA:%s \n",p->data);
            printf("NUME GAZDA:%s \n",p->numeGazda);
            for(int i=0;i<p->students->ultim;i++)
                printf("NUME PART:%s\t EMAIL PART:%s \n",p->students[i].nume, p->students[i].email);
            printf("\n");
            p = p->next;
        }
}

void modificare_email_student(conferinta **head_ref, int id_conferinta, char nume_student[], char new_email[])
{
    conferinta *p = *head_ref;
    while(p != NULL)
        {
            if(p->ID != id_conferinta)
                {
                    printf("\nNOT FOUND!\n");
                    return;
                }
            for(int i=0;i<p->students->ultim;i++)
                if(strcmp(p->students[i].nume,nume_student) == 0)
                    strcpy(p->students[i].email,new_email);
            p = p->next;
        }
}

int main()
{
    conferinta *my_conferinta = NULL;
    adauga_in_lista(&my_conferinta,11,"21.10.2001","Tiurbe Serban",1);
    afiseaza_lista(my_conferinta);
    printf("\n DUPA \n");
    modificare_email_student(&my_conferinta,11,"Barna Alin","alinas@yahoo.com");
    afiseaza_lista(my_conferinta);
}