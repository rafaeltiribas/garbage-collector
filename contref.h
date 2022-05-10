#include <stdio.h>
#include <stdlib.h>

typedef struct contador
{
    int cont;
    void *endereco;
}contador;

contador *c[1000];
int pos = 0;

void *malloc2(int size_)
{
    contador *aux = (contador*)malloc(sizeof(contador));
    aux->cont=1;
    c[pos]=aux;
    pos++;
    void *memoria=malloc(size_);
    aux->endereco=memoria;
    return aux->endereco;
}

void atualiza(void *ende, int contador)
{
    int aux;
    while(aux<pos&&ende!=c[aux]->endereco)
    {
        if(ende==c[aux]->endereco)
        {
            c[aux]->cont+=contador;
            if(c[aux]->cont==0)
            {
                free(c[aux]->endereco);
                free(c[aux]);
            }
            break;
        }
        aux++;
    }
}

void atrib2(void *end1, void *end2)
{
    atualiza(end1, -1);
    end1=end2;
    atualiza(end2, 1);
}

void dump()
{
    int i=0;
    if(c==NULL)
        printf("Nenhuma memoria alocada.\n");
    else
    {
        while(i<pos)
        {
            printf("Endereco: %d\nContador: %d\n", c[i]->endereco, c[i]->cont);
            i++;
        }
    }
}
