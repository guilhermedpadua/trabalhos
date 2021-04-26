#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

char* nome_disciplina(int i)
{
    switch(i){
    case 0:
        return "Portugues";
    case 1:
        return "Matematica";
    case 2:
        return "Fisica";
    case 3:
        return "Historia";
    case 4:
        return "Geografia";
    case 5:
        return "Artes";
    }
}

int main()
{
    aluno **turma = cria_turma();
    aluno **aluno_exibe = malloc(sizeof(aluno*));
    *aluno_exibe = NULL;
    int opcao_1, opcao_2, opcao_3, opcao_4;
    char opcao_melhor_media;
    do{
        system("cls");
        printf("=============================================================\n");
        printf("[1] - INSERIR ALUNO                                          \n");
        printf("[2] - REMOVER ALUNO                                          \n");
        printf("[3] - LISTAR ALUNOS                                          \n");
        printf("[4] - BUSCAR ALUNO                                           \n");
        printf("[5] - ALTERAR                                                \n");
        printf("[6] - PERCENTUAL DE APROVADOS, REPROVADOS E DEPENDENCIA      \n");
        printf("[7] - DADOS DO(A) ALUNO(A) COM MELHOR MEDIA                  \n");
        printf("[8] - SAIR                                                   \n");
        printf("==============================================================\n");
        printf(">> ");
        scanf("%d", &opcao_1);
        setbuf(stdin, NULL);
        char nome[100];
        int matricula;
        disc disciplinas[6];
        struct aluno *novo_aluno = NULL;

        switch(opcao_1){
        case 1:
            printf("Digite o nome do aluno: ");
            scanf("%[^\n]s", nome);
            printf("Digite a matricula do aluno: ");
            scanf("%d", &matricula);
            setbuf(stdin, NULL);
            if(!(matricula >= 1000 && matricula <= 9999)){
                while(!(matricula >= 1000 && matricula <= 9999)){
                    printf("A matricula digitada e invalida! Digite novamente: ");
                    scanf("%d", &matricula);
                    setbuf(stdin, NULL);
                }
            }
            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 3; j++){
                    printf("Digite a nota %d para a disciplina %s: ", j + 1, nome_disciplina(i));
                    scanf("%f", &disciplinas[i].notas[j]);
                    setbuf(stdin, NULL);
                    if(disciplinas[i].notas[j] < 0 || disciplinas[i].notas[j] > 10){
                        while(disciplinas[i].notas[j] < 0 || disciplinas[i].notas[j] > 10){
                            printf("Nota invalida! Digite a nota %d para a disciplina %s: ", j + 1, nome_disciplina(i));
                            scanf("%f", &disciplinas[i].notas[j]);
                            setbuf(stdin, NULL);
                        }
                    }
                }
                printf("Digite a quantidade de faltas: ");
                scanf("%d", &disciplinas[i].faltas);
                printf("\n");
                setbuf(stdin, NULL);
                disciplinas[i].media = (disciplinas[i].notas[0] + disciplinas[i].notas[1] + disciplinas[i].notas[2])/3.0;
            }
            novo_aluno = cria_aluno(nome, matricula, disciplinas[0], disciplinas[1], disciplinas[2], disciplinas[3], disciplinas[4], disciplinas[5]);
            if(buscar_aluno(matricula, aluno_exibe, turma)){
                printf("A MATRICULA INSERIDA JA PERTENCE A UM ALUNO CADASTRADO, POR ISSO NAO FOI POSSIVEL REALIZAR O CADASTRO.\n");
            }else{
                insere_aluno(novo_aluno, turma);
                printf("ALUNO CADASTRADO COM SUCESSO!\n");
            }
            printf("Pressione qualquer tecla para continuar...\n");
            getchar();
            setbuf(stdin, NULL);
            break;
        case 2:
            if(*turma == NULL){
                printf("TURMA VAZIA!\n");
            }else{
                printf("Digite a matricula do aluno a ser removido: ");
                scanf("%d", &matricula);
                setbuf(stdin, NULL);
                if(remover_aluno(matricula, turma)){
                    printf("Aluno removido com sucesso!\n");
                }else{
                    printf("Matricula inexistente!\n");
                }
            }
            printf("Pressione qualquer tecla para continuar...\n");
            getchar();
            setbuf(stdin, NULL);
            break;
        case 3:
            if(*turma == NULL){
                printf("TURMA VAZIA!\n");
            }else{
                listar(*turma);
            }
            printf("Pressione qualquer tecla para continuar...\n");
            getchar();
            setbuf(stdin, NULL);
            break;
        case 4:
            if(*turma == NULL){
                printf("\tTURMA VAZIA!\n");
                printf("\tPressione qualquer tecla para continuar...\n");
                getchar();
                setbuf(stdin, NULL);
            }else{
                printf("Dite a matricula do aluno: ");
                scanf("%d", &matricula);
                setbuf(stdin, NULL);
                if(buscar_aluno(matricula, aluno_exibe, turma)){
                    exibe_dados(*aluno_exibe);
                }else{
                    printf("\tALUNO NAO ENCONTRADO!\n");
                }
                printf("\tPressione qualquer tecla para continuar...\n");
                getchar();
                setbuf(stdin, NULL);
            }
            break;
        case 5:
            if(*turma == NULL){
                printf("\tTURMA VAZIA!\n");
                printf("\tPressione qualquer tecla para continuar...\n");
                getchar();
                setbuf(stdin, NULL);
            }else{
                printf("Digite a matricula do aluno cujas informacoes serao alteradas: ");
                scanf("%d", &matricula);
                setbuf(stdin, NULL);
                if(buscar_aluno(matricula, aluno_exibe, turma) == 0){
                    printf("\n\tMATRICULA INEXISTENTE!\n");
                    printf("\tPressione qualquer tecla para continuar...\n");
                    getchar();
                    setbuf(stdin, NULL);
                }else{
                    system("cls");
                    printf("===========================\n");
                    printf("O QUE VOCE DESEJA ALTERAR? \n");
                    printf("---------------------------\n");
                    printf("[1] - NOME                 \n");
                    printf("[2] - NOTA (uma das tres)  \n");
                    printf("[3] - FREQUENCIA           \n");
                    printf("[0] - CANCELAR             \n");
                    printf("===========================\n");
                    printf(">> ");
                    scanf("%d", &opcao_2);
                    setbuf(stdin, NULL);
                    switch(opcao_2){
                    case 1:
                        printf("Digite o novo nome: ");
                        scanf("%[^\n]s", nome);
                        setbuf(stdin, NULL);
                        strcpy((*aluno_exibe)->nome, nome);
                        printf("Alteracao realizada com sucesso!\nPressione qualquer tecla para continuar...\n");
                        atualiza_situacao_aluno(*aluno_exibe);
                        getchar();
                        setbuf(stdin, NULL);
                        break;
                    case 2:
                        printf("EM QUAL DAS DISCIPLINAS VOCE DESEJA ALTERAR A NOTA?\n");
                        for(int i = 0; i < 6; i++){
                            printf("[%d] - %s\n", i + 1, nome_disciplina(i));
                        }
                        printf("\n>> ");
                        scanf("%d", &opcao_3);
                        setbuf(stdin, NULL);
                        switch(opcao_3-1){
                        case 0:
                            printf("Qual das 3 de %s notas voce deseja alterar?\n[1] - 1\n[2] - 2\n[3] - 3\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &opcao_4);
                            setbuf(stdin, NULL);
                            printf("Digite a nova nota: ");
                            scanf("%f", &(*aluno_exibe)->portugues.notas[opcao_4-1]);
                            setbuf(stdin, NULL);
                            break;
                        case 1:
                            printf("Qual das 3 de %s notas voce deseja alterar?\n[1] - 1\n[2] - 2\n[3] - 3\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &opcao_4);
                            setbuf(stdin, NULL);
                            printf("Digite a nova nota: ");
                            scanf("%f", &(*aluno_exibe)->matematica.notas[opcao_4-1]);
                            setbuf(stdin, NULL);
                            break;
                        case 2:
                            printf("Qual das 3 de %s notas voce deseja alterar?\n[1] - 1\n[2] - 2\n[3] - 3\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &opcao_4);
                            setbuf(stdin, NULL);
                            printf("Digite a nova nota: ");
                            scanf("%f", &(*aluno_exibe)->fisica.notas[opcao_4-1]);
                            setbuf(stdin, NULL);
                            break;
                        case 3:
                            printf("Qual das 3 de %s notas voce deseja alterar?\n[1] - 1\n[2] - 2\n[3] - 3\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &opcao_4);
                            setbuf(stdin, NULL);
                            printf("Digite a nova nota: ");
                            scanf("%f", &(*aluno_exibe)->historia.notas[opcao_4-1]);
                            setbuf(stdin, NULL);
                            break;
                        case 4:
                            printf("Qual das 3 de %s notas voce deseja alterar?\n[1] - 1\n[2] - 2\n[3] - 3\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &opcao_4);
                            setbuf(stdin, NULL);
                            printf("Digite a nova nota: ");
                            scanf("%f", &(*aluno_exibe)->geografia.notas[opcao_4-1]);
                            setbuf(stdin, NULL);
                            break;
                        case 5:
                            printf("Qual das 3 de %s notas voce deseja alterar?\n[1] - 1\n[2] - 2\n[3] - 3\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &opcao_4);
                            setbuf(stdin, NULL);
                            printf("Digite a nova nota: ");
                            scanf("%f", &(*aluno_exibe)->artes.notas[opcao_4-1]);
                            setbuf(stdin, NULL);
                            break;
                        }
                        atualiza_situacao_aluno(*aluno_exibe);
                        printf("\nAlteracao realizada com sucesso!\nPressione qualquer tecla para continuar...");
                        getchar();
                        setbuf(stdin, NULL);
                        break;
                    case 3:
                        printf("EM QUAL DAS DISCIPLINAS VOCE DESEJA ALTERAR A FREQUENCIA?\n");
                        for(int i = 0; i < 6; i++){
                            printf("[%d] - %s\n", i + 1, nome_disciplina(i));
                        }
                        printf("\n>> ");
                        scanf("%d", &opcao_3);
                        setbuf(stdin, NULL);
                        switch(opcao_3-1){
                        case 0:
                            printf("Digite o novo numero de faltas para a disciplina %s\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &(*aluno_exibe)->portugues.faltas);
                            setbuf(stdin, NULL);
                            break;
                        case 1:
                            printf("Digite o novo numero de faltas para a disciplina %s\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &(*aluno_exibe)->matematica.faltas);
                            setbuf(stdin, NULL);
                            break;
                        case 2:
                            printf("Digite o novo numero de faltas para a disciplina %s\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &(*aluno_exibe)->fisica.faltas);
                            setbuf(stdin, NULL);
                            break;
                        case 3:
                            printf("Digite o novo numero de faltas para a disciplina %s\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &(*aluno_exibe)->historia.faltas);
                            setbuf(stdin, NULL);
                            break;
                        case 4:
                            printf("Digite o novo numero de faltas para a disciplina %s\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &(*aluno_exibe)->geografia.faltas);
                            setbuf(stdin, NULL);
                            break;
                        case 5:
                            printf("Digite o novo numero de faltas para a disciplina %s\n>> ", nome_disciplina(opcao_3-1));
                            scanf("%d", &(*aluno_exibe)->artes.faltas);
                            setbuf(stdin, NULL);
                            break;
                        }
                        atualiza_situacao_aluno(*aluno_exibe);
                        printf("\nAlteracao realizada com sucesso!\nPressione qualquer tecla para continuar...");
                        getchar();
                        setbuf(stdin, NULL);
                        break;
                    }
                }
            }
            break;
        case 6:
            if(total_alunos(turma) > 0){
                exibe_situacao(turma);
                printf("Pressione qualquer tecla para continuar...\n");
            }else{
                printf("\tTurma vazia!! Pressione qualquer tecla para continuar....\n");
            }
            getchar();
            setbuf(stdin, NULL);
            break;
        case 7:
            if(total_alunos(turma) > 0){
                system("cls");
                printf("=============================\n");
                printf("       MELHOR MEDIA EM?      \n");
                printf("-----------------------------\n");
                printf("[M] - Matematica             \n");
                printf("[P] - Portugues              \n");
                printf("[F] - Fisica                 \n");
                printf("=============================\n");
                printf(">> ");
                scanf("%c", &opcao_melhor_media);
                setbuf(stdin, NULL);
                switch(opcao_melhor_media){
                case 'M':
                    exibe_dados(aluno_melhor_media_em('M', turma));
                    printf("\nPressione qualquer tecla para continuar...\n");
                    getchar();
                    setbuf(stdin, NULL);
                    break;
                case 'P':
                    exibe_dados(aluno_melhor_media_em('P', turma));
                    printf("\nPressione qualquer tecla para continuar...\n");
                    getchar();
                    setbuf(stdin, NULL);
                    break;
                case 'F':
                    exibe_dados(aluno_melhor_media_em('F', turma));
                    printf("\nPressione qualquer tecla para continuar...\n");
                    getchar();
                    setbuf(stdin, NULL);
                    break;
                default:
                    printf("\tOPCAO INVALIDA!\n\tPressione qualquer tecla para continuar....\n");
                    getchar();
                    setbuf(stdin, NULL);
                }
            }else{
                printf("\tTURMA VAZIA!\n\tPressione qualquer tecla para continuar....\n");
                getchar();
                setbuf(stdin, NULL);
            }
            break;
        }
    }while(opcao_1 != 8);
    return 0;
}
