#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6
#define M 3

struct funcionario{
    int codigo;
    char nome[51];
    int codigo_cidade;
};

typedef struct funcionario Funcionario;

struct cidade{
    int codigo;
    char nome[51];
    char estado[3];
};

typedef struct cidade Cidade;


int main()
{
    Funcionario *funcionarios = malloc(sizeof(Funcionario) * N);
    Funcionario auxiliar;
    Cidade *cidades = malloc(sizeof(Cidade) * M);
    int i, j, k;

    //lendo os dados dos funcionários
    for(i = 0; i < N; i++){
        scanf("%d", &funcionarios[i].codigo);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", funcionarios[i].nome);
        setbuf(stdin, NULL);
        scanf("%d", &funcionarios[i].codigo_cidade);
        setbuf(stdin, NULL);
    }

    //lendo os dados da cidade
    for(i = 0; i < M; i++){
        scanf("%d", &cidades[i].codigo);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", cidades[i].nome);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", cidades[i].estado);
        setbuf(stdin, NULL);
    }

    //ordenando o vetor de cidades em ordem crescente, de acordo com o nome de cada uma, usando o bubble sort
    for(i = 0; i < M - 1; i++){
        for(j = i + 1; j < M; j++){
            if(strcmp(cidades[i].nome, cidades[j].nome) > 0){
                Cidade aux;
                aux = cidades[i];
                cidades[i] = cidades[j];
                cidades[j] = aux;
            }
        }
    }

    printf("\n\n");

    //exibindo o relatório
    for(i = 0; i < M; i++){
        printf("%s - %s\n", cidades[i].nome, cidades[i].estado);
        //pegando todos os funcionarios relacionados à cidade[i] e colocando-os em funcionarios_i;
        Funcionario *funcionarios_i = NULL;
        int comprimento_funcionarios_i = 0;

        for(j = 0; j < N; j++){
            if(funcionarios[j].codigo_cidade == cidades[i].codigo){
                funcionarios_i = realloc(funcionarios_i, sizeof(Funcionario) * (++comprimento_funcionarios_i));
                funcionarios_i[comprimento_funcionarios_i - 1] = funcionarios[j];
            }
        }
        //ordenando funcionarios_i por ordem alfabética
        for(j = 0; j < comprimento_funcionarios_i - 1; j++){
            for(k = j + 1; k < comprimento_funcionarios_i; k++){
                if(strcmp(funcionarios_i[j].nome, funcionarios_i[k].nome) > 0){
                    auxiliar = funcionarios_i[j];
                    funcionarios_i[j] = funcionarios_i[k];
                    funcionarios_i[k] = auxiliar;
                }
            }
        }

        //exibindo os funcionarios (armazenados em funcionarios_i) de cada cidade
        for(j = 0; j < comprimento_funcionarios_i; j++){
            printf("%d %s\n", funcionarios_i[j].codigo, funcionarios_i[j].nome);
        }
        printf("\n\n");
    }

    return 0;
}
