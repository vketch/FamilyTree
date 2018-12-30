/*
 * HumanPerson_test.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: vsadivskyy
 */
// Unit tests for the  Person class
#include <gtest/gtest.h>
#include <HumanPerson.h>

namespace family_tree {

class TestHumanPerson: public testing::Test {
protected:
    HumanPerson *Adam;
    HumanPerson *Eva;
    void SetUp() {
        Adam = new HumanPerson("AdamFirstName", "AdamSecondName", NULL, NULL,
                HumanPerson::MALE);
        Eva = new HumanPerson("EvaFirstName", "EvaSecondName", NULL, NULL,
                HumanPerson::FEMALE);
    }
    void TearDown() {
        delete Adam;
        delete Eva;
    }
};

TEST(HumanPerson, TestConstructorWithDefaultParameters) {
    HumanPerson * SomeBody = new HumanPerson("SomeBody");
    ASSERT_TRUE(SomeBody != NULL);
    EXPECT_EQ(SomeBody->getFname(), "SomeBody");
    EXPECT_EQ(SomeBody->getSname(), "");
    EXPECT_EQ(SomeBody->getSex(), HumanPerson::UNKNOWN);
}

TEST_F(TestHumanPerson, TestConstructorWithAllParameters) {
    ASSERT_TRUE(Adam != NULL);
    EXPECT_EQ(Adam->getFname(), "AdamFirstName");
    EXPECT_EQ(Adam->getSname(), "AdamSecondName");
    EXPECT_EQ(Adam->getSex(), HumanPerson::MALE);
    EXPECT_EQ(Eva->getSex(), HumanPerson::FEMALE);
    EXPECT_EQ(Adam->getStrSex(), "MALE");
}

TEST_F(TestHumanPerson, TestChildrenAndParents) {
    HumanPerson *Kain = new HumanPerson("KainFirstName", "KainSecondName", Adam, Eva,
            HumanPerson::MALE);
    HumanPerson *Avel = new HumanPerson("KainFirstName", "KainSecondName", Adam, Eva,
            HumanPerson::MALE);

    EXPECT_EQ(Adam->getKids().size(), 2u);
    EXPECT_EQ(Adam->getKids(), Eva->getKids());
    EXPECT_EQ(Adam->getKids().back(), Avel);
    EXPECT_EQ(Eva->getKids()[0], Kain);
    EXPECT_EQ(Kain->getFather(), Adam);
    EXPECT_EQ(Avel->getMather(), Eva);
}

TEST_F(TestHumanPerson, TestAddSpouses) {
	EXPECT_EQ(Adam->addSpouse(Eva), true);
    EXPECT_EQ(Adam->getSpouses().back(), Eva);
    EXPECT_EQ(Eva->getSpouses().back(), Adam);
    EXPECT_EQ(Adam->addSpouse(Eva), false);
}

TEST_F(TestHumanPerson, TestAddKid) {
    HumanPerson Kain("KainFirstName", "KainSecondName");
    EXPECT_EQ(Adam->addKid(Kain), true);
    EXPECT_EQ(Adam->addKid(Kain), false);
	EXPECT_EQ(Adam->getKids().size(), 1u);
	EXPECT_EQ(Adam->getKids()[0]->getFname(), Kain.getFname());
    EXPECT_EQ(Kain.getFather()->getFname(), Adam->getFname());
}

}/* namespace family_tree */
