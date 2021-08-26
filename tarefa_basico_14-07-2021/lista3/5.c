#include <stdio.h>
#include <stdlib.h>
#define TAM 100

int main()
{
    int vetor[TAM], i, j, soma_repetidos = 0, entrou;
    //preenchendo o vetor
    for(i = 0; i < TAM; i++){
        printf("Digite o elemento %d do vetor: ", i);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < TAM; i++){
        entrou = 0;
        for(j = 0; j < TAM; j++){
            if((vetor[j] == vetor[i]) && (i != j) && (vetor[i] != 0)){
                soma_repetidos += vetor[j];
                vetor[j] = 0;
                entrou = 1;
            }
        }
        if(entrou){
            soma_repetidos += vetor[i];
            vetor[i] = 0;
        }
    }

    printf("Numeros repetidos: %d\n", soma_repetidos);
    return 0;
}

