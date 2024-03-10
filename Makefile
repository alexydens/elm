# Directories
SRC_DIR=src
INC_DIR=include
BUILD_DIR=build
TEST_DIR=test

# Compilation and linking flags
CFLAGS = -Wall -Wextra -pedantic -ansi -DENABLE_ASSERT
LDFLAGS = -lm -O3 -ffast-math

# Object files
$(BUILD_DIR)/vector.o: $(SRC_DIR)/vector.c
	$(CC) -c $< -I./$(INC_DIR)/ $(CFLAGS) -o $@
$(BUILD_DIR)/matrix.o: $(SRC_DIR)/matrix.c
	$(CC) -c $< -I./$(INC_DIR)/ $(CFLAGS) -o $@
# Actual library
$(BUILD_DIR)/libelm.a:  $(BUILD_DIR)/vector.o\
												$(BUILD_DIR)/matrix.o
	$(AR) rcs $@ $(BUILD_DIR)/*.o
# Test app
$(BUILD_DIR)/test: $(BUILD_DIR)/libelm.a
	$(CC) $(TEST_DIR)/*.c $< -I$(INC_DIR) $(CFLAGS) -o $@ $(LDFLAGS)

# Phony rules
.PHONY: test build clean

# Run test app
test: $(BUILD_DIR)/test
	$(BUILD_DIR)/test

# Build library
build: $(BUILD_DIR)/libelm.a

# Clear build directory
clean:
	rm -rf $(BUILD_DIR)/*
