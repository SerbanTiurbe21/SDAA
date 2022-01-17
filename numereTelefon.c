#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int sol[11];

int cifraPara(int nr)
{
    return (nr % 2 == 0);
}

void afisare(int k)
{
    for(int i=0;i<=k;i++)
        printf("%d ", sol[i]);
    printf("\n");
}

bool ok(int k)
{
    if(k==0 && sol[k] == 0)
        return true;
    else
        return false;
    if(k==1 && sol[k] == 7)
        return true;
    else
        return false;
    if(k==2 && sol[k] == 9)
        return true;
    else
        return false;
    if(k==3 && sol[k] == 9)
        return true;
    else
        return false;
    if(k==9 && sol[k] == 0)
        return true;
    else
        return false;
    if(k > 4 && k <= 10)
        {
            if(cifraPara(sol[k-1]) && cifraPara(sol[k]))
                return false;
        }
    return true;
}

int solutie(int k)
{
    return (k == 9);
}

void back(int k)
{
    for(int i=0;i<10;i++)
        {
            sol[k] = i;
            if(ok(k))
                {
                    if(solutie(k))
                        afisare(k);
                    else
                        back(k+1);
                }
        }
}

int main()
{
    back(0);
}

/*
#include <stdio.h>
#include <stdlib.h>

int sol[100];

void afisare(int k) {
	for (int i = 0; i <= k+1; i++)
		printf("%d ", sol[i]);
	printf("\n");
}

int solutie(int k) {
	return (k == 8);
}

int valid(int k) {
	if (k == 8 && sol[k] % 2 == 0)
		return 0;
	if (sol[k] % 2 == 0 && sol[k - 1] % 2 == 0)
		return 0;
	return 1;
}

void back(int k) {
	sol[0] = 0;
	sol[1] = 7;
	sol[2] = 9;
	sol[3] = 9;
	sol[9] = 0;

	for (int i = 0; i < 10; i++) {
		sol[k] = i;
		if (valid(k))
			if (solutie(k))
				afisare(k);
			else
				back(k + 1);
	}
}

int main() {
	back(4);
	return 0;
}
*/