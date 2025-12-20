TARGET=01
BUILD_DIR=build

all:
	mkdir -p $(BUILD_DIR)
	riscv64-linux-gnu-as -o $(BUILD_DIR)/$(TARGET).o $(TARGET).s
	riscv64-linux-gnu-ld -o $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/$(TARGET).o

run: all
	qemu-riscv64 ./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
