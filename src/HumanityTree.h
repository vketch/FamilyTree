/*
 * HumanityTree.h
 *
 *  Created on: Jan 26, 2016
 *      Author: vsadivskyy
 */

#ifndef SRC_HUMANITYTREE_H_
#define SRC_HUMANITYTREE_H_

#include "Person.h"

namespace family_tree {

class HumanityTree {
public:
  virtual ~HumanityTree();
  HumanityTree* getInstanse();

  /*Add Person to family tree*/
  Person* AddPrs(std::string fname, std::string sname = "", Person* father =
  NULL, Person* mather = NULL, Person::Sex sex = Person::UNKNOWN);

  /*Returns pointer to Person by the Person id*/
  Person* getPrsById(unsigned long id) const;

private:
  HumanityTree();
  HumanityTree *mTree = NULL;
  std::vector<Person *> mPrs;   //array of pointers to the persons
};

} /* namespace fm_tree */

#endif /* SRC_HUMANITYTREE_H_ */
