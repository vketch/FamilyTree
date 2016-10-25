/*
 * HumanityTree_test.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: vsadivskyy
 */
// Unit tests for the  HumanityTree class
#include <gtest/gtest.h>
#include "HumanityTree.h"

namespace family_tree {

TEST(HumanityTree,  TestUnicity){
	HumanityTree *ht = HumanityTree;
	ASSERT_TRUE(ht != NULL);
}

}/* namespace family_tree */
