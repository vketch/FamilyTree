/*
 * HistoricDateTime.h
 *
 *  Created on: Oct 11, 2017
 *      Author: sadivsky
 */

#ifndef HISTORICDATETIME_H_
#define HISTORICDATETIME_H_

namespace family_tree {

//constexpr days HUMAN_START = days(days_from_civil<unsigned long>(-100, 1, 1));  // 0000-01-01
//constexpr days HUMAN_START = days(days_from_civil<unsigned long>(-100, 1, 1));  // 0000-01-01

class HistoricDateTime {
public:
    HistoricDateTime(int year, unsigned month, unsigned day);
    virtual ~HistoricDateTime();

    int getDaysfrom1970(); // returns day from 1970/01/01 A.D, negative value return days before 1970/01/01 A.D

private:
    int mDays = 0; //day from the 1970-01-01
};

} /* namespace family_tree */

#endif /* HISTORICDATETIME_H_ */
