#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char culori[][20] = {"alb","galben","rosu","verde","albastru","negru"};

void draw(int culoare1, int culoare2, int culoare3)
{
    if(culoare1 > 5 || culoare2 > 5 || culoare3 > 5)
        return;
    if(culoare1 != culoare2 && culoare1 != culoare3 && culoare2 != culoare3)
        printf("%s %s %s \n",culori[culoare1],culori[culoare2],culori[culoare3]);
    if(culoare3 <= 5)
        {
            if(culoare3 == 5) draw(culoare1+1,culoare2,0);
            if(culoare3 < 5) draw(culoare1,culoare2,culoare3+1);
        }
}

int main()
{
    draw(0,3,0);
    draw(0,1,0);
}