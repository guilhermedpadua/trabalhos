#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int gols_1, gols_2;
    scanf("%d", &gols_1);
    scanf("%d", &gols_2);
    if(gols_1 > gols_2)
        printf("O time 1 venceu.\n");
    else if(gols_2 > gols_1)
        printf("O time 2 venceu.\n");
    else
        printf("Empate.\n");

    return 0;
}
