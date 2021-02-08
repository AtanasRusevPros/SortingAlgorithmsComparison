/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file ArraysTools.cpp
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

#include "GenericMergeData.h"
#include "Arrays_Tools.h"

#include "AlgorithmSupport.h"

#define DEBUG_PRINTS_ARRAYS_OFF
#ifdef DEBUG_PRINTS_ARRAYS_ON
#define dout cout
#else
#define dout 0 && cout
#endif


using namespace std;
using std::cout;
using std::endl;



// the function returns the number of positive peaks in the sequence of elements
// it neglects situations with plateaus - i.e. if we have ...,13,15,12.... - this is a peak
// if we have .....,13,15,15,15,12....... - this is not counted as peak!
// TODO todo FIXME fixme !!!
unsigned long counterOfPeaks(int arr[], unsigned long size) {

    unsigned long result = 0;

    if (2 >= size) {
        dout << "Critical ERROR too small array !!!!1" << endl;
    }
    else {
        int prev = arr[0];
        for (unsigned int i = 1; i < (size - 1); i++) {
            if ((arr[i] > prev) && (arr[i] > arr[i + 1])) {
                result++;
            }
            prev = arr[i];
        }

        if (0 == result) {
            dout << "CRITICAL ERROR in CHECKS!!! Array SORTED or REVERSE SORTED !!! " << endl;
        }
        else {
            dout << " Array SHUFFLED CORRECTLY ! " << endl;
        }
    }
    return result;
};


// returns 0 if array sorted, otherwise the index of first inversion and breaks further check
unsigned long checkIfArrSorted(int arr[], unsigned long size, bool rev) {

    unsigned long result = 0;

    if (2 >= size) {
        dout << "Critical ERROR too small array !!!!" << endl;
        result = std::numeric_limits<unsigned long>::max();
    }
    else {
        int prev = arr[0];
        if (!rev) {
            for (unsigned int i = 1; i < size; i++) {
                if (arr[i] < prev) {
                    dout << "CRITICAL ERROR in CHECKS!!! Array not sorted, found at element : " << i << "   Previous number: " << prev << "   Current number : " << arr[i] << endl;
                    result = i;
                    break;
                }
                prev = arr[i];
            }
            if (0 == result) {
                dout << " Array SORTED CORRECTLY ! " << endl;
            }
        }
        else {
            for (unsigned int i = 1; i < size; i++) {
                if (arr[i] > prev) {
                    dout << "CRITICAL ERROR in CHECKS!!! Array not REVERSE sorted, found at element : " << i << "   Previous number: " << prev << "   Current number : " << arr[i] << endl;
                    result = i;
                    break;
                }
                prev = arr[i];
            }
            if (0 == result) {
                dout << " Array REVERSE SORTED CORRECTLY ! " << endl;
            }
        }
    }
    /*if (result > 0) {
        printArray(arr, size);
        std::cout.flush();
    }*/
    return result;
}


TestDataType_ERROR checkArrayInputBefore(SingleTestContainer* testCtr)
{
    TestDataType_ERROR result = TestDataType_ERROR::ARRAY_OK;

    switch (testCtr->dataType) {

    case TestDataType::RAND_with_Repeats:
    case TestDataType::RAND_NO_REPEATS_SHUFFLED:
    case TestDataType::SORTED_WITH_SOME_ZEROES_INSERTED:
    {
        if (0 == counterOfPeaks(testCtr->array, testCtr->size)) {
            result = TestDataType_ERROR::RAND_ARRAY_NOT_RAND;
        };

        break;
    };

    case TestDataType::REV_SORTED:
    {
        if (0 != checkIfArrSorted(testCtr->array, testCtr->size, true)) {
            result = TestDataType_ERROR::REV_SORTED_NOT_REVERSE_SORTED;
        }
        break;
    };

    case TestDataType::SORTED:
    case TestDataType::ONE_NUMBER:
    case TestDataType::ONLY_ZEROES:
    {
        if (0 != checkIfArrSorted(testCtr->array, testCtr->size)) {
            result = TestDataType_ERROR::SORTED_NOT_SORTED;
        }
        break;
    };

    default: {
        // this shall never happen at all
        cout << "Critical Error while parsing data type !!!! " << endl;
        break;
    };

    }

    return result;
};

TestDataType_ERROR checkArrayInputBeforeForMultiTest(int* dataArr, SingleTestContainer* testCtr)
{
    TestDataType_ERROR result = TestDataType_ERROR::ARRAY_OK;

    switch (testCtr->dataType) {

    case TestDataType::RAND_with_Repeats:
    case TestDataType::RAND_NO_REPEATS_SHUFFLED:
    case TestDataType::SORTED_WITH_SOME_ZEROES_INSERTED:
    {
        if (0 == counterOfPeaks(dataArr, testCtr->size)) {
            result = TestDataType_ERROR::RAND_ARRAY_NOT_RAND;
        };

        break;
    };

    case TestDataType::REV_SORTED:
    {
        if (0 != checkIfArrSorted(dataArr, testCtr->size, true)) {
            result = TestDataType_ERROR::REV_SORTED_NOT_REVERSE_SORTED;
        }
        break;
    };

    case TestDataType::SORTED:
    case TestDataType::ONE_NUMBER:
    case TestDataType::ONLY_ZEROES:
    {
        if (0 != checkIfArrSorted(dataArr, testCtr->size)) {
            result = TestDataType_ERROR::SORTED_NOT_SORTED;
        }
        break;
    };

    default: {
        // this shall never happen at all
        cout << "Critical Error while parsing data type !!!! " << endl;
        break;
    };

    }

    return result;
};


int binarySearch(int* arr, int leftLimit, int rightLimit, int x)
{
    while (leftLimit <= rightLimit) {
        int idxToCheck = leftLimit + (rightLimit - leftLimit) / 2;

        if (arr[idxToCheck] == x)
            return idxToCheck;

        if (arr[idxToCheck] < x)
            leftLimit = idxToCheck + 1;

        else
            rightLimit = idxToCheck - 1;
    }
    return -1;
}
