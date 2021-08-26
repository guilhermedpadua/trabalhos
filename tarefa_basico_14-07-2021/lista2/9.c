#include <stdio.h>
#include <stdlib.h>
#define TAM 10
int main()
{

    int vet[TAM] = {1, 0, 1, 1, 1, 0, 1, 0, 1, 0}, res;
    res = (((vet[0] && vet[1]) || vet[2]) && vet[3] && vet[4] && vet[5] && vet[6] && vet[7] && vet[8] && vet[9]);
    if(res)
        printf("TRUE\n");
    else
        printf("FALSE\n");
    return 0;
}

