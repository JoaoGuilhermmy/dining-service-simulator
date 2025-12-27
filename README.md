# 🍽️ Sistema de Gerenciamento de Restaurante em C

<div align="center">

![C](https://img.shields.io/badge/C-99-blue?style=for-the-badge&logo=c)
![Cross-Platform](https://img.shields.io/badge/Platform-Cross--Platform-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**Sistema completo de gerenciamento de pedidos para restaurantes usando Estruturas de Dados**

[📖 Sobre](#sobre-o-projeto) • [🚀 Instalação](#instalação) • [💡 Funcionalidades](#funcionalidades) • [🏗️ Arquitetura](#arquitetura)

---

**[🇺🇸 English Version](README.en.md)**

</div>

---

## 📋 Sobre o Projeto

O **IMD Palace Restaurant System** é um sistema de gerenciamento de pedidos desenvolvido em C que simula o fluxo completo de um restaurante. Utiliza **Filas (Queue)** para gerenciar a ordem de preparo na cozinha e **Listas Encadeadas** para montar o pedido de cada mesa antes do envio.

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

## ✨ Funcionalidades

### 🍽️ Cardápio Disponível

#### 🥗 Entradas
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

#### Adicionar Itens ao Pedido
- Navegação por categorias (Entrada/Principal/Sobremesa)
- Seleção múltipla de itens por categoria
- Confirmação de cada item adicionado
- Pedido mantido em memória até finalização

#### Remover Itens do Pedido
- Visualização de todos os itens do pedido atual
- Seleção por categoria e código
- Remoção antes do envio para cozinha
- Opção de cancelar a remoção

#### Finalizar Pedido
- Transferência automática para fila da cozinha
- Atribuição de número de mesa
- Liberação de memória da lista temporária
- Incremento automático de mesa para próximo pedido

### 👨‍🍳 Visualização da Cozinha

```
Pedidos na cozinha:
Mesa 1 - Entrada: Sopa de Cebola
Mesa 1 - Prato Principal: Lasanha à Bolonhesa
Mesa 1 - Sobremesa: Tiramisu
Mesa 2 - Entrada: Salada Caesar
Mesa 2 - Prato Principal: Filé Mignon com Fritas
```

- Ordem FIFO respeitada
- Identificação clara de mesa e tipo de prato
- Atualização em tempo real

---

## 🏗️ Arquitetura

### Estrutura do Projeto

```
restaurante/
├── fila.c              # Implementação da fila (cozinha)
├── fila.h              # Interface da fila
├── lista.c             # Implementação da lista encadeada (pedido)
├── lista.h             # Interface da lista + arrays de pratos
├── main.c              # Ponto de entrada e interface do usuário
└── makefile            # Script de compilação
```

### Estruturas de Dados

#### 1. **Lista Encadeada** (Pedido Temporário)
```c
typedef struct no {
    TipoPrato tipo;      // ENTRADA, PRINCIPAL, SOBREMESA
    int valor;           // Código do prato (1-5)
    struct no *proximo;
} No;
```

**Uso:** Armazena temporariamente os itens do pedido de uma mesa antes do envio para cozinha.

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

**Uso:** Mantém ordem de preparo dos pedidos (primeiro a entrar, primeiro a sair).

### Diagrama de Fluxo

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

### Gerenciamento de Memória

**Alocação Dinâmica:**
```c
// Ao adicionar item ao pedido
No *novo = malloc(sizeof(No));

// Ao enviar para fila da cozinha
Pedido *novo = malloc(sizeof(Pedido));
```

**Liberação:**
```c
// Após enviar pedido, libera lista temporária
while (cabeca != NULL) {
    No *temp = cabeca;
    cabeca = cabeca->proximo;
    free(temp);
}
```

---

## 🚀 Instalação

### Pré-requisitos

- 🔧 **Compilador C:** GCC, Clang, ou MSVC
- 📦 **Make** (opcional, mas recomendado)
- 💻 **Sistema Operacional:** Windows, Linux ou macOS

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
gcc -std=c99 -o restaurante main.c lista.c fila.c

# Windows com MinGW
gcc -std=c99 -o restaurante.exe main.c lista.c fila.c
```

---

## 💻 Como Usar

### Fluxo Básico

```
1. Inicie o programa
   ↓
2. Selecione "1 - Fazer pedido"
   ↓
3. Escolha itens das categorias (Entradas, Principal, Sobremesas)
   ↓
4. Revise e remova itens se necessário (opção 4)
   ↓
5. Finalize o pedido (opção 0)
   ↓
6. Visualize a fila da cozinha (opção 2)
   ↓
7. Saia do programa (opção 3)
```

### Exemplo de Uso Completo

```
Bem Vindo ao restaurante IMD palace

1 - Fazer pedido
2 - Visualizar pedidos na cozinha
3 - Sair

Escolha: 1

--- MONTAGEM DO PEDIDO ---

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
5. Camarão ao Alho

Digite o número (0 para sair): 2

Salada Caesar adicionada ao pedido

Deseja pedir outra entrada? (Sim = 1, Não = 0): 0

--- MONTAGEM DO PEDIDO ---

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

--- MONTAGEM DO PEDIDO ---

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

### Compatibilidade Multiplataforma

```c
// lista.c - Limpeza de tela
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

// Delay de tela
#ifdef _WIN32
    Sleep(segundos * 1000);
#else
    sleep(segundos);
#endif
```

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
```

**Vantagem:** Centralização dos nomes, fácil manutenção e tradução.

### Enum para Tipos

```c
typedef enum {
    ENTRADA,
    PRINCIPAL,
    SOBREMESA
} TipoPrato;
```

**Benefício:** Type-safety e legibilidade do código.

---

## 🎓 Conceitos de Estruturas de Dados

### Fila (Queue) - FIFO

**Características:**
- ✅ Primeiro a Entrar, Primeiro a Sair
- ✅ Inserção no fim (`inserir_fila`)
- ✅ Remoção no início (`remover_fila`)
- ✅ Complexidade O(1) para ambas operações

**Aplicação no Projeto:**
- Ordem justa de preparo dos pedidos
- Cozinha processa na ordem de chegada

### Lista Encadeada (Linked List)

**Características:**
- ✅ Tamanho dinâmico
- ✅ Inserção eficiente no início (O(1))
- ✅ Remoção de elemento específico (O(n))
- ✅ Uso eficiente de memória

**Aplicação no Projeto:**
- Construção dinâmica do pedido
- Permite adicionar/remover itens antes de finalizar

---

## 📊 Complexidade Computacional

| Operação | Complexidade | Estrutura |
|----------|--------------|-----------|
| Adicionar item ao pedido | O(1) | Lista Encadeada |
| Remover item do pedido | O(n) | Lista Encadeada |
| Enviar pedido para cozinha | O(n) | Lista → Fila |
| Inserir na fila | O(1) | Fila |
| Remover da fila | O(1) | Fila |
| Visualizar fila | O(n) | Fila |

---

## 🚀 Melhorias Futuras

### Curto Prazo
- [ ] Adicionar preços aos pratos
- [ ] Calcular total do pedido
- [ ] Implementar sistema de comanda
- [ ] Adicionar data/hora aos pedidos
- [ ] Salvar histórico em arquivo

### Médio Prazo
- [ ] Interface gráfica com ncurses (Linux) ou conio (Windows)
- [ ] Sistema de múltiplos garçons
- [ ] Controle de estoque de ingredientes
- [ ] Tempo estimado de preparo
- [ ] Sistema de prioridade (VIP)

### Longo Prazo
- [ ] Aplicativo mobile para garçons (React Native)
- [ ] Dashboard em tempo real (web)
- [ ] Integração com impressora de pedidos
- [ ] Analytics de pratos mais vendidos
- [ ] Sistema de reservas de mesas

---

## 🐛 Troubleshooting

### Problema: Caracteres especiais não aparecem corretamente

**Solução Windows:**
```bash
# Execute o terminal com codificação UTF-8
chcp 65001
```

**Solução Linux/macOS:**
```bash
# Verifique locale
locale

# Se necessário, exporte UTF-8
export LANG=pt_BR.UTF-8
```

### Problema: Erro de compilação "undefined reference"

**Causa:** Arquivos não foram linkados corretamente.

**Solução:**
```bash
# Certifique-se de compilar TODOS os .c juntos
gcc -o restaurante main.c lista.c fila.c
```

### Problema: Vazamento de memória

**Verificação com Valgrind (Linux):**
```bash
valgrind --leak-check=full ./restaurante
```

---

## 🤝 Contribuindo

Contribuições são muito bem-vindas!

1. Fork o projeto
2. Crie uma branch (`git checkout -b feature/MinhaFeature`)
3. Commit suas mudanças (`git commit -m 'Adiciona MinhaFeature'`)
4. Push para a branch (`git push origin feature/MinhaFeature`)
5. Abra um Pull Request

### Ideias para Contribuição
- 🎨 Adicionar cores ao menu (ANSI codes)
- 💾 Implementar persistência de dados
- 🧪 Criar testes unitários
- 📖 Traduzir para outros idiomas
- 🔒 Adicionar autenticação de garçons

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
- Stack Overflow pelas soluções de problemas comuns

---

<div align="center">

### ⭐ Se este projeto foi útil, considere dar uma estrela!

**Desenvolvido com ❤️ e muito ☕**

### 💡 Projeto educacional para demonstrar Estruturas de Dados em C

</div>
