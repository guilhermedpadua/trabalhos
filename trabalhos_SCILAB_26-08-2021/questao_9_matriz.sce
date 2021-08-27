
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
               return;
            end
        end
    end
endfunction



matriz = input("Digite uma matriz no formato [a b c; d e f; g h i]: ");
x = input("Digite o numero que deseja encontrar na matriz: ");
[linha, coluna] = ocorrencia(matriz, x);
disp("Linha: " + string(linha));
disp("Coluna: " + string(coluna));

/*
 * Neste problema, usaremos o recurso "return", que serve para terminar a execução de uma função
 * dada uma condição. A estratégia de resolução consiste em percorrer a matriz (fazemos isso com o laço da linha 11)
 * e verificar, para cada elemento da matriz, se o mesmo é igual ao segundo argumento passado à função.
 * Se for, então atribuímos a posição linha e coluna desse elemento às variáveis "linha" e "coluna", que serão
 * retornadas. Também usamos "return" para encerrar a função ali. Isso é importante, pois caso existam mais
 * elementos iguais na matriz, serão retornados as coordenadas do último elemento igual - e não do primeiro.
 *
 * Repare que, se não houver nenhum elemento na matriz igual ao elemento passado, o retorno será [-1, -1], já
 * que as variáveis "linha" e "coluna" já são inicializadas com esses valores nas linhas 6 e 7.
 */