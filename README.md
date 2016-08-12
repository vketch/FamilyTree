# FamilyTree
Solution for the organizing a family tree.
The main  goal is to provide a possibility to build a whole family tree of the Bible persons.

## Building
On Linux: 
Clone source codes into PATH

```bash
git clone https://github.com/vketch/
```
change the directory 
```bash
cd $PATH/FamilyTree 
```
and simply compile it
```bash
make 
```
The family_tree.a library will be located in the  $PATH/lib/

## Unit tests
To run unit tests 
```bash 
make 
```
It will perform following:
    * clone google tests into  $PATH directory
    * build google tests library 
    * build unit tests and run them
    
For the second time the only building unit tests and run them will be perform     

