#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 3
#define M 3

int matrice[N][M];

void draw_diagonala(int i, int j, int culoare)
{
    if(i > N || j > M)
        return;
    culoare = culoare % 4; //asta daca ajunge culoarea prea mare

    if(j<M)
        {
            
        }
}