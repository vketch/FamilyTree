/*
 * Person.cpp
 *
 *  Created on: 30 ����. 2018 �.
 *      Author: root
 */

#include "Person.h"

namespace family_tree {

Person::Person(std::string fname, Person::PersonType type): mFname(fname), mType(type) {
    if (fname.size() == 0){
        throw PersonException("Person should has first name at least");
    }
};

} /* namespace family_tree */
