/* Implementation of Person class
 */
#include <iostream>
#include "Person.h"

namespace family_tree {

unsigned long Person::mPrsCnt = 0;

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
        for(Person* spouse : mSpouses)
            std::cout << spouse->mFname << ',';
        std::cout << std::endl;
    }

    if (!mKids.empty()) {
        std::cout << "	Kids: ";
          for(Person* kid : mKids)
              std::cout << kid->mFname << ',';
        std::cout << std::endl;
    }
}

} /* namespace fm_tree */

