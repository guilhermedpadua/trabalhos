#include <stdio.h>
#include <stdlib.h>
/*
 * Inclus�o de <stdlib.h> para uso do valor da constante NULL e fun��o atoi()
 * atoi() -> recebe uma string como argumento, converte-a para um n�mero inteiro e a retorna
 */
#include <string.h>
/*
 * Inclus�o de <string.h> para uso das fun��es strlen(), strcpy() e strtok()
 * strlen() -> retorna o comprimento de uma string passada como argumento
 * strcpy() -> recebe como argumento duas strings, str1 e str2, e copia str2 para str1
 * strtok() -> quebra uma string em v�rias subtrings, que s�o separadas por um delimitador passado como argumento � fun��o
 */

struct data{
    int dia;
    int mes;
    int ano;
};

typedef struct data Data;

struct pessoa{
    char *nome;
    Data nascimento;
};

typedef struct pessoa Pessoa;

int preenche_vetor(int num_maximo_pessoas, Pessoa *pessoas[], char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "r");
    if(!arquivo){
        printf("Erro na abertura do arquivo!\n");
        system("pause");
        exit(1);
    }
    if(num_maximo_pessoas > 100)
        num_maximo_pessoas = 100;

    int pessoas_lidas = 0;
    char *string_pessoa, *string_nome, *str_nasc;

    while(!feof(arquivo) && pessoas_lidas < num_maximo_pessoas){

        string_pessoa = malloc(93);
        if(!string_pessoa){
            printf("Erro ao alocar memoria!\n");
            system("pause");
            exit(1);
        }
        /*
         * Para cada linha, aloca-se uma string de 91 espa�os, pois o nome tem at� 80 caracteres, a data ocupa 10 caracteres,
         * existe um s�mbolo de dois pontos e um espa�o separando a data e o nome, totalizando 92, no entanto deve-se
         * alocar mais um espa�o para o delimitador de string (\0), totalizando 93 caracteres no m�ximo.
         */
        fgets(string_pessoa, 91, arquivo);
        string_nome = strtok(string_pessoa, ":");
        str_nasc = strtok(NULL, ": ");

        Pessoa *p = malloc(sizeof(Pessoa));

        if(!p){
            printf("Erro ao alocar memoria!\n");
            system("pause");
            exit(1);
        }
        p->nome = malloc(strlen(string_nome));

        if(!(p->nome)){
            printf("Erro ao alocar memoria!\n");
            system("pause");
            exit(1);
        }
        strcpy(p->nome, string_nome);

        p->nascimento.dia = atoi(strtok(str_nasc, "/"));
        p->nascimento.mes = atoi(strtok(NULL, "/"));
        p->nascimento.ano = atoi(strtok(NULL, "/"));

        pessoas[pessoas_lidas++] = p;
    }
    fclose(arquivo);
    return pessoas_lidas;
}


void aniversario(int qt_pessoas, Pessoa *pessoas[], int mes_aniversario)
{
    int i, dia, mes, ano, qt;
    qt = 0;
    for(i = 0; i < qt_pessoas; i++){
        if(pessoas[i]->nascimento.mes == mes_aniversario){
            dia = pessoas[i]->nascimento.dia;
            mes = pessoas[i]->nascimento.mes;
            ano = pessoas[i]->nascimento.ano;
            printf("------------------------\n");
            printf("NOME: %s                \n", pessoas[i]->nome);
            printf("NASCIMENTO: %d-%d-%d    \n", dia, mes, ano);
            printf("------------------------\n");
            qt++;
        }
    }
    if(qt == 0)
        printf("Nenhuma das pessoas faz aniversario no mes informado.\n");
}

void libera_memoria(Pessoa *pessoas[], int qt_pessoas)
{
    int i;
    for(i = 0; i < qt_pessoas; i++){
        free(pessoas[i]);
    }
}

int main()
{
    Pessoa *pessoas[101]; //alocando um vetor de ponteiros com 101 posi��es
    int qt = preenche_vetor(101, pessoas, "pessoas.txt");
    /*
     * tentando ler 101 pessoas do arquivo, por�m o m�ximo ser� 100, pois, como pede a descri��o do problema,
     * n�o pode passar disso.
     */
    aniversario(qt, pessoas, 12); //pedindo que se exiba as pessoas lidas que fazem anivers�rio no mes de julho
    libera_memoria(pessoas, qt); //liberando a mem�ria alocada em preenche_vetor()
    return 0;
}
