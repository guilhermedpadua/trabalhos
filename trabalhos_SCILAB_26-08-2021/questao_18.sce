
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
