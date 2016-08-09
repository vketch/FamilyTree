/*
 * HumanityTree.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: vsadivskyy
 */

#include "HumanityTree.h"

namespace family_tree {

HumanityTree::~HumanityTree() {
  // TODO Auto-generated destructor stub
}

HumanityTree::HumanityTree() {

}

HumanityTree* HumanityTree::getInstanse() {
  if (mTree == NULL)
    mTree = new HumanityTree();

  return mTree;
}

Person* HumanityTree::AddPrs(std::string fname, std::string sname,
    Person* father, Person* mather, Person::Sex sex) {

  Person* prsn = new Person(fname, sname, father, mather, sex);
  mPrs.push_back(prsn);

  return prsn;
}

Person* HumanityTree::getPrsById(unsigned long id) const {

  if (!mPrs.empty()) {
    for (std::vector<Person*>::const_iterator it = mPrs.begin();
        it < mPrs.end(); ++it)
      if ((*it)->getID() == id)
        return (*it);
    return NULL;
  } else
    return NULL;
}

} /* namespace fm_tree */
