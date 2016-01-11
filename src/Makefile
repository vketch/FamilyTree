
LIB_NAME = FamilyTree

LIB_MODULES = Person \
          FamilyTree 

LIB_OBJECTS = $(addsuffix .o, $(LIB_MODULES))
TEST_MODULES = $(addsuffix _test, $(LIB_MODULES))
TEST_OBJECTS = $(addsuffix .o, $(TEST_MODULES))
TESTS = $(addprefix ./, $(TEST_MODULES))

.PHONY: all build clean tests

build: $(LIB_NAME).a

$(LIB_NAME).a: $(LIB_OBJECTS)

all: clean build tests

tests: $(TESTS) 

run_tests:
	$(TESTS)
	
$(TESTS): $(LIB_OBJECTS) $(TEST_OBJECTS)
	g++ -o $@ $^
		
clean:
	rm -f *.o
	rm -f $(TESTS)
	
%.o: %.c %.h 

