SRC_DIR=src
INC_DIR=include
BUILD_DIR=build
TEST_DIR=test

CFLAGS = -Wall -Wextra -pedantic -ansi -DENABLE_ASSERT
LDFLAGS = -lm -O3 -ffast-math

$(BUILD_DIR)/vector.o: $(SRC_DIR)/vector.c
	$(CC) -c $< -I./$(INC_DIR)/ $(CFLAGS) -o $@
$(BUILD_DIR)/matrix.o: $(SRC_DIR)/matrix.c
	$(CC) -c $< -I./$(INC_DIR)/ $(CFLAGS) -o $@

$(BUILD_DIR)/libelm.a:  $(BUILD_DIR)/vector.o\
												$(BUILD_DIR)/matrix.o
	$(AR) rcs $@ $(BUILD_DIR)/*.o

$(BUILD_DIR)/test: $(BUILD_DIR)/libelm.a
	$(CC) $(TEST_DIR)/*.c $< -I$(INC_DIR) $(CFLAGS) -o $@ $(LDFLAGS)

.PHONY: test build clean

test: $(BUILD_DIR)/test
	$(BUILD_DIR)/test

build: $(BUILD_DIR)/libelm.a

clean:
	rm -rf $(BUILD_DIR)/*
