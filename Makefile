SRC_DIR = src
LIB_DIR = lib
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test

dir_guard=@mkdir -p $(@D)

LIB_NAME = family_tree
LIB = $(LIB_DIR)/$(LIB_NAME).a 

LIB_MODULES = Person \
          FamilyTree \
          HumanityTree
           
LIB_OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIB_MODULES) ))

.PHONY: all build clean tests

build: $(LIB)

all: clean build 
	
$(LIB): $(LIB_OBJECTS)
	$(dir_guard)
	ar rcs $@ $^
	  		
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(dir_guard)
	g++ -c -o $@ $^  

$(BIN_DIR)/%: $(OBJ_DIR)/%.o 
	$(dir_guard)
	g++ -o $@ $< $(LIB) 

clean:
	rm -f ./$(OBJ_DIR)/*.o
	rm -f ./$(LIB_DIR)/*.a	 
	rm -f ./$(BIN_DIR)/*
	rm -f  gtest.a gtest_main.a *.o	


#  !!!Unit tests part!!!  
TEST_SUFIX =_test
TEST_MODULES = Person_test                             
TEST_OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(TEST_MODULES)))
UNIT_TESTS = $(addprefix $(TEST_DIR)/, $(addsuffix $(TEST_SUFIX), $(LIB_NAME)))
# Flags passed to the C++ compiler to compile gtests
CXXFLAGS += -g -Wall -Wextra -pthread

tests: gtests $(UNIT_TESTS)
	$(UNIT_TESTS)

$(UNIT_TESTS) : $(LIB_OBJECTS) $(TEST_OBJECTS) 
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_LIB) -lpthread

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(dir_guard)
	g++ $(CXXFLAGS) -I$(SRC_DIR) -I$(GTEST_DIR)/include  -c -o $@ $^ -lpthread  
 
include googletests.mk


