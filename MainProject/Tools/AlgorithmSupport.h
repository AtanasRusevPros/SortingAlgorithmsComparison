/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file AlgorithmSupport.h
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
*  \details For full explanation on why and how this project was designed please
*     check the pdf version of the accompanying article in the docs directory
*
*  \author Atanas Georgiev Rusev (https://github.com/AtanasRusevPros)
*  \author Please add your name for additional contributions
*
*/

#ifndef ALGORITHMSUPPORT_H
#define ALGORITHMSUPPORT_H

#include "GenericMergeData.h"
#include "TimeMeasureChrono_ns.h"

inline unsigned int min(unsigned int a, unsigned int b)
{
    if (b < a)
        return b;
    return a;
}

inline void printArray(int* arr, unsigned int size) {

    cout << "\nArray SIZE: " << size << "  ::: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

inline void printArrayHex(int* arr, unsigned int size) {

    cout << "Array SIZE: " << size << "  ::: ";
    for (int i = 0; i < size; i++) {
        cout << std::hex << arr[i] << " , ";
    }
    cout << endl;
}


inline std::string intToBits(uint32_t num) {
    string res{};
    for (int i = 0; i < 32; i++) {
        res.append(to_string(0 != (num & (0x1 << i))));
    }
    return res;
};

inline bool insertionSort_Rusev(int arr[], unsigned int left, unsigned int right, unsigned int size);

#endif // !ALGORITHMSUPPORT_H