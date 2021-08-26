#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c;
    printf("Digite os tres numeros inteiros separados por espaco e pressione ENTER: ");
    scanf("%d %d %d", &a, &b, &c);
    if(a == b && b == c){
        printf("igual\n");
    }else if(a != b && b != c && c != a)
        printf("diferente\n");

    return 0;
}

