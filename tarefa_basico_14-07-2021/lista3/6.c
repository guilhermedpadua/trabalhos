#include <stdio.h>
#include <stdlib.h>
#define TAM 50

int main()
{
    float A[TAM], B[TAM], C[TAM], D[TAM*3];
    int i, j;

    //preenchendo o vetor A
    for(i = 0; i < TAM; i++){
        printf("Digite o valor %d do vetor A: ", i);
        scanf("%f", &A[i]);
    }

    //preenchendo o vetor B
    for(i = 0; i < TAM; i++){
        printf("Digite o valor %d do vetor B: ", i);
        scanf("%f", &B[i]);
    }

    //preenchendo o vetor C
    for(i = 0; i < TAM; i++){
        printf("Digite o valor %d do vetor C: ", i);
        scanf("%f", &C[i]);
    }

    //preenchendo o vetor D
    for(i = 0; i < TAM*3; i++){
        if(i >= 0 && i < TAM)
            D[i] = A[i];
        else if(i >= TAM && i <= 2*TAM - 1)
            D[i] = B[i - TAM];
        else if(i >= 2*TAM)
            D[i] = C[i - 2*TAM];
    }

    //ordenando o vetor D
    for(i = 0; i < TAM*3; i++){
        for(j = 0; j < TAM*3 - 1; j++){
            if(D[j] > D[j+1]){
                A[0] = D[j+1];
                D[j+1] = D[j];
                D[j] = A[0];
            }
        }
    }

    //exibindo o vetor D
    for(i = 0; i < TAM*3; i++)
        printf("%.2f, ", D[i]);

    return 0;
}

