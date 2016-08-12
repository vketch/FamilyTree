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

class TestPerson : public testing::Test{
protected:
	Person *Adam;
	Person *Eva;
	void SetUp(){
		Adam = new Person("AdamFirstName", "AdamSecondName", NULL, NULL, Person::MALE);
		Eva = new Person("EvaFirstName", "EvaSecondName", NULL, NULL, Person::FEMALE);
	}
	void TearDown(){
		delete Adam;
		delete Eva;
	}
};

TEST(Person,  TestConstructorWithDefaultParameters){
	Person * SomeBody = new Person("SomeBody");
	ASSERT_TRUE(SomeBody != NULL);
    EXPECT_EQ( SomeBody->getFname(), "SomeBody");
    EXPECT_EQ( SomeBody->getSname(), "");
    EXPECT_EQ( SomeBody->getSex(), Person::UNKNOWN);
}

TEST_F(TestPerson,  TestConstructorWithAllParameters){
	ASSERT_TRUE(Adam != NULL);
    EXPECT_EQ( Adam->getFname(), "AdamFirstName");
    EXPECT_EQ( Adam->getSname(), "AdamSecondName");
    EXPECT_EQ( Adam->getSex(), Person::MALE);
    EXPECT_EQ( Adam->getStrSex(), "MALE");
}

TEST_F(TestPerson,  TestSpouses){
	Adam->addSpouse(Eva);
	EXPECT_EQ( Adam->getSpouses().back(), Eva);
	EXPECT_EQ( Eva->getSpouses().back(), Adam);
}

TEST_F(TestPerson,  TestChildrenAndParents){
	Person *Kain = new Person("KainFirstName", "KainSecondName", Adam, Eva, Person::MALE);
	Person *Avel = new Person("KainFirstName", "KainSecondName", Adam, Eva, Person::MALE);

	EXPECT_EQ(Adam->getKids().size(), 2);
	EXPECT_EQ(Adam->getKids(), Eva->getKids());
	EXPECT_EQ(Adam->getKids().back(), Avel);
	EXPECT_EQ(Eva->getKids()[0], Kain);
	EXPECT_EQ(Kain->getFather(), Adam);
	EXPECT_EQ(Avel->getMather(), Eva);

}



}/* namespace family_tree */