#====================================================
#     Variables
#====================================================
TARGET_EXEC := main
TEST_EXEC := tests
CC := g++
BUILD_DIR := bin
SRC_DIR := src
TEST_DIR := test
OBJ_DIR := obj

#====================================================
#     Source files
#====================================================
SRC := $(shell find $(SRC_DIR) -name '*.cpp')
TEST := $(shell find $(SRC_DIR) -type f | grep -v 'main.cpp') $(shell find $(TEST_DIR) -name '*.cpp')
OBJ := $(SRC:%=$(OBJ_DIR)/%.o)
TEST_OBJ := $(TEST:%=$(OBJ_DIR)/%.o)

#====================================================
#     Dependencies and flags
#====================================================
DEPS := $(OBJ:.o=.d)
INC_DIR := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIR))
WFLAGS := -Wall -Wextra -Wno-unused
CPPFLAGS := -std=c++17 -g $(LDFLAGS) $(INC_FLAGS) -MMD -MP $(WFLAGS)
LDFLAGS := -losmanip -larsenalgear

#====================================================
#     Aliases
#====================================================
.PHONY: clean all

#====================================================
#     Building
#====================================================

#Building all:
all: $(BUILD_DIR)/$(TARGET_EXEC) $(BUILD_DIR)/$(TEST_EXEC)
main: $(BUILD_DIR)/$(TARGET_EXEC)
tests: $(BUILD_DIR)/$(TEST_EXEC)

#Building main executable:
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJ)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

#Building test executable:
$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJ)
	@ mkdir -p $(dir $@)
	$(CC) $(TEST_OBJ) -o $@ $(LDFLAGS)

#Put object files into the object dir:
$(OBJ_DIR)/%.cpp.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#====================================================
#     Clean
#====================================================
clean:
	rm -r $(OBJ_DIR) $(BUILD_DIR)

#====================================================
#     Include
#====================================================
-include $(DEPS)