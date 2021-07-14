#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int um, dois, tres, quatro;
    int condicao1 = 0, condicao2 = 0, condicao3 = 0, condicao4 = 0;
    scanf("%d", &um);
    scanf("%d", &dois);
    scanf("%d", &tres);
    scanf("%d", &quatro);

    if((um >= 1 && um <= 25 ) || (dois >= 1 && dois <= 25) || (tres >= 1 && tres <= 25) || (quatro >= 1 && quatro >= 25))
        condicao1 = 1;
    if((um >= 26 && um <= 50 ) || (dois >= 26 && dois <= 50) || (tres >= 26 && tres <= 50) || (quatro >= 26 && quatro >= 50))
        condicao2 = 1;
    if((um >= 51 && um <= 75 ) || (dois >= 51 && dois <= 75) || (tres >= 51 && tres <= 75) || (quatro >= 51 && quatro >= 75))
        condicao3 = 1;
    if((um >= 76 && um <= 100 ) || (dois >= 76 && dois <= 100) || (tres >= 76 && tres <= 100) || (quatro >=76  && quatro >= 100))
        condicao4 = 1;

    if(condicao1)
        printf("Ha pelo menos um numero no intervalo 1-25.\n");
    if(condicao2)
        printf("Ha pelo menos um numero no intervalo 26-50.\n");
    if(condicao3)
        printf("Ha pelo menos um numero no intervalo 51-75.\n");
    if(condicao4)
        printf("Ha pelo menos um numero no intervalo 76-100.\n");

    return 0;
}
