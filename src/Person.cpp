/* Implementation of Person class
 */
#include <iostream>
#include "Person.h"

namespace family_tree {

unsigned long Person::mPrsCnt=0;

std::string Person::getStrSex() const {
  switch (mSex) {
  case Person::UNKNOWN:
    return "UNKNOWN";

  case Person::MALE:
    return "MALE";

  case Person::FEMALE:
    return "FEMALE";

  default:
    return "UNDEFINED";

  }
}

void Person::printInfo() const {
  std::cout << mFname + " " + mSname + "(" + getStrSex() + ")" << "[" << mID
      << "]" << std::endl;

  if (mFather != NULL)
    std::cout << "	Father: " << mFather->getFname() << std::endl;

  if (mMather != NULL)
    std::cout << "	Mather: " << mMather->getFname() << std::endl;

  if (!mSpouses.empty()) {
    std::cout << "	Spouses: ";
    for (std::vector<Person*>::const_iterator it = mSpouses.begin();
        it < mSpouses.end(); ++it)
      std::cout << (*it)->mFname << ',';
    std::cout << std::endl;
  }

  if (!mKids.empty()) {
    std::cout << "	Kids: ";
    for (std::vector<Person*>::const_iterator it = mKids.begin();
        it < mKids.end(); ++it)
      std::cout << (*it)->mFname << ',';
    std::cout << std::endl;
  }
}
} // fm_tree

