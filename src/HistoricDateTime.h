/*
 * HistoricDateTime.h
 *
 *  Created on: Oct 11, 2017
 *      Author: sadivsky
 */

#ifndef HISTORICDATETIME_H_
#define HISTORICDATETIME_H_

#include <chrono>

namespace family_tree {

typedef std::chrono::duration
        <
            long long,
            std::ratio_multiply<std::ratio<24>, std::chrono::hours::period>
        > days;

template <class Int>
constexpr
Int
days_from_civil(Int y, unsigned m, unsigned d) noexcept
{
    static_assert(std::numeric_limits<unsigned>::digits >= 18,
             "This algorithm has not been ported to a 16 bit unsigned integer");
    static_assert(std::numeric_limits<Int>::digits >= 20,
             "This algorithm has not been ported to a 16 bit signed integer");
    y -= m <= 2;
    const Int era = (y >= 0 ? y : y-399) / 400;
    const unsigned yoe = static_cast<unsigned>(y - era * 400);      // [0, 399]
    const unsigned doy = (153*(m + (m > 2 ? -3 : 9)) + 2)/5 + d-1;  // [0, 365]
    const unsigned doe = yoe * 365 + yoe/4 - yoe/100 + doy;         // [0, 146096]
    return era * 146097 + static_cast<Int>(doe) - 719468;
}

constexpr days HUMAN_START = days(days_from_civil(-100, 1, 1));  // 0000-01-01

class HistoricDateTime {
public:
    HistoricDateTime();
    virtual ~HistoricDateTime();
};

} /* namespace family_tree */

#endif /* HISTORICDATETIME_H_ */
