#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c, d, e, f, acertos = 0;
    printf("Digite os tres numeros inteiros da aposta separados por espaco: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Digite os tres numeros inteiros sorteads separados por espaco: ");
    scanf("%d %d %d", &d, &e, &f);

    if(a == d || a == e || a == f)
        acertos++;
    if(b == d || b == e || b == f)
        acertos++;
    if(c == d || c == e || c == f)
        acertos++;
    printf("Quantidade de acertos: %d.\n", acertos);

    return 0;
}

