#include <stdio.h>
#include <stdlib.h>
#define TAM 100

int main()
{
    float numeros[TAM], aux;
    int i, j;
    //preenchendo o vetor

    for(i = 0; i < TAM; i++){
        printf("Digite o elemento %d do vetor: ", i);
        scanf("%f", &numeros[i]);
    }

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM - 1; j++){
            if(numeros[j] < numeros[j+1]){
                aux = numeros[j+1];
                numeros[j+1] = numeros[j];
                numeros[j] = aux;
            }
        }
    }

    printf("Segundo maior: %.2f\n", numeros[1]);
    return 0;
}

