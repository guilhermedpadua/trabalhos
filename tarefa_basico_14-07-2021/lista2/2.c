#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int main()
{
    int vetor[MAX], i;
    for(i = 0; i < MAX; i++){
        printf("Digite o %d elemento do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for(i = MAX - 1; i >= 0; i--)
        printf("%d, ", vetor[i]);
    return 0;
}

