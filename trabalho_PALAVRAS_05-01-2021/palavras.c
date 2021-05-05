
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char matriz[10][100]; //matriz onde serão armazenadas as 10 palavras. Cada palavra lida poderá ser de até 99 caracteres
    char letra;
    for(int i = 0; i < 10; i++){ //lendo as 10 palavras
        scanf("%s", matriz[i]);
        setbuf(stdin, NULL);
    }

    printf("\n\n");

    printf("Digite uma letra: ");
    scanf("%c", &letra);
    setbuf(stdin, NULL);

    char *vetor = NULL; //vetor onde serão armazenadas as palavras inciadas com as letras digitadas pelo usuario
    int comprimento_vetor = 0;
    for(int i = 0; i < 10; i++){
        if(matriz[i][0] == letra){
            for(int j = 0; j < strlen(matriz[i]); j++){
                if(comprimento_vetor == 0){
                    vetor = realloc(vetor, sizeof(char) * (comprimento_vetor + 2));
                    comprimento_vetor = comprimento_vetor + 2;
                    vetor[0] = matriz[i][0];
                    vetor[1] = '\0';
                }else{
                    vetor = realloc(vetor, sizeof(char) * (comprimento_vetor + 1));
                    comprimento_vetor++;
                    vetor[comprimento_vetor - 2] = matriz[i][j];
                    vetor[comprimento_vetor - 1] = '\0';
                }
            }
        }
    }

    printf("%s\n", vetor); //mostrando o vetor de palavras no final
    return 1;
}
