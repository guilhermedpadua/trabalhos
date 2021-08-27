clear;
clc;

function [resultado] = verifica_linhas(matriz)
    resultado = %F;
    
    [linhas, colunas] = size(matriz);
    for i=1:linhas
        diferente_de_zero = 0;
        for j=1:colunas
            if(matriz(i, j) <> 0)
                diferente_de_zero = diferente_de_zero + 1;
            end
        end
        if(diferente_de_zero == 0)
            resultado = %T;
            break;
        end
    end
endfunction

matriz = input("Digite uma matriz no formato [a b c; d e f; g h i]: ");
resultado = verifica_linhas(matriz);
if(resultado == %F)
    disp("Falso");
else
    disp("Verdadeiro");
end

/*
 * Para resolver esse problema, inicialmente criamos uma variável "resultado" com o valor falso. Essa variável será retornada.
 * Ela inicia com falso, pois vamos examinar cada linha da matriz e, caso não encontremos, em alguma dessas linhas,
 * nenhum valor diferente de zero, essa variável passará a valer VERDADEIRO, pois significa que encontramos
 * uma linha que é composta somente de zeros (nenhum elemento diferente de zero implica em todos eles seram iguais a zero).
 * Para verificar se numa linha tem elementos diferentes de zero, criamos, para cada linha, a variável "diferente_de_zero"
 * que inicia com o valor 0, na linha 9 (pois ainda não examinamos a linha) e, caso algum elemento da linha examinada
 * seja diferente de zero, somamos uma unidade à variável "diferente_de_zero". Ao final do laço da linha 10, portanto,
 * teremos o total de elementos da linha que são diferentes de zero na variável "diferente_de_zero". Se essa variável for
 * igual a zero, significa que a linha recém-examinada é formada somente por zeros. Fazemos esse teste  é feito na linha
 * 15. Se for igual a 0, colocamos VERDADEIRO na variável e então saímos do laço com a instrução "break" (linha 17). 
 * É importante finalizar a execução ali, pois já encontramos o que queríamos, ou seja, não faz mais sentido continuar
 * examinando a matriz.
 */
