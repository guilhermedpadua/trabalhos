#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    int dia;
    int mes;
    int ano;
};

typedef struct data Data;

struct cliente{
    int identificacao;
    Data adesao;
};

typedef struct cliente Cliente;


void exibeCliente(Cliente cliente)
{
    printf("-------------------------\n");
    printf("IDENTIFICACAO: %d\n", cliente.identificacao);
    printf("DATA DE ADESAO: %d/%d/%d\n", cliente.adesao.dia, cliente.adesao.mes, cliente.adesao.ano);
    printf("-------------------------\n\n");
}

int datasIguais(Data d1, Data d2)
{
    return d1.dia == d2.dia && d1.mes == d2.mes && d1.ano == d2.ano;
}


Cliente* preenche_vetor(char *nome_arquivo, int *quantidade)
{

    FILE *arquivo = fopen(nome_arquivo, "r");
    if(!arquivo){
        printf("Erro ao abrir arquivo!\n");
        system("pause");
        exit(1);
    }

    char primeira_linha[100];
    char *numero;
    int numClientes, i = 0;

    fgets(primeira_linha, 30, arquivo);

    numero = strtok(primeira_linha, ":");
    numero = strtok(NULL, ": ");
    numClientes = atoi(numero);
    *quantidade = numClientes;

    Cliente *clientes = (Cliente *) malloc(sizeof(Cliente) * numClientes);

    if(!clientes){
        printf("Erro ao alocar memoria!\n");
        system("pause");
        return NULL;
    }


    while(!feof(arquivo)){
        int identidade, dia, ano, mes;

        fgets(primeira_linha, 99, arquivo);

        numero = strtok(primeira_linha, " ");
        identidade = atoi(numero);

        numero = strtok(NULL, " ");
        dia = atoi(numero);

        numero = strtok(NULL, " ");
        mes = atoi(numero);

        numero = strtok(NULL, " ");
        ano = atoi(numero);

        clientes[i].identificacao = identidade;
        clientes[i].adesao.dia = dia;
        clientes[i].adesao.mes = mes;
        clientes[i].adesao.ano = ano;

        i++;
    }

    fclose(arquivo);
    return clientes;
}


void clientesPorData(Cliente *clientes, int qtdClientes, Data data)
{
    int i, qt = 0;
    for(i = 0; i < qtdClientes; i++){
        if(datasIguais(clientes[i].adesao, data)){
            exibeCliente(clientes[i]);
            qt++;
        }
    }
    if(qt == 0){
        printf("NENHUM CLIENTE TEM DATA DE ADESAO IGUAL A DATA INFORMADA.\n");
    }
}

void liberaMemoria(Cliente *clientes)
{
    free(clientes);
}

int main()
{
    int quantidade;
    Cliente *vetor = preenche_vetor("clientes.txt", &quantidade);
    if(!vetor){
        printf("Erro!\n");
        system("pause");
        return 1;
    }

    Data d1 = {21, 05, 2024};
    clientesPorData(vetor, quantidade, d1);
    liberaMemoria(vetor);
    return 0;
}
