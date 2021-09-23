#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[100];
    char matricula[20];
    float notas[4];
}Aluno;

void limpa_buffer()
{
    char c = getchar();
    while(c != '\n'){
        c = getchar();
    }
}

void lista_alunos(Aluno* alunos, int total)
{
    printf("<<<<%d>>>\n", total);
    int i, j;
    for(i = 0; i < total; i++){
        printf("-----------------------------------------\n");
        printf("NOME: %s\n", alunos[i].nome);
        printf("MATRICULA: %s\n", alunos[i].matricula);
        for(j = 0; j < 4; j++){
            printf("NOTA %d: %.2f\n", j+1, alunos[i].notas[j]);
        }
        printf("=========================================\n");
    }
}

int remove_aluno(Aluno* alunos, int* total_alunos, char* matricula)
{

    int posicao = -1;
    for(int i = 0; i < (*total_alunos); i++){
        if(strcmp(alunos[i].matricula, matricula) == 0){
            posicao = i;
            break;
        }
    }
    if(posicao == -1){
        return 0;
    }
    for(int i = posicao; i < (*total_alunos); i++){
        alunos[i] = alunos[i + 1];
    }
    realloc(alunos, sizeof(Aluno) * (--(*total_alunos)));
    return 1;
}

Aluno* busca_aluno(Aluno* alunos, int total_alunos, char* matricula)
{
    for(int i = 0; i < total_alunos; i++){
        if(strcmp(alunos[i].matricula, matricula) == 0){
            return &alunos[i];
        }
    }
    return NULL;
}

int main()
{

    Aluno *alunos = NULL, *aluno_resultado = NULL;
    int opcao, total_alunos = 0;
    char nome_aluno[100], matricula_aluno[20];
    float notas[4];
    do{
        printf("=========================================\n");
        printf("[1] - Cadastrar aluno.                   \n");
        printf("[2] - Listar alunos.                     \n");
        printf("[3] - Remover aluno.                     \n");
        printf("[4] - Pesquisar aluno.                   \n");
        printf("[0] - Sair.                              \n");
        printf("=========================================\n");
        printf(">> ");
        scanf("%d", &opcao);
        limpa_buffer();
        switch(opcao){
            case 1:
                printf("Digite o nome do aluno: ");
                scanf("%[^\n]s", nome_aluno);
                limpa_buffer();
                printf("Digite a matricula do aluno: ");
                scanf("%[^\n]s", matricula_aluno);
                limpa_buffer();
                printf("Digite as 4 notas do aluno separadas por espaco: ");
                scanf("%f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3]);
                limpa_buffer();
                alunos = realloc(alunos, sizeof(Aluno) * (++total_alunos));
                if(alunos == NULL){
                    printf("Erro ao cadastrar aluno1!\n");
                    break;
                }
                strcpy(alunos[total_alunos - 1].nome, nome_aluno);
                strcpy(alunos[total_alunos - 1].matricula, matricula_aluno);
                alunos[total_alunos - 1].notas[0] = notas[0];
                alunos[total_alunos - 1].notas[1] = notas[1];
                alunos[total_alunos - 1].notas[2] = notas[2];
                alunos[total_alunos - 1].notas[3] = notas[3];
                printf("Aluno cadastrado!\n");
            break;
            case 2:
                if(total_alunos == 0){
                    printf("Sem alunos cadastrados!\n\n\n");
                }else{
                    lista_alunos(alunos, total_alunos);
                }
            break;
            case 3:
                if(total_alunos == 0){
                    printf("Nao ha alunos cadastrados!\n");
                }else{
                    printf("Digite a matricula do aluno a ser removido: ");
                    scanf("%[^\n]s", matricula_aluno);
                    limpa_buffer();
                    if(remove_aluno(alunos, &total_alunos, matricula_aluno) == 1){
                        printf("Aluno removido!\n");
                    }else{
                        printf("O aluno nao existe ou houve um erro ao tentar remove-lo.\n");
                    }
                }
            break;
            case 4:
                if(total_alunos == 0){
                    printf("Nao ha alunos cadastrados!\n");
                }else{
                    printf("Digite a matricula do aluno: ");
                    scanf("%[^\n]s\n", matricula_aluno);
                    limpa_buffer();
                    aluno_resultado = busca_aluno(alunos, total_alunos, matricula_aluno);
                    if(aluno_resultado != NULL){
                        printf("-------------------------------\n");
                        printf("NOME: %s\n", aluno_resultado->nome);
                        printf("MATRICULA: %s\n", aluno_resultado->matricula);
                        printf("NOTAS: ");
                        for(int j = 0; j < 4; j++)
                            printf("%.2f ", aluno_resultado->notas[j]);
                        printf("\n--------------------------------\n\n");
                    }else{
                        printf("Aluno nao encontrado!\n");
                    }
                }
            break;
            case 0:
                printf("saindo...\n");
            break;
            default:
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);


    return 0;
}
