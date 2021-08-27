
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


/*1) precisamos receber dois vetores como argumentos na função, por este motivo a definição
   da função fica: intersecao(vetor1, vetor2), na qual vetor1 e vetor2 são os dois vetores
   passados como argumentos.

2) precisamos criar um vetor vazio, onde ficarão os números da interseção. Esse vetor é chamado
   de "vsaida".

3) também precisamos criar uma variável para controlar o comprimento do vetor criado no passo 2.
   Essa variável é chamada de "vsaida_comprimento", e inicilamente tem 0, pois o vetor inicia vazio.

4) agora precisamos verificar quais são os numeros comuns aos dois vetores. Para fazer isso, fazemos o
   seguinte: para cada elemento no vetor1, verificamos se ele aparece no vetor2, ou seja, percorremos o
   vetor1 (com o laço controlado pela variável i), pegando cada posição e comparando essa posição
   a todas as outras do vetor2 (para comparar a todas as posições do vetor 2, percorremos o mesmo
   usando o laço controlado pela variável j). Dentro do segundo laço, controlado por j, verificamos
   se o número aparece nos dois vetores, com uma condição (if).

4.1) também precisamos de uma variável flag "ja_esta" para sinalizar se um numero repetido já se
   encontra ou não no vetor criado no passo 2. Ela sempre inicia com 0, pois pressupomos que um
   numero repetido não está no vetor. Ela assume o valor 1 e passa a sinalizar que já armazenamos
    número repetido, caso verifiquemos que ele já está no vetor. Essa verificação é feita por um
    terceiro laço, controlado pela variável k.

5) caso seja um numero comum aos dois vetores, agora precisamos saber se ele já não está presente
   no vetor criado no passo 2. Caso já esteja não fazemos nada. Se não estiver, então o adicionamos
   ao vetor. Para verificar se está ou não, consultamos a variável flag "ja_esta", criada no passo 4.1.
   Caso ela seja igual a 0, adicionamos o número ao vetor. Se ela for igual a 1, significa que já
   armazenamos esse número, então não fazemos nada.*/