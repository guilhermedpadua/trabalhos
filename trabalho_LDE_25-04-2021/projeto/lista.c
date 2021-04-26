#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


aluno** cria_turma()
{
    aluno** nova_turma = (aluno**) malloc(sizeof(aluno*));
    if(nova_turma != NULL)
        *nova_turma = NULL;
    return nova_turma;
}


void atualiza_situacao_aluno(aluno *aluno)
{
        aluno->portugues.media = (aluno->portugues.notas[0] + aluno->portugues.notas[1] +  aluno->portugues.notas[2])/3.0;
        aluno->matematica.media = (aluno->matematica.notas[0] + aluno->matematica.notas[1] +  aluno->matematica.notas[2])/3.0;
        aluno->fisica.media = (aluno->fisica.notas[0] + aluno->fisica.notas[1] +  aluno->fisica.notas[2])/3.0;
        aluno->historia.media = (aluno->historia.notas[0] + aluno->historia.notas[1] +  aluno->historia.notas[2])/3.0;
        aluno->geografia.media = (aluno->geografia.notas[0] + aluno->geografia.notas[1] +  aluno->geografia.notas[2])/3.0;
        aluno->artes.media = (aluno->artes.notas[0] + aluno->artes.notas[1] +  aluno->artes.notas[2])/3.0;

        float medias_disciplinas[6] = {aluno->portugues.media, aluno->matematica.media, aluno->fisica.media, aluno->geografia.media, aluno->historia.media, aluno->artes.media};
        float percentual_ausencia_disciplinas[6] = {(aluno->portugues.faltas/30.0)*100, (aluno->matematica.faltas/30.0)*100, (aluno->fisica.faltas/30.0)*100, (aluno->geografia.faltas/30.0)*100, (aluno->historia.faltas/30.0)*100, (aluno->artes.faltas/30.0)*100};
        int media_menor_que_6 = 0;
        int percentual_ausencia_maior_que_25 = 0;
        int percentual_ausencia_igual_a_25 = 0;
        for(int i = 0; i < 6; i++){
            if(medias_disciplinas[i] < 6){
                media_menor_que_6++;
            }
        }
        for(int i = 0; i < 6; i++){
            if(percentual_ausencia_disciplinas[i] > 25){
                percentual_ausencia_maior_que_25++;
            }else if(percentual_ausencia_disciplinas[i] == 25){
                percentual_ausencia_igual_a_25++;
            }
        }
        if(media_menor_que_6 == 0){
            strcpy(aluno->situacao, "APROVADO");
        }else{
            if(media_menor_que_6 >= 2 || percentual_ausencia_maior_que_25 == 3){
                strcpy(aluno->situacao, "REPROVADO");
            }else if(media_menor_que_6 == 1 || percentual_ausencia_igual_a_25 == 1){
                strcpy(aluno->situacao, "DEPENDENCIA");
            }
        }
}

aluno* cria_aluno(char nome[100], int matricula, disc prt, disc mtm, disc fis, disc hst, disc ggf, disc art)
{
    aluno *aluno_criado = (aluno*) malloc(sizeof(aluno));
    if(aluno_criado != NULL){
        strcpy(aluno_criado->nome, nome);
        aluno_criado->matricula = matricula;
        aluno_criado->portugues = prt;
        aluno_criado->matematica = mtm;
        aluno_criado->fisica = fis;
        aluno_criado->geografia = ggf;
        aluno_criado->historia = hst;
        aluno_criado->artes = art;
        aluno_criado->proximo = NULL;
        aluno_criado->anterior = NULL;

        //definindo a situação do aluno
        atualiza_situacao_aluno(aluno_criado);
    }
    return aluno_criado;
}

int insere_aluno(aluno *novo_aluno, aluno **turma)
{
    //é o único elemento (quando a turma está vazia)
    if((*turma) == NULL){
        *turma = novo_aluno;
        return 1;
    }
    aluno *p = *turma;
    while(novo_aluno->matricula > p->matricula && p->proximo != NULL){
        p = p->proximo;
    }

    if(p->matricula < novo_aluno->matricula){
        //insere à direita
        if(p->proximo == NULL){
            //é o último
            p->proximo = novo_aluno;
            novo_aluno->anterior = p;
            novo_aluno->proximo = NULL;
        }else{
            //é intermediário
            struct aluno *prox = p->proximo;
            p->proximo = novo_aluno;
            novo_aluno->anterior = p;
            novo_aluno->proximo = prox;
            prox->anterior = novo_aluno;
        }
    }else{
        //insere à esquerda
        if(p->anterior == NULL){
            //é o primeiro
            novo_aluno->proximo = p;
            p->anterior = novo_aluno;
            novo_aluno->anterior = NULL;
            *turma = novo_aluno;
        }else{
            //é intermediário
            struct aluno *ant = p->anterior;

            ant->proximo = novo_aluno;
            novo_aluno->proximo = p;
            p->anterior = novo_aluno;
            novo_aluno->anterior = ant;
        }
    }
    return 1;
}

void listar(aluno *al)
{
    if(al == NULL){
        return;
    }else{
        exibe_dados(al);
        listar(al->proximo);
    }
}


void exibe_dados(aluno *al)
{
    printf("==============================================================================\n");
    printf("NOME: %s                                                             \n",al->nome);
    printf("MATRICULA: %d                                                  \n",al->matricula );
    printf("------------------------------------------------------------------------------\n");
    printf("PORTUGUES: NOTA1: %.1f, NOTA2: %.1f, NOTA3: %.1f, MEDIA: %.1f, FALTAS: %d\n", al->portugues.notas[0], al->portugues.notas[1], al->portugues.notas[2], al->portugues.media, al->portugues.faltas);
    printf("MATEMATICA: NOTA1: %.1f, NOTA2: %.1f, NOTA3: %.1f, MEDIA: %.1f, FALTAS: %d\n", al->matematica.notas[0], al->matematica.notas[1], al->matematica.notas[2], al->matematica.media, al->matematica.faltas);
    printf("FISICA: NOTA1: %.1f, NOTA2: %.1f, NOTA3: %.1f, MEDIA: %.1f, FALTAS: %d\n", al->fisica.notas[0], al->fisica.notas[1], al->fisica.notas[2], al->fisica.media, al->fisica.faltas);
    printf("HISTORIA: NOTA1: %.1f, NOTA2: %.1f, NOTA3: %.1f, MEDIA: %.1f, FALTAS: %d\n", al->historia.notas[0], al->historia.notas[1], al->historia.notas[2], al->historia.media, al->historia.faltas);
    printf("GEOGRAFIA: NOTA1: %.1f, NOTA2: %.1f, NOTA3: %.1f, MEDIA: %.1f, FALTAS: %d\n", al->geografia.notas[0], al->geografia.notas[1], al->geografia.notas[2], al->geografia.media, al->geografia.faltas);
    printf("ARTES: NOTA1: %.1f, NOTA2: %.1f, NOTA3: %.1f, MEDIA: %.1f, FALTAS: %d\n", al->artes.notas[0], al->artes.notas[1], al->artes.notas[2], al->artes.media, al->artes.faltas);
    printf("SITUACAO: [%s]\n", al->situacao);
    printf("==============================================================================\n\n");
}

int remover_aluno(int matr, aluno **turma)
{

    if((*turma) == NULL)
        return 0;

    struct aluno *r, *q, *p = *turma;

    int existe = 0;
    while(p != NULL){
        if(p->matricula == matr){
            existe = 1;
            break;
        }
        p = p->proximo;
    }
    if(existe){
        //primeiro elemento
        if(p->anterior == NULL){
            *turma = p->proximo;
            if(p->proximo != NULL)
                (p->proximo)->anterior = NULL;
            free(p);
            return 1;
        }

        //ultimo elemento com lista de comprimento > 1
        if(p->proximo == NULL){
            (p->anterior)->proximo = NULL;
            free(p);
            return 1;
        }

        //elemento intermediario
        if(p->proximo != NULL && p->anterior != NULL){
            r = p->anterior;
            q = p->proximo;
            r->proximo = q;
            q->anterior = r;
            free(p);
        }
        return 1;
    }else{
        return 0;
    }
}



int buscar_aluno(int matr, aluno **al, aluno **turma)
{
    if((*turma) == NULL)
        return 0;

    struct aluno *p = *turma;

    int existe = 0;
    while(p != NULL){
        if(p->matricula == matr){
            existe = 1;
            break;
        }
        p = p->proximo;
    }
    if(existe){
        *al = p;
        return 1;
    }else{
        *al = NULL;
        return 0;
    }
}


int total_alunos(aluno **turma)
{
    if(*turma == NULL)
        return 0;
    aluno *p = *turma;
    int total = 0;
    do{
        total++;
        p =  p->proximo;
    }while(p != NULL);
    return total;
}


aluno* aluno_melhor_media_em(char disciplina, aluno **turma)
{


    if(total_alunos(turma) == 1){
        return *turma;
    }

    char criterio;
    float melhor_media;
    struct aluno *al = *turma;
    struct aluno *aluno_melhor_media = *turma;

    switch(disciplina){
    case 'M':
        criterio = 'M';
        melhor_media = (*turma)->matematica.media;
        break;
    case 'P':
        criterio = 'P';
        melhor_media = (*turma)->portugues.media;
        break;
    case 'F':
        melhor_media = (*turma)->fisica.media;
        criterio = 'F';
        break;
    }

    while(1){
        if(criterio == 'M'){
            if(al->matematica.media > melhor_media){
                melhor_media = al->matematica.media;
                aluno_melhor_media = al;
            }
        }else if(criterio == 'P'){
            if(al->portugues.media > melhor_media){
                melhor_media = al->portugues.media;
                aluno_melhor_media = al;
            }
        }else if(criterio == 'F'){
            if(al->fisica.media > melhor_media){
                melhor_media = al->fisica.media;
                aluno_melhor_media = al;
            }
        }
        al = al->proximo;
        if(al == NULL)
            break;
    }
    return aluno_melhor_media;
}


void exibe_situacao(struct aluno **turma)
{
    int reprovados = 0;
    int aprovados = 0;
    int dependencia = 0;

    struct aluno *al = *turma;
    while(al != NULL){
        if(strcmp(al->situacao, "APROVADO") == 0){
            aprovados++;
        }else if(strcmp(al->situacao, "REPROVADO") == 0){
            reprovados++;
        }else if(strcmp(al->situacao, "DEPENDENCIA") == 0){
            dependencia++;
        }
        al = al->proximo;
    }
    printf("\nAPROVADOS: %.2f%%\n", (aprovados/(float)total_alunos(turma))*100);
    printf("REPROVADOS: %.2f%%\n", (reprovados/(float)total_alunos(turma))*100);
    printf("EM DEPENDENCIA: %.2f%%\n\n", (dependencia/(float)total_alunos(turma))*100);
}
