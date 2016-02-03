
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
#TEST_OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(TEST_MODULES)))
#TESTS = $(addprefix $(BIN_DIR)/, $(TEST_MODULES))

.PHONY: all build clean init tests

build: $(LIB)
	
$(LIB): $(LIB_OBJECTS)
	ar rcs $@ $<
	
$(TESTS): $(LIB_OBJECTS) $(TEST_OBJECTS)
	g++ -o $@ $^

all: clean build tests 

run_tests: $(TESTS) 
	$(TESTS)
		
clean:
	rm -f $(LIB_OBJECTS) 
	rm -f $(TEST_OBJECTS)
	rm -f $(TESTS)
		
obj/%.o: src/%.cpp
	g++ -c -o $@ $^  
	
	
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

