/*
 * Person_test.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: vsadivskyy
 */
// Unit tests for the  Person class
#include <gtest/gtest.h>
#include "Person.h"

namespace family_tree {

class TestPerson: public testing::Test {
protected:
    Person *Adam;
    Person *Eva;
    void SetUp() {
        Adam = new Person("AdamFirstName", "AdamSecondName", NULL, NULL,
                Person::MALE);
        Eva = new Person("EvaFirstName", "EvaSecondName", NULL, NULL,
                Person::FEMALE);
    }
    void TearDown() {
        delete Adam;
        delete Eva;
    }
};

TEST(Person, TestConstructorWithDefaultParameters) {
    Person * SomeBody = new Person("SomeBody");
    ASSERT_TRUE(SomeBody != NULL);
    EXPECT_EQ(SomeBody->getFname(), "SomeBody");
    EXPECT_EQ(SomeBody->getSname(), "");
    EXPECT_EQ(SomeBody->getSex(), Person::UNKNOWN);
}

TEST_F(TestPerson, TestConstructorWithAllParameters) {
    ASSERT_TRUE(Adam != NULL);
    EXPECT_EQ(Adam->getFname(), "AdamFirstName");
    EXPECT_EQ(Adam->getSname(), "AdamSecondName");
    EXPECT_EQ(Adam->getSex(), Person::MALE);
    EXPECT_EQ(Eva->getSex(), Person::FEMALE);
    EXPECT_EQ(Adam->getStrSex(), "MALE");
}

TEST(Person, TestConstructorExceptionWithNoFname) {
	bool throwPersonException = false;
	try{
		Person* SomeBody = new Person("");
	}
	catch (PersonException&){
		throwPersonException = true;
	}
	catch (...){
		throwPersonException = false;
	}
	EXPECT_EQ(throwPersonException, true);
}

TEST_F(TestPerson, TestChildrenAndParents) {
    Person *Kain = new Person("KainFirstName", "KainSecondName", Adam, Eva,
            Person::MALE);
    Person *Avel = new Person("KainFirstName", "KainSecondName", Adam, Eva,
            Person::MALE);

    EXPECT_EQ(Adam->getKids().size(), 2u);
    EXPECT_EQ(Adam->getKids(), Eva->getKids());
    EXPECT_EQ(Adam->getKids().back(), Avel);
    EXPECT_EQ(Eva->getKids()[0], Kain);
    EXPECT_EQ(Kain->getFather(), Adam);
    EXPECT_EQ(Avel->getMather(), Eva);

}

TEST_F(TestPerson, TestAddSpouses) {
	EXPECT_EQ(Adam->addSpouse(Eva), true);
    EXPECT_EQ(Adam->getSpouses().back(), Eva);
    EXPECT_EQ(Eva->getSpouses().back(), Adam);
    EXPECT_EQ(Adam->addSpouse(Eva), false);
}

TEST_F(TestPerson, TestAddKid) {
    Person Kain("KainFirstName", "KainSecondName");
    EXPECT_EQ(Adam->addKid(Kain), true);
    EXPECT_EQ(Adam->addKid(Kain), false);
	EXPECT_EQ(Adam->getKids().size(), 1u);
	EXPECT_EQ(Adam->getKids()[0]->getFname(), Kain.getFname());
    EXPECT_EQ(Kain.getFather()->getFname(), Adam->getFname());
}

}/* namespace family_tree */
