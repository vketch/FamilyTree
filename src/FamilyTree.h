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
#include <iostream>
#include <algorithm>

#ifndef SRC_FAMILYTREE_H_
#define SRC_FAMILYTREE_H_
namespace family_tree {

class FamilyTree {
public:
    FamilyTree();
    virtual ~FamilyTree();

    /*Add Person to family tree*/
    void addPrs(Person& person);

    /*Get person Persons quantity in Family tree*/
    unsigned long getSize() const{ return mPrs.size(); }

    /*Returns pointer to Person by the Person id*/
    Person* getPrsById(unsigned long id) const;

    class iterator: public std::iterator< std::random_access_iterator_tag,
                                          Person*, Person*, Person**, Person*>{
        protected:
            std::vector<Person *>::iterator mIter;
        public:
            explicit iterator(std::vector<Person *>::iterator iter): mIter(iter) {}
            iterator operator++(){ ++this->mIter; return *this; }
            iterator operator++(int){ iterator retval(mIter++);  return  retval; }
            bool operator==(iterator other) const { return mIter == other.mIter;}
            bool operator!=(iterator other) const { return !(mIter == other.mIter);}
            Person* operator*() const { return *mIter; }
    };

    iterator begin() { return iterator(mPrs.begin()); }
    iterator end() { return iterator(mPrs.end()); }

private:
    FamilyTree(FamilyTree &obj);
    FamilyTree& operator=(FamilyTree &obj);

    std::vector<Person *> mPrs;   //Family tree persons

};

}/* namespace fm_tree */

#endif /* SRC_FAMILYTREE_H_ */
