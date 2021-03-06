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
 * A L??GICA DO PROGRAMA ?? SIMPLES: INICIALMENTE N??S LEMOS N LINHAS, ONDE CADA LINHA DESCREVE UM ASSASSINATO, LOGO N
 * ?? O NUMERO DE ASSASSINATOS. PARA CADA ASSASSINATO, N??S LEMOS DOIS NOMES, O DA ESQUERDA ?? O ASSASSINO E O DA DIREITA
 * ?? O ASSASSINADO. ASSIM, PODEMOS CRIAR UM VETOR DE ASSASSINOS, ONDE V??O PARAR TODOS OS NOMES DO LADO ESQUERDO (TODOS OS ASSASSINOS)
 * E UM OUTRO VETOR DE ASSASSINADOS, ONDE V??O PARAR TODOS OS NOMES DO LADO DIREITO (AS V??TIMAS).
 *
 * DESSA FORMA, PRECISAMOS DE DOIS VETORES. A ESTRUTURA DESSES DOIS VETORES ?? IGUAL PARA TODOS: CADA ELEMENTO ?? UMA STRUCT
 * DO TIPO PESSOA (DEFINIDA NA LINHA 4), ONDE O PRIMEIRO CAMPO ?? O NOME E O SEGUNDO CAMPO ?? UM N??MERO INTEIRO CHAMADO 'PARTICIPA????O',
 * QUE GUARDA QUANTAS VEZES A PESSOA FOI ASSASSINADA (NO CASO DE UMA V??TIMA) OU PRATICOU O ASSASSINATO (NO CASO DE UM ASSASSINO).
 *
 * SEMPRE QUE LEMOS DOIS NOMES ENVOLVIDOS EM UM ASSASSINATO, VERIFICAMOS: PARA O ASSASSINO, SE ELE J?? EST?? NO VETOR DE ASSASSINOS
 * (ESSA VERIFICA????O ?? FEITA COM A FUN????O assassino_cadastrado, que retorna 1 caso o o nome que passamos a ela j?? esteja no vetor e 0 caso contr??rio);
 * CASO ELE J?? ESTEJA CADASTRADO, N??S APENAS INCREMENTAMOS O CAMPO "PARTICIPACAO" DA STRUCT, PARA INDICAR QUE ELE EST?? ENVOLVIDO EM MAIS UM ASSASSINATO,
 * SE ELE N??O ESTIVER CADASTRADO, N??S O CADASTRAMOS (ESSE CADASTRO ?? FEITO COM A FUN????O cadastra_assassino, que aumenta o tamanho do vetor
 * de assassinos dinamicamente e adiciona o novo assassino ?? ??ltima posicao, inicializando o campo 'participa????o' com 1, pois ?? a primeira participa????o
 * do assassino em um assassinato). Para o ASSASSINADO (NOME ?? DIREITA), N??S SIMPLESMENTE ADICIONAMOS AO VETOR DE ASSASSINADOS
 *
 * J?? NA LINHA 86, N??S VAMOS PERCORRENDO CADA POSI????O DOS ASSASSINOS E FAZEMOS O SEGUINTE: SE O ASSASSINO ATUAL ESTIVER NO VETOR DE ASSASSINADOS (ESSA VERFICA????O ?? FEITA
 * COM A FUN????O assassino_cadastrado(), QUE RECEBE UM NOME E RETORNA 1 CASO ESSE NOME ESTEJA NO VETOR DE ASSASSINADOS E 0 CASO CONTR??RIO), SE ELE ESTIVER, SIGNIFICA
 * QUE ELE FOI MORTO, PORTANTO N??O EXIBIMOS SEU NOME. SE ELE N??O ESTIVER, EXIBIMOS SEU NOME, SEGUIDO DA QUANTIDADE DE ASSASSINATOS PRATICADOS POR ELE, QUE EST??
 * ARMAZENADA NO CAMPO 'PARTICIPA????O'
 *
 */
