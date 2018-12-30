/*
 * Person_test.cpp
 *
 *  Created on: 30 груд. 2018 р.
 *      Author: root
 */

/*
 * Person_test.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: vsadivskyy
 */
// Unit tests for the  Person class
#include <gtest/gtest.h>
#include <Person.h>

namespace family_tree {

class TestPerson: public testing::Test {
};

TEST_F(TestPerson, TestConstructor) {
    Person person("SomeOne", Person::HUMAN);
    EXPECT_EQ(person.getFname(), "SomeOne");
    EXPECT_EQ(person.getType(), Person::HUMAN);
}

TEST(Person, TestConstructorExceptionWithNoFname) {
    bool throwPersonException = false;
    try{
        Person* SomeBody = new Person("", Person::HUMAN );
    }
    catch (PersonException&){
        throwPersonException = true;
    }
    catch (...){
        throwPersonException = false;
    }
    EXPECT_EQ(throwPersonException, true);
}

TEST_F(TestPerson, TestSetGetID) {
    Person person("SomeOne", Person::HUMAN);
    person.setId(100u);
    EXPECT_EQ(person.getID(), 100u);
}

}/* namespace family_tree */



