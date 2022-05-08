#include "contref.h"
#include <stdio.h>
#include <stdlib.h>

contador *lista = NULL;

void *malloc2(int tamanho)
{
    contador *aux;
    aux = malloc2(sizeof(contador));
    aux->endereco = malloc(tamanho);
    aux->cont = 1;
    aux->prox = NULL;
    if(lista!=NULL)
        aux->prox = lista;
    lista = aux;
    return lista->endereco;
}

void atualiza(void *end1, int incremento)
{

}
















void *atrib2(void **end1, void *end2)
{
    if((*end1)!=NULL)
    {
        contador *aux = lista;
    }
}
