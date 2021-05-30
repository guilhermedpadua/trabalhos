#include <stdio.h>
#include <math.h>

/*
 * Inclus�o da biblioteca math.h para usar as fun��es pow(), fabs() e sqrt()
 * pow() -> recebe um n�mero de ponto flutuante e retorna seu quadrado, tamb�m em plonto flutuante de dupla precis�o
 * fabs() -> recebe um n�mero de ponto flutuante e retorna seu valor absoluto.
 * sqrt() -> recebe um double e retorna sua raiz quadrada, tamb�m do tipo double
 */

struct ponto{
    double x;
    double y;
};

/*
 * Defini��o do tipo  Ponto.
 */

typedef struct ponto Ponto;

struct circulo{
    Ponto centro;
    double raio;
};

typedef struct circulo Circulo;

/*
 * Defini��o do tipo circulo.
 */

struct retangulo{
    Ponto canto_inferior_esquerdo;
    Ponto canto_superior_direito;
};

typedef struct retangulo Retangulo;

/*
 * Defini��o do tipo retangulo.
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
 * Aqui � definida a fun��o que serve para calcular a dist�ncia entre dois pontos. Ela recebe dois valores do tipo Ponto.
 * Nela, optei por usar a fun��o fabs(), que retorna o valor absoluto de um n�mero,
 * para que a ordem na qual se passam os argumentos a ela seja irrelavante.
 */

double menor_distancia(double d1, double d2)
{
    if(d1 < d2)
        return d1;
    return d2;
}

/*
 * Defini��o da fun��o menor_distania(), que servir� de aux�lio para c�lculo do raio da circunfer�ncia inscrita a um
 * ret�ngulo.
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
 * Defini��o da fun��o circulo_inscrito(). Ela recebe um ret�ngulo e retorna, por valor, a circunfer�ncia inscrita a ele.
 * Para isso, calculam-se as coordenadas x e y do centro da circunfer�ncia. Tamb�m calcula-se o raio da circunfer�ncia inscrita
 * com o auxilio da fun��o menor_distancia().
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
 * Defini��o da fun��o circulo_circunscrito(). Ela recebe um argumento do tipo Retangulo e retorna o c�rculo
 * circunscrito a esse ret�ngulo. Tamb�m calcula-se o raio da circunfer�ncia: para isso, basta calcular a distancia
 * entre o canto superior direito e canto inferior esquerdo do ret�ngulo (diagonal) com o auxilio da funcao
 * distancia_entre_dois_pontos() e ent�o dividi-la por 2.
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
