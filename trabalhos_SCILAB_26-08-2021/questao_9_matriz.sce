
clear;
clc;

function [linha, coluna] = ocorrencia(matriz, x)
    linha = -1;
    coluna = -1;
    encontrado = %F;
    
    [linhas, colunas] = size(matriz);
    for i=1:linhas
        for j=1:colunas
            if(matriz(i, j) == x)
               linha = i;
               coluna = j; 
            end
        end
    end
endfunction



matriz = input("Digite uma matriz no formato [a b c; d e f; g h i]: ");
x = input("Digite o numero que deseja encontrar na matriz: ");
[linha, coluna] = ocorrencia(matriz, x);
disp("Linha: " + string(linha));
disp("Coluna: " + string(coluna));
