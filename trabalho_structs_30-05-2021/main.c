#include <stdio.h>
#include <stdlib.h>

struct disciplina{
    int codigo;
    char nome[60];
    int creditos;
};

typedef struct disciplina Disciplina;

struct disciplina_cursada{
    int codigo_disciplina_cursada;
    int ano;
    int semestre;
    float media_final;
};

typedef struct disciplina_cursada Disciplina_cursada;


void exibe_historico(int tot_disciplinas_cursadas, Disciplina_cursada disciplinas_cursadas[], Disciplina disciplinas[], int tot_disciplinas)
{
    int i, j, soma_pesos = 0;
    float soma_medias = 0;

    for(i = 0; i < tot_disciplinas_cursadas; i++){
        for(j = 0; j < tot_disciplinas; j++){
            if(disciplinas_cursadas[i].codigo_disciplina_cursada == disciplinas[j].codigo){
                printf("%s (%d) %.1f\n", disciplinas[j].nome, disciplinas[j].codigo, disciplinas_cursadas[i].media_final);
                soma_pesos += disciplinas[j].creditos;
                soma_medias += disciplinas_cursadas[i].media_final * disciplinas[j].creditos;
            }
        }
    }
    printf("\nCOEFICIENTE DE RENDIMENTO: %.3f\n", soma_medias/soma_pesos);
}

int main()
{

    int total_disciplinas_cursadas = 6;
    int total_disciplinas_cadastradas = 5;

    /*
     * PRIMEIRO, VAMOS CADASTRAR AS DISCIPLINAS. PARA ESSE EXEMPLO, CADASTRAREMOS APENAS 5.
     * ELES FICARÃO EM UM VETOR DE STRUCTS DO TIPO DISCIPLINA.
     */

    Disciplina disciplinas[5];

    //Disciplina 1
    disciplinas[0].codigo = 1;
    strcpy(disciplinas[0].nome, "Arquitetura de Computadores");
    disciplinas[0].creditos = 4;

    //Disciplina 2
    disciplinas[1].codigo = 2;
    strcpy(disciplinas[1].nome, "Etica e Cidadania");
    disciplinas[1].creditos = 2.;

    //Disciplina 3
    disciplinas[2].codigo = 3;
    strcpy(disciplinas[2].nome, "Calculo Integral e Diferencial I");
    disciplinas[2].creditos = 7;

    //Disciplina 4
    disciplinas[3].codigo = 4;
    strcpy(disciplinas[3].nome, "Geometria Analitica");
    disciplinas[3].creditos = 6;

    //Disciplina 5
    disciplinas[4].codigo = 5;
    strcpy(disciplinas[4].nome, "Introducao a Programacao");
    disciplinas[4].creditos = 6;

    /*
     * Agora, usaremos um vetor para simular o histórico do aluno. Cada posição desse vetor possui um struct do tipo
     * Disciplina_cursada, que armazena a informação da disciplina cursada, ano e semestre em que foi cursada e a
     * a média do aluno. Aqui, cadastraremos duas disciplinas repetidas, para indiciar uma reprovação.
     */

    Disciplina_cursada disciplinas_cursadas[6];

    //Etica e cidadania
    disciplinas_cursadas[0].codigo_disciplina_cursada = 2;
    disciplinas_cursadas[0].ano = 2019;
    disciplinas_cursadas[0].semestre = 1;
    disciplinas_cursadas[0].media_final = 7;


    //Arquitetura de Computadores
    disciplinas_cursadas[1].codigo_disciplina_cursada = 1;
    disciplinas_cursadas[1].ano = 2019;
    disciplinas_cursadas[1].semestre = 1;
    disciplinas_cursadas[1].media_final = 8;


    //Calculo Integral e Diferencial
    disciplinas_cursadas[2].codigo_disciplina_cursada = 3;
    disciplinas_cursadas[2].ano = 2019;
    disciplinas_cursadas[2].semestre = 1;
    disciplinas_cursadas[2].media_final = 8;


    //Geometria Analitica
    disciplinas_cursadas[3].codigo_disciplina_cursada = 4;
    disciplinas_cursadas[3].ano = 2019;
    disciplinas_cursadas[3].semestre = 1;
    disciplinas_cursadas[3].media_final = 9;


    //Introducao à Programação (reprovação)
    disciplinas_cursadas[4].codigo_disciplina_cursada = 5;
    disciplinas_cursadas[4].ano = 2019;
    disciplinas_cursadas[4].semestre = 1;
    disciplinas_cursadas[4].media_final = 3.5;



    //Introducao à Programação (2ª vez)
    disciplinas_cursadas[5].codigo_disciplina_cursada = 5;
    disciplinas_cursadas[5].ano = 2019;
    disciplinas_cursadas[5].semestre = 2;
    disciplinas_cursadas[5].media_final = 9.7;


    exibe_historico(total_disciplinas_cursadas, disciplinas_cursadas, disciplinas, total_disciplinas_cadastradas);

    return 0;
}
