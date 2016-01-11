/*
 * FamilyTree.cpp
 *
 *  Created on: Jan 11, 2016
 *      Author: vsadivskyy
 */

#include "FamilyTree.h"

FamilyTree::FamilyTree() {
	// TODO Auto-generated constructor stub

}

FamilyTree::~FamilyTree() {
	mPrs.clear();
}

Person* FamilyTree::getPrsById( unsigned long id) const{

	if( !mPrs.empty() ) {
		for( std::vector<Person*>::const_iterator it=mPrs.begin(); it < mPrs.end(); ++it )
			if( (*it)->getID() == id )
				return (*it);
		return NULL;
	}
	else
		return NULL;
}

