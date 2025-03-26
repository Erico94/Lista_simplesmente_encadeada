#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *prox;
} No;

No *criarLista();
void adicionarElementos(No *);
void printarLista(No *);
void excluirUmNo(No *, int);
void excluirLista(No *);


int main()
{
    // inicializando lista
    No *lista = criarLista();

    // adicionando elementos
    adicionarElementos(lista);

    // printar elementos
    printarLista(lista);

    // excluir um elemento filtrando pelo dado
    int dado = 45;
    excluirUmNo(lista, dado);

    printarLista(lista);

    // excluir lista inteira
    excluirLista(lista);

    return 1;
}

No *criarLista()
{
    No *novaLista = NULL;
    novaLista = (No *)malloc(sizeof(No));
    novaLista->dado = 25;
    novaLista->prox = NULL;
    return novaLista;
}

void adicionarElementos(No *lista)
{
    int valores[] = {1, 8, 63, 45, -8};
    No *atual = lista;
    for (int i = 0; i < 5; i++)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo == NULL)
        {
            printf("Erro ao alocar memoria.");
            exit(1);
        }
        novoNo->dado = valores[i];
        novoNo->prox=NULL;
        atual->prox = novoNo;
        atual = novoNo;
    }
}

void printarLista(No *lista)
{
    No *atual = lista;
    if (lista == NULL)
    {
        printf("Lista vazia.");
        return;
    }

    while (atual->prox != NULL)
    {
        printf("\nDado: %d", atual->dado);
        atual = atual->prox;
    }
    system("PAUSE");
    return;
}

void excluirUmNo(No *lista, int dado)
{
    // Caso o elemento a ser excluído seja o primeiro da lista, o ponteiro da lista deve
    //  ser alterado para apontar para o próximo elemento antes da exclusão do
    // primeiro elemento.
    if (lista->dado == dado && lista->prox != NULL)
    {
        lista = lista->prox;
        free(lista);
        return;
    }
    else if (lista->dado == dado && lista->prox == NULL)
    {
        free(lista);
        return;
    }

    No *noAnterior;
    while (lista->prox != NULL)
    {

        if (lista->dado == dado)
        {
            noAnterior->prox = lista->prox;
            free(lista);
            return;
        }
        noAnterior = lista;
        lista = lista->prox;
    }
}

void excluirLista(No *lista){
    if(lista == NULL){
        printf("Lista ja esta vazia.");
        return;
    }
    
    No *atual = lista;
    No *prox;
    while (atual->prox != NULL)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    
}
