#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char nome_produto[100];
    float valor, imposto, valor_bruto_total = 0,  imposto_total = 0, valor_total_liquido;

    for(int i = 0; i < 10; i++){
        printf("Digite o nome do produto %d: ", i+1);
        scanf("%[^\n]s",  nome_produto);
        setbuf(stdin, NULL);
        printf("Digite o valor do produto %d: ", i+1);
        scanf("%f", &valor);
        setbuf(stdin, NULL);
        printf("Digite o valor do imposto do produto %d: ", i+1);
        scanf("%f", &imposto);
        setbuf(stdin, NULL);
        printf("\n\n");
        valor_bruto_total += valor;
        imposto_total += imposto;
        valor_total_liquido += valor - imposto;
    }

    printf("Valor total bruto das 10 notas: %.1f\n", valor_bruto_total);
    printf("Valor total do imposto: %.1f\n", imposto_total);
    printf("Valor liquido total: %.1f\n", valor_total_liquido);
    return 0;
}
