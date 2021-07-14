#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int main()
{
    int vetor[MAX], i, menor;
    for(i = 0; i < MAX; i++){
        printf("Digite o %d elemento do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    menor = vetor[0];

    for(i = 0; i < MAX; i++){
        if(vetor[i] < menor)
            menor = vetor[i];
    }
    printf("MENOR: %d.\n", menor);
    return 0;
}

