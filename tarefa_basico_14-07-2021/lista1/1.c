#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, maior, menor, meio;
    int condicao1 = 0, condicao2 = 0;
    //pressupõe que todos os números são diferentes entre si
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if(a > b && b > c){
        maior = a;
        if(b > c){
            meio = b;
            menor = c;
        }else{
            meio = c;
            menor = b;
        }
    }else if(b > a && b > c){
        maior = b;
        if(a > c){
            meio = a;
            menor = c;
        }else{
            meio = c;
            menor = a;
        }
    }else{
        maior = c;
        if(b > a){
            meio = b;
            menor = a;
        }else{
            meio = a;
            menor = b;
        }
    }
    if(maior%2 == 0 && meio%2 == 1 && menor%2 == 1){
        condicao1 = 1;
    }
    if(menor%2 == 1){
        condicao2 = 1;
    }
    if(condicao1 || condicao2)
        printf("VERDADEIRO\n");
    else
        printf("FALSO\n");
    return 0;
}
