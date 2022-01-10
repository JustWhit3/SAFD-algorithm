#====================================================
#     VARIABLES
#====================================================
TARGET_EXEC := main.exe
TEST_EXEC := tests.exe
CC := g++
BUILD_DIR := bin
SRC_DIR := src
TEST_DIR := test
OBJ_DIR := obj

#====================================================
#     SOURCE FILES
#====================================================
SRC := $(shell find $(SRC_DIR) -name '*.cpp')
TEST := $(shell find $(SRC_DIR) -type f | grep -v 'main.cpp') $(shell find $(TEST_DIR) -name '*.cpp')
OBJ := $(SRC:%=$(OBJ_DIR)/%.o)
TEST_OBJ := $(TEST:%=$(OBJ_DIR)/%.o)

#====================================================
#     DEPENDENCIES AND FLAGS
#====================================================
DEPS := $(OBJ:.o=.d)
INC_DIR := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIR))
CPPFLAGS := -g $(INC_FLAGS) -MMD -MP

#====================================================
#     ALIASES
#====================================================
.PHONY: clean all

#====================================================
#     BUILDING
#====================================================

#Building all:
all: $(BUILD_DIR)/$(TARGET_EXEC) $(BUILD_DIR)/$(TEST_EXEC)

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
#     CLEAN
#====================================================
clean:
	rm -r $(OBJ_DIR) $(BUILD_DIR)

#====================================================
#     INCLUDE
#====================================================
-include $(DEPS)