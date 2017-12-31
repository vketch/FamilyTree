/*
 * crono_date.h
 *
 *  Created on: Dec 31, 2017
 *      Author: vsadivskyy
 */

/* Implementation are based algorithms from there
 * https://howardhinnant.github.io/date_algorithms.html */

#ifndef CRONO_DATE_H_
#define CRONO_DATE_H_

#include <chrono>
#include <ratio>

//typedef std::chrono::duration<
//          unsigned long,
//          std::ratio_multiply<std::ratio<24>, std::chrono::hours::period>
//        > days;

template <class Int>
//constexpr
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

#endif /* CRONO_DATE_H_ */
