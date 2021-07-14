#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, i;
    printf("Digite os dois numeros inteiros positivos separados por espaco e pressione ENTER: ");
    scanf("%d %d", &a, &b);

    if(a == b){
        printf("Numeros iguais.\n");
    }else{
        if(a < b){
            float media = 0;
            for(i = a; i <= b; i++)
                media += i;
            media = media/((b-a)+1);
            printf("MEDIA: %.2f\n", media);
        }else{
            int tot_pares = 0;
            for(i = b; i <= a; i++){
                if(i%2 == 0)
                    tot_pares++;
            }
            printf("Total de pares: %d.\n", tot_pares);
        }
    }

    return 0;
}

