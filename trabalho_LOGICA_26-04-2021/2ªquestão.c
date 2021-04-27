#include <stdio.h>
#include <stdlib.h>

int main()
{
    float soma_areas = 0, raio, area;
    int quantidade_areas = 0;
    const int PI = 3.141592;

    do{
        printf("Digite o raio: ");
        scanf("%f", &raio);
        setbuf(stdin, NULL);
        if(raio >= 0){
            area = PI * raio;
            printf("Area: %.2f.\n\n\n", area);
            soma_areas = soma_areas + area;
            quantidade_areas++;
        }
    }while(raio >= 0);
    printf("\n\nMedia das areas: %.2f.\n", soma_areas/quantidade_areas);

    return 0;
}
