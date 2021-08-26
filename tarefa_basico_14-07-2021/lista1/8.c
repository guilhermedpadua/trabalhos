#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c, d, e;
    int c1 = 0, tem = 0;
    printf("Digite os 5 numeros separados por espaco e pressione ENTER: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    //a b c d e -> a, b
    //a c b d e -> a, c
    //a d b c e -> a, d
    //a e b c d -> a, e

    //b c d e a -> b, c
    //b d a c e -> b, d
    //b e a c d -> b, e

    //c d a b e -> c, d
    //c e a b d -> c, e

    //d e a b c -> d, e
    if(a == b){
        if(c != a && d != a && c == d){
            tem = 1;
        }
        if(c != a && e != a && c == e){
            tem = 1;
        }
        if(d != a && e != a && d == e){
            tem = 1;
        }

    }else if(a == c){
        if(b != a && d != a && b == d){
            tem = 1;
        }
        if(b != a && b != a && b == e){
            tem = 1;
        }
        if(d != a && e != a && d == e){
            tem = 1;
        }
    }else if(a == d){
        if(b != a && c != a && b == c){
            tem = 1;
        }
        if(b != a && e != a && b == e){
            tem = 1;
        }
        if(c != a && e != a && c == e){
            tem = 1;
        }
    }else if(a == e){
        if(b != a && c != a && b == c){
            tem = 1;
        }
        if(b != a && d != a && b == d){
            tem = 1;
        }
        if(c != a && d != a && c == d){
            tem = 1;
        }
    }else if(b == c){
        if(d != b && e != b && d == e){
            tem = 1;
        }
        if(d != b && a != b && d == a){
            tem = 1;
        }
        if(e != b && a != b && e == a){
            tem = 1;
        }
    }else if(b == d){
        if(a != b && c != b && a == c){
            tem = 1;
        }
        if(a != b && e != b && a == e){
            tem = 1;
        }
        if(c != b && e != b && c == e){
            tem = 1;
        }
    }else if(b == e){
        if(a != b && c != b && a == c){
            tem = 1;
        }
        if(a != b && d != b && a == d){
            tem = 1;
        }
        if(c != b && d != b && c == d){
            tem = 1;
        }
    }else if(c == d){
        if(a != d && b != d && a == b){
            tem = 1;
        }
        if(a != d && e != d && a == e){
            tem = 1;
        }
        if(b != d && e != d && a == e){
            tem = 1;
        }
    }else if(c == e){
        if(a != c && b != c && a == b){
            tem = 1;
        }
        if(a != c && d != c && a == d){
            tem = 1;
        }
        if(b != c && d != c && b == c){
            tem = 1;
        }
    }else if(d == e){
        if(a != d && b != d && a == b){
            tem = 1;
        }
        if(a != d && c != d && a == c){
            tem = 1;
        }
        if(b != d && c != d && b == c){
            tem = 1;
        }
    }

    if(tem)
        printf("Ha pelo menos 2 pares diferentes de numeros iguais.\n");
    else
        printf("Nao ha o minimo de 2 pares diferentes de numeros iguais.\n");
    return 0;
}
/*
a, b
a, c,
a, d
a, e
b, c
b, d
b, e
c, d
c, e
d, e
*/
