#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct carta{
    char numero[3];
    char naipe[8];
};

typedef struct carta Carta;

Carta gera_carta()
{
    int numero_carta = (rand() % 13) + 1;
    int numero_naipe = (rand() % 4) + 1;
    Carta nova_carta;

    switch(numero_carta){
    case 1:
        strcpy(nova_carta.numero, "A");
        break;
    case 2:
        strcpy(nova_carta.numero, "2");
        break;
    case 3:
        strcpy(nova_carta.numero, "3");
        break;
    case 4:
        strcpy(nova_carta.numero, "4");
        break;
    case 5:
        strcpy(nova_carta.numero, "5");
        break;
    case 6:
        strcpy(nova_carta.numero, "6");
        break;
    case 7:
        strcpy(nova_carta.numero, "7");
        break;
    case 8:
        strcpy(nova_carta.numero, "8");
        break;
    case 9:
        strcpy(nova_carta.numero, "9");
        break;
    case 10:
        strcpy(nova_carta.numero, "10");
        break;
    case 11:
        strcpy(nova_carta.numero, "J");
        break;
    case 12:
        strcpy(nova_carta.numero, "Q");
        break;
    case 13:
        strcpy(nova_carta.numero, "K");
        break;
    }

    switch(numero_naipe){
    case 1:
        strcpy(nova_carta.naipe, "ouros");
        break;
    case 2:
        strcpy(nova_carta.naipe, "espadas");
        break;
    case 3:
        strcpy(nova_carta.naipe, "copas");
        break;
    case 4:
        strcpy(nova_carta.naipe, "paus");
        break;
    }

    return nova_carta;

}

Carta *distribui_cartas(int quantidade)
{
    Carta *cartas = malloc(sizeof(Carta) * quantidade);
    for(int i = 0; i < quantidade; i++){
        cartas[i] = gera_carta();
    }
    return cartas;
}

int main()
{
    srand(time(NULL));
    int numero_de_cartas;
    Carta *jogadores[4];
    printf("Digite o numero de cartas para cada jogador: ");
    scanf("%d", &numero_de_cartas);
    if(numero_de_cartas % 2 == 0){
        while(numero_de_cartas % 2 == 0){
            printf("Este numero nao eh valido!\nDigite um numero impar: ");
            scanf("%d", &numero_de_cartas);
        }
    }

    for(int i = 0; i < 4; i++)
        jogadores[i] = distribui_cartas(numero_de_cartas);

    for(int i = 0; i < 4; i++){
        printf("\n\nJogador %d\n", i + 1);
        for(int j = 0; j < numero_de_cartas; j++){
            printf("-------------------------------\n");
            printf("<%s, %s>\n", jogadores[i][j].numero, jogadores[i][j].naipe);
            printf("-------------------------------\n");
        }
    }

    for(int i = 0; i < 4; i++)
        free(jogadores[i]);

    return 0;
}
