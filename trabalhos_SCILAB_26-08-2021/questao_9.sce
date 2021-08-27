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

/*
 * Para esta questão, a ideia é percorrer  o vetor recebido como argumento e verificar quais 
 * elementos do mesmo não são repetidos. Para isso, usamos dois laços for: o primeiro serve
 * para pegar elemento por elemento; o segundo serve para comparar o elemento escolhido pelo
 * primeiro laço aos demais elementos. Caso comparemos o elemento de uma posição ao elemento
 * de outra posição e eles sejam iguais (estando em posições diferentes), então marcamos
 * a variável nao_repetido (linha 12) como TRUE, isto é, passaremos a sinalizar esse elemento
 * em questão como um número repetido.
 *
 * Na linha 15, verificamos se o número em questão não está repetido no vetor e, caso não esteja,
 * adicionamos o mesmo ao vetor criado na linha 5, que serve para armazenar esses numeros.
 */