SRC_DIR = src
LIB_DIR = lib
OBJ_DIR = obj

dir_guard=@mkdir -p $(@D)

LIB_NAME = family_tree
LIB = $(LIB_DIR)/$(LIB_NAME).a 

LIB_MODULES = Person \
          FamilyTree \
          HumanityTree
                     
LIB_OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIB_MODULES) ))

.PHONY: all build clean

build: $(LIB)

all: clean build 
	
$(LIB): $(LIB_OBJECTS)
	$(dir_guard)
	ar rcs $@ $^
	  		
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(dir_guard)
	g++ -std=c++11 -c -o $@ $^  

clean: clean_samples
	rm -f ./$(OBJ_DIR)/*.o
	rm -f ./$(LIB_DIR)/*.a	
		 	
#  !!!Unit test part!!!  
TEST_DIR = test  
TEST_SUFIX =_test
TEST_MODULES = Person_test                            
TEST_OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(TEST_MODULES)))
UNIT_TESTS = $(addprefix $(TEST_DIR)/, $(addsuffix $(TEST_SUFIX), $(LIB_NAME)))
# Flags passed to the C++ compiler to compile gtests
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11

.PHONY: tests utest_build_print

tests:  gtests utest_build_print $(UNIT_TESTS)
	@echo -----------Run Unit Tests-------------
	$(UNIT_TESTS)
	
$(UNIT_TESTS): $(LIB_OBJECTS) $(TEST_OBJECTS) 
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_LIB) -lpthread

utest_build_print:
	@echo --------Build Unit Tests-----------

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(dir_guard)
	g++ $(CXXFLAGS) -I$(SRC_DIR) -I$(GTEST_DIR)/include  -c -o $@ $^ -lpthread  
 
include googletests.mk

#  !!!Sample part!!!
.PHONY: samples clean_samples
SAM_DIR = samples
SAMPLES = $(SAM_DIR)/Person_sample \
          $(SAM_DIR)/FamilyTree_sample
          
samples: $(SAMPLES)

$(SAM_DIR)/%_sample: $(SAM_DIR)/%_sample.cpp $(LIB)   
	$(dir_guard)
	g++ -o $@ $< $(LIB) -I$(SRC_DIR) 

clean_samples:
	rm -f $(SAMPLES)	
