#ifndef CONTREF_H_INCLUDED
#define CONTREF_H_INCLUDED

typedef struct contador
{
    int cont;
    void *endereco;
    struct contador *prox;
}contador;

void *malloc2(int tamanho);
void *atrib2(void **end1, void *end2);
contador *removeElemento(contador *heap, void *endereco);
void dump();
void atualiza(void *end1, int incremento);

#endif
