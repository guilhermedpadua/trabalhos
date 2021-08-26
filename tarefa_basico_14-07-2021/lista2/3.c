#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int main()
{
    int vetor[MAX], i, aux, j;
    for(i = 0; i < MAX; i++){
        printf("Digite o %d elemento do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    //ordenando
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX - 1; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }


    for(i = 0; i < MAX; i++)
        printf("%d, ", vetor[i]);
    return 0;
}

