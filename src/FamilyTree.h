/*
 * FamilyTree.h
 *
 *  Created on: Jan 11, 2016
 *      Author: vsadivskyy
 */

#include <vector>
#include "Person.h"

#ifndef SRC_FAMILYTREE_H_
#define SRC_FAMILYTREE_H_

class FamilyTree {
	FamilyTree(FamilyTree &obj){}
	FamilyTree& operator=(FamilyTree &obj){ return obj; }
public:
	FamilyTree();
	virtual ~FamilyTree();
	std::vector<Person*> mPrs;   //Family tree persons

	/*Returns pointer to Person by the Person id*/
	Person *getPrsById( unsigned long id) const;
};

#endif /* SRC_FAMILYTREE_H_ */
