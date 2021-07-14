#include <stdio.h>
#include <stdlib.h>
int main()
{
    float notas[6], maior, menor, nota_final = 0, soma_notas = 0;
    int i;
    for(i = 0; i < 6; i++)
        scanf("%f", &notas[i]);

    maior = notas[0];
    menor = notas[0];
    for(i = 0; i < 6; i++){
        if(notas[i] > maior)
            maior = notas[i];
        if(notas[i] < menor)
            menor = notas[i];
    }

    for(i = 0; i < 6; i++)
        soma_notas += notas[i];

    nota_final = soma_notas - (maior + menor);

    printf("Nota final do atleta: %.2f\n", nota_final);
    return 0;
}
