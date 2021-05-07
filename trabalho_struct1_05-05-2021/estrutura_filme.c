#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme{
    char nome[100];
    char genero[100];
    int duracao;
    int estrelas;
    int ano;
};

typedef struct filme Filme;

//quando o 2 é o maior -> OK
//quando o 1 é o maior -> OK
//quando o 3 é o maior -> OK
//quando os 3 são iguais -> OK

int main()
{
    Filme filmes[3];

    strcpy(filmes[0].nome, "As aventuras de PI");
    strcpy(filmes[0].genero, "Drama");
    filmes[0].duracao = 145;
    filmes[0].estrelas = 4;
    filmes[0].ano = 2015;

    strcpy(filmes[1].nome, "Bohemian Rhapsody");
    strcpy(filmes[1].genero, "Drama");
    filmes[1].duracao = 120;
    filmes[1].estrelas = 5;
    filmes[1].ano = 2015;

    printf("Digite o nome do terceiro filme: ");
    scanf("%[^\n]s", filmes[2].nome);
    setbuf(stdin, NULL);
    printf("Digite o genero do terceiro filme: ");
    scanf("%[^\n]s", filmes[2].genero);
    setbuf(stdin, NULL);
    printf("Digite a duracao, em minutos, do terceiro filme: ");
    scanf("%d", &filmes[2].duracao);
    setbuf(stdin, NULL);
    printf("Digite o numero de estrelas do terceiro filme: ");
    scanf("%d", &filmes[2].estrelas);
    setbuf(stdin, NULL);
    printf("Digite o ano do terceiro filme: ");
    scanf("%d", &filmes[2].ano);
    setbuf(stdin, NULL);

    int maior, meio, menor;

    if(filmes[0].ano > filmes[1].ano && filmes[0].ano > filmes[2].ano){
        maior = 0;
        if(filmes[1].ano > filmes[2].ano){
            meio = 1;
            menor = 2;
        }else{
           meio = 2;
           menor = 1;
        }
    }else if(filmes[1].ano > filmes[2].ano && filmes[1].ano > filmes[0].ano){
        maior = 1;
        if(filmes[0].ano > filmes[2].ano){
            meio = 0;
            menor = 2;
        }else{
            meio = 2;
            menor = 0;
        }
    }else if(filmes[2].ano > filmes[1].ano && filmes[2].ano > filmes[0].ano){
        maior = 2;
        if(filmes[0].ano > filmes[1].ano){
            meio = 0;
            menor = 1;
        }else{
            meio = 1;
            menor = 0;
        }
    }else{
        maior = 0;
        meio = 1;
        menor = 2;
    }


    printf("NOME: %s\n", filmes[maior].nome);
    printf("GENERO: %s\n", filmes[maior].genero);
    printf("DURACAO: %d minutos\n", filmes[maior].duracao);
    printf("ESTRELAS: %d\n", filmes[maior].estrelas);
    printf("ANO: %d\n", filmes[maior].ano);
    printf("------------------------------------------\n");

    printf("NOME: %s\n", filmes[meio].nome);
    printf("GENERO: %s\n", filmes[meio].genero);
    printf("DURACAO: %d minutos\n", filmes[meio].duracao);
    printf("ESTRELAS: %d\n", filmes[meio].estrelas);
    printf("ANO: %d\n", filmes[meio].ano);
    printf("------------------------------------------\n");

    printf("NOME: %s\n", filmes[menor].nome);
    printf("GENERO: %s\n", filmes[menor].genero);
    printf("DURACAO: %d minutos\n", filmes[menor].duracao);
    printf("ESTRELAS: %d\n", filmes[menor].estrelas);
    printf("ANO: %d\n", filmes[menor].ano);
    return 0;
}
