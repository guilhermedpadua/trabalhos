
clear;
clc;



function [resultado] = verifica_matriz(matriz)    
    [linhas, colunas] = size(matriz);
    //verificando se é nula ou cheia
    elementos_diferentes_de_zero = 0;
    elementos_iguais_a_zero = 0;
    for i=1:linhas
        for j=1:colunas
            if(matriz(i, j) == 0)
                elementos_iguais_a_zero = elementos_iguais_a_zero + 1;
            else
                elementos_diferentes_de_zero = elementos_diferentes_de_zero + 1;
            end
        end
    end
    if(elementos_diferentes_de_zero == 0)
        resultado = "nula";
        return;
    end
    if(elementos_iguais_a_zero == 0)
        resultado = "cheia";
        return;
    end
    
    
    //verificando se é matriz identidade ou diagonal
    matriz_identidade = 1;
    elementos_fora_da_diagonal_principal_diferentes_de_zero = 0;
    for i=1:linhas
        for j=1:colunas
            if(i == j)
               if(matriz(i, j) <> 1)
                   matriz_identidade = 0;
               end
            else
                if(matriz(i, j) <> 0)
                    matriz_identidade = 0;
                    elementos_fora_da_diagonal_principal_diferentes_de_zero = elementos_fora_da_diagonal_principal_diferentes_de_zero + 1;
                end
            end
        end
    end
    if(matriz_identidade == 1)
        resultado = "identidade";
        return;
    end
    if(elementos_fora_da_diagonal_principal_diferentes_de_zero == 0)
        resultado = "diagonal";
        return;
    end
    
    //verificando se a matriz é simétrica
    simetrica = 1;
    for i=1:linhas
        for j=1:colunas
            if(matriz(i, j) <> matriz(j, i))
                simetrica = 0;
            end
        end
    end
    if(simetrica == 1)
        resultado = "simétrica";
        return;
    end
    
    
    //verificando se a matriz é triangular superior ou triangular inferior
    triangular_superior = 1;
    triangular_inferior = 1;
    for i=1:linhas
        for j=1:colunas
            if(i > j & matriz(i, j) <> 0)
                triangular_superior = 0;
            end
            if(j > i & matriz(i, j) <> 0)
                triangular_inferior = 0;
            end
        end
    end
    
    if(triangular_superior == 1)
        resultado = "triangular superior";
        return;
    end
    
    if(triangular_inferior == 1)
        resultado = "triangular inferior";
        return;
    end
    
    
    //verificando se a matriz é permutação
    soma_total = 0;
    permutacao = 1;
    for i = 1:linhas
        soma_linha = 0;
        soma_coluna = 0;
        for j = 1:colunas
            soma_linha = soma_linha + matriz(i, j);
            soma_coluna = soma_coluna + matriz(j , i);
        end
        if(soma_linha <> 1)
            permutacao = 0;
        end
        if(soma_coluna <> 1)
            permutacao = 0;
        end
        soma_total = soma_total + soma_linha + soma_coluna;
    end
    
    if(permutacao == 0)
        resultado = "nenhuma";
        return;
    end
    if(permutacao == 1)
        if(soma_total <> colunas*2)
            resultado = "nenhuma";
        else
            resultado = "permutação";
            return;
        end    
    end
    resultado = "nenhuma";
endfunction



matriz = input("Digite uma matriz no formato [a b c; d e f; g h i]: ");
resultado = verifica_matriz(matriz);
disp(resultado);

/*
 * Na resolução dessa questão, novamente usamos a palavra "return" para finalizar a execução da função em alguns
 * momentos. Ela é importante, pois algumas matrizes se encaixam em mais de uma das classificações: por exemplo,
 * uma matriz pode ser, ao mesmo tempo, identidade e permutação, cheia e simétrica, etc. Então usamos o "return"
 * para terminarmos a função logo após encontrarmos a primeira classificação para a matriz.
 */

 /*
  * Verificando se a matriz é nula ou cheia. Nessa parte, criamos duas variáveis, "elementos_iguais_a_zero" e 
  * "elementos_diferentes_de_zero", que começam com zero. Então percorremos a matriz e vamos contando
  * quantos elementos da mesma são iguais a zero e quantos são diferente. Na linha 21, testamos com o if
  * o número de elementos diferentes de zero dentro da matriz é igual a zero. Se for, significa que só tempo
  * zeros na matris e ela é uma matriz nula. Então atribuimos à variável "resultado" a string "nula" e paramos
  * a execução da função nesse momento, com a palavra reservada "return".
  * Logo abaixo, verificamos se a quantidade de elementos iguais a zero dentro da matriz. Só chegaremos nessa
  * parte caso a matriz não seja nula (senão teríamos parado no return da linha 23). Se o número de elementos
  * diferentes de zero dentro da matriz for igual a zero, significa que ela só tem zeros. Caso positivo, retornarmos
  * "cheia" e paramos a execução na linha 27.
  *
  */

  /*
   * Verificando se a matriz é simétrica. Este caso é simples. Uma matriz simétrica é aquela
   * que é igual à sua transposta. E a transposta de uma matriz é a matriz que se obtém trocando linhas por
   * colunas. Então, criamos uma variável chamada "simétrica" que tem 1 inicialmente, isto é, pressupomos
   * que a matriz é simétrica. Agora, a partir da linha, 59, percorremos a matriz e vamos verificando se
   * ela é igual a sua transposta em todas as posições. Dado um elemento na posição [x, y] na matriz M, na transposta
   * de M, esse elemento estará na posição [y, x]. Por isso, vamos comparando cada elemento matriz(i, j) da matriz
   * à sua provável posição na transposta, isto é, matriz(j, i). Fazemos isso para todos os elementos. Caso encontremos
   * um que seja diferente, significa que a matriz não igual a sua transposta, então marcamos a variável
   * "simetrica" com o valor 0 (linha 62). Ao final, verificamos se a matriz continua sendo simétrica, isto é,
   * se o valor da variável "simétrica" ainda é 1. Caso seja, então retornarmos "simétrica" e paramos a execução
   * ali mesmo, na linha 68, com a palavra reservada "return".
   *

   *
   * Este mesmo processo se repete para a verificação de todas as outras classificações.
   * Se chegarmos à linha 128, significa que a matriz passada não se encaixou em nenhuma das classificações, então
   * retornarmos "nenhuma".
   */
