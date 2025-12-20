TARGET=cod
BUILD_DIR=build

AS=riscv64-linux-gnu-as
CC=riscv64-linux-gnu-gcc
CFLAGS=-O2 -static

SRC_C=main.c
SRC_S=cod.s
OBJ_C=$(BUILD_DIR)/main.o
OBJ_S=$(BUILD_DIR)/cod.o
BIN=$(BUILD_DIR)/$(TARGET)

all: $(BIN)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ_S): $(SRC_S) | $(BUILD_DIR)
	$(AS) -o $(OBJ_S) $(SRC_S)

$(OBJ_C): $(SRC_C) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $(OBJ_C) $(SRC_C)

$(BIN): $(OBJ_S) $(OBJ_C)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ_C) $(OBJ_S)

run: all
	qemu-riscv64 ./$(BIN)

clean:
	rm -rf $(BUILD_DIR)
