/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file TimeMeasureChrono_ns.h
*
* See LICENSE file at the top of the source tree.
*
* \copyright This program is free software: you can redistribute it and/or modify
* it under the terms of the "GNU Lesser General Public License v3.0"
* as published by the Free Software Foundation.
* THE ONLY ADDITIONAL REQUIREMENT is when using the source to keep the name
* of the original Author(s) (Atanas Georgiev Rusev and/or another project
* contributor) AND adding your name below with statement of the additions made.
*
* A copy of the license can be found in the main directory of this project in
* the LICENSE.txt file. In case you want more information refer to the internet
* link https://www.gnu.org/licenses/lgpl-3.0.html
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* ------------------------------------------------------------------------------
*
*  \brief Basic time measurement and conversions functions.
*  \details For full explanation on why and how this project was designed please
*     check the pdf version of the accompanying article in the docs directory
*
*  \author Atanas Georgiev Rusev (https://github.com/AtanasRusevPros)
*  \author Please add your name for additional contributions
*
*/

#ifndef TIMEMEASURECHRONO_NS_H
#define TIMEMEASURECHRONO_NS_H

#include <iostream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

nanoseconds getTime_Since_Epoch_ns();

inline auto convLng_ns(unsigned long long par) -> std::string {
    std::string result{};
    if (par != 0) {
        auto str = std::to_string(par);
        char* newStr = const_cast<char*>(str.c_str());
        auto len = str.length();
        for (unsigned int i = 0, lenTmp = len - 1; i != str.length(); i++, lenTmp--) {
            result.push_back(newStr[i]);
            if ((!(lenTmp % 3)) && (lenTmp > 1))
                result.append(",");
        }
    }
    else {
        result = "0";
    }
    result.append(" ns");
    return result;
};

#define MICROSECONDS_100_IN_NANOSEC 100000

#endif // TIMEMEASURECHRONO_NS_H
