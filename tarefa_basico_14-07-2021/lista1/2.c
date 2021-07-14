#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char caractere, c;
    scanf("%c", &caractere);
    if(isalpha(caractere)){
        c = toupper(caractere);
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            printf("Vogal.\n");
        else
            printf("Consoante.\n");
    }else{
        printf("Nao eh uma letra.\n");
    }

    return 0;
}
