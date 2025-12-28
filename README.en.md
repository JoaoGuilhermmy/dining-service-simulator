# 🍽️ Restaurant Management System

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-Queue%20%7C%20Linked%20List-orange?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Cross--Platform-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**Complete order management system for restaurants using Queue and Linked List**

[🇧🇷 Versão em Português](README.md) | [📖 About](#-about-the-project) | [🚀 Installation](#-installation) | [💡 Features](#-features)

---

</div>

## 📋 About the Project

The **IMD Palace Restaurant System** is an order management system developed in C that simulates the complete flow of a restaurant. It uses:

- **Queue**: To manage the preparation order in the kitchen (FIFO)
- **Linked List**: To assemble each table's order before sending

### 🎯 Objectives

- Demonstrate mastery of **Fundamental Data Structures** in C
- Implement **Queue (FIFO)** for order preparation sequence
- Use **Linked List** for dynamic order composition
- Create system with **dynamic memory allocation**
- Apply **modular programming** with multiple files

### ✨ Key Features

- 🍕 **Complete Menu** - Appetizers, main courses and desserts
- 📋 **Order System** - Dynamic assembly per table
- 🔥 **Kitchen Queue** - Preparation order respected (FIFO)
- 🗑️ **Item Removal** - Order modification before sending
- 🖥️ **Interactive Interface** - Intuitive console menu
- 🔄 **Cross-Platform** - Compatible with Windows, Linux and macOS

---

## 🏗️ Architecture

### Directory Structure

```
restaurant/
├── fila.c              # Queue implementation (kitchen)
├── fila.h              # Queue interface
├── lista.c             # Linked list implementation (order)
├── lista.h             # List interface + dish arrays
├── main.c              # Entry point and user interface
└── makefile            # Build script
```

### 📊 Data Structures

#### 1. **Linked List** (Temporary Order)

```c
typedef enum {
    ENTRADA,
    PRINCIPAL,
    SOBREMESA
} TipoPrato;

typedef struct no {
    TipoPrato tipo;      // ENTRADA, PRINCIPAL, SOBREMESA
    int valor;           // Dish code (1-5)
    struct no *proximo;
} No;
```

**Usage**: Temporarily stores table order items before sending to kitchen.

**Advantages**:
- ✅ Dynamic size
- ✅ O(1) insertion at beginning
- ✅ Facilitates item addition/removal

#### 2. **Queue** (Kitchen)

```c
typedef struct Pedido {
    int mesa;               // Table number
    TipoPrato tipo;         // Dish type
    int valor;              // Dish code
    struct Pedido *proximo;
} Pedido;

typedef struct {
    Pedido *inicio;
    Pedido *fim;
} Fila;
```

**Usage**: Maintains order preparation sequence (first in, first out).

**Advantages**:
- ✅ FIFO guaranteed
- ✅ O(1) insertion at end
- ✅ O(1) removal at beginning

### 🔄 Data Flow

```
┌─────────────────┐
│  Customer Table 1│
│ Start Order     │
└────────┬────────┘
         │
         ▼
┌─────────────────────────────┐
│  Linked List (Order)        │
│  ┌───┐   ┌───┐   ┌───┐     │
│  │ A ├──►│ M ├──►│ D │     │
│  └───┘   └───┘   └───┘     │
│  Appetizer  Main  Dessert   │
└────────┬────────────────────┘
         │ Finalize Order
         ▼
┌─────────────────────────────┐
│    Kitchen Queue (FIFO)     │
│  ┌────┐  ┌────┐  ┌────┐    │
│  │T1A │→ │T1M │→ │T1D │→...│
│  └────┘  └────┘  └────┘    │
│  start              end      │
└─────────────────────────────┘
         │
         ▼
┌─────────────────┐
│   Preparation   │
│   in Kitchen    │
└─────────────────┘
```

---

## 💡 Features

### 🥗 Available Menu

#### Appetizers
1. Onion Soup
2. Caesar Salad
3. Bruschetta
4. Beef Carpaccio
5. Garlic Shrimp

#### 🍝 Main Courses
1. Lasagna Bolognese
2. Filet Mignon with Fries
3. Grilled Chicken with Vegetables
4. Codfish à Gomes de Sá
5. Mushroom Risotto

#### 🍰 Desserts
1. Tiramisu
2. Red Fruit Cheesecake
3. Chocolate Mousse
4. Milk Pudding
5. Vanilla Ice Cream with Strawberry Sauce

### 📝 Order Management

#### 1️⃣ Add Items to Order

```c
inserir_pedido(&cabeca, ENTRADA, 2);  // Caesar Salad
inserir_pedido(&cabeca, PRINCIPAL, 1); // Lasagna
```

**Process**:
- Navigation by categories
- Multiple item selection
- Confirmation of each item
- Order kept in memory until finalization

#### 2️⃣ Remove Items from Order

```c
remover_pedido(&cabeca, ENTRADA, 2);  // Remove Caesar Salad
```

**Process**:
- View all items
- Selection by category and code
- Removal before sending to kitchen

#### 3️⃣ Finalize Order

```c
// Transfer order to kitchen queue
No *atual = cabeca;
while (atual != NULL) {
    inserir_fila(&cozinha, atual->tipo, atual->valor, mesa);
    atual = atual->proximo;
}
```

**Process**:
1. Automatic transfer to kitchen queue
2. Table number assignment
3. Temporary list memory release
4. Automatic table increment

#### 4️⃣ View Kitchen

```c
imprime_fila(&cozinha);
```

**Output**:
```
Orders in kitchen:
Table 1 - Appetizer: Onion Soup
Table 1 - Main Course: Lasagna Bolognese
Table 1 - Dessert: Tiramisu
Table 2 - Appetizer: Caesar Salad
Table 2 - Main Course: Filet Mignon with Fries
```

---

## 🚀 Installation

### Prerequisites

- **C Compiler**: GCC, Clang or MSVC
- **Make** (optional)
- **Operating System**: Windows, Linux or macOS

### Compilation

#### Using Makefile (Recommended)

```bash
# Clone the repository
git clone https://github.com/JoaoGuilhermmy/restaurant-system-c.git
cd restaurant-system-c

# Compile
make

# Run
./restaurante          # Linux/macOS
restaurante.exe        # Windows
```

#### Manual Compilation

```bash
# Linux/macOS
gcc -std=c99 -Wall -Wextra -o restaurante main.c lista.c fila.c

# Windows with MinGW
gcc -std=c99 -Wall -Wextra -o restaurante.exe main.c lista.c fila.c
```

---

## 💻 How to Use

### Complete Usage Example

```
        Welcome to IMD palace restaurant

        1 - Place order
        2 - View orders in kitchen
        3 - Exit

Choice: 1

        1 - Choose Appetizers
        2 - Choose Main Course
        3 - Choose Desserts
        4 - Remove Dish
        0 - Finalize order

Choice: 1

        Appetizers:
        1. Onion Soup
        2. Caesar Salad
        3. Bruschetta
        4. Beef Carpaccio
        5. Garlic Shrimp

Enter number: 2
Caesar Salad added to order
Want another appetizer? (Yes = 1, No = 0): 0

Choice: 2

        Main Courses:
        1. Lasagna Bolognese
        2. Filet Mignon with Fries
        3. Grilled Chicken with Vegetables
        4. Codfish à Gomes de Sá
        5. Mushroom Risotto

Enter number: 1
Lasagna Bolognese added to order
Want another main course? (Yes = 1, No = 0): 0

Choice: 0
Order sent to kitchen successfully!

--- MAIN MENU ---

Choice: 2

Orders in kitchen:
Table 1 - Appetizer: Caesar Salad
Table 1 - Main Course: Lasagna Bolognese
```

---

## 🔧 Technical Details

### Global Dish Arrays

```c
// lista.c
const char *entradas[] = {
    "Onion Soup",
    "Caesar Salad",
    "Bruschetta",
    "Beef Carpaccio",
    "Garlic Shrimp"
};

const char *principais[] = {
    "Lasagna Bolognese",
    "Filet Mignon with Fries",
    "Grilled Chicken with Vegetables",
    "Codfish a Gomes de Sa",
    "Mushroom Risotto"
};

const char *sobremesas[] = {
    "Tiramisu",
    "Red Fruit Cheesecake",
    "Chocolate Mousse",
    "Milk Pudding",
    "Vanilla Ice Cream with Strawberry Sauce"
};
```

**Advantage**: Name centralization, easy maintenance and translation.

### Cross-Platform Compatibility

```c
// lista.c - Screen clearing
void limpa_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pause
void espera(int segundos) {
#ifdef _WIN32
    Sleep(segundos * 1000);
#else
    sleep(segundos);
#endif
}
```

### Dynamic Allocation

```c
// Insert in list
void inserir_pedido(No **cabeca, TipoPrato tipo, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Memory allocation error.\n");
        return;
    }
    novo->tipo = tipo;
    novo->valor = valor;
    novo->proximo = *cabeca;
    *cabeca = novo;
}

// Insert in queue
void inserir_fila(Fila *fila, TipoPrato tipo, int valor, int mesa) {
    Pedido *novo = malloc(sizeof(Pedido));
    if (novo == NULL) {
        printf("Memory allocation error!\n");
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

### Memory Management

```c
// Free list after finalizing order
while (cabeca != NULL) {
    No *temp = cabeca;
    cabeca = cabeca->proximo;
    free(temp);
}
```

---

## 📊 Computational Complexity

| Operation | Complexity | Structure | Justification |
|-----------|------------|-----------|---------------|
| Add item to order | O(1) | Linked List | Insert at beginning |
| Remove item from order | O(n) | Linked List | Search + removal |
| Send order to kitchen | O(n) | List → Queue | Traverse list |
| Insert in queue | O(1) | Queue | Insert at end |
| Remove from queue | O(1) | Queue | Remove at beginning |
| View queue | O(n) | Queue | Traverse all |

---

## 🎓 Data Structures Concepts

### Queue - FIFO

**Characteristics**:
- First In, First Out
- Insertion at end (`inserir_fila`)
- Removal at beginning (`remover_fila`)
- O(1) complexity for both operations

**Application in Project**:
- Fair order preparation sequence
- Kitchen processes in arrival order

### Linked List

**Characteristics**:
- Dynamic size
- Efficient insertion at beginning (O(1))
- Specific element removal (O(n))
- Efficient memory usage

**Application in Project**:
- Dynamic order construction
- Allows adding/removing items before finalization

---

## 🐛 Troubleshooting

### Problem: "undefined reference" compilation error

**Solution**:
```bash
gcc -o restaurante main.c lista.c fila.c
```

### Problem: Special characters don't appear

**Windows**:
```bash
chcp 65001
```

**Linux/macOS**:
```bash
export LANG=en_US.UTF-8
```

### Problem: Memory leak

**Check with Valgrind (Linux)**:
```bash
valgrind --leak-check=full ./restaurante
```

---

## 📈 Possible Improvements

### Short Term
- [ ] Add prices to dishes
- [ ] Calculate order total
- [ ] Implement ticket system
- [ ] Add input validation

### Medium Term
- [ ] GUI with ncurses
- [ ] Multiple waiter system
- [ ] Ingredient inventory control
- [ ] Estimated preparation time

### Long Term
- [ ] Mobile app for waiters
- [ ] Real-time dashboard
- [ ] Printer integration
- [ ] Best-selling dishes analytics

---

## 📄 License

This project is under the MIT license. See the [LICENSE](LICENSE) file for more details.

---

## 👨‍💻 Author

**João Guilhermmy**

- 🔗 GitHub: [https://github.com/JoaoGuilhermmy](https://github.com/JoaoGuilhermmy)
- 💼 LinkedIn: [www.linkedin.com/in/joão-guilhermmy-93661b29b](https://www.linkedin.com/in/joão-guilhermmy-93661b29b)
- 📧 Email: joaoguilhermmy2@gmail.com

---

## 🙏 Acknowledgments

- C community for excellent documentation
- Professors and colleagues who contributed with feedback
- Stack Overflow for problem solutions

---

<div align="center">

### ⭐ If this project was useful, consider giving it a star!

**Developed with ❤️ and lots of ☕**

### 💡 Educational project demonstrating Queue and Linked List in C

</div>
