
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

.PHONY: all build clean test

build: $(LIB) 
	
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
#	rm -f $(TESTS)

all: clean build test

TEST_SUFIX =_test
#TEST_MODULES = $(addsuffix $(TEST_SUFIX), $(LIB_MODULES))
TEST_MODULES = Person_test                              
TEST_OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(TEST_MODULES)))
UNIT_TESTS = $(addprefix $(TEST_DIR)/, $(addsuffix $(TEST_SUFIX), $(LIB_NAME)))

tests: $(UNIT_TESTS)
	@echo $(UNIT_TESTS) 

$(UNIT_TESTS) : $(LIB_OBJECTS) $(TEST_OBJECTS) gtest.a gtest_main.a
	g++ -o $@ $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ 

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = ../../googletest/googletest/

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

#sample1.o : $(USER_DIR)/sample1.cc $(USER_DIR)/sample1.h $(GTEST_HEADERS)
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1.cc

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(dir_guard)
	g++ $(CPPFLAGS) $(CXXFLAGS) -I$(SRC_DIR)  -c -o $@ $^  

#sample1_unittest.o : $(USER_DIR)/sample1_unittest.cc \
#                     $(USER_DIR)/sample1.h $(GTEST_HEADERS)
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1_unittest.cc





















#### Google Unit Tests ######
 				
#run_tests: $(TESTS) 
#	$(TESTS)

#$(TESTS): $(LIB) $(TEST_OBJECTS)
	
## setup environment  	
#setup: gtest
#	  		
### Google test #####
## Google dir
#GTESTS_ROOT = ./googletest
#
##include tunned gtest make  file
##include gmakefile.mk
#	
## Google test repository  	
#GT_REPO  = https://github.com/google/googletest.git
#
##gtest libs
#GR_LIB =  $(LIB_DIR)/gtest.a $(LIB_DIR)/gtest_main.a  
#
#gtest: gt_clone $(GR_LIB)  
#
#gt_clone:
#	rm -rf $(GTESTS_ROOT) 
#	git clone $(GT_REPO)
## Google Test #####	

