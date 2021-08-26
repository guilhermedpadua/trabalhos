#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct endereco{
    char rua[11];
    int numero;
    char complemento[11];
    char bairro[11];
}Endereco;

typedef struct imovel{
    Endereco endereco;
    int num_quartos;
    int valor;
}Imovel;

//I
Imovel* vetor_estruturas(char *nome_arquivo, int *num_registros)
{
    FILE* arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL)
        return NULL;
    int tam_vetor;
    char string_linha[150], *piece;
    if(fgets(string_linha, 150, arquivo) == NULL)
        return NULL;
    tam_vetor = atoi(string_linha);
    Imovel* imoveis = malloc(sizeof(Imovel) * tam_vetor);
    if(imoveis == NULL)
        return NULL;
    int i;
    for(i = 0; i < tam_vetor; i++){
        if(fgets(string_linha, 150, arquivo) != NULL){
            piece = strtok(string_linha, " ");
            strcpy(imoveis[i].endereco.rua, piece);
            piece = strtok(NULL, " ");
            imoveis[i].endereco.numero = atoi(piece);
            piece = strtok(NULL, " ");
            strcpy(imoveis[i].endereco.complemento, piece);
            piece = strtok(NULL, " ");
            strcpy(imoveis[i].endereco.bairro, piece);
            piece = strtok(NULL, " ");
            imoveis[i].num_quartos = atoi(piece);
            piece = strtok(NULL, " ");
            piece = strtok(NULL, " ");
            imoveis[i].valor = atoi(piece);
        }
    }
    *num_registros = tam_vetor;
    return imoveis;
}

//II
void imprime_imovel(Imovel* imovel)
{
    printf("\t%s ", imovel->endereco.rua);
    printf("%d ", imovel->endereco.numero);
    printf("%s ", imovel->endereco.complemento);
    (imovel->num_quartos > 1) ? printf("%d quartos ", imovel->num_quartos) : printf("%d quarto ", imovel->num_quartos);
    printf("R$ %d\n", imovel->valor);

}

//II
void imprime_imoveis(Imovel* imoveis, int quantidade)
{
    int i;
    for(i = 0; i < quantidade; i++){
        imprime_imovel(&imoveis[i]);
    }
}

//III
Imovel** imoveis_disponiveis(Imovel* imoveis, int tot_imoveis, char* bairro, int num_quartos, int* retorno)
{
    int i, tot_quartos = 0, j;
    Imovel** imoveis_condicao = NULL;
    for(i = 0; i < tot_imoveis; i++){
        if(imoveis[i].num_quartos == num_quartos && strcmp(imoveis[i].endereco.bairro, bairro) == 0){
            imoveis_condicao = realloc(imoveis_condicao, sizeof(Imovel*) * (++tot_quartos));
            if(imoveis_condicao == NULL){
                if(tot_quartos > 1)
                    free(imoveis_condicao);
                return  NULL;
            }
            imoveis_condicao[tot_quartos - 1] = &(imoveis[i]);
        }
    }
    *retorno = tot_quartos;
    return imoveis_condicao;
}

//IV
char* gera_codigo(char* nome_cliente, char* nascimento)
{
    char* codigo = malloc(strlen(nome_cliente) + strlen(nascimento) + 1);
    if(codigo == NULL)
        return NULL;
    int i, c, n;
    i = c = n = 0;
    while(nome_cliente[c] != '\0' || nascimento[n] != '\0'){
        if(nome_cliente[c] != '\0'){
            codigo[i++] = nome_cliente[c++];
        }
        if(nascimento[n] != '\0'){
            codigo[i++] = nascimento[n++];
        }
    }
    codigo[i] = '\0';
    return codigo;
}


void imprime_ponteiros(Imovel** ponteiros, int quantidade)
{
    int i;
    for(i = 0; i < quantidade; i++){
        imprime_imovel(ponteiros[i]);
    }
}


int main()
{
    int quantidade, quantidade_match = 0, i;
    Imovel* imoveis = vetor_estruturas("arquivo.txt", &quantidade);

    printf("Vetor de Imoveis:\n");
    imprime_imoveis(imoveis, quantidade);

    char cliente1_nome[] = "ROBERTO";
    char cliente1_nascimento[] = "22101960";
    char cliente1_bairro[] = "CENTRO";
    int cliente1_quartos = 10;

    char cliente2_nome[] = "MARIA";
    char cliente2_nascimento[] = "30121997";
    char cliente2_bairro[] = "RODOVIARIA";
    int cliente2_quartos = 88;


    printf("\n\n");

    //Verificando imoveis disponiveis para  cliente 1
    Imovel** disponiveis = imoveis_disponiveis(imoveis, quantidade, cliente1_bairro, cliente1_quartos, &quantidade_match);
    if(disponiveis != NULL){
        printf("%d oferta(s) para %s, %s com %d quarto(s).\n", quantidade_match, gera_codigo(cliente1_nome, cliente1_nascimento), cliente1_bairro, cliente1_quartos);
        imprime_ponteiros(disponiveis, quantidade_match);
    }else{
        printf("Nao ha ofertas disponiveis para %s.\n", gera_codigo(cliente1_nome, cliente1_nascimento));
    }

    //Verificando imoveis disponiveis para cliente2
    disponiveis = imoveis_disponiveis(imoveis, quantidade, cliente2_bairro, cliente2_quartos, &quantidade_match);
    if(disponiveis != NULL){
        printf("%d oferta(s) para %s, %s com %d quarto(s).\n", quantidade_match, gera_codigo(cliente2_nome, cliente2_nascimento), cliente2_bairro, cliente2_quartos);
        imprime_ponteiros(disponiveis, quantidade_match);
    }else{
        printf("Nao ha ofertas disponiveis para %s.\n", gera_codigo(cliente2_nome, cliente2_nascimento));
    }



    return 0;
}
