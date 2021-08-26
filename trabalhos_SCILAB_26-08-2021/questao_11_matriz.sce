

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
