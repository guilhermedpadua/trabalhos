#include <stdio.h>
#include <stdlib.h>
#include <math.h> //importação da biblioteca math.h para uso da função sqrt

struct ponto{
    float x;
    float y;
};

typedef struct ponto PONTO;

float dAB(PONTO p) //funcao para calcular a distancia entre um ponto e a origem
{
    float xa = p.x;
    float xb = 0;
    float ya = p.y;
    float yb = 0;
    float dAB = (float)sqrt((xa - xb)*(xa - xb)*(ya - yb)*(ya - yb)); //calculo da distancia entre o ponto e a origem de acordo com a formula dada na descrição do programa
    return dAB;
}

int main()
{
    int N, i, j;
    scanf("%d", &N);
    PONTO *vetor_pontos = malloc(sizeof(PONTO) * N);

    //lendo os pontos
    for(i = 0; i < N; i++){
        scanf("%f %f", &vetor_pontos[i].x, &vetor_pontos[i].y);
    }

    //ordenando o vetor de pontos com o uso do algoritmo bubble sort
    for(i = 0; i < N - 1; i++){
        for(j = i + 1; j < N; j++){
            if(dAB(vetor_pontos[i]) > dAB(vetor_pontos[j])){
                PONTO auxiliar = vetor_pontos[i];
                vetor_pontos[i] = vetor_pontos[j];
                vetor_pontos[j] = auxiliar;
            }
        }
    }

    printf("\n");

    //exibindo o vetor de pontos já ordenado
    for(i = 0; i < N; i++)
        printf("%.1f %.1f\n", vetor_pontos[i].x, vetor_pontos[i].y);

    //desalocando a memória reservada na linha 26
    free(vetor_pontos);
    return 0;
}


/*
 * NESTE PROGRAMA FOI USADA UMA FUNÇÃO PARA CALCULAR A DISTANCIA ENTRE UM PONTO E A ORIGEM;
 * PARA ISTO, ELA RECEBE COMO ARGUMENTO UM PONTO E RETORNA A DISTANCIA ENTRE ELE E A ORIGEM.
 */
