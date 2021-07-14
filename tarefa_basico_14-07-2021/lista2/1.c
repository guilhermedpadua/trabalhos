#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main()
{
    int vetor[MAX], i, j, repetido = 0, pos, rep;
    for(i = 0; i < MAX; i++){
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            if(vetor[i] == vetor[j] && i != j){
                repetido = 1;
                break;
            }
        }
        if(repetido)
            break;
    }
    if(repetido){
        printf("Ha numeros repetidos no vetor.\n");
    }else{
        printf("Nao ha numeros repetidos no vetor.\n");
    }
    return 0;
}

