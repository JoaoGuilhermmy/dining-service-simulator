#ifndef LISTA_H
#define LISTA_H

extern const char *entradas[];
extern const char *principais[];
extern const char *sobremesas[];

// Enum para os tipos de pratos
typedef enum
{
    ENTRADA,
    PRINCIPAL,
    SOBREMESA
} TipoPrato;

// Nó da lista encadeada: representa UM prato
typedef struct no
{
    TipoPrato tipo; // Tipo do prato
    int valor;      // Código do prato
    struct no *proximo;
} No;

void inserir_pedido(No **cabeca, TipoPrato tipo, int valor);
void remover_pedido(No **cabeca, TipoPrato tipo, int valor);
void imprime_pedidos(No *cabeca);
void limpa_tela();
void espera(int segundos);

#endif
