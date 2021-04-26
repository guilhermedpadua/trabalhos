#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char matricula[11], nome[100], sexo, resp;
    int idade, tot_lidos = 0, smis25 = 0, qt_smii20 = 0, soma_smii20 = 0;

    do{
        printf("Digite o nome: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);
        printf("Digite a matricula: ");
        scanf("%[^\n]s", matricula);
        setbuf(stdin, NULL);
        printf("Digite o sexo [F/M]: ");
        scanf("%c", &sexo);
        setbuf(stdin, NULL);
        printf("Digite a idade: ");
        scanf("%d", &idade);
        setbuf(stdin, NULL);
        tot_lidos++;
        if(sexo == 'M' && idade > 25){
            smis25++;
        }
        if(idade < 20){
            qt_smii20++;
            soma_smii20 += idade;
        }
        printf("\n\nDESEJA CADASTRAR MAIS UM ALUNO [S/N]?  ");
        scanf("%c", &resp);
        setbuf(stdin, NULL);
        printf("\n\n");
    }while(toupper(resp) != 'N');

    printf("TOTAL DE ALUNOS LIDOS: %d.\n", tot_lidos);
    printf("ALUNOS DO SEXO MASCULINO COM IDADE SUPERIOR A 25 ANOS: %d.\n", smis25);
    printf("MEDIA DE ALUNOS COM IDADE INFERIOR A 20 ANOS: %.1f.\n", soma_smii20/(float)qt_smii20);

    return 0;
}
