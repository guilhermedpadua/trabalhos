#include <stdio.h>
#include <stdlib.h>
#define TAM 100

int main()
{
    int vetor[TAM], i, busca;

    //preenchendo o vetor
    for(i = 0; i < TAM; i++){
        printf("Digite o elemento %d do vetor: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite o numero que quer buscar no vetor: ");
    scanf("%d", &busca);

    for(i = 0; i < TAM; i++){
        if(vetor[i] == busca){
            printf("\nO numero procurado foi encontrado na posicao %d do vetor.\n", i);
            return 0;
        }
    }

    printf("O numero procurado nao esta no vetor.\n");
    return 0;
}

