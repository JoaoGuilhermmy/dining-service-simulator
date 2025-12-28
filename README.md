# 🍽️ Sistema de Gerenciamento de Restaurante

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-Queue%20%7C%20Linked%20List-orange?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Cross--Platform-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**Sistema completo de gerenciamento de pedidos para restaurantes usando Fila e Lista Encadeada**

[🇺🇸 English Version](README.en.md) | [📖 Sobre](#-sobre-o-projeto) | [🚀 Instalação](#-instalação) | [💡 Funcionalidades](#-funcionalidades)

---

</div>

## 📋 Sobre o Projeto

O **IMD Palace Restaurant System** é um sistema de gerenciamento de pedidos desenvolvido em C que simula o fluxo completo de um restaurante. Utiliza:

- **Filas (Queue)**: Para gerenciar a ordem de preparo na cozinha (FIFO)
- **Listas Encadeadas**: Para montar o pedido de cada mesa antes do envio

### 🎯 Objetivos

- Demonstrar domínio de **Estruturas de Dados Fundamentais** em C
- Implementar **Fila (FIFO)** para ordem de preparo dos pedidos
- Utilizar **Lista Encadeada** para composição dinâmica de pedidos
- Criar sistema com **alocação dinâmica de memória**
- Aplicar **programação modular** com múltiplos arquivos

### ✨ Características Principais

- 🍕 **Cardápio Completo** - Entradas, pratos principais e sobremesas
- 📋 **Sistema de Pedidos** - Montagem dinâmica por mesa
- 🔥 **Fila da Cozinha** - Ordem de preparo respeitada (FIFO)
- 🗑️ **Remoção de Itens** - Modificação de pedidos antes do envio
- 🖥️ **Interface Interativa** - Menu intuitivo no console
- 🔄 **Multiplataforma** - Compatível com Windows, Linux e macOS

---

## 🏗️ Arquitetura

### Estrutura de Diretórios

```
restaurante/
├── fila.c              # Implementação da fila (cozinha)
├── fila.h              # Interface da fila
├── lista.c             # Implementação da lista encadeada (pedido)
├── lista.h             # Interface da lista + arrays de pratos
├── main.c              # Ponto de entrada e interface do usuário
└── makefile            # Script de compilação
```

### 📊 Estruturas de Dados

#### 1. **Lista Encadeada** (Pedido Temporário)

```c
typedef enum {
    ENTRADA,
    PRINCIPAL,
    SOBREMESA
} TipoPrato;

typedef struct no {
    TipoPrato tipo;      // ENTRADA, PRINCIPAL, SOBREMESA
    int valor;           // Código do prato (1-5)
    struct no *proximo;
} No;
```

**Uso**: Armazena temporariamente os itens do pedido de uma mesa antes do envio para cozinha.

**Vantagens**:
- ✅ Tamanho dinâmico
- ✅ Inserção O(1) no início
- ✅ Facilita adição/remoção de itens

#### 2. **Fila** (Cozinha)

```c
typedef struct Pedido {
    int mesa;               // Número da mesa
    TipoPrato tipo;         // Tipo do prato
    int valor;              // Código do prato
    struct Pedido *proximo;
} Pedido;

typedef struct {
    Pedido *inicio;
    Pedido *fim;
} Fila;
```

**Uso**: Mantém ordem de preparo dos pedidos (primeiro a entrar, primeiro a sair).

**Vantagens**:
- ✅ FIFO garantido
- ✅ Inserção O(1) no fim
- ✅ Remoção O(1) no início

### 🔄 Fluxo de Dados

```
┌─────────────────┐
│  Cliente Mesa 1 │
│ Inicia Pedido   │
└────────┬────────┘
         │
         ▼
┌─────────────────────────────┐
│  Lista Encadeada (Pedido)   │
│  ┌───┐   ┌───┐   ┌───┐     │
│  │ E ├──►│ P ├──►│ S │     │
│  └───┘   └───┘   └───┘     │
│  Entrada Principal Sobremesa│
└────────┬────────────────────┘
         │ Finalizar Pedido
         ▼
┌─────────────────────────────┐
│    Fila da Cozinha (FIFO)   │
│  ┌────┐  ┌────┐  ┌────┐    │
│  │M1E │→ │M1P │→ │M1S │→...│
│  └────┘  └────┘  └────┘    │
│  inicio              fim     │
└─────────────────────────────┘
         │
         ▼
┌─────────────────┐
│     Preparo     │
│   na Cozinha    │
└─────────────────┘
```

---

## 💡 Funcionalidades

### 🥗 Cardápio Disponível

#### Entradas
1. Sopa de Cebola
2. Salada Caesar
3. Bruschetta
4. Carpaccio de Carne
5. Camarão ao Alho

#### 🍝 Pratos Principais
1. Lasanha à Bolonhesa
2. Filé Mignon com Fritas
3. Frango Grelhado com Legumes
4. Bacalhau à Gomes de Sá
5. Risoto de Cogumelos

#### 🍰 Sobremesas
1. Tiramisu
2. Cheesecake de Frutas Vermelhas
3. Mousse de Chocolate
4. Pudim de Leite
5. Sorvete de Baunilha com Calda de Morango

### 📝 Gerenciamento de Pedidos

#### 1️⃣ Adicionar Itens ao Pedido

```c
inserir_pedido(&cabeca, ENTRADA, 2);  // Salada Caesar
inserir_pedido(&cabeca, PRINCIPAL, 1); // Lasanha
```

**Processo**:
- Navegação por categorias
- Seleção múltipla de itens
- Confirmação de cada item
- Pedido mantido em memória até finalização

#### 2️⃣ Remover Itens do Pedido

```c
remover_pedido(&cabeca, ENTRADA, 2);  // Remove Salada Caesar
```

**Processo**:
- Visualização de todos os itens
- Seleção por categoria e código
- Remoção antes do envio para cozinha

#### 3️⃣ Finalizar Pedido

```c
// Transfere pedido para fila da cozinha
No *atual = cabeca;
while (atual != NULL) {
    inserir_fila(&cozinha, atual->tipo, atual->valor, mesa);
    atual = atual->proximo;
}
```

**Processo**:
1. Transferência automática para fila da cozinha
2. Atribuição de número de mesa
3. Liberação de memória da lista temporária
4. Incremento automático de mesa

#### 4️⃣ Visualizar Cozinha

```c
imprime_fila(&cozinha);
```

**Saída**:
```
Pedidos na cozinha:
Mesa 1 - Entrada: Sopa de Cebola
Mesa 1 - Prato Principal: Lasanha à Bolonhesa
Mesa 1 - Sobremesa: Tiramisu
Mesa 2 - Entrada: Salada Caesar
Mesa 2 - Prato Principal: Filé Mignon com Fritas
```

---

## 🚀 Instalação

### Pré-requisitos

- **Compilador C**: GCC, Clang ou MSVC
- **Make** (opcional)
- **Sistema Operacional**: Windows, Linux ou macOS

### Compilação

#### Usando Makefile (Recomendado)

```bash
# Clone o repositório
git clone https://github.com/JoaoGuilhermmy/sistema-restaurante-c.git
cd sistema-restaurante-c

# Compile
make

# Execute
./restaurante          # Linux/macOS
restaurante.exe        # Windows
```

#### Compilação Manual

```bash
# Linux/macOS
gcc -std=c99 -Wall -Wextra -o restaurante main.c lista.c fila.c

# Windows com MinGW
gcc -std=c99 -Wall -Wextra -o restaurante.exe main.c lista.c fila.c
```

---

## 💻 Como Usar

### Exemplo Completo de Uso

```
        Bem Vindo ao restaurante IMD palace

        1 - Fazer pedido
        2 - Visualizar pedidos na cozinha
        3 - Sair

Escolha: 1

        1 - Escolher Entradas
        2 - Escolher Prato Principal
        3 - Escolher Sobremesas
        4 - Remover Prato
        0 - Finalizar pedido

Escolha: 1

        Entradas:
        1. Sopa de Cebola
        2. Salada Caesar
        3. Bruschetta
        4. Carpaccio de Carne
        5. Camarao ao Alho

Digite o número: 2
Salada Caesar adicionada ao pedido
Deseja pedir outra entrada? (Sim = 1, Não = 0): 0

Escolha: 2

        Pratos Principais:
        1. Lasanha à Bolonhesa
        2. Filé Mignon com Fritas
        3. Frango Grelhado com Legumes
        4. Bacalhau à Gomes de Sá
        5. Risoto de Cogumelos

Digite o número: 1
Lasanha à Bolonhesa adicionada ao pedido
Deseja pedir outro prato principal? (Sim = 1, Não = 0): 0

Escolha: 0
Pedido enviado para a cozinha com sucesso!

--- MENU PRINCIPAL ---

Escolha: 2

Pedidos na cozinha:
Mesa 1 - Entrada: Salada Caesar
Mesa 1 - Prato Principal: Lasanha à Bolonhesa
```

---

## 🔧 Detalhes Técnicos

### Arrays Globais de Pratos

```c
// lista.c
const char *entradas[] = {
    "Sopa de Cebola",
    "Salada Caesar",
    "Bruschetta",
    "Carpaccio de Carne",
    "Camarao ao Alho"
};

const char *principais[] = {
    "Lasanha à Bolonhesa",
    "File Mignon com Fritas",
    "Frango Grelhado com Legumes",
    "Bacalhau a Gomes de Sa",
    "Risoto de Cogumelos"
};

const char *sobremesas[] = {
    "Tiramisu",
    "Cheesecake de Frutas Vermelhas",
    "Mousse de Chocolate",
    "Pudim de Leite",
    "Sorvete de Baunilha com Calda de Morango"
};
```

**Vantagem**: Centralização dos nomes, fácil manutenção e tradução.

### Compatibilidade Multiplataforma

```c
// lista.c - Limpeza de tela
void limpa_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pausa
void espera(int segundos) {
#ifdef _WIN32
    Sleep(segundos * 1000);
#else
    sleep(segundos);
#endif
}
```

### Alocação Dinâmica

```c
// Inserir na lista
void inserir_pedido(No **cabeca, TipoPrato tipo, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo->tipo = tipo;
    novo->valor = valor;
    novo->proximo = *cabeca;
    *cabeca = novo;
}

// Inserir na fila
void inserir_fila(Fila *fila, TipoPrato tipo, int valor, int mesa) {
    Pedido *novo = malloc(sizeof(Pedido));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->mesa = mesa;
    novo->tipo = tipo;
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (fila->fim == NULL) {
        fila->inicio = fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}
```

### Gerenciamento de Memória

```c
// Liberar lista após finalizar pedido
while (cabeca != NULL) {
    No *temp = cabeca;
    cabeca = cabeca->proximo;
    free(temp);
}
```

---

## 📊 Complexidade Computacional

| Operação | Complexidade | Estrutura | Justificativa |
|----------|--------------|-----------|---------------|
| Adicionar item ao pedido | O(1) | Lista Encadeada | Inserção no início |
| Remover item do pedido | O(n) | Lista Encadeada | Busca + remoção |
| Enviar pedido para cozinha | O(n) | Lista → Fila | Percorre lista |
| Inserir na fila | O(1) | Fila | Inserção no fim |
| Remover da fila | O(1) | Fila | Remoção no início |
| Visualizar fila | O(n) | Fila | Percorre todos |

---

## 🎓 Conceitos de Estruturas de Dados

### Fila (Queue) - FIFO

**Características**:
- Primeiro a Entrar, Primeiro a Sair
- Inserção no fim (`inserir_fila`)
- Remoção no início (`remover_fila`)
- Complexidade O(1) para ambas operações

**Aplicação no Projeto**:
- Ordem justa de preparo dos pedidos
- Cozinha processa na ordem de chegada

### Lista Encadeada (Linked List)

**Características**:
- Tamanho dinâmico
- Inserção eficiente no início (O(1))
- Remoção de elemento específico (O(n))
- Uso eficiente de memória

**Aplicação no Projeto**:
- Construção dinâmica do pedido
- Permite adicionar/remover itens antes de finalizar

---

## 🐛 Solução de Problemas

### Problema: Erro de compilação "undefined reference"

**Solução**:
```bash
gcc -o restaurante main.c lista.c fila.c
```

### Problema: Caracteres especiais não aparecem

**Windows**:
```bash
chcp 65001
```

**Linux/macOS**:
```bash
export LANG=pt_BR.UTF-8
```

### Problema: Vazamento de memória

**Verificação com Valgrind (Linux)**:
```bash
valgrind --leak-check=full ./restaurante
```

---

## 📈 Possíveis Melhorias

### Curto Prazo
- [ ] Adicionar preços aos pratos
- [ ] Calcular total do pedido
- [ ] Implementar sistema de comanda
- [ ] Adicionar validação de entrada

### Médio Prazo
- [ ] Interface gráfica com ncurses
- [ ] Sistema de múltiplos garçons
- [ ] Controle de estoque de ingredientes
- [ ] Tempo estimado de preparo

### Longo Prazo
- [ ] Aplicativo mobile para garçons
- [ ] Dashboard em tempo real
- [ ] Integração com impressora
- [ ] Analytics de pratos mais vendidos

---

## 📄 Licença

Este projeto está sob a licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais detalhes.

---

## 👨‍💻 Autor

**João Guilhermmy**

- 🔗 GitHub: [https://github.com/JoaoGuilhermmy](https://github.com/JoaoGuilhermmy)
- 💼 LinkedIn: [www.linkedin.com/in/joão-guilhermmy-93661b29b](https://www.linkedin.com/in/joão-guilhermmy-93661b29b)
- 📧 Email: joaoguilhermmy2@gmail.com

---

## 🙏 Agradecimentos

- Comunidade C pela documentação excelente
- Professores e colegas que contribuíram com feedback
- Stack Overflow pelas soluções de problemas

---

<div align="center">

### ⭐ Se este projeto foi útil, considere dar uma estrela!

**Desenvolvido com ❤️ e muito ☕**

### 💡 Projeto educacional demonstrando Fila e Lista Encadeada em C

</div>
