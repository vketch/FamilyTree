/*
 * HistoricDateTime.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: sadivsky
 */

#include "HistoricDateTime.h"
#include "crono_date.h"

namespace family_tree {

//const unsigned long =  HUMANITY_DAY_START//day from the beginning of humanity from
//constexpr days HUMAN_START = days(days_from_civil<unsigned long>(-100, 1, 1));  // 0000-01-01

//constexpr days HUMAN_START = days(days_from_civil<unsigned long>(-100, 1, 1));  // 0000-01-01

HistoricDateTime::HistoricDateTime(int year, unsigned month, unsigned day) {
    mDays = days_from_civil<int>(year, month, day);
}

HistoricDateTime::~HistoricDateTime() {
    // TODO Auto-generated destructor stub
}

int HistoricDateTime::getDaysfrom1970(){
    return mDays;
};

} /* namespace family_tree */
