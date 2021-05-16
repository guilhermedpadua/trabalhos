#include <stdio.h>
#include <stdlib.h>

struct aluno{
  char nome[30];
  float media;
  int faltas;
};

int main(void) {
  int quantidade_alunos, i, j;
  printf("Quantos alunos serao cadastrados? ");
  scanf("%d", &quantidade_alunos);
  setbuf(stdin, NULL);
  struct aluno *alunos = malloc(sizeof(struct aluno) * quantidade_alunos);

  for(i = 0; i < quantidade_alunos; i++){
    printf("Digite o nome do aluno %d: ", i + 1);
    scanf("%[^\n]s", alunos[i].nome);
    setbuf(stdin, NULL);
    printf("Digite a media do aluno %d: ", i + 1);
    scanf("%f", &alunos[i].media);
    setbuf(stdin, NULL);
    printf("Digite quantidade de faltas do aluno %d: ", i + 1);
    scanf("%d", &alunos[i].faltas);
    setbuf(stdin, NULL);
  }

  //ordenando as informações com o algoritmo bubble sort
  for(i = 0; i < quantidade_alunos - 1; i++){
    for(j = i + 1; j < quantidade_alunos; j++){
      struct aluno auxiliar;
      if(alunos[i].media < alunos[j].media){
        auxiliar = alunos[i];
        alunos[i] = alunos[j];
        alunos[j] = auxiliar;
      }
    }
  }

  //exibindo as informações
  for(i = 0; i < quantidade_alunos; i++){
    printf("ALUNO %d\n", i + 1);
    printf("NOME: %s\n", alunos[i].nome);
    printf("MEDIA: %.1f\n", alunos[i].media);
    printf("FALTAS: %d\n", alunos[i].faltas);
    printf("---------------------------\n");
  }
  return 0;
}