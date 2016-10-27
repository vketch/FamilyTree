/*
 * FamilyTree_test.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: vsadivskyy
 */

// Unit tests for the  FamilyTree class
#include <gtest/gtest.h>
#include "FamilyTree.h"
#include <string>

namespace family_tree {
class TestFamilyTree: public testing::Test {
public:
    static const int personQuanity=10;
protected:
    Person *persons[personQuanity];
    FamilyTree famTree;
    void SetUp() {
        for( int i=0; i<personQuanity; i++){
            persons[i] =  new Person("Person_"+std::to_string(i) );
            famTree.AddPrs( persons[i]);
        }
    }
    void TearDown() {
        for(Person *person :persons )
            delete person;
    }
};

const int TestFamilyTree::personQuanity;

TEST_F(TestFamilyTree, TestPersonsQuanityInFamily) {
    EXPECT_EQ(famTree.getSize(), TestFamilyTree::personQuanity);
}

TEST_F(TestFamilyTree, TestIteratorOperators) {
    auto it  = famTree.begin();
    EXPECT_EQ((*it)->getFname(), "Person_0");
    EXPECT_EQ((*(++it))->getFname(), "Person_1");
    EXPECT_EQ((*(it++))->getFname(), "Person_1");
    EXPECT_EQ((*it)->getFname(), "Person_2");
}

TEST_F(TestFamilyTree, TestIteratorsInLoop) {
    int count=0;
    for( auto it= famTree.begin(); it != famTree.end(); it++, count++);
    EXPECT_EQ( count, TestFamilyTree::personQuanity);
}

TEST_F(TestFamilyTree, TestGetPersonByIdPositive) {
    Person *per  = *famTree.begin();
    unsigned long id = per->getID();
    EXPECT_EQ( famTree.getPrsById(id)->getFname(), "Person_0" );
}

TEST_F(TestFamilyTree, TestC11RangeLoop) {
    int i=0;
    for( Person *person :famTree)
        EXPECT_EQ(person->getFname(), ("Person_"+std::to_string(i++)) );
}

}/* namespace family_tree */


