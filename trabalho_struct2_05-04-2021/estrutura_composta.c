#include <stdio.h>
#include <stdlib.h>

struct nome{
    char nome[40];
    char sobrenome[60];
};

typedef struct nome Nome;

struct pessoa{
    Nome nome;
    int idade;
    float altura;
};

typedef struct pessoa Pessoa;


int main()
{
    Pessoa pessoa;
    printf("Digite o nome: ");
    scanf("%s", pessoa.nome.nome);
    setbuf(stdin, NULL);
    printf("Digite o sobrenome: ");
    scanf("%[^\n]s", pessoa.nome.sobrenome);
    setbuf(stdin, NULL);
    printf("Digite a idade: ");
    scanf("%d", &pessoa.idade);
    setbuf(stdin, NULL);
    printf("Digite a altura: ");
    scanf("%f", &pessoa.altura);

    printf("\n----------------------------------\n");
    printf("NOME: %s %s\n", pessoa.nome, pessoa.nome.sobrenome);
    printf("IDADE: %d\n", pessoa.idade);
    printf("ALTURA: %.2f\n", pessoa.altura);
    printf("\n----------------------------------\n");
    return 0;
}
