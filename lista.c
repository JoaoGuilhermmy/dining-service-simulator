#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// Inclusão de bibliotecas para o sistema operacional
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Arrays com os nomes dos pratos
const char *entradas[] =
    {
        "Sopa de Cebola",
        "Salada Caesar",
        "Bruschetta",
        "Carpaccio de Carne",
        "Camarao ao Alho"};

const char *principais[] =
    {
        "Lasanha à Bolonhesa",
        "File Mignon com Fritas",
        "Frango Grelhado com Legumes",
        "Bacalhau a Gomes de Sa",
        "Risoto de Cogumelos"};

const char *sobremesas[] = {
    "Tiramisu",
    "Cheesecake de Frutas Vermelhas",
    "Mousse de Chocolate",
    "Pudim de Leite",
    "Sorvete de Baunilha com Calda de Morango"};

// Função para inserir um prato na lista
void inserir_pedido(No **cabeca, TipoPrato tipo, int valor)
{
    if (valor < 1 || valor > 5)
    {
        printf("Código de prato inválido!\n");
        return;
    }

    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    novo->tipo = tipo;
    novo->valor = valor;
    novo->proximo = *cabeca;
    *cabeca = novo;
}

// Função para remover um prato específico
void remover_pedido(No **cabeca, TipoPrato tipo, int valor)
{
    No *anterior = NULL;
    No *atual = *cabeca;

    while (atual != NULL && !(atual->tipo == tipo && atual->valor == valor))
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        printf("Prato não encontrado.\n");
        return;
    }

    if (anterior == NULL)
    {
        *cabeca = atual->proximo;
    }
    else
    {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

// Função para imprimir os pedidos com os nomes
void imprime_pedidos(No *cabeca)
{
    if (cabeca == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }

    No *atual = cabeca;
    while (atual != NULL)
    {
        const char *nome = NULL;

        if (atual->valor < 1 || atual->valor > 5)
        {
            nome = "Código inválido";
        }
        else
        {
            switch (atual->tipo)
            {
            case ENTRADA:
                nome = entradas[atual->valor - 1];
                printf("Entrada: %s\n", nome);
                break;
            case PRINCIPAL:
                nome = principais[atual->valor - 1];
                printf("Principal: %s\n", nome);
                break;
            case SOBREMESA:
                nome = sobremesas[atual->valor - 1];
                printf("Sobremesa: %s\n", nome);
                break;
            }
        }

        atual = atual->proximo;
    }
}

// Função para limpar a tela
void limpa_tela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");

#endif
}

// Função para pausar o programa
void espera(int segundos)
{
#ifdef _WIN32
    Sleep(segundos * 1000);
#else
    sleep(segundos);
#endif
}
