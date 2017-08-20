/*
 * FamilyTree.cpp
 *
 *  Created on: Jan 11, 2016
 *      Author: vsadivskyy
 *
 *  Class to build family tree
 */

#include "FamilyTree.h"

namespace family_tree {
//unsigned long Person::mPrsCnt = 0;

FamilyTree::FamilyTree() {
    // TODO Auto-generated constructor stub

}

FamilyTree::~FamilyTree() {
    mPrs.clear();
}

void FamilyTree::AddPrs(shPerson person) {
    if (person != NULL)
        mPrs.push_back(person);
//   mID = Person::mPrsCnt;
//   Person::mPrsCnt++;
}

shPerson FamilyTree::getPrsById(unsigned long id) const {

    if (!mPrs.empty()) {
        for ( shPerson person : mPrs)
            if (person->getID() == id)
                return person;
        return NULL;
    } else
        return NULL;
}

}/* namespace fm_tree */
