#include <stdio.h>
#include <stdlib.h>
int main()
{
    char cadeia[3][100];
    int azul = 0, preto = 0, vermelho = 0;
    int i, condicao1 = 0, condicao2 = 0, condicao3 = 0;
    for(i = 0; i < 3; i++){
        scanf("%s", cadeia[i]);
        fflush(stdin);
    }

    if(strcmp(cadeia[0], "azul") == 0 && strcmp(cadeia[1], "preto") == 0)
        condicao1 = 1;
    if(strcmp(cadeia[0], "azul") == 0 && strcmp(cadeia[1], "vermelho") == 0)
        condicao1 = 1;
    if(strcmp(cadeia[0], "preto") == 0 && strcmp(cadeia[1], "vermelho") == 0)
        condicao1 = 1;
    if(strcmp(cadeia[0], "preto") == 0 && strcmp(cadeia[1], "azul") == 0)
        condicao1 = 1;

    if(strcmp(cadeia[0], "azul") == 0 && strcmp(cadeia[2], "preto") == 0)
        condicao2 = 1;
    if(strcmp(cadeia[0], "azul") == 0 && strcmp(cadeia[2], "vermelho") == 0)
        condicao2 = 1;
    if(strcmp(cadeia[0], "preto") == 0 && strcmp(cadeia[2], "vermelho") == 0)
        condicao2 = 1;
    if(strcmp(cadeia[0], "preto") == 0 && strcmp(cadeia[2], "azul") == 0)
        condicao2 = 1;

    if(strcmp(cadeia[1], "azul") == 0 && strcmp(cadeia[2], "preto") == 0)
        condicao3 = 1;
    if(strcmp(cadeia[1], "azul") == 0 && strcmp(cadeia[2], "vermelho") == 0)
        condicao3 = 1;
    if(strcmp(cadeia[1], "preto") == 0 && strcmp(cadeia[2], "vermelho") == 0)
        condicao3 = 1;
    if(strcmp(cadeia[1], "preto") == 0 && strcmp(cadeia[2], "azul") == 0)
        condicao3 = 1;

    if(condicao1 || condicao2 || condicao3)
        printf("VERDADEIRO.\n");
    else
        printf("FALSO.\n");


}

//azul, preto, branco
