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
    static HumanityTree* getInstanse() {
        if (mHumTree == NULL)
            mHumTree = new HumanityTree();
        return mHumTree;
    }
    virtual ~HumanityTree() {
        // TODO Auto-generated destructor stub
    }

    /*Add Person to Humanity tree*/
    void AddPrs(Person& person) {
        mPrs.push_back(&person);
    }

    /*Returns pointer to Person by the Person id*/
    Person* getPrsById(unsigned long id) const {
        if (!mPrs.empty()) {
            for (Person *person : mPrs)
                if (person->getID() == id)
                    return person;
            return NULL;
        } else
            return NULL;
    }

private:
    HumanityTree() {
    }
    ;
    static HumanityTree *mHumTree;
    std::vector<Person *> mPrs;   //array of pointers to the persons
};

} /* namespace fm_tree */

#endif /* SRC_HUMANITYTREE_H_ */
