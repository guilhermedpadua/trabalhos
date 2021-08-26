
clear;
clc;

function [vsaida] = intersecao(vetor1, vetor2)
    vsaida = [];
    vsaida_comprimento = 0;
    for i=1:length(vetor1)
        ja_esta = 0;
        for j=1:length(vetor2)
            if(vetor2(j) == vetor1(i)) 
                for k=1:vsaida_comprimento
                    if(vsaida(k) == vetor1(i))
                        ja_esta = 1;
                    end
                end
                
                if(ja_esta == 0)
                    vsaida_comprimento = vsaida_comprimento + 1;
                    vsaida(vsaida_comprimento) = vetor1(i);
                end    
            end
        end
    end
    vsaida = vsaida';
endfunction



v1 = input("Digite o primeiro vetor no formato [a b c d]: ");
v2 = input("Digite o segundo vetor no formato [a b c d]: ");
[vsaida] = intersecao(v1, v2);
disp(vsaida);
