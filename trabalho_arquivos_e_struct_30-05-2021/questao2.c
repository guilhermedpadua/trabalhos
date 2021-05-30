#include <stdio.h>
#include <math.h>

/*
 * Inclusão da biblioteca math.h para usar as funções pow(), fabs() e sqrt()
 * pow() -> recebe um número de ponto flutuante e retorna seu quadrado, também em plonto flutuante de dupla precisão
 * fabs() -> recebe um número de ponto flutuante e retorna seu valor absoluto.
 * sqrt() -> recebe um double e retorna sua raiz quadrada, também do tipo double
 */

struct ponto{
    double x;
    double y;
};

/*
 * Definição do tipo  Ponto.
 */

typedef struct ponto Ponto;

struct circulo{
    Ponto centro;
    double raio;
};

typedef struct circulo Circulo;

/*
 * Definição do tipo circulo.
 */

struct retangulo{
    Ponto canto_inferior_esquerdo;
    Ponto canto_superior_direito;
};

typedef struct retangulo Retangulo;

/*
 * Definição do tipo retangulo.
 */

double distancia_entre_dois_pontos(Ponto p1, Ponto p2)
{
    if(p1.y == p2.y)
        return fabs(p2.x - p1.x);
    if(p1.x == p2.x)
        return fabs(p2.y - p1.y);
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

/*
 * Aqui é definida a função que serve para calcular a distância entre dois pontos. Ela recebe dois valores do tipo Ponto.
 * Nela, optei por usar a função fabs(), que retorna o valor absoluto de um número,
 * para que a ordem na qual se passam os argumentos a ela seja irrelavante.
 */

double menor_distancia(double d1, double d2)
{
    if(d1 < d2)
        return d1;
    return d2;
}

/*
 * Definição da função menor_distania(), que servirá de auxílio para cálculo do raio da circunferência inscrita a um
 * retângulo.
 */

Circulo circulo_inscrito(Retangulo retangulo)
{
    Circulo c_i;
    c_i.centro.x = (retangulo.canto_inferior_esquerdo.x + retangulo.canto_superior_direito.x)/2.0;
    c_i.centro.y = (retangulo.canto_inferior_esquerdo.y + retangulo.canto_superior_direito.y)/2.0;
    double superior_direito_x  = retangulo.canto_superior_direito.x;
    double superior_direito_y  = retangulo.canto_superior_direito.y;
    double inferior_esquerdo_x = retangulo.canto_inferior_esquerdo.x;
    double inferior_esquerdo_y  = retangulo.canto_inferior_esquerdo.y;
    c_i.raio = menor_distancia((superior_direito_x-inferior_esquerdo_x)/2.0, (superior_direito_y - inferior_esquerdo_y)/2.0);
    return c_i;
}

/*
 * Definição da função circulo_inscrito(). Ela recebe um retângulo e retorna, por valor, a circunferência inscrita a ele.
 * Para isso, calculam-se as coordenadas x e y do centro da circunferência. Também calcula-se o raio da circunferência inscrita
 * com o auxilio da função menor_distancia().
 */

Circulo circulo_circunscrito(Retangulo retangulo)
{
    Circulo c_c;
    c_c.centro.x  = (retangulo.canto_inferior_esquerdo.x + retangulo.canto_superior_direito.x)/2.0;
    c_c.centro.y = (retangulo.canto_inferior_esquerdo.y + retangulo.canto_superior_direito.y)/2.0;
    c_c.raio = distancia_entre_dois_pontos(retangulo.canto_inferior_esquerdo, retangulo.canto_superior_direito)/2.0;
    return c_c;
}

/*
 * Definição da função circulo_circunscrito(). Ela recebe um argumento do tipo Retangulo e retorna o círculo
 * circunscrito a esse retângulo. Também calcula-se o raio da circunferência: para isso, basta calcular a distancia
 * entre o canto superior direito e canto inferior esquerdo do retângulo (diagonal) com o auxilio da funcao
 * distancia_entre_dois_pontos() e então dividi-la por 2.
 */

int main()
{
    Retangulo r1 = {{5, 3}, {9, 6}};
    Circulo c_i_r1 = circulo_inscrito(r1);
    Circulo c_c_r1 = circulo_circunscrito(r1);

    printf("Circulo inscrito ao retangulo r1\n");
    printf("Raio: %lf\n", c_i_r1.raio);
    printf("Centro: (%lf, %lf)\n", c_i_r1.centro.x, c_i_r1.centro.y);
    printf("--------------------------------------\n");

    printf("Circulo circunscrito ao retangulo r1\n");
    printf("Raio: %lf\n", c_c_r1.raio);
    printf("Centro: (%lf, %lf)\n", c_c_r1.centro.x, c_c_r1.centro.y);
    printf("---------------------------------------\n");





    Retangulo quadrado = {{10, 8}, {14, 12}}; //criando um quadrado
    Circulo c_i_quadrado = circulo_inscrito(quadrado);
    Circulo c_c_quadrado = circulo_circunscrito(quadrado);

    printf("Circulo inscrito ao quadrado\n");
    printf("Raio: %lf\n", c_i_quadrado.raio);
    printf("Centro: (%lf, %lf)\n", c_i_quadrado.centro.x, c_i_quadrado.centro.y);
    printf("--------------------------------------\n");

    printf("Circulo circunscrito ao \n");
    printf("Raio: %lf\n", c_c_quadrado.raio);
    printf("Centro: (%lf, %lf)\n", c_c_quadrado.centro.x, c_c_quadrado.centro.y);
    printf("---------------------------------------\n");

    return 0;
}
