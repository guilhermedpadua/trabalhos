#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N, idade, i, menor_idade, maior_idade;
    char nome[100], nome_mais_jovem[100], nome_mais_idoso[100];
    scanf("%d", &N);
    setbuf(stdin, NULL);

    for(i = 0; i < N; i++){
        printf("NOME: ");
        gets(nome);
        setbuf(stdin, NULL);
        printf("IDADE: ");
        scanf("%d", &idade);
        setbuf(stdin, NULL);
        if(i == 0){
            maior_idade = idade;
            menor_idade = idade;
        }
        if(idade > maior_idade){
            maior_idade = idade;
            strcpy(nome_mais_idoso, nome);
        }
        if(idade < menor_idade){
            menor_idade = idade;
            strcpy(nome_mais_jovem, nome);
        }
    }

    printf("PESSOA MAIS JOVEM: %s\nIDADE: %d\n\n", nome_mais_jovem, menor_idade);
    printf("PESSOA MAIS IDOSA: %s\nIDADE: %d\n\n", nome_mais_idoso, maior_idade);
    return 0;
}

