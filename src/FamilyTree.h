/*
 * FamilyTree.h
 *
 *  Created on: Jan 11, 2016
 *      Author: vsadivskyy
 *
 *  Class to build family tree
 */

#include <vector>
#include "Person.h"

#ifndef SRC_FAMILYTREE_H_
#define SRC_FAMILYTREE_H_
namespace family_tree {

class FamilyTree {

private:
    FamilyTree(FamilyTree &obj) {
    }
    FamilyTree& operator=(FamilyTree &obj) {
        return obj;
    }

    std::vector<Person *> mPrs;   //Family tree persons
public:
    FamilyTree();
    virtual ~FamilyTree();

    /*Add Person to family tree*/
    void AddPrs(Person *person);

    /*Returns pointer to Person by the Person id*/
    Person* getPrsById(unsigned long id) const;
};

}/* namespace fm_tree */

#endif /* SRC_FAMILYTREE_H_ */
