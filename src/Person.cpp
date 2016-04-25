/* Implementation of Person class
 */
#include <iostream>
#include "Person.h"

namespace family_tree {

unsigned long Person::mPrsCnt = 0;
Person::Person(std::string fname, std::string sname, Person* father,
    Person* mather, Person::Sex sex) {
  mFname = fname;
  mSname = sname;
  mSex = sex;
  mFather = father;
  mMather = mather;
  if (mFather != NULL)
    mFather->mKids.push_back(this);

  if (mMather != NULL)
    mMather->mKids.push_back(this);
  mID = mPrsCnt;
  mPrsCnt++;
}

Person::~Person() {
}

std::string Person::getFname() const {
  return mFname;
}

std::string Person::getSname() const {
  return mSname;
}

const std::vector<Person*>& Person::getKids() const {
  return mKids;
}

const std::vector<Person*>& Person::getSpouses() const {
  return mSpouses;
}

Person::Sex Person::getSex() const {
  return mSex;
}

unsigned long Person::getID() const {
  return mID;
}

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

void Person::addSpouse(Person* person) {
  mSpouses.push_back(person);
  person->mSpouses.push_back(this);
}
} // fm_tree

