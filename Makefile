
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

#TEST_SUFIX =_test
#TEST_MODULES = $(addsuffix $(TEST_SUFIX), $(LIB_MODULES))
#TEST_OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(TEST_MODULES)))
#TESTS = $(addprefix $(BIN_DIR)/, $(TEST_MODULES))

.PHONY: all build clean test

build: $(LIB) 
	
$(LIB): $(LIB_OBJECTS)
	$(dir_guard)
	ar rcs $@ $^
	
$(TESTS): $(LIB) $(TEST_OBJECTS)  

all: clean build test
		
clean:
	rm -f $(LIB_OBJECTS) 
	rm -f $(TEST_OBJECTS)
#	rm -f $(TESTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(dir_guard)
	g++ -c -o $@ $^  

$(BIN_DIR)/%: $(OBJ_DIR)/%.o 
	$(dir_guard)
	g++ -o $@ $< $(LIB) 
				
#run_tests: $(TESTS) 
#	$(TESTS)
	
# setup environment  	
setup: gtest
	  		
## Google test #####
# Google dir
GTESTS_ROOT = ./googletest

#include tunned gtest make  file
include gmakefile.mk
	
# Google test repository  	
GT_REPO  = https://github.com/google/googletest.git

#gtest libs
GR_LIB =  $(LIB_DIR)/gtest.a $(LIB_DIR)/gtest_main.a  

gtest: gt_clone $(GR_LIB)  

gt_clone:
	rm -rf $(GTESTS_ROOT) 
	git clone $(GT_REPO)
## Google Test #####	

