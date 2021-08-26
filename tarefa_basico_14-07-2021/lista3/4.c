#include <stdio.h>
#include <stdlib.h>
#define TAM 100

int main()
{
    int vetor[TAM], i, j, repetidos = 0;
    //preenchendo o vetor
    for(i = 0; i < TAM; i++){
        printf("Digite o elemento %d do vetor: ", i);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            if(vetor[i] == vetor[j] && i != j){
                repetidos++;
            }
        }
    }


    printf("Numeros repetidos: %d\n", repetidos/2);
    return 0;
}

