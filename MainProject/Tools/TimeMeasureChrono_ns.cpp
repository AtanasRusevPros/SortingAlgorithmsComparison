/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file TimeMeasureChrono_ns.cpp
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

#include <iostream>
#include <chrono>


using namespace std;
using namespace std::chrono;


using std::cout;
using std::endl;
using std::string;

nanoseconds getTime_Since_Epoch_ns() {
    high_resolution_clock::time_point t1;
    t1 = high_resolution_clock::now();
    auto time = time_point_cast<nanoseconds>(t1);
    return time.time_since_epoch();
}


