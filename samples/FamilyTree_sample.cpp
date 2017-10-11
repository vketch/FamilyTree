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
  const int count = 10;
  Person *persons[count];
  FamilyTree famTree;

  for( int i=0; i<count; i++){
      persons[i] =  new Person("Person_"+std::to_string(i));
      famTree.addPrs( *persons[i]);
  }

  for(Person *person :persons ){
	  person->printInfo();
      delete person;
  }

  return 0;
}
