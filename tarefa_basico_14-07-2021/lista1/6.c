#include <stdio.h>
#include <stdlib.h>
int main()
{
    int placar_apostado[2], placar_jogo[2], tot_pontos = 0;
    int empate = 0, acertou_vencedor = 0;
    printf("Placar apostado (digite na forma AxB): ");
    scanf("%dx%d", &placar_apostado[0], &placar_apostado[1]);
    printf("Placar do jogo (digita na forma AxB): ");
    scanf("%dx%d", &placar_jogo[0], &placar_jogo[1]);

    if(placar_jogo[0] == placar_jogo[1]){
        empate = 1;
    }else{
        if(placar_jogo[0] > placar_jogo[1] && placar_apostado[0] > placar_apostado[1])
            acertou_vencedor = 1;
        else if(placar_jogo[1] > placar_jogo[0] && placar_apostado[1] > placar_apostado[0])
            acertou_vencedor = 1;
    }

    if(empate || acertou_vencedor)
        tot_pontos = 10;


    if(placar_jogo[1] == placar_apostado[1])
        tot_pontos += 5;
    if(placar_jogo[0] == placar_apostado[0])
        tot_pontos += 5;

    printf("Total de pontos do apostador: %d.\n", tot_pontos);
    return 0;
}

//azul, preto, branco
