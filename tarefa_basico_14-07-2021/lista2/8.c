#include <stdio.h>
#include <stdlib.h>
#define TAM 6
int main()
{
    int vetor[TAM] = {1, 2, 2, 3, 3, 4}, j, i, tmp;
    for(i = 0; i < TAM - 1; i++){
        if(vetor[i] == vetor[i + 1]){
            tmp = vetor[i];
            for(j = i; j < TAM - 1; j++){
                vetor[j] = vetor[j+1];
            }
            vetor[TAM - 1] = tmp;
        }
    }
    for(i = 0; i < TAM; i++){
        printf("%d, ", vetor[i]);
    }

    return 0;
}

