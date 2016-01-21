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
namespace FamilyTree{
	class FamilyTree {
	private:
		FamilyTree(FamilyTree &obj){}
		FamilyTree& operator=(FamilyTree &obj){ return obj; }

		std::vector<Person *> mPrs;   //Family tree persons
	public:
		FamilyTree();
		virtual ~FamilyTree();

		/*Add Person to family tree*/
		void AddPrs( Person *person);

		/*Returns pointer to Person by the Person id*/
		Person* getPrsById( unsigned long id) const;
	};
} // FamilyTree

#endif /* SRC_FAMILYTREE_H_ */
