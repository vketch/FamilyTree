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
    shPerson Adam;
    shPerson Eva;
    void SetUp() {
        Adam = shPerson(new Person("AdamFirstName", "AdamSecondName", nullptr, nullptr,
                Person::MALE));
        Eva = shPerson(new Person("EvaFirstName", "EvaSecondName", nullptr, nullptr,
                Person::FEMALE));
    }
    void TearDown() {
        Adam = nullptr;
        Eva = nullptr;
    }
};

TEST(Person, TestConstructorWithDefaultParameters) {
    shPerson  SomeBody = shPerson( new Person("SomeBody") );
    ASSERT_TRUE(SomeBody != nullptr);
    EXPECT_EQ(SomeBody->getFname(), "SomeBody");
    EXPECT_EQ(SomeBody->getSname(), "");
    EXPECT_EQ(SomeBody->getSex(), Person::UNKNOWN);
}

TEST_F(TestPerson, TestConstructorWithAllParameters) {
    ASSERT_TRUE(Adam != nullptr);
    EXPECT_EQ(Adam->getFname(), "AdamFirstName");
    EXPECT_EQ(Adam->getSname(), "AdamSecondName");
    EXPECT_EQ(Adam->getSex(), Person::MALE);
    EXPECT_EQ(Eva->getSex(), Person::FEMALE);
    EXPECT_EQ(Adam->getStrSex(), "MALE");
}

TEST(Person, TestConstructorExceptionWithNoFname) {
	bool throwPersonException = false;
	try{
		shPerson SomeBody = shPerson(new Person(""));
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
    shPerson Kain = shPerson( new Person("KainFirstName", "KainSecondName", Adam, Eva,
            Person::MALE) );
    shPerson Avel = shPerson( new Person("KainFirstName", "KainSecondName", Adam, Eva,
            Person::MALE) );

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
    shPerson Kain = shPerson(new Person("KainFirstName", "KainSecondName"));
    EXPECT_EQ(Adam->addKid(Kain), true);
    EXPECT_EQ(Adam->addKid(Kain), false);
	EXPECT_EQ(Adam->getKids().size(), 1u);
	EXPECT_EQ(Adam->getKids()[0]->getFname(), Kain->getFname());
    EXPECT_EQ(Kain->getFather()->getFname(), Adam->getFname());
}

}/* namespace family_tree */
