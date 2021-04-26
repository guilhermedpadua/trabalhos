#include <stdlib.h>

struct disciplina{
    float notas[3];
    unsigned int faltas;
    float media;
};

typedef struct disciplina disc;

struct aluno{
    char nome[100];
    int matricula;
    disc portugues;
    disc matematica;
    disc fisica;
    disc historia;
    disc geografia;
    disc artes;
    char situacao[11];
    struct aluno *anterior, *proximo;
};

typedef struct aluno aluno;

aluno** cria_turma();
aluno* cria_aluno(char nome[100], int matricula, disc prt, disc mtm, disc fis, disc hst, disc ggf, disc art);
int insere_aluno(aluno *novo_aluno, aluno **turma);
void listar(aluno *primeiro_aluno);
int remover_aluno(int matricula, aluno **turma);
int buscar_aluno(int matricula, aluno **al, aluno **turma);
int total_alunos(aluno **turma);
aluno* aluno_melhor_media_em(char disciplina, aluno **turma);
void atualiza_situacao_aluno(aluno *aluno);
void exibe_situacao(struct aluno **turma);
