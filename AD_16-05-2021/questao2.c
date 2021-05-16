#include <stdio.h>
#include <stdlib.h>


int soma_impares(int *vet, int comprimento)
{
  int soma_impares = 0, i;
  for(i = 0; i < comprimento; i++)
    if(vet[i] % 2 == 1)
      soma_impares += vet[i];
  return soma_impares;
}


int main(void) {
  int tamanho_vetor, i;
  printf("Qual o tamanho do vetor? ");
  scanf("%d", &tamanho_vetor);
  int *vetor = malloc(sizeof(int) * tamanho_vetor);
  for(i = 0; i < tamanho_vetor; i++){
    printf("Digite o elemento numero %d: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  printf("\n\nVETOR LIDO\n");
  for(i = 0; i < tamanho_vetor; i++){
    (i+1 == tamanho_vetor)? printf("%d.\n", vetor[i]) : printf("%d, ", vetor[i]);
  }

  printf("\nSOMA DOS NUMEROS IMPARES: %d.\n", soma_impares(vetor, tamanho_vetor));

  free(vetor);
  return 0;
}