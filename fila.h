#ifndef FILA_H
#define FILA_H

#include "lista.h"
#include <stdbool.h>

// Structs referente ao armazenamento do pedido, onde recebe o número da mesa, o tipo do prato e o codigo do prato.
typedef struct Pedido
{
    int mesa;
    TipoPrato tipo;
    int valor;
    struct Pedido *proximo;
} Pedido;

// Struct referente ao armazenamento da fila
typedef struct
{
    Pedido *inicio;
    Pedido *fim;
} Fila;

void inicia_fila(Fila *f);
void imprime_fila(Fila *f);
void inserir_fila(Fila *fila, TipoPrato tipo, int valor, int mesa);
bool esta_vazia(Fila *f);
int remover_fila(Fila *fila);
#endif