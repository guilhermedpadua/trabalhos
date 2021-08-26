#include <stdio.h>
#include <time.h>
#ifdef __unix__
    #include <unistd.h>
    #include <stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
    #define OS_Windows
    #include <windows.h>
#endif

#define TRUE 1
#define FALSE 0

typedef struct No{
    int valor;
    struct No* prox;
}TNo;

typedef TNo* TLista;

TLista* cria_lista()
{
    TLista* lista = malloc(sizeof(TLista));
    if(lista != NULL){
        *lista = NULL;
    }
    return lista;
}

int inserir(TLista* L, int numero)
{
    if(L == NULL)
        return FALSE;
    TNo* novo_no = malloc(sizeof(TNo));
    if(novo_no == NULL)
        return FALSE;
    novo_no->valor = numero;
    novo_no->prox = NULL;
    if((*L) == NULL){
        novo_no->prox = *L;
        *L = novo_no;
        return TRUE;
    }
    TNo* e = *L;
    while(e->prox != NULL){
        e = e->prox;
    }
    e->prox = novo_no;
    return TRUE;
}

int remover_por_valor(TLista* L, int numero)
{
    TNo* atual = *L;
    TNo* anterior = NULL;
    int encontrou = 0;
    if((*L) == NULL)
        return FALSE;
    while(atual){
        if(atual->valor == numero){
            encontrou = 1;
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    if(encontrou){
        if(anterior == NULL){
            *L = atual->prox;
        }else{
            anterior->prox = atual->prox;
        }
        free(atual);
        return TRUE;
    }
    return FALSE;
}

int remover_por_posicao(TLista* L, int posicao)
{
    TNo* atual = *L;
    TNo* anterior = NULL;
    int encontrou = 0, pos = 1;
    if((*L) == NULL)
        return FALSE;
    while(atual){
        if(pos == posicao){
            encontrou = 1;
            break;
        }
        anterior = atual;
        atual = atual->prox;
        pos++;
    }

    if(encontrou){
        if(anterior == NULL){
            *L = atual->prox;
        }else{
            anterior->prox = atual->prox;
        }
        free(atual);
        return TRUE;
    }
    return FALSE;
}

void exibir(TLista L)
{
    if(L == NULL){
        printf("\nLista vazia!\n\n");
        return;
    }
    TNo* no = L;
    while(no){
        if(no->prox == NULL){
            printf("%d.\n\n\n", no->valor);
        }else{
            printf("%d, ", no->valor);
        }
        no = no->prox;
    }
    return;
}


int lista_esta_vazia(TLista L)
{
    if(L == NULL)
        return TRUE;
    return FALSE;
}

int elemento_esta_na_lista(TLista* L, int elemento)
{
    if(L == NULL)
        return FALSE;
    if(lista_esta_vazia(*L))
        return FALSE;
    TNo* e = *L;
    while(e){
        if(e->valor == elemento)
            return TRUE;
        e = e->prox;
    }
    return FALSE;
}

TNo* busca_elemento(TLista* lista, int valor)
{
    if(lista == NULL)
        return NULL;
    if(lista_esta_vazia(*lista) == TRUE)
        return NULL;
    TNo* e = *lista;
    while(e != NULL){
        if(e->valor == valor)
            return e;
        e = e->prox;
    }
    return NULL;
}


int troca_valores(TLista* L, int v1, int v2)
{
    if(L == NULL)
        return FALSE;
    if(lista_esta_vazia(*L))
        return FALSE;
    int aux;
    TNo* n1 = busca_elemento(L, v1);
    TNo* n2 = busca_elemento(L, v2);
    if(n1 == NULL || n2 == NULL)
        return FALSE;
    aux = n1->valor;
    n1->valor = n2->valor;
    n2->valor = aux;
    return TRUE;
}


void limpa_tela()
{
    #ifdef OS_Windows
        system("cls");
    #else
        system("clear");
    #endif
}

void pausa(float delay1)
{
    if(delay1 < 0.001)
        return; // pode ser ajustado e/ou evita-se valores negativos.
    float inst1 = 0, inst2 = 0;
    inst1 = (float) clock() / (float) CLOCKS_PER_SEC;
    while (inst2 - inst1 < delay1)
        inst2 = (float) clock() / (float) CLOCKS_PER_SEC;
    return;
}

void aguarde(char* texto)
{
    limpa_tela();
    printf ("%s.\n", texto);
    pausa(0.4);
    limpa_tela();
    printf ("%s..\n", texto);
    pausa (0.4);
    limpa_tela();
    printf ("%s.,.\n", texto);
    pausa (0.4);
    limpa_tela();
}

void espera()
{
    printf("\nPressione ENTER para continuar...\n\n");
    getchar();
    getchar();
}

int main()
{
    TLista* lista = cria_lista();
    int opcao, n, v2;
    do{
        limpa_tela();
        printf("------------------------------------\n");
        printf("[0] - Sair                          \n"); //ok
        printf("[1] - Inserir elemento              \n"); //ok
        printf("[2] - Remover elemento por valor    \n"); //ok
        printf("[3] - Remover elemento por posicao  \n"); //ok
        printf("[4] - Alterar um valor por outro    \n");
        printf("[5] - Buscar elemento               \n");
        printf("[6] - Exibir elementos da lista     \n"); //ok
        printf("------------------------------------\n");
        printf(">> ");
        scanf("%d", &opcao);
        switch(opcao){
            case 0:
                printf("Obrigado por usar nosso programa!\n\n");
                espera();
            break;
            case 1:
                printf("Digite o numero a ser inserido: ");
                scanf("%d", &n);
                aguarde("Inserindo");
                if(inserir(lista, n) == TRUE){
                    printf("Insercao realizada com sucesso!\n\n\n");
                }else{
                    printf("Erro ao inserir elemento!\n\n\n");
                }
                espera();
            break;
            case 2:
                if(lista_esta_vazia(*lista)){
                    printf("A lista esta vazia!\n\n");
                }else{
                    printf("Digite o valor do elemento o qual deseja remover: ");
                    scanf("%d", &n);
                    aguarde("Removendo elemento");
                    if(remover_por_valor(lista, n)){
                        printf("Remocao bem-sucedida!\n\n");
                    }else{
                        printf("Elemento nao encontrado ou erro ao tentar remove-lo!\n\n");
                    }
                }
                espera();
            break;
            case 3:
                if(lista_esta_vazia(*lista)){
                    printf("A lista esta vazia!\n\n");
                }else{
                    printf("Digite a posicao do elemento a ser removido da lista: ");
                    scanf("%d", &n);
                    aguarde("Removendo");
                    if(remover_por_posicao(lista, n)){
                        printf("Remocao bem-sucedida!\n\n");
                    }else{
                        printf("Posicao invalida ou erro ao tentar remove-lo!\n\n");
                    }
                }
                espera();
            break;
            case 4:
                if(lista_esta_vazia(*lista)){
                    printf("A lista esta vazia!\n\n");
                }else{
                    printf("Digite o primeiro elemento: ");
                    scanf("%d", &n);
                    printf("Digite o segundo elemento: ");
                    scanf("%d", &v2);
                    aguarde("Realizando troca");
                    if(troca_valores(lista, n, v2)){
                        printf("Troca bem-sucedida!\n\n");
                    }else{
                        printf("Houve um erro ao tentarmos realizar a troca!\n\n");
                    }
                }
                espera();
            break;
            case 5:
                if(lista_esta_vazia(*lista)){
                    printf("A lista esta vazia!\n\n");
                }else{
                    printf("Digite o valor do elemento: ");
                    scanf("%d", &n);
                    aguarde("Pesquisando");
                    if(busca_elemento(lista, n) != NULL){
                        printf("Elemento encontrado!\n");
                    }else{
                        printf("Elemento inexistente!\n");
                    }
                }
                espera();
            break;
            case 6:
                exibir(*lista);
                espera();
            break;
            default:
                printf("Opcao invalida!\n");
                espera();
        }
    }while(opcao != 0);
    return 0;
}
