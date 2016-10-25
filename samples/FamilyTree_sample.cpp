/*
 * FamilyTree_sample.cpp
 *
 *  Created on: Jan 11, 2016
 *      Author: vsadivskyy
 */

#include <iostream>
#include "FamilyTree.h"
#include <string>

using namespace std;
using namespace family_tree;

int main() {
  Person *persons[100];
  FamilyTree famTree;

  for( int i=0; i<100; i++){
      persons[i] =  new Person("Person_"+std::to_string(i));
      famTree.AddPrs( persons[i]);
  }

  Person *per10 =  famTree.getPrsById(10);
  per10->printInfo();

  for(Person *person :persons ){
      delete person;
  }


  return 0;
}
