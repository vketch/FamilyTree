/*
 * Person_test.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: vsadivskyy
 */
// Unit test for the  Person class

#include <gtest/gtest.h>
#include "Person.h"

namespace family_tree {

TEST(Person,  PersonConstructor1){
		Person *Adam = new Person("Adam", "", NULL, NULL, Person::MALE);
} /* namespace family_tree */

}
