#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void insert(node **head_ref, int data)
{
    node *last = *head_ref;
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
        {
            printf("Eroare!");
            exit(EXIT_FAILURE);
        }
    new_node->data = data;
    new_node->next = NULL;

    if(*head_ref == NULL)
        {
            *head_ref = new_node;
            return;
        }
    while(last->next != NULL)
        last = last->next;

    last->next = new_node;

    return;
}

void printList(node *lista)
{
    while(lista != NULL)
        {
            printf("%d ",lista->data);
            lista = lista->next;
        }
    printf("\n");
}

void mijloc(node *lista)
{
    node *slow_ptr = lista;
    node *fast_ptr = lista;
    node *q = NULL;
    int d;

    if(lista != NULL)
        {
            while(fast_ptr != NULL && fast_ptr->next != NULL)
                {
                    q = slow_ptr;
                    fast_ptr = fast_ptr->next->next;
                    slow_ptr = slow_ptr->next;
                    //q->next = slow_ptr->next;
                    //d = slow_ptr->data;
                    //free(slow_ptr);
                }
            q->next = slow_ptr->next;
            free(slow_ptr);
        }
    //printf("%d ",d);
}

int main()
{
    node *lista = NULL;
    insert(&lista,10);
    insert(&lista,11);
    insert(&lista,12);
    insert(&lista,13);
    insert(&lista,14);
    printList(lista);
    mijloc(lista);
    printList(lista);
}