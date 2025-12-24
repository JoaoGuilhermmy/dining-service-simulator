#include "fila.h"
#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Funções referentes a fila

// Função para inicializar a fila
void inicia_fila(Fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

// Função para imprimir a fila
void imprime_fila(Fila *f)
{
    if (esta_vazia(f))
    {
        printf("  => Nenhum pedido na cozinha!\n");
        return;
    }

    Pedido *temp = f->inicio;

    printf("\nPedidos na cozinha:\n");

    while (temp != NULL)
    {
        const char *tipo_str;
        const char *nome_prato;

        switch (temp->tipo)
        {
        case ENTRADA:
            tipo_str = "Entrada";
            nome_prato = entradas[temp->valor - 1];
            break;
        case PRINCIPAL:
            tipo_str = "Prato Principal";
            nome_prato = principais[temp->valor - 1];
            break;
        case SOBREMESA:
            tipo_str = "Sobremesa";
            nome_prato = sobremesas[temp->valor - 1];
            break;
        default:
            tipo_str = "Tipo Desconhecido";
            nome_prato = "Prato Desconhecido";
            break;
        }

        printf("Mesa %d - %s: %s\n", temp->mesa, tipo_str, nome_prato);

        temp = temp->proximo;
    }
}

// Função para inserir um pedido na fila
void inserir_fila(Fila *fila, TipoPrato tipo, int valor, int mesa)
{
    Pedido *novo = malloc(sizeof(Pedido));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para o pedido!\n");
        return;
    }

    novo->mesa = mesa;
    novo->tipo = tipo;
    novo->valor = valor;
    novo->proximo = NULL;

    if (fila->fim == NULL)
    {
        fila->inicio = fila->fim = novo;
    }
    else
    {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

// Função para verificar se a fila está vazia
bool esta_vazia(Fila *f)
{
    return f->inicio == NULL;
}

// Função para remover um pedido da fila
Pedido *remover_fila(Fila *fila)
{
    if (esta_vazia(fila))
    {
        printf("  => Nenhum pedido para remover!\n");
        return NULL;
    }

    Pedido *removido = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL)
    {
        fila->fim = NULL; // A fila ficou vazia
    }

    removido->proximo = NULL; // Segurança: desconecta da fila
    return removido;
}
