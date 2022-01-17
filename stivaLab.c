#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct membru{
    char nume[100];
}membru;

typedef struct stack{
    int top;
    membru membri[100];
}stack;

typedef struct proiect{
    int id;
    int dimensiuneMaxEchipa;
    stack echipa;
}proiect;

typedef struct lista{
    proiect projects[100];
    int ultim;
}lista;

void adauga_proiect(lista *head_ref, proiect pr)
{ 
    head_ref->projects[head_ref->ultim] = pr;
    head_ref->ultim++;
}

void adauga_membru_in_echipa(stack *stiva, membru member)
{
    if(stiva->top == 0)
        {
            printf("Stiva este plina!\n");
            return;
        }
    else
        {
            stiva->top = stiva->top-1;
            stiva->membri[stiva->top-1] = member;
        }
}

bool stivid(stack s)
{
    bool stivid_result;
    if(s.top == 100)
        stivid_result=true;
    else stivid_result=false;
    return stivid_result;
}

void detasare_membru_din_echipa(stack *stiva, membru *member)
{
    if(stivid(*stiva))
        {
            printf("Stiva este goala!\n");
            return;
        }
    else
        {
            *member = stiva->membri[stiva->top];
            stiva->top = stiva->top+1;
        }
}

void afisare_lista(lista head_ref)
{
    for(int i=0;i<head_ref.ultim;i++)
        {
            printf("Proiect[%d]: \n",i);
            printf("ID: \n",head_ref.projects[i].id);
            printf("DIMENSIUNE MAXIMA ECHIPA: \n",head_ref.projects[i].dimensiuneMaxEchipa);
            printf("Echipa: \n");
            for(int j=0;j<head_ref.projects[i].echipa.top;j++)
                printf("%s ",head_ref.projects[i].echipa.membri[j].nume);
            printf("\n");
        }
}

