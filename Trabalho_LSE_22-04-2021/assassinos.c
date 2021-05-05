#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    char nome[11];
    int participacao;
};

int assassino_cadastrado(char nome_assassino[11], struct pessoa* assassinos, int quantidade_assassinos)
{
    if(quantidade_assassinos == 0)
        return 0;
    for(int i = 0; i < quantidade_assassinos; i++){
        if(strcmp(nome_assassino, assassinos[i].nome) == 0){
            return 1;
        }
    }
    return 0;
}

void incrementa_assassinato(char nome_assassino[11], struct pessoa* assassinos, int quantidade_assassinos)
{
    for(int i = 0; i < quantidade_assassinos; i++){
        if(strcmp(nome_assassino, assassinos[i].nome) == 0){
            assassinos[i].participacao = assassinos[i].participacao + 1;
            return;
        }
    }
}

struct pessoa* cadastra_assassino(struct pessoa* assassinos, char nome_assassino[11], int* quantidade_assassinos)
{
    assassinos = realloc(assassinos, sizeof(struct pessoa) * ++(*quantidade_assassinos));
    strcpy(assassinos[(*quantidade_assassinos) - 1].nome, nome_assassino);
    assassinos[(*quantidade_assassinos) - 1].participacao = 1;
    return assassinos;
};

struct pessoa* cadastra_assassinado(struct pessoa* assassinados, char nome_assassinado[11], int *quantidade_assassinados)
{
    assassinados = realloc(assassinados, sizeof(struct pessoa) * ++(*quantidade_assassinados));
    strcpy(assassinados[(*quantidade_assassinados) - 1].nome, nome_assassinado);
    assassinados[(*quantidade_assassinados) - 1].participacao = 1;
    return assassinados;
};


int foi_assassinado(char nome_pessoa[11], struct pessoa* assassinados, int tamanho)
{
    if(tamanho == 0)
        return 0;
    for(int i = 0; i < tamanho; i++){
        if(strcmp(nome_pessoa, assassinados[i].nome) == 0){
            return 1;
        }
    }
    return 0;
}




int main()
{
    struct pessoa* assassinos = NULL;
    struct pessoa* assassinados = NULL;

    int quantidade_assassinatos, quantidade_assassinos = 0, quantidade_assassinados = 0;

    scanf("%d", &quantidade_assassinatos);

    for(int i = 0; i < quantidade_assassinatos; i++){
        char nome_assassino[11], nome_assassinado[11];
        scanf("%s %s", nome_assassino, nome_assassinado);
        setbuf(stdin, NULL);
        if(assassino_cadastrado(nome_assassino, assassinos, quantidade_assassinos)){
            incrementa_assassinato(nome_assassino, assassinos, quantidade_assassinos);
        }else{
            assassinos = cadastra_assassino(assassinos, nome_assassino, &quantidade_assassinos);
        }
        assassinados = cadastra_assassinado(assassinados, nome_assassinado, &quantidade_assassinados);
    }


    //ordenando na ordem decrescente
    for(int i = 0; i < quantidade_assassinos - 1; i++){
        for(int j = i + 1; j < quantidade_assassinos; j++){
            if(assassinos[i].participacao < assassinos[j].participacao){
                struct pessoa aux = assassinos[i];
                assassinos[i] = assassinos[j];
                assassinos[j] = aux;
            }
        }
    }

    printf("\n\nHALL OF MURDERERS\n");

    for(int i = 0; i < quantidade_assassinos; i++){
        if(!foi_assassinado(assassinos[i].nome, assassinados, quantidade_assassinados)){
            printf("%s %d\n", assassinos[i].nome, assassinos[i].participacao);
        }
    }
    return 0;
}



/*
 * A LÓGICA DO PROGRAMA É SIMPLES: INICIALMENTE NÓS LEMOS N LINHAS, ONDE CADA LINHA DESCREVE UM ASSASSINATO, LOGO N
 * É O NUMERO DE ASSASSINATOS. PARA CADA ASSASSINATO, NÓS LEMOS DOIS NOMES, O DA ESQUERDA É O ASSASSINO E O DA DIREITA
 * É O ASSASSINADO. ASSIM, PODEMOS CRIAR UM VETOR DE ASSASSINOS, ONDE VÃO PARAR TODOS OS NOMES DO LADO ESQUERDO (TODOS OS ASSASSINOS)
 * E UM OUTRO VETOR DE ASSASSINADOS, ONDE VÃO PARAR TODOS OS NOMES DO LADO DIREITO (AS VÍTIMAS).
 *
 * DESSA FORMA, PRECISAMOS DE DOIS VETORES. A ESTRUTURA DESSES DOIS VETORES É IGUAL PARA TODOS: CADA ELEMENTO É UMA STRUCT
 * DO TIPO PESSOA (DEFINIDA NA LINHA 4), ONDE O PRIMEIRO CAMPO É O NOME E O SEGUNDO CAMPO É UM NÚMERO INTEIRO CHAMADO 'PARTICIPAÇÃO',
 * QUE GUARDA QUANTAS VEZES A PESSOA FOI ASSASSINADA (NO CASO DE UMA VÍTIMA) OU PRATICOU O ASSASSINATO (NO CASO DE UM ASSASSINO).
 *
 * SEMPRE QUE LEMOS DOIS NOMES ENVOLVIDOS EM UM ASSASSINATO, VERIFICAMOS: PARA O ASSASSINO, SE ELE JÁ ESTÁ NO VETOR DE ASSASSINOS
 * (ESSA VERIFICAÇÃO É FEITA COM A FUNÇÃO assassino_cadastrado, que retorna 1 caso o o nome que passamos a ela já esteja no vetor e 0 caso contrário);
 * CASO ELE JÁ ESTEJA CADASTRADO, NÓS APENAS INCREMENTAMOS O CAMPO "PARTICIPACAO" DA STRUCT, PARA INDICAR QUE ELE ESTÁ ENVOLVIDO EM MAIS UM ASSASSINATO,
 * SE ELE NÃO ESTIVER CADASTRADO, NÓS O CADASTRAMOS (ESSE CADASTRO É FEITO COM A FUNÇÃO cadastra_assassino, que aumenta o tamanho do vetor
 * de assassinos dinamicamente e adiciona o novo assassino à última posicao, inicializando o campo 'participação' com 1, pois é a primeira participação
 * do assassino em um assassinato). Para o ASSASSINADO (NOME À DIREITA), NÓS SIMPLESMENTE ADICIONAMOS AO VETOR DE ASSASSINADOS
 *
 * JÁ NA LINHA 86, NÓS VAMOS PERCORRENDO CADA POSIÇÃO DOS ASSASSINOS E FAZEMOS O SEGUINTE: SE O ASSASSINO ATUAL ESTIVER NO VETOR DE ASSASSINADOS (ESSA VERFICAÇÃO É FEITA
 * COM A FUNÇÃO assassino_cadastrado(), QUE RECEBE UM NOME E RETORNA 1 CASO ESSE NOME ESTEJA NO VETOR DE ASSASSINADOS E 0 CASO CONTRÁRIO), SE ELE ESTIVER, SIGNIFICA
 * QUE ELE FOI MORTO, PORTANTO NÃO EXIBIMOS SEU NOME. SE ELE NÃO ESTIVER, EXIBIMOS SEU NOME, SEGUIDO DA QUANTIDADE DE ASSASSINATOS PRATICADOS POR ELE, QUE ESTÁ
 * ARMAZENADA NO CAMPO 'PARTICIPAÇÃO'
 *
 */
