/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file AlgorithmSupport.cpp
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

#include "GenericMergeData.h"
#include "TimeMeasureChrono_ns.h"

//------------------------------------------------------------------------------------------
//---------        Rusev Impl Insertion Sort :    ------------------------------------------
//------------------------------------------------------------------------------------------

// this function performs simple insertion sort from left to right index.
// Size is passed here only for the check - result is true if sort performed,
// false if not performed due to left or right equal or bigger than size!
inline bool insertionSort_Rusev(int arr[], unsigned int left, unsigned int right, unsigned int size)
{
    bool result = true;

    if ((left >= size) || (right >= size))
        result = false;;

    unsigned int prevIdxCmp, i;
    int currValueToCompare;

    for (unsigned int currIdx = left + 1; currIdx <= right; currIdx++)
    {
        currValueToCompare = arr[currIdx];
        prevIdxCmp = currIdx;

        // check all previous numbers to find the right position
        while (prevIdxCmp > left)
        {
            if (currValueToCompare < arr[prevIdxCmp - 1]) {
                prevIdxCmp--;
            }
            else {
                break;
            }
        }

        // now that we have the right position - shift all numbers from it
        // until the current position
        if (prevIdxCmp < currIdx) {
            for (i = currIdx; i > prevIdxCmp; i--) {
                arr[i] = arr[i - 1];
            };
            arr[i] = currValueToCompare;
        }
    }
    return result;
}