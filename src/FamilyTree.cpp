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

void FamilyTree::addPrs(HumanPerson& person) {
     mPrs.push_back(&person);
//   mID = Person::mPrsCnt;
//   Person::mPrsCnt++;
}

HumanPerson* FamilyTree::getPrsById(unsigned long id) const {

    if (!mPrs.empty()) {
        for ( HumanPerson* person : mPrs)
            if (person->getID() == id)
                return person;
        return NULL;
    } else
        return NULL;
}

}/* namespace fm_tree */
