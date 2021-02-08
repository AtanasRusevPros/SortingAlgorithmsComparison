/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file stl_StableSort.cpp
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


#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "../Tools/AlgorithmSupport.h"
#include "stl_StableSort.h"


#define ADDITIONAL_DEBUG_ON
#ifdef ADDITIONAL_DEBUG_ON
#define adDbg cout
#define printArrayAdDbg printArray
#else 
#define adDbg 0 && cout
#define printArrayAdDbg(a,b) 
#endif

#define ADDITIONAL_DEBUG2_ON
#ifdef ADDITIONAL_DEBUG2_ON
#define execRep std::cout
// #define printArrayAdDbg printArray
#else 
#define execRep 0 && cout
// #define printArrayAdDbg(a,b) 
#endif

static inline void swapInl(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


static inline void swapInl(unsigned int* a, unsigned int* b) {
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}


static inline void swapInl(unsigned long long * a, unsigned long long* b) {
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

void stl_StableSort(int arr[], unsigned int size) {
    std::stable_sort(arr, arr + size);
}

void stl_sortRegular(int arr[], unsigned int size) {
    std::sort(arr, arr + size);
}