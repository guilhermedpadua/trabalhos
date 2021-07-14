#include <stdio.h>
#include <stdlib.h>
#define TAM 50

typedef struct pessoa{
    char nome[100];
    int idade;
    int eh_maior;
}Pessoa;

int main()
{
    int i;
    Pessoa pessoas[TAM];
    for(i = 0; i < TAM; i++){
        printf("Digite o nome da pessoa %d: ", i + 1);
        gets(pessoas[i].nome);
        setbuf(stdin, NULL);
        printf("Digite a idade de %s: ", pessoas[i].nome);
        scanf("%d", &pessoas[i].idade);
        setbuf(stdin, NULL);
        if(pessoas[i].idade >= 18)
            pessoas[i].eh_maior = 1;
        else
            pessoas[i].eh_maior = 0;
    }

    printf("\n\nMENORES DE IDADE...\n");
    for(i = 0; i < TAM; i++){
        if(!(pessoas[i].eh_maior))
            printf("%s\n", pessoas[i].nome);
    }
    printf("\n\nMAIORES DE IDADE...\n");
    for(i = 0; i < TAM; i++){
        if(pessoas[i].eh_maior)
            printf("%s\n", pessoas[i].nome);
    }


    return 0;
}

