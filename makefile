# Nome do executável
TARGET = restaurante

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99

# Arquivos-fonte
SRC = main.c lista.c fila.c
OBJ = $(SRC:.c=.o)

# Regra principal
all: $(TARGET)

# Como gerar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regra para gerar os .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f *.o $(TARGET)
