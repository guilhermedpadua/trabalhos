
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
    
    
    //verificando se é matriz identidade
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
    transposta = 1;
    for i=1:linhas
        for j=1:colunas
            if(matriz(i, j) <> matriz(j, i))
                transposta = 0;
            end
        end
    end
    if(transposta == 1)
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
