#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ano_nascimento, procedencia, total_motoristas = 0;
    int motorista_menor_de_21 = 0, mulheres_capital = 0;
    int motorista_interior_idade_maior_que_60 = 0, mulher_maior_de_60 = 0;
    int ano_atual = 2021, opcao;
    char sexo;

    do{
        printf("\n\nDigite o ano de nascimento do(a) motorista: ");
        scanf("%d", &ano_nascimento);
        setbuf(stdin, NULL);
        printf("Digite o sexo do(a) motorista [M/F]: ");
        scanf("%c", &sexo);
        setbuf(stdin, NULL);
        printf("Digite a procedencia do(a) motorista\n");
        printf("[0] - Capital\n");
        printf("[1] - Interior\n");
        printf("[2] - Outro estado\n>> ");
        scanf("%d", &procedencia);
        setbuf(stdin, NULL);
        if((ano_atual - ano_nascimento) < 21){
            motorista_menor_de_21++;
        }
        if(procedencia == 0 && sexo == 'F'){
            mulheres_capital++;
        }
        if(procedencia == 1 && (ano_atual - ano_nascimento) > 60){
            motorista_interior_idade_maior_que_60++;
        }
        if(sexo == 'F' && (ano_atual - ano_nascimento) > 60){
            mulher_maior_de_60 = 1;
        }
        total_motoristas++;

        printf("\nDigite [1] para continuar cadastrando ou [0] para sair.\n");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);
    }while(opcao != 0);

    printf("\n=====================================================\n");
    printf("Motoristas com menos de 21 anos: %.1f%%\n", (motorista_menor_de_21/(float)total_motoristas)*100);
    printf("Mulheres da capital: %d\n", mulheres_capital);
    printf("Motoristas do interior maiores de 60: %d\n", motorista_interior_idade_maior_que_60);
    if(mulher_maior_de_60)
        printf("Existe pelo menos uma mulher com mais de 60 anos.\n");
    else
        printf("Nao existe nenhuma mulher com mais de 60 anos.\n");
    printf("=====================================================\n");
    return 0;
}
