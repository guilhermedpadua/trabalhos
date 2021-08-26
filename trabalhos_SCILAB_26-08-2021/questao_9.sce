clear;
clc;

function [numeros_unicos] = unicos(vetor)
    numeros_unicos = [];
    comprimento = 0;
    
    for i = 1:length(vetor)
        nao_repetido = %T;
        for j = 1:length(vetor)
            if(vetor(i) == vetor(j) & i <> j)
                nao_repetido = %F;
            end
        end
        if(nao_repetido)
            comprimento = comprimento + 1;
            numeros_unicos(comprimento) = vetor(i);
        end
    end
    numeros_unicos = numeros_unicos';
endfunction


a = input("Digite um vetor no formato [a b c d e f]: ");
[numeros_unicos] = unicos(a);
disp(numeros_unicos);
