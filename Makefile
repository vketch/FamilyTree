
SRC_DIR = src
LIB_DIR = lib
OBJ_DIR = obj
BIN_DIR = bin

LIB_NAME = FamilyTree
LIB = $(LIB_DIR)/$(LIB_NAME).a 

LIB_MODULES = Person \
          FamilyTree \
          HumanityTree
           
LIB_OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIB_MODULES) ))

TEST_MODULES = $(addsuffix _test, $(LIB_MODULES))
TEST_OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(TEST_MODULES)))
TESTS = $(addprefix $(BIN_DIR)/, $(TEST_MODULES))

.PHONY: all build clean tests

build: $(LIB)
	
$(LIB): $(LIB_OBJECTS)
	ar rcs $@ $<

all: clean build tests

tests: $(TESTS)  

run_tests:
	$(TESTS)
	
$(TESTS): $(LIB_OBJECTS) $(TEST_OBJECTS)
	g++ -o $@ $^
		
clean:
	rm -f $(LIB_OBJECTS) 
	rm -f $(TEST_OBJECTS)
	rm -f $(TESTS)
	
obj/%.o: src/%.cpp
	g++ -c -o $@ $^  

