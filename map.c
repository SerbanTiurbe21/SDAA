#include <stdio.h>

#define N 3
#define M 3

int harta[N][M];


int verifica_diagonala(int i, int j);

void draw_diagonala(int i, int j, int culoare)
{
	if(i > N || j > M) return;

	culoare = culoare % 4; // in caz ca ajunge culoarea prea mare

	if(j < M)
	{
		do{
			harta[i][j] = culoare + 1;
			culoare ++;
			culoare = culoare % 4;
		}while(!verifica_diagonala(i,j));
		draw_diagonala(i,j+1,culoare);
	}
	if(j == M) draw_diagonala(i + 1, 0,culoare);
}

int verifica_diagonala(int i, int j)
{
	int increment_i[4] = {1,1,-1,-1};
    int increment_j[4] = {-1,1,1,-1};

    int index, new_i, new_j;

    for(index = 0;index < 4; index++)
    {
        new_i = i + increment_i[index];
        new_j = j + increment_j[index];

        if(new_i >= 0 && new_i < N && new_j >= 0 && new_j < M && harta[new_i][new_j] != 0)
        {
            if(harta[i][j] == harta[new_i][new_j]) return 0;
        }
    }

    return 1;
}

void afisare_matrice()
{
    int i,j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            printf("%d\t", harta[i][j]);
        }
        printf("\n");
    }
}

int main()
{
	draw_diagonala(0,0,0);
	afisare_matrice();
}