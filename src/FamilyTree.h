/*
 * FamilyTree.h
 *
 *  Created on: Jan 11, 2016
 *      Author: vsadivskyy
 *
 *  Class to build family tree
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include "HumanPerson.h"

#ifndef SRC_FAMILYTREE_H_
#define SRC_FAMILYTREE_H_
namespace family_tree {

class FamilyTree {
public:
    FamilyTree();
    virtual ~FamilyTree();

    /*Add Person to family tree*/
    void addPrs(HumanPerson& person);

    /*Get person Persons quantity in Family tree*/
    unsigned long getSize() const{ return mPrs.size(); }

    /*Returns pointer to Person by the Person id*/
    HumanPerson* getPrsById(unsigned long id) const;

    class iterator: public std::iterator< std::random_access_iterator_tag,
                                          HumanPerson*, HumanPerson*, HumanPerson**, HumanPerson*>{
        protected:
            std::vector<HumanPerson *>::iterator mIter;
        public:
            explicit iterator(std::vector<HumanPerson *>::iterator iter): mIter(iter) {}
            iterator operator++(){ ++this->mIter; return *this; }
            iterator operator++(int){ iterator retval(mIter++);  return  retval; }
            bool operator==(iterator other) const { return mIter == other.mIter;}
            bool operator!=(iterator other) const { return !(mIter == other.mIter);}
            HumanPerson* operator*() const { return *mIter; }
    };

    iterator begin() { return iterator(mPrs.begin()); }
    iterator end() { return iterator(mPrs.end()); }

private:
    FamilyTree(FamilyTree &obj);
    FamilyTree& operator=(FamilyTree &obj);

    std::vector<HumanPerson *> mPrs;   //Family tree persons

};

}/* namespace fm_tree */

#endif /* SRC_FAMILYTREE_H_ */
