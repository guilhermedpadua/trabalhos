#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int main()
{
    int vetor1[MAX], vetor2[MAX], i, j, repetidos = 0;
    for(i = 0; i < MAX; i++){
        printf("Digite o %d elemento do vetor 1: ", i + 1);
        scanf("%d", &vetor1[i]);
    }

    printf("\n\n");

    for(i = 0; i < MAX; i++){
        printf("Digite o %d elemento do vetor 2: ", i + 1);
        scanf("%d", &vetor2[i]);
    }

    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            if(vetor1[i] == vetor2[j])
                repetidos++;
        }
    }

    printf("\n\n");

    printf("Ha %d numeros em ambos os vetores.\n", repetidos);

    return 0;
}

