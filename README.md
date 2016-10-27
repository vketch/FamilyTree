# FamilyTree
Solution for the organizing a family tree.
The main  goal is to provide a possibility to build a whole family tree of the Bible persons.

## Building
To build under: 
* Linux requares: git(1.9.1), gcc(4.8.4), make(3.81) 
* Windows requare: cygwin, git(2.10.1), gcc(5.4), make(4.1)
 
Clone project

```bash
git clone https://github.com/vketch/FamilyTree.git
```
change the directory 
```bash
cd FamilyTree 
```
and simply compile it
```bash
make 
```
The family_tree.a library will be located in the  $PATH/lib/

## Unit tests
To run unit tests 
```bash 
make tests
```
It will perform following:
* clone google tests into project root directory
* build google tests library 
* build unit tests and run them
    
For the second time the only building unit tests and run them will be performed    

## Samples
To build samples (under samples dir) run 
```bash 
make samples
```
