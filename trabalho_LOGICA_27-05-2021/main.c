#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int N, qt_asteriscos, aux;
    char carac;
    scanf("%d", &N);
    setbuf(stdin, NULL);
    int vetor[N];
    for(int i = 0; i < N; i++){
        qt_asteriscos = 0;
        while ((carac = getchar()) != '\n'){
            if(carac == '*')
                qt_asteriscos++;
        }
        vetor[i] = qt_asteriscos;
    }

    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < vetor[i]; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
