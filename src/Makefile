PROJECT = TestPerson
MODULES = Person

.PHONY: all build clean

all: clean build tests

build:
	g++ -o $(PROJECT) $(PROJECT).cpp $(MODULES).cpp 

tests:
	./$(PROJECT)
	
clean:
	rm -f *.o
	rm -f $(PROJECT) 

