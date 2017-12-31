/*
 * HistoricDateTime_test.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: sadivsky
 */

// Unit tests for the  FamilyTree class
#include <gtest/gtest.h>
#include "HistoricDateTime.h"

namespace family_tree {

TEST(HistoricDateTime, Test1970) {
    HistoricDateTime days(1970,1,1);
    EXPECT_EQ(days.getDaysfrom1970(), 0);
}



} /* namespace family_tree */
