
clear;
clc;

function [vsaida] = reorganiza(vetor)
    primeiro_elemento = vetor(1);
    
    vsaida = [];
    vsaida_comprimento = 0;
    
    menores = [];
    menores_comprimento = 0;
    
    maiores = [];
    maiores_comprimento = 0;
    
    for i=1:length(vetor)
        if(vetor(i) < primeiro_elemento)
            menores_comprimento = menores_comprimento + 1;
            menores(menores_comprimento) = vetor(i);
        elseif(vetor(i) > primeiro_elemento)
            maiores_comprimento = maiores_comprimento+1;
            maiores(maiores_comprimento) = vetor(i);
        end    
    end
    
    for j=1:length(menores)
        vsaida_comprimento = vsaida_comprimento + 1;
        vsaida(vsaida_comprimento) = menores(j);
    end
    
    vsaida_comprimento = vsaida_comprimento + 1;
    vsaida(vsaida_comprimento) = primeiro_elemento;
    
    for j=1:length(maiores)
        vsaida_comprimento = vsaida_comprimento + 1;
        vsaida(vsaida_comprimento) = maiores(j);
    end
    
    vsaida = vsaida';
endfunction


vetor = input("Digite o primeiro vetor no formato [a b c d]: ");
[vsaida] = reorganiza(vetor);
disp(vsaida);

/*
 * A estratégia para resolver esse problema é a seguinte: criamos um vetor para armazenar os número menores
 * que o da primeira posição do vetor passado (linha 11), criamos um vetor para armazenar os números maiores
 * que o da primeira posição do vetor passado (linha 14). Agora, devemos percorrer o vetor original
 * e preencher o vetor criado na linha 11, com os números menores e também o vetor criado na linha 14, com os 
 * maiores numeros. Fazemos isso no for da linha 17. A partir da linha 26, já temos um vetor com os números
 * menores que aquele na primeira posição do vetor original e outro vetor com os números maiores que o da
 * primeira posição do vetor original. Então basta unirmos esses dois vetore em um só, colocando entre eles
 * o primeiro elemento do vetor original. Dessa forma, à esquerda estarão os menores e à direita os maiores.
 * No for da linha 17, colocamos os numeros menores no terceiro vetor, na linha 33, colocamos no terceiro 
 * vetor o primeiro elemento do vetor original e, no for da linha 35, colocamos os números maiores no terceiro
 * vetor.
 *
 */