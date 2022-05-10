#include <stdio.h>
#include <stdlib.h>

typedef struct contador
{
    int cont;
    void *endereco;
    struct contador *prox;
}contador;

contador* c = NULL;

void* malloc2(int tamanho)  //realiza a alocacao dinamica e retorna o endereco da area criada
{
    contador* aux = (contador*)malloc(sizeof(contador));
    aux->endereco = malloc(tamanho);
    aux->cont = 1;
    if(c == NULL)
        c = aux;
    else
        c->prox = aux;

    return c->endereco;
}

contador* apagaNo(void* endereco1)
{
    contador* aux = c;
    while(aux!=NULL&&aux->endereco!=endereco1)
        aux = aux->prox;
    if(aux!=NULL)
    {
        free(aux->endereco);
        free(aux);
        return NULL;
    }
}

void atualiza(void* endereco1, void* endereco2)
{
    int i = 0;
    contador* aux = c;
    while(aux!=NULL && aux->endereco!=endereco1)
        aux = aux->prox;
    if(aux!=NULL&&aux->endereco==endereco1)
        aux->cont--;
    if(aux->cont == 0)
        apagaNo(endereco1);
    aux = c;
    while(aux!=NULL && aux->endereco!=endereco2)
        aux = aux->prox;
    if(aux!=NULL&&aux->endereco==endereco1)
        aux->cont++;
}

void atrib2(void* endereco1, void* endereco2)
{
    atualiza(endereco1, endereco2);
    endereco1 = endereco2;
}

void dump()
{
    contador* aux = c;
    if(aux==NULL)
        printf("Sem alocacao de memoria.\n");
    else
    {
       while(aux!=NULL)
       {
           printf("Endereco: %p\nContador: %d\n", aux->endereco, aux->cont);
           aux=aux->prox;
       }
    }
}

