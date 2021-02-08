/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file RusevUltra.cpp
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

#include "../Tools/AlgorithmSupport.h"
#include "RusevSwapSort2.h"


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


// TODO FINISH if necessary
void sort4numsRusevSwapSortBasedOn2(int arr[]) {
    
    unsigned int i;
    // these are the smallest and the biggest numbers
    int currMin, currMax, temp, temp2;
    unsigned int posCurrMin = 0, posCurrMax = 3, posCurrStart = 0, posCurrEnd = 3;

    currMin = arr[0];    
    currMax = arr[3];

    // iterating through numbers
    for (i = 0; i < 4; i++) {

        // finding the smallest number - get next smallest only if it is really smaller. Thus if we have smallest in the beginning we will not require swap.
        if (arr[i] < currMin) {
            currMin = arr[i];
            posCurrMin = i;
        }

        // finding the biggest number. Get only if it is greater.
        if (arr[i] > currMax) {
            currMax = arr[i];
            posCurrMax = i;
        }
    }

    // we have now the minimum and the maximum
    // if we have to swap - swap
    // Improved performance of our cases:

    if (posCurrMin == posCurrEnd) {

        if (posCurrMax == posCurrStart) {
            // 2. swap ends
            arr[posCurrStart] = currMin;
            arr[posCurrEnd] = currMax;

        }
        else { // means posCurrMax == somwhere in the middle
            // 3. 3 nums, collide at end
            temp = arr[posCurrStart];
            arr[posCurrStart] = currMin;
            arr[posCurrEnd] = currMax;
            arr[posCurrMax] = temp;
        }
    }
    else {
        if (posCurrMin == posCurrStart) {

            if (posCurrMax == posCurrEnd) {
                // 1. Do nothing - everything in correct place
            }
            else { // means posCurrMax == somwhere in the middle
                // 7. Swap only max0 with end
                temp = arr[posCurrEnd];
                arr[posCurrMax] = temp;
                arr[posCurrEnd] = currMax;
            }
        }
        else { // this means we are somwhere in the middle for the current minimal value!

            if (posCurrMax == posCurrEnd) {
                // 6. Swap only min0 with start
                temp = arr[posCurrStart];
                arr[posCurrMin] = temp;
                arr[posCurrStart] = currMin;
            }
            else { // means posCurrMax == somwhere in the middle

                if (posCurrMax == posCurrStart) {
                    // 4. 3 nums, collide at start
                    temp = arr[posCurrEnd];
                    arr[posCurrStart] = currMin;
                    arr[posCurrEnd] = currMax;
                    arr[posCurrMin] = temp;
                }
                else { // means posCurrMax == somwhere in the middle
                    // 5. double 2 swaps
                    temp = arr[posCurrEnd];
                    temp2 = arr[posCurrStart];

                    arr[posCurrMax] = temp;
                    arr[posCurrMin] = temp2;

                    arr[posCurrStart] = currMin;
                    arr[posCurrEnd] = currMax;
                }
            }
        }
    }

    if (arr[1] < arr[2]) {
        temp = arr[1];
        arr[1] = arr[2];
        arr[2] = temp;
    }
}

void sortNumsInsertionMin2(int arr[], unsigned int size) {    
    unsigned int prevIdxCmp, i;
    int currValueToCompare;

    for (unsigned int currIdx = 1; currIdx < size; currIdx++)
    {
        currValueToCompare = arr[currIdx];
        prevIdxCmp = currIdx;

        // check all previous numbers to find the right position
        while (prevIdxCmp > 0)
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
}

void sort0_to_4NumsWithIfs(int arr[], unsigned int size) {
    int min0, max0, min1, max1, temp1;
    unsigned int min0Idx, maxIdx, min1Idx, tempIdxSum;

    switch (size) {
        case 0:
        case 1: break;
        case 2: {
            if (arr[0] > arr[1]) {
                swapInl(arr, &arr[1]);
            }
            break;
        }
        case 3: {
            min0 = arr[0];
            min0Idx = 0;
            if (arr[1] < min0) {
                min0 = arr[1];
                min0Idx = 1;
            }
            if (arr[2] < min0) {
                min0 = arr[2];
                min0Idx = 2;
            }

            max0 = arr[2];
            maxIdx = 2;
            if (arr[1] > max0) {
                max0 = arr[1];
                maxIdx = 1;
            }
            if (arr[0] > max0) {
                max0 = arr[0];
                maxIdx = 0;
            }

            min1Idx = 3 - maxIdx - min0Idx;
            temp1 = arr[min1Idx];

            arr[0] = min0;
            arr[1] = temp1;
            arr[2] = max0;

            break;
        }
        case 4: {
            min0 = arr[0];
            min0Idx = 0;
            if (arr[1] < min0) {
                min0 = arr[1];
                min0Idx = 1;
            }
            if (arr[2] < min0) {
                min0 = arr[2];
                min0Idx = 2;
            }
            if (arr[3] < min0) {
                min0 = arr[3];
                min0Idx = 3;
            }

            max0 = arr[3];
            maxIdx = 3;

            if (arr[2] > max0) {
                max0 = arr[2];
                maxIdx = 2;
            }

            if (arr[1] > max0) {
                max0 = arr[1];
                maxIdx = 1;
            }

            if (arr[0] > max0) {
                max0 = arr[0];
                maxIdx = 0;
            }

            // TODO finish this !!!
            // min0 and max0 will always be different. So we need only the two other indexes, i.e. the next smaller from max0, and the next bigger from min0
            // 

            // so - when we have two numbersw out of 4 - then we may have the following sum of the two indexes:
            //  0+1=1
            //  0+2=2
            //  0+3=3 - this and the other 3 are the only to have coincidence
            //  1+2=3 - this and the other 3 are the only to have coincidence
            //  1+3=4
            //  2+3=5
            tempIdxSum = min0Idx + maxIdx;
            // so we get the sum and:

            switch (tempIdxSum) {
                // then the other two numbers are 2 and 3
                case 1: {
                    if (arr[2] > arr[3]) {
                        min1 = arr[3];
                        max1 = arr[2];
                    }
                    else {
                        min1 = arr[2];
                        max1 = arr[3];
                    }
                    break;
                }

                case 2: {
                    if (arr[1] > arr[3]) {
                        min1 = arr[3];
                        max1 = arr[1];
                    }
                    else {
                        min1 = arr[1];
                        max1 = arr[3];
                    }
                    break;
                }

                case 3: {
                    if ((0 == min0Idx) || (0 == maxIdx)) { // if this - we have 3 from 0+3, 
                        if (arr[1] > arr[2]) {
                            min1 = arr[2];
                            max1 = arr[1];
                        }
                        else {
                            min1 = arr[1];
                            max1 = arr[2];
                        }
                    }
                    else { // otherwise it is from 1+2
                        if (arr[0] > arr[3]) {
                            min1 = arr[3];
                            max1 = arr[0];
                        }
                        else {
                            min1 = arr[0];
                            max1 = arr[3];
                        }                        
                    }
                    break;
                }

                case 4: {
                    if (arr[0] > arr[2]) {
                        min1 = arr[2];
                        max1 = arr[0];
                    }
                    else {
                        min1 = arr[0];
                        max1 = arr[2];
                    }
                    break;
                }

                case 5: {
                    if (arr[0] > arr[1]) {
                        min1 = arr[1];
                        max1 = arr[0];
                    }
                    else {
                        min1 = arr[0];
                        max1 = arr[1];
                    }
                    break;
                }
                default: {
                    // THIS SHALL NEVER HAPPEN !!!
                    break;
                }
            } // end internal switch 5 
            arr[0] = min0;
            arr[1] = min1;
            arr[2] = max1;
            arr[3] = max0;

            break;
        } // end general switch 4 

        default: {
            // THIS SHALL NEVER HAPPEN !!!
            break;
        }
    }
}

void sort2NumsWithIfsRusev(int arr[], unsigned int size) {
    if (arr[0] > arr[1]) {
        swapInl(arr, &arr[1]);
    }
}
void sort3NumsWithIfsRusev(int arr[], unsigned int size) {
    int min0, max0;
    unsigned int min0Idx, min1Idx, maxIdx;

    min0 = arr[0];
    min0Idx = 0;
    if (arr[1] < min0) {
        min0 = arr[1];
        min0Idx = 1;
    }
    if (arr[2] < min0) {
        min0 = arr[2];
        min0Idx = 2;
    }

    max0 = arr[2];
    maxIdx = 2;
    if (arr[1] > max0) {
        max0 = arr[1];
        maxIdx = 1;
    }
    if (arr[0] > max0) {
        max0 = arr[0];
        maxIdx = 0;
    }

    min1Idx = 3 - maxIdx - min0Idx;

    int temp1 = arr[min1Idx];

    arr[0] = min0;
    arr[1] = temp1;
    arr[2] = max0;
}
void sort4NumsWithIfsRusev(int arr[], unsigned int size) {
    int min0, min1, max1, max0;
    unsigned int min0Idx, maxIdx, tempIdxSum;

    min0 = arr[0];
    min0Idx = 0;
    if (arr[1] < min0) {
        min0 = arr[1];
        min0Idx = 1;
    }
    if (arr[2] < min0) {
        min0 = arr[2];
        min0Idx = 2;
    }
    if (arr[3] < min0) {
        min0 = arr[3];
        min0Idx = 3;
    }

    max0 = arr[3];
    maxIdx = 3;

    if (arr[2] > max0) {
        max0 = arr[2];
        maxIdx = 2;
    }

    if (arr[1] > max0) {
        max0 = arr[1];
        maxIdx = 1;
    }

    if (arr[0] > max0) {
        max0 = arr[0];
        maxIdx = 0;
    }

    // so - when we have two numbersw out of 4 - then we may have the following sum of the two indexes:
    //  0+1=1
    //  0+2=2
    //  0+3=3 - this and the other 3 are the only to have coincidence
    //  1+2=3 - this and the other 3 are the only to have coincidence
    //  1+3=4
    //  2+3=5
    tempIdxSum = min0Idx + maxIdx;
    // so we get the sum and:

    switch (tempIdxSum) {
        // then the other two numbers are 2 and 3
    case 1: {
        if (arr[2] > arr[3]) {
            min1 = arr[3];
            max1 = arr[2];
        }
        else {
            min1 = arr[2];
            max1 = arr[3];
        }
        break;
    }

    case 2: {
        if (arr[1] > arr[3]) {
            min1 = arr[3];
            max1 = arr[1];
        }
        else {
            min1 = arr[1];
            max1 = arr[3];
        }
        break;
    }

    case 3: {
        if ((0 == min0Idx) || (0 == maxIdx)) { // if this - we have 3 from 0+3, 
            if (arr[1] > arr[2]) {
                min1 = arr[2];
                max1 = arr[1];
            }
            else {
                min1 = arr[1];
                max1 = arr[2];
            }
        }
        else { // otherwise it is from 1+2
            if (arr[0] > arr[3]) {
                min1 = arr[3];
                max1 = arr[0];
            }
            else {
                min1 = arr[0];
                max1 = arr[3];
            }
        }
        break;
    }

    case 4: {
        if (arr[0] > arr[2]) {
            min1 = arr[2];
            max1 = arr[0];
        }
        else {
            min1 = arr[0];
            max1 = arr[2];
        }
        break;
    }

    case 5: {
        if (arr[0] > arr[1]) {
            min1 = arr[1];
            max1 = arr[0];
        }
        else {
            min1 = arr[0];
            max1 = arr[1];
        }
        break;
    }
    default: {
        // THIS SHALL NEVER HAPPEN !!!
        break;
    }
    } // end internal switch 5 
    arr[0] = min0;
    arr[1] = min1;
    arr[2] = max1;
    arr[3] = max0;
}

void sort8NumsWithIfsRusev(int arr[], unsigned int size) {
    int min0, min1, min2, min3, max3, max2, max1, max0, currNum;
    unsigned int min0Idx, min1Idx, maxIdx, max2Idx, idx;

    const unsigned int limit = 8;
    uint8_t tempArr[limit] = {0,0,0,0, 0,0,0,0};


    min0 = arr[0];
    min0Idx = 0;
    min1 = arr[1];
    min1Idx = 1;

    max0 = arr[7];
    maxIdx = 7;
    max1 = arr[6];
    max2Idx = 6;

    for (idx = 0; idx < limit; idx++) {
        // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
        // we care to compare with min1 - only if it is bigger. If it is equal - we have to compare with min1. 
        currNum = arr[idx];
        if (idx > 1) {
            if (min0 < min1) {
                if (currNum < min1) {
                    min1 = currNum;
                    min1Idx = idx;
                }
            }
            else {
                if (currNum < min0) {
                    min0 = currNum;
                    min0Idx = idx;
                }
            }
        }
        // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
        if (idx < 6) {
            if (max1 < max0) {
                if (currNum > max1) {
                    max1 = currNum;
                    max2Idx = idx;
                }
            }
            else {
                if (currNum > max0) {
                    max0 = currNum;
                    maxIdx = idx;
                }
            }
        }
    }
    // if necessary - swap based on indexes to keep the stability
    if ((min0Idx > min1Idx) && (min0 >= min1)) {
        if (min0 > min1) swapInl(&min0, &min1);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
        swapInl(&min0Idx, &min1Idx);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
    }

    if ((max2Idx > maxIdx) && (max1 >= max0)){
        swapInl(&max0, &max1);
        swapInl(&maxIdx, &max2Idx);
    }
                
    // we have now min0, min1, max0 and max1
    tempArr[min0Idx] = 1;
    tempArr[min1Idx] = 1;
    tempArr[maxIdx] = 1;
    tempArr[max2Idx] = 1;

    // now how to get the new starting values?
    // considering that we already have the max0 and mins - we get the current values:
    min3 = min2 = max0;
    max3 = max2 = min0;
        
    // now if our number is not marked - it will again take part in the evaluation
    for (idx = 0; idx < limit; idx++) {
        if (0 == tempArr[idx]) {
            // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
            // we care to compare with min3 - only if it is bigger. If it is equal - we have to compare with min1. 
            currNum = arr[idx];
            if (min2 < min3) {
                if (currNum < min3) {
                    min3 = currNum;
                    min0Idx = idx;
                }
            }
            else {
                if (currNum < min2) {
                    min2 = currNum;
                    min0Idx = idx;
                }
            }
            // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
            if (max3 < max2) {
                if (currNum > max3) {
                    max3 = currNum;
                    max2Idx = idx;
                }
            }
            else {
                if (currNum > max2) {
                    max2 = currNum;
                    maxIdx = idx;
                }
            }
        }
    }

    // if necessary - swap based on indexes to keep the stability
    if ((min0Idx > min1Idx) && (min2 >= min3)) {
        swapInl(&min2, &min3);
        // swapInl(&min0Idx, &min1Idx); // we don't need the indexes any more
    }

    if ((max2Idx > maxIdx) && (max3 >= max2)) {
        swapInl(&max3, &max2);
        // swapInl(&maxIdx, &max2Idx); // we don't need the indexes any more
    }
    /////////////////////////////////
    // now we have all numbers - we can directly assign them:
    arr[0] = min0;
    arr[1] = min1;
    arr[2] = min2;
    arr[3] = min3;
    arr[4] = max3;
    arr[5] = max2;
    arr[6] = max1;
    arr[7] = max0;   
}

void sort16NumsWithIfsRusev(int arr[], unsigned int size) {
    int min0, min1, min2, min3, min4, min5, min6, min7, max7, max6, max5, max4, max3, max2, max1, max0, currNum;
    unsigned int min0Idx, min1Idx, maxIdx, max2Idx, idx;

    const unsigned int limit = 16;
    uint8_t tempArr[limit] = { 0,0,0,0, 0,0,0,0,  0,0,0,0, 0,0,0,0 };

    min0 = arr[0];
    min0Idx = 0;
    min1 = arr[1];
    min1Idx = 1;

    max0 = arr[15];
    maxIdx = 15;
    max1 = arr[14];
    max2Idx = 14;

    for (idx = 0; idx < limit; idx++) {
        // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
        // we care to compare with min1 - only if it is bigger. If it is equal - we have to compare with min1. 
        currNum = arr[idx];
        if (idx > 1) {
            if (min0 < min1) {
                if (currNum < min1) {
                    min1 = currNum;
                    min1Idx = idx;
                }
            }
            else {
                if (currNum < min0) {
                    min0 = currNum;
                    min0Idx = idx;
                }
            }
        }
        // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
        if (idx < 14) {
            if (max1 < max0) {
                if (currNum > max1) {
                    max1 = currNum;
                    max2Idx = idx;
                }
            }
            else {
                if (currNum > max0) {
                    max0 = currNum;
                    maxIdx = idx;
                }
            }
        }
    }
    // if necessary - swap based on indexes to keep the stability
    if ((min0Idx > min1Idx) && (min0 >= min1)) {
        if (min0 > min1) swapInl(&min0, &min1);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
        swapInl(&min0Idx, &min1Idx);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
    }

    if ((max2Idx > maxIdx) && (max1 >= max0)) {
        swapInl(&max0, &max1);
        swapInl(&maxIdx, &max2Idx);
    }

    // we have now min0, min1, max0 and max1
    tempArr[min0Idx] = 1;
    tempArr[min1Idx] = 1;
    tempArr[maxIdx] = 1;
    tempArr[max2Idx] = 1;

    // now how to get the new starting values?
    // considering that we already have the max0 and mins - we get the current values:
    min3 = min2 = max0;
    max3 = max2 = min0;

    // now if our number is not marked - it will again take part in the evaluation
    for (idx = 0; idx < limit; idx++) {
        if (0 == tempArr[idx]) {
            // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
            // we care to compare with min3 - only if it is bigger. If it is equal - we have to compare with min1. 
            currNum = arr[idx];
            if (min2 < min3) {
                if (currNum < min3) {
                    min3 = currNum;
                    min1Idx = idx;
                }
            }
            else {
                if (currNum < min2) {
                    min2 = currNum;
                    min0Idx = idx;
                }
            }
            // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
            if (max3 < max2) {
                if (currNum > max3) {
                    max3 = currNum;
                    max2Idx = idx;
                }
            }
            else {
                if (currNum > max2) {
                    max2 = currNum;
                    maxIdx = idx;
                }
            }
        }
    }

    // if necessary - swap based on indexes to keep the stability
    if ((min0Idx > min1Idx) && (min2 >= min3)) {
        swapInl(&min2, &min3);
        swapInl(&min0Idx, &min1Idx);
    }

    if ((max2Idx > maxIdx) && (max3 >= max2)) {
        swapInl(&max3, &max2);
        swapInl(&maxIdx, &max2Idx);
    }

    // we have now min0, min1, max0 and max1
    tempArr[min0Idx] = 1;
    tempArr[min1Idx] = 1;
    tempArr[maxIdx] = 1;
    tempArr[max2Idx] = 1;

    // now how to get the new starting values?
    // considering that we already have the max0 and mins - we get the current values:
    min5 = min4 = max0;
    max5 = max4 = min0;

    /////////////////////////////////
    // now we have the first 8 numbers
    //---------------------------------
    // SECOND PART
    // going on 2 more times with the rest of the 8 numbers:


    // now if our number is not marked - it will again take part in the evaluation
    for (idx = 0; idx < limit; idx++) {
        if (0 == tempArr[idx]) {
            // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
            // we care to compare with min5 - only if it is bigger. If it is equal - we have to compare with min1. 
            currNum = arr[idx];
            if (min4 < min5) {
                if (currNum < min5) {
                    min5 = currNum;
                    min1Idx = idx;
                }
            }
            else {
                if (currNum < min4) {
                    min4 = currNum;
                    min0Idx = idx;
                }
            }
            // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
            if (max5 < max4) {
                if (currNum > max5) {
                    max5 = currNum;
                    max2Idx = idx;
                }
            }
            else {
                if (currNum > max4) {
                    max4 = currNum;
                    maxIdx = idx;
                }
            }
        }
    }

    // if necessary - swap based on indexes to keep the stability
    if ((min0Idx > min1Idx) && (min4 >= min5)) {
        swapInl(&min4, &min5);
        swapInl(&min0Idx, &min1Idx);
    }

    if ((max2Idx > maxIdx) && (max5 >= max4)) {
        swapInl(&max5, &max4);
        swapInl(&maxIdx, &max2Idx);
    }

    // we have now min0, min1, max0 and max1
    tempArr[min0Idx] = 1;
    tempArr[min1Idx] = 1;
    tempArr[maxIdx] = 1;
    tempArr[max2Idx] = 1;
    // -----------------------------
    // FINAL PART:
    // now how to get the new starting values?
    // considering that we already have the max0 and mins - we get the current values:
    min7 = min6 = max0;
    max7 = max6 = min0;


    // now if our number is not marked - it will again take part in the evaluation
    for (idx = 0; idx < limit; idx++) {
        if (0 == tempArr[idx]) {
            // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
            // we care to compare with min7 - only if it is bigger. If it is equal - we have to compare with min1. 
            currNum = arr[idx];
            if (min6 < min7) {
                if (currNum < min7) {
                    min7 = currNum;
                    min1Idx = idx;
                }
            }
            else {
                if (currNum < min6) {
                    min6 = currNum;
                    min0Idx = idx;
                }
            }
            // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
            if (max7 < max6) {
                if (currNum > max7) {
                    max7 = currNum;
                    max2Idx = idx;
                }
            }
            else {
                if (currNum > max6) {
                    max6 = currNum;
                    maxIdx = idx;
                }
            }
        }
    }

    // if necessary - swap based on indexes to keep the stability
    if ((min0Idx > min1Idx) && (min6 >= min7)) {
        swapInl(&min6, &min7);
        // swapInl(&min0Idx, &min1Idx); // we don't need the indexes any more
    }

    if ((max2Idx > maxIdx) && (max7 >= max6)) {
        swapInl(&max6, &max7);
        // swapInl(&maxIdx, &max2Idx); // we don't need the indexes any more
    }

    arr[0] = min0;
    arr[1] = min1;
    arr[2] = min2;
    arr[3] = min3;

    arr[4] = min4;
    arr[5] = min5;
    arr[6] = min6;
    arr[7] = min7;

    arr[8] = max7;
    arr[9] = max6;
    arr[10] = max5;
    arr[11] = max4;

    arr[12] = max3;
    arr[13] = max2;
    arr[14] = max1;
    arr[15] = max0;
}

static inline void goThroughArr(unsigned int limit, int& min0, int& min1, int& max0, int& max1, unsigned int& min0Idx, unsigned int& min1Idx, unsigned int& maxIdx, unsigned int& max2Idx, int *arr, uint8_t *tempArr ) {
    int currNum; unsigned int idx;
    // now if our number is not marked - it will again take part in the evaluation
    for (idx = 0; idx < limit; idx++) {
        if (0 == tempArr[idx]) {
            // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
            // we care to compare with min5 - only if it is bigger. If it is equal - we have to compare with min1. 
            currNum = arr[idx];
            if (min0 < min1) {
                if (currNum < min1) {
                    min1 = currNum;
                    min1Idx = idx;
                }
            }
            else {
                if (currNum < min0) {
                    min0 = currNum;
                    min0Idx = idx;
                }
            }
            // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
            if (max1 < max0) {
                if (currNum > max1) {
                    max1 = currNum;
                    max2Idx = idx;
                }
            }
            else {
                if (currNum > max0) {
                    max0 = currNum;
                    maxIdx = idx;
                }
            }
        }
    }


    if (min0 > min1) {
        swapInl(&min0, &min1);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
        swapInl(&min0Idx, &min1Idx);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
    }
    /* // BUT - WE DON'T NEED THIS AS IT IS POINTLESS TO CHANGE THE INDEXES ONLY - THOSE WILL BE ONLY MARKED!
    else {
        // if ((min0 == min1) && (min0Idx > min1Idx)) {
            // swapInl(&min0Idx, &min1Idx);
        // }
    }*/
    // if necessary - swap based on indexes to keep the stability    

    if (max1 > max0) {
        swapInl(&max0, &max1);
        swapInl(&maxIdx, &max2Idx);
    }

    // we have now min0, min1, max0 and max1
    tempArr[min0Idx] = 1;
    tempArr[min1Idx] = 1;
    tempArr[maxIdx] = 1;
    tempArr[max2Idx] = 1;
}

void sort32NumsWithIfsRusev(int arr[], unsigned int size) {
    int min0, min1, min2, min3, min4, min5, min6, min7, min8, min9, min10, min11,min12,min13,min14, min15, max15, max14, max13, max12, max11, max10, max9, max8,  max7, max6, max5, max4, max3, max2, max1, max0, currNum;
    unsigned int min0Idx, min1Idx, maxIdx, max2Idx, idx;

    const unsigned int limit = 32, minIdxConst = 0, maxIdxConst = 31;
    uint8_t tempArr[limit] = { 0,0,0,0, 0,0,0,0,  0,0,0,0, 0,0,0,0 ,  0,0,0,0, 0,0,0,0,  0,0,0,0, 0,0,0,0 };

    min0 = arr[minIdxConst];
    min0Idx = minIdxConst;
    min1 = arr[minIdxConst+1];
    min1Idx = minIdxConst+ 1;

    max0 = arr[maxIdxConst];
    maxIdx = maxIdxConst;
    max1 = arr[maxIdxConst-1];
    max2Idx = maxIdxConst-1;

    // only first part is different as we have to find the first two mins and 2 maxes
    for (idx = 0; idx < limit; idx++) {
        // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
        // we care to compare with min1 - only if it is bigger. If it is equal - we have to compare with min1. 
        currNum = arr[idx];
        if (idx > 1) {
            if (min0 < min1) {
                if (currNum < min1) {
                    min1 = currNum;
                    min1Idx = idx;
                }
            }
            else {
                if (currNum < min0) {
                    min0 = currNum;
                    min0Idx = idx;
                }
            }
        }
        // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
        if (idx < maxIdxConst - 1) {
            if (max1 < max0) {
                if (currNum > max1) {
                    max1 = currNum;
                    max2Idx = idx;
                }
            }
            else {
                if (currNum > max0) {
                    max0 = currNum;
                    maxIdx = idx;
                }
            }
        }
    }

    if (min0 > min1) {
        swapInl(&min0, &min1);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
        swapInl(&min0Idx, &min1Idx);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
    }
    /* // BUT - WE DON'T NEED THIS AS IT IS POINTLESS TO CHANGE THE INDEXES ONLY - THOSE WILL BE ONLY MARKED!
    else {        
        // if ((min0 == min1) && (min0Idx > min1Idx)) {
            // swapInl(&min0Idx, &min1Idx);
        // }
    }*/
    // if necessary - swap based on indexes to keep the stability    

    if (max1 > max0) {
        swapInl(&max0, &max1);
        swapInl(&maxIdx, &max2Idx);
    }

    // we have now min0, min1, max0 and max1
    tempArr[min0Idx] = 1;
    tempArr[min1Idx] = 1;
    tempArr[maxIdx] = 1;
    tempArr[max2Idx] = 1;

    // now how to get the new starting values?
    // considering that we already have the max0 and mins - we get the current values:
    min3 = min2 = max0;
    max3 = max2 = min0;

    goThroughArr(limit, min2, min3, max2, max3, min0Idx, min1Idx, maxIdx, max2Idx, arr, tempArr);

    min5 = min4 = max0;
    max5 = max4 = min0;

    goThroughArr(limit, min4, min5, max4, max5, min0Idx, min1Idx, maxIdx, max2Idx, arr, tempArr);

    min7 = min6 = max0;
    max7 = max6 = min0;

    goThroughArr(limit, min6, min7, max6, max7, min0Idx, min1Idx, maxIdx, max2Idx, arr, tempArr);

    min9 = min8 = max0;
    max9 = max8 = min0;

    goThroughArr(limit, min8, min9, max8, max9, min0Idx, min1Idx, maxIdx, max2Idx, arr, tempArr);

    min11 = min10 = max0;
    max11 = max10 = min0;

    goThroughArr(limit, min10, min11, max10, max11, min0Idx, min1Idx, maxIdx, max2Idx, arr, tempArr);

    min13 = min12 = max0;
    max13 = max12 = min0;

    goThroughArr(limit, min12, min13, max12, max13, min0Idx, min1Idx, maxIdx, max2Idx, arr, tempArr);

    min15 = min14 = max0;
    max15 = max14 = min0;

    goThroughArr(limit, min14, min15, max14, max15, min0Idx, min1Idx, maxIdx, max2Idx, arr, tempArr);

    arr[0] = min0;
    arr[1] = min1;
    arr[2] = min2;
    arr[3] = min3;

    arr[4] = min4;
    arr[5] = min5;
    arr[6] = min6;
    arr[7] = min7;

    arr[8] = min8;
    arr[9] = min9;
    arr[10] = min10;
    arr[11] = min11;

    arr[12] = min12;
    arr[13] = min13;
    arr[14] = min14;
    arr[15] = min15;


    arr[16] = max15;
    arr[17] = max14;
    arr[18] = max13;
    arr[19] = max12;

    arr[20] = max11;
    arr[21] = max10;
    arr[22] = max9;
    arr[23] = max8;

    arr[24] = max7;
    arr[25] = max6;
    arr[26] = max5;
    arr[27] = max4;

    arr[28] = max3;
    arr[29] = max2;
    arr[30] = max1;
    arr[31] = max0;
}


void sort32NumsWithIfsTemporaryArrayRusev(int arr[], unsigned int size) {
    
    const unsigned int limit = 32, minIdxConst = 0, maxIdxConst = 31;
    uint8_t tempArr[limit] = { 0,0,0,0, 0,0,0,0,  0,0,0,0, 0,0,0,0 ,  0,0,0,0, 0,0,0,0,  0,0,0,0, 0,0,0,0 };

    int sortedArr[limit], currNum, min0, min1, max1, max0, initMin, initMax;
    unsigned int min0Idx, min1Idx, max0Idx, max1Idx, idx, mainCycle;

    min0 = arr[minIdxConst];
    min0Idx = minIdxConst;
    min1 = arr[minIdxConst + 1];
    min1Idx = minIdxConst + 1;

    max0 = arr[maxIdxConst];
    max0Idx = maxIdxConst;
    max1 = arr[maxIdxConst - 1];
    max1Idx = maxIdxConst - 1;

    // only first part is different as we have to find the first two mins and 2 maxes
    for (idx = 0; idx < limit; idx++) {
        // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
        // we care to compare with min1 - only if it is bigger. If it is equal - we have to compare with min1. 
        currNum = arr[idx];
        if (idx > 1) {
            if (min0 < min1) {
                if (currNum < min1) {
                    min1 = currNum;
                    min1Idx = idx;
                }
            }
            else {
                if (currNum < min0) {
                    min0 = currNum;
                    min0Idx = idx;
                }
            }
        }
        // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
        if (idx < maxIdxConst - 1) {
            if (max1 < max0) {
                if (currNum > max1) {
                    max1 = currNum;
                    max1Idx = idx;
                }
            }
            else {
                if (currNum > max0) {
                    max0 = currNum;
                    max0Idx = idx;
                }
            }
        }
    }

    if (min0 > min1) {
        swapInl(&min0, &min1);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
        swapInl(&min0Idx, &min1Idx);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
    }

    if (max1 > max0) {
        swapInl(&max0, &max1);
        swapInl(&max0Idx, &max1Idx);
    }

    // we have now min0, min1, max0 and max1
    tempArr[min0Idx] = 1;
    tempArr[min1Idx] = 1;
    tempArr[max0Idx] = 1;
    tempArr[max1Idx] = 1;

    sortedArr[minIdxConst] = initMin = min0;
    sortedArr[minIdxConst + 1] = min1;
    sortedArr[maxIdxConst - 1] = max1;
    sortedArr[maxIdxConst] = initMax = max0;


    // we count here until we finish a certain number of iterations.
    for (mainCycle = 0; mainCycle < 7; mainCycle++) {
        min0 = min1 = initMax; // initializing with the biggest number found!
        max0 = max1 = initMin; // initializing with the smallest number found!

        // now if our number is not marked - it will again take part in the evaluation
        for (idx = 0; idx < limit; idx++) {
            if (0 == tempArr[idx]) {
                // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
                // we care to compare with min1 - only if it is bigger. If it is equal - we have to compare with min1. 
                currNum = arr[idx];
                if (min0 < min1) {
                    if (currNum < min1) {
                        min1 = currNum;
                        min1Idx = idx;
                    }
                }
                else {
                    if (currNum < min0) {
                        min0 = currNum;
                        min0Idx = idx;
                    }
                }
                // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
                if (max1 < max0) {
                    if (currNum > max1) {
                        max1 = currNum;
                        max1Idx = idx;
                    }
                }
                else {
                    if (currNum > max0) {
                        max0 = currNum;
                        max0Idx = idx;
                    }
                }
            }
        }

        // if necessary - swap based on indexes to keep the stability
        if (min0 > min1) {
            swapInl(&min0, &min1);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
            swapInl(&min0Idx, &min1Idx);       // swapping on temporary variables can be really fast compared to swapping somwhere in memory
        } 
        if (max1 > max0) {
            swapInl(&max0, &max1);
            swapInl(&max0Idx, &max1Idx);
        }        
        // we have now min0, min1, max0 and max1
        tempArr[min0Idx] = 1;
        tempArr[min1Idx] = 1;
        tempArr[max0Idx] = 1;
        tempArr[max1Idx] = 1;

        sortedArr[minIdxConst + 2 + mainCycle *2] = min0;
        sortedArr[minIdxConst + 2 + mainCycle *2 + 1] = min1;
        sortedArr[maxIdxConst - 2 - mainCycle * 2 - 1] = max1;
        sortedArr[maxIdxConst - 2 - mainCycle * 2] = max0;
    }

    for (idx = 0; idx < limit; idx++) {
        arr[idx] = sortedArr[idx];
    }
}




// this is with DYNAMIC ALLOCATION OF STACKS
template <const int T>
void RusevUltraBasedOn4Rusev(int arr[], unsigned int size) {

    unsigned int i;

    unsigned int partsCntr, temp;

    int tempInt;

    bool notSorted = false, notRevSorted = false;

    int prev = arr[0];

    for (i = 1; i < size; i++) {
        if (arr[i] < prev)
            notSorted = true;

        if (arr[i] > prev)
            notRevSorted = true;

        prev = arr[i];
        if (notRevSorted && notSorted) {
            break;
        }
    }

    if (notSorted) {
        if (notRevSorted) {

            partsCntr = (size / T);

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) 
                sort32NumsWithIfsRusev((arr + i * T), T);

            temp = size % T;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) 
                sortNumsInsertionMin2((arr + i * T), temp);

            //now merging all pieces:

            int* leftAr = new int[size];
            int* rightAr = new int[size];
            // start merging from midSz T. It will merge form midSz e.g. 32, then 64, 128 and so on 
            for (unsigned int midSz = T; midSz < size; midSz = 2 * midSz)
            {
                // pick starting point of left sub array. We
                // are going to merge arr[left..left+midSz-1]
                // and arr[left+midSz, left+2*midSz-1]
                // After every merge, we increase left by 2*midSz
                for (unsigned int left = 0; left < size; left += 2 * midSz)
                {
                    // find ending point of left sub array
                    // mid+1 is starting point of right sub array
                    unsigned int mid = left + midSz - 1;
                    if (mid > size - 1) {
                        break;
                    }
                    unsigned int right = min((left + 2 * midSz - 1), (size - 1));

                    // merge sub array arr[left.....mid] & arr[mid+1....right]
                    // merge_Rusev_impr(int arr[], unsigned int leftInput, unsigned int midInput, unsigned int rightInput, int* leftAr, int* rightAr)
                    merge_Rusev_impr(arr, left, mid, right, leftAr, rightAr);
                }
            }

            delete[] leftAr;
            delete[] rightAr;
        }
        else {
            //-----------------------------------------------
            // do the reversing!

            for (i = 0; i < size / 2; i++) {
                tempInt = arr[i];
                arr[i] = arr[size - i - 1];
                arr[size - i - 1] = tempInt;
            }
        }
    }
    else {
        //---------------------------------------
        // Do nothing - the array is sorted !
    }
}



// this is with DYNAMIC ALLOCATION OF STACKS
template <const int T>
void RusevUltraBasedOn4RusevV2(int arr[], unsigned int size) {

    unsigned int i;

    unsigned int partsCntr, temp;

    int tempInt;

    bool notSorted = false, notRevSorted = false;

    int prev = arr[0];

    for (i = 1; i < size; i++) {
        if (arr[i] < prev)
            notSorted = true;

        if (arr[i] > prev)
            notRevSorted = true;

        prev = arr[i];
        if (notRevSorted && notSorted) {
            break;
        }
    }

    if (notSorted) {
        if (notRevSorted) {

            partsCntr = (size / T);

            // sorting each single piece
            for (i = 0; i < partsCntr; i++)
                sort32NumsWithIfsTemporaryArrayRusev((arr + i * T), T);

            temp = size % T;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp)
                sortNumsInsertionMin2((arr + i * T), temp);

            //now merging all pieces:

            int* leftAr = new int[size];
            int* rightAr = new int[size];
            // start merging from midSz T. It will merge form midSz e.g. 32, then 64, 128 and so on 
            for (unsigned int midSz = T; midSz < size; midSz = 2 * midSz)
            {
                // pick starting point of left sub array. We
                // are going to merge arr[left..left+midSz-1]
                // and arr[left+midSz, left+2*midSz-1]
                // After every merge, we increase left by 2*midSz
                for (unsigned int left = 0; left < size; left += 2 * midSz)
                {
                    // find ending point of left sub array
                    // mid+1 is starting point of right sub array
                    unsigned int mid = left + midSz - 1;
                    if (mid > size - 1) {
                        break;
                    }
                    unsigned int right = min((left + 2 * midSz - 1), (size - 1));

                    // merge sub array arr[left.....mid] & arr[mid+1....right]
                    // merge_Rusev_impr(int arr[], unsigned int leftInput, unsigned int midInput, unsigned int rightInput, int* leftAr, int* rightAr)
                    merge_Rusev_impr(arr, left, mid, right, leftAr, rightAr);
                }
            }

            delete[] leftAr;
            delete[] rightAr;
        }
        else {
            //-----------------------------------------------
            // do the reversing!

            for (i = 0; i < size / 2; i++) {
                tempInt = arr[i];
                arr[i] = arr[size - i - 1];
                arr[size - i - 1] = tempInt;
            }
        }
    }
    else {
        //---------------------------------------
        // Do nothing - the array is sorted !
    }
}


typedef struct ValuePos_s {
    unsigned long long pos;
    int val;
}ValuePos_t;

#define LIMITER 4


#define MIN_IDX 0
#define MIN2_IDX 1
#define MAX2_IDX 2
#define MAX_IDX 3

#define DEBUG_PRINTS_ON
#ifdef DEBUG_PRINTS_ON
#define pout std::cout
#else
#define pout 0 && std::cout
#endif

using namespace std;

void RusevUltraSwapSort4(int arr[], unsigned int size) {
    register uint32_t tempArr = 0, tempArIdx;
    unsigned int minIdxConst = 0, maxIdxConst = 31;
    int min0, min1, max0, max1, minInit, maxInit;
    unsigned int min0Idx, min1Idx, max0Idx, max1Idx;
    unsigned int i, mainCycle;

    const unsigned int limit = 32, mainCycleLimit = 8;

    min0 = arr[minIdxConst];
    min0Idx = minIdxConst;
    min1 = arr[minIdxConst + 1];
    min1Idx = minIdxConst + 1;

    max0 = arr[maxIdxConst];
    max0Idx = maxIdxConst;
    max1 = arr[maxIdxConst - 1];
    max1Idx = maxIdxConst - 1;

    pout << "INIT: min0 " << min0 << " min1 "<< min1 << " max1 " << max1 << " max0 " << max0 << endl;
    pout << "INDEXES: min0 " << min0Idx << " min1 " << min1Idx << " max1 " << max1Idx << " max0 " << max0Idx << endl;

    int sortedArr[32] = { 0,0,0,0, 0,0,0,0,    0,0,0,0, 0,0,0,0,  0,0,0,0, 0,0,0,0,  0,0,0,0, 0,0,0,0, };

    int currNum;

    // first we pass through the array for the first two numbers


    // only first part is different as we have to find the first two mins and 2 maxes
    for (i = 0; i < limit; i++) {
        // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
        // we care to compare with min1 - only if it is bigger. If it is equal - we have to compare with min1. 
        currNum = arr[i];
        if (i > 1) {
            if (min0 < min1) {
                if (currNum < min1) {
                    min1 = currNum;
                    min1Idx = i;
                }
            }
            else {
                if (currNum < min0) {
                    min0 = currNum;
                    min0Idx = i;
                }
            }
        }
        // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
        if (i < maxIdxConst - 1) {
            if (max1 < max0) {
                if (currNum > max1) {
                    max1 = currNum;
                    max1Idx = i;
                }
            }
            else {
                if (currNum > max0) {
                    max0 = currNum;
                    max0Idx = i;
                }
            }
        }
    }

    
    if ((min0 > min1) || ((min1 == min0) && (min0Idx > min1Idx))) {
        swapInl(&min0, &min1);
        swapInl(&min0Idx, &min1Idx);
    }

    if ((max1 > max0) || ((max1 == max0) && (max1Idx > max0Idx))) {
        swapInl(&max0, &max1);
        swapInl(&max0Idx, &max1Idx);
    }

    // we have now min0, min1, max0 and max1
    tempArr |= 1 << min0Idx;
    tempArr |= 1 << min1Idx;
    tempArr |= 1 << max0Idx;
    tempArr |= 1 << max1Idx;

    sortedArr[minIdxConst] = min0;
    minInit = min0;
    sortedArr[minIdxConst+1] = min1;
    sortedArr[maxIdxConst-1] = max1;
    sortedArr[maxIdxConst] = max0;
    maxInit = max0;

    auto lamBits = [](uint32_t num) -> string{
        string res{};
        for (int i = 0; i < 32; i++) {
            res.append( to_string(0 != (num & (0x1 << i))));
        }
        return res;
    };

    pout << "ITERATION 0: min0 " << min0 << " min1 " << min1 << " max1 " << max1 << " max0 " << max0 << endl;
    pout << "INDEXES: min0 " << min0Idx << " min1 " << min1Idx << " max1 " << max1Idx << " max0 " << max0Idx << endl;
    pout << "tempArr BITS: " << lamBits(tempArr) << endl;
    

    pout << " ARRAY AFTER THIS ITERATION: sortedArr : " << endl;
    printArray(sortedArr, 32);

    minIdxConst += 2;
    maxIdxConst -= 2;

    // now how to get the new starting values?
    // considering that we already have the max0 and mins - we get the current values:
    max1 = max0 = minInit;
    min1 = min0 = maxInit;
    
    
    // we initialize here that by default the minimum is at start, and the maximum is at end.
    // then we iterate through the numbers to check this. This initialization is crucially important.
    
    for (mainCycle = 0; mainCycle < mainCycleLimit-1; mainCycle++) {
        // iterating through numbers
        pout << " \n \n ---------------- MAIN CYCLE " << mainCycle << " ---------------- " << endl;
        tempArIdx = 1;
        for (i = 0; i < limit; i++) {

            pout << "INTERNAL CYCLE ITERATION " << i << "  tempArr : " << lamBits(tempArr) << "    Evaluating bit result: " << (!(tempArIdx & tempArr)) << endl;

            if (!(tempArIdx & tempArr)) {
                // first evaluate the minimums - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
                // we care to compare with min5 - only if it is bigger. If it is equal - we have to compare with min1. 
                currNum = arr[i];

                pout << "         min0 " << min0 << " min1 " << min1 << " max1 " << max1 << " max0 " << max0 << endl;
                pout << "INDEXES: min0 " << min0Idx << " min1 " << min1Idx << " max1 " << max1Idx << " max0 " << max0Idx << endl;
                pout << "currNum : " << currNum << endl;
                

                if (min0 < min1) {
                    pout << "min0 < min1 TRUE " << endl;

                    if (currNum < min1) {
                        min1 = currNum;
                        min1Idx = i;
                        // pout << "currNum < min1 TRUE ; new min1 : " << min1 << endl;
                    }
                }
                else {
                    if (currNum < min0) {
                        min0 = currNum;
                        min0Idx = i;
                        // pout << "currNum < min0 TRUE ; new min0 : " << min0 << endl;
                    }
                }
                // second evaluate the MAXIMUMS - we either have one or the other case, never both. By this way we cannot have the two mins with the same number.
                if (max1 < max0) {
                    
                    pout << "max1 < max0 TRUE " << endl;

                    if (currNum >= max1) {
                        max1 = currNum;
                        max1Idx = i;
                        pout << "currNum < max1 TRUE ; new max1 : " << max1 << endl;
                    }
                }
                else {
                    if (max0 == max1) {
                        pout << "max1 == max0 TRUE " << endl;
                        if (max0Idx > max1Idx) {
                            if (currNum >= max1) {
                                max1 = currNum;
                                max1Idx = i;
                                pout << "currNum < max1 TRUE ; new max1 : " << max1 << endl;
                            }
                        }
                        else {
                            if (currNum >= max0) {
                                max0 = currNum;
                                max0Idx = i;
                                pout << "currNum < max0 TRUE ; new max0 : " << max0 << endl;
                            }
                        }
                    }
                    else { 
                        if (currNum >= max0) {
                            max0 = currNum;
                            max0Idx = i;
                            pout << "currNum < max0 TRUE ; new max0 : " << max0 << endl;
                        }
                    }
                }
            }
            tempArIdx = tempArIdx << 1;
        }

        if ((min0 > min1) || ((min1 == min0) && (min0Idx > min1Idx))) {
            swapInl(&min0, &min1);
            swapInl(&min0Idx, &min1Idx);
        }

        if ((max1 > max0) || ((max1 == max0) && ( max1Idx > max0Idx))) {
            swapInl(&max0, &max1);
            swapInl(&max0Idx, &max1Idx);
        }

        // we have now min0, min1, max0 and max1
        tempArr |= 1 << min0Idx;
        tempArr |= 1 << min1Idx;
        tempArr |= 1 << max0Idx;
        tempArr |= 1 << max1Idx;

        sortedArr[minIdxConst] = min0;
        sortedArr[minIdxConst + 1] = min1;
        sortedArr[maxIdxConst - 1] = max1;
        sortedArr[maxIdxConst] = max0;

        minInit = min0;
        maxInit = max0;
        max1 = max0 = minInit;
        min1 = min0 = maxInit;

        pout << "ITERATION" << mainCycle+1 << ": min0 " << min0 << " min1 " << min1 << " max1 " << max1 << " max0 " << max0 << endl;
        pout << "INDEXES: min0 " << min0Idx << " min1 " << min1Idx << " max1 " << max1Idx << " max0 " << max0Idx << endl;
        pout << "tempArr BITS: " << lamBits(tempArr) << endl;

        pout << " ARRAY AFTER THIS ITERATION: sortedArr : " << endl;
        printArray(sortedArr,32);

        minIdxConst += 2;
        maxIdxConst -= 2;
    }

    // finally copy all numbers
    for (i = 0; i < 32; i++) {
        arr[i] = sortedArr[i];
    }
    pout << "\n\n\n\n";
}

void RusevSwapSort4_ImprovedIfsV2(int arr[], unsigned int size) {

    
    bool finished = false;
    unsigned int i, posCurrStart = 0, posCurrEnd = size - 1, posCurrStart2 = posCurrStart + 1, posCurrEnd2 = posCurrEnd - 1;
    uint32_t startPos = 0x1, start2Pos = 0x2, end2Pos = 0x1 << 30, endPos = 0x1 << 31;    

    uint32_t map = 0, mapPos = 0;

    ValuePos_t newVals[LIMITER];
    int valToGet[LIMITER] = {};
    unsigned int cntrGet = 0;

    int currVal;

    //------------------------------------------------------------------------------------------    
    // main cycle
    while (!finished) {
        // we initialize here that by default the minimum is at start, and the maximum is at end.
        // then we iterate through the numbers to check this. This initialization is crucially important.

        newVals[MIN_IDX].val = arr[posCurrStart];
        newVals[MIN2_IDX].val = arr[posCurrStart2];
        newVals[MAX2_IDX].val = arr[posCurrEnd2];
        newVals[MAX_IDX].val = arr[posCurrEnd];

        newVals[MIN_IDX].pos = posCurrStart;
        newVals[MIN2_IDX].pos = posCurrStart2;
        newVals[MAX2_IDX].pos = posCurrEnd2;
        newVals[MAX_IDX].pos = posCurrEnd;

        // iterating through numbers
        for (i = posCurrStart; i <= posCurrEnd; i++) {

            currVal = arr[i];

            // finding the smallest number - get next smallest only if it is really smaller. Thus if we have smallest in the beginning we will not require swap.
            if (newVals[MIN_IDX].val >= newVals[MIN2_IDX].val) {
                if (currVal < newVals[MIN_IDX].val) {
                    newVals[MIN_IDX].val = currVal;
                    newVals[MIN_IDX].pos = i;
                }
            }
            else {
                if (currVal < newVals[MIN2_IDX].val) {
                    newVals[MIN2_IDX].val = currVal;
                    newVals[MIN2_IDX].pos = i;
                }
            }

            // finding the biggest number. Get only if it is greater.
            if (newVals[MAX_IDX].val < newVals[MAX2_IDX].val) {
                if (currVal > newVals[MAX_IDX].val) {
                    newVals[MAX_IDX].val = currVal;
                    newVals[MAX_IDX].pos = i;
                }
            }
            else {
                if (currVal > newVals[MAX2_IDX].val) {
                    newVals[MAX2_IDX].val = currVal;
                    newVals[MAX2_IDX].pos = i;
                }
            }
        }

        if (newVals[MAX2_IDX].val > newVals[MAX_IDX].val) {
            swapInl(&newVals[MAX2_IDX].val, &newVals[MAX_IDX].val);
            swapInl(&newVals[MAX2_IDX].pos, &newVals[MAX_IDX].pos);
        };

        if (newVals[MIN_IDX].val > newVals[MIN2_IDX].val) {
            swapInl(&newVals[MIN_IDX].val, &newVals[MIN2_IDX].val);
            swapInl(&newVals[MIN_IDX].pos, &newVals[MIN2_IDX].pos);
        };

        map |= (0x1 << newVals[MIN_IDX].pos);
        map |= (0x1 << newVals[MIN2_IDX].pos);
        map |= (0x1 << newVals[MAX2_IDX].pos);
        map |= (0x1 << newVals[MAX_IDX].pos);

        mapPos |= startPos;
        mapPos |= start2Pos;
        mapPos |= end2Pos;
        mapPos |= endPos;

        cntrGet = 0;

        if (!(map & startPos)) {
            valToGet[cntrGet] = arr[posCurrStart];
            cntrGet++;
        }        
        if (!(map & start2Pos)) {
            valToGet[cntrGet] = arr[posCurrStart2];
            cntrGet++;
        }
        if (!(map & end2Pos)) {
            valToGet[cntrGet] = arr[posCurrEnd2];
            cntrGet++;
        }
        if (!(map & endPos)) {
            valToGet[cntrGet] = arr[posCurrEnd];
            cntrGet++;
        }
        

        /*
        if ((newVals[MIN_IDX].pos != posCurrEnd) &&
            (newVals[MIN2_IDX].pos != posCurrEnd) &&
            (newVals[MAX2_IDX].pos != posCurrEnd) &&
            (newVals[MAX_IDX].pos != posCurrEnd)) {
                valToGet[cntrGet] = arr[posCurrEnd];
                cntrGet++;
        };*/

        //------------------------------------------------------------------------------
        // define which positions shall newVals[MAX_IDX].val be written to outside of end indexes:
        /*
        if ((newVals[MAX_IDX].pos > posCurrStart2) && (newVals[MAX_IDX].pos < posCurrEnd2)) {
            cntrGet--;
            arr[newVals[MAX_IDX].pos] = valToGet[cntrGet];
        }*/

        //------------------------------------------------------------------------------
        // define which positions shall newVals[MAX_IDX].val be written to outside of end indexes:
        if (!(mapPos & (0x1 << newVals[MAX_IDX].pos))) {
            cntrGet--;
            arr[newVals[MAX_IDX].pos] = valToGet[cntrGet];
        }
        if (!(mapPos & (0x1 << newVals[MAX2_IDX].pos))) {
            cntrGet--;
            arr[newVals[MAX2_IDX].pos] = valToGet[cntrGet];
        }
        if (!(mapPos & (0x1 << newVals[MIN2_IDX].pos))) {
            cntrGet--;
            arr[newVals[MIN2_IDX].pos] = valToGet[cntrGet];
        }
        if (!(mapPos & (0x1 << newVals[MIN_IDX].pos))) {
            cntrGet--;
            arr[newVals[MIN_IDX].pos] = valToGet[cntrGet];
        }

        arr[posCurrStart] = newVals[MIN_IDX].val;
        arr[posCurrStart2] = newVals[MIN2_IDX].val;
        arr[posCurrEnd2] = newVals[MAX2_IDX].val;
        arr[posCurrEnd] = newVals[MAX_IDX].val;

        if (4 < (posCurrEnd - posCurrStart)) {
            posCurrStart += 2;
            posCurrStart2 += 2;
            posCurrEnd2 -= 2;
            posCurrEnd -= 2;
            
            startPos = startPos << 2;
            start2Pos = start2Pos << 2;
            end2Pos = end2Pos >> 2;
            endPos = endPos >> 2;
        }
        else {
            finished = true;
            break;
        }
    }
}

#include <fstream>
#include <string>

void printArrToStream(std::ofstream& stream, int* arr, const unsigned length) {

    stream << "Array SIZE: " << length << ",";
    for (int i = 0; i < length; i++) {
        stream << arr[i] << ", ";
    }
    stream << endl;
}

void RusevSwapSort4_ImprovedIfs(int arr[], unsigned int size) {
    
    static unsigned cntrExec = 0;
    static unsigned cntrCyc = 1;

    bool firstPass = true;
    // std::ofstream execRep("Execution_" + std::to_string(cntrExec++) + "_.csv");

    unsigned int i, posCurrStart = 0, posCurrEnd = size - 1;

    uint32_t map = 0, mapPos = 0;

    ValuePos_t newVals[LIMITER];
    int valToGet[LIMITER] = {};
    unsigned int cntrGet = 0;

    unsigned int posCurrStart2, posCurrEnd2;

    int currVal;
    

    //------------------------------------------------------------------------------------------
    // Do the regular Rusev Sort
    // main cycle
    while (1) {
        execRep << "Iteration: " << cntrCyc++ << ",";
        // printArrToStream(execRep, arr, size);

        printArray(arr, size);

        // we initialize here that by default the minimum is at start, and the maximum is at end.
        // then we iterate through the numbers to check this. This initialization is crucially important.

        posCurrStart2 = posCurrStart + 1;
        posCurrEnd2 = posCurrEnd - 1;

        newVals[MIN_IDX].val = arr[posCurrStart];
        newVals[MIN2_IDX].val = arr[posCurrStart2];
        newVals[MAX2_IDX].val = arr[posCurrEnd2];
        newVals[MAX_IDX].val = arr[posCurrEnd];

        newVals[MIN_IDX].pos = posCurrStart;
        newVals[MIN2_IDX].pos = posCurrStart2;
        newVals[MAX2_IDX].pos = posCurrEnd2;
        newVals[MAX_IDX].pos = posCurrEnd;
        
        execRep << "posCurrStart posCurrStart2 posCurrEnd2 posCurrEnd : ," << posCurrStart << "," << posCurrStart2 << "," << posCurrEnd2 << "," << posCurrEnd << "\n";
        execRep << "Starting values: min  min2 max2 max ," << newVals[MIN_IDX].val << "," << newVals[MIN2_IDX].val << "," << newVals[MAX2_IDX].val << "," << newVals[MAX_IDX].val << "\n";

        // iterating through numbers
        for (i = posCurrStart; i <= posCurrEnd; i++) {
            
            currVal = arr[i];
            execRep << " Current Value: ,"<< currVal << "\n";

            if (i > posCurrStart2 || (false == firstPass)) { // we need this check so that at the first iteration we jump over the initial two numbers we took from posCurrStart and posCurrStart2
                // finding the smallest number - get next smallest only if it is really smaller. Thus if we have smallest in the beginning we will not require swap.
                if (newVals[MIN_IDX].val >= newVals[MIN2_IDX].val) {
                    if (currVal < newVals[MIN_IDX].val) {
                        newVals[MIN_IDX].val = currVal;
                        newVals[MIN_IDX].pos = i;
                        execRep << "  New min0," << currVal << "," << "at pos: , " << i << "\n";
                    }
                }
                else {
                    if (currVal < newVals[MIN2_IDX].val) {
                        newVals[MIN2_IDX].val = currVal;
                        newVals[MIN2_IDX].pos = i;
                        execRep << "  New min1," << currVal << "," << "at pos: , " << i << "\n";
                    }
                }
            }

            if (i < posCurrEnd2 || (false == firstPass)) { // we need this check so that at the first iteration we jump over the final two numbers we took from posCurrEnd and posCurrEnd2
                // finding the biggest number. Get only if it is greater.
                if (newVals[MAX_IDX].val < newVals[MAX2_IDX].val) {
                    if (currVal > newVals[MAX_IDX].val) {
                        newVals[MAX_IDX].val = currVal;
                        newVals[MAX_IDX].pos = i;
                        execRep << "  New max," << currVal << "," << "at pos: , " << i << "\n";
                    }
                }
                else {
                    if (currVal > newVals[MAX2_IDX].val) {
                        newVals[MAX2_IDX].val = currVal;
                        newVals[MAX2_IDX].pos = i;
                        execRep << "  New max2," << currVal << "," << "at pos: , " << i << "\n";
                    }
                }
            }
        }

        firstPass = false;

        if (newVals[MAX2_IDX].val > newVals[MAX_IDX].val) {
            swapInl(&newVals[MAX2_IDX].val, &newVals[MAX_IDX].val);
            swapInl(&newVals[MAX2_IDX].pos, &newVals[MAX_IDX].pos);
            execRep << "  SWAPPING MAXes max2 max after SWAP: ," << newVals[MAX2_IDX].val << "," << newVals[MAX_IDX].val << "\n";
        };

        if (newVals[MIN_IDX].val > newVals[MIN2_IDX].val) {
            swapInl(&newVals[MIN_IDX].val, &newVals[MIN2_IDX].val);
            swapInl(&newVals[MIN_IDX].pos, &newVals[MIN2_IDX].pos);
            execRep << "  SWAPPING MINs min0 min2 after SWAP: ," << newVals[MIN_IDX].val << "," << newVals[MIN2_IDX].val << "\n";
        };

        map |= (0x1 << newVals[MIN_IDX].pos);
        map |= (0x1 << newVals[MIN2_IDX].pos);
        map |= (0x1 << newVals[MAX2_IDX].pos);
        map |= (0x1 << newVals[MAX_IDX].pos);

        execRep << " MAP after current Iter: ," << intToBits(map) << ",";

        
        mapPos |= (0x1 << posCurrStart);
        mapPos |= (0x1 << posCurrStart2);
        mapPos |= (0x1 << posCurrEnd2);
        mapPos |= (0x1 << posCurrEnd);


        execRep << " MAPpos after current Iter: ," << intToBits(mapPos) << "\n";

        cntrGet = 0;

        if (!(map & (0x1 << posCurrStart))) {
            valToGet[cntrGet++] = arr[posCurrStart];
            execRep << "Adding to Get from posCurrStart : ," << valToGet[cntrGet-1] << "\n";
        }

        if (!(map & (0x1 << posCurrStart2))){
            valToGet[cntrGet++] = arr[posCurrStart2];
            execRep << "Adding to Get from posCurrStart2 : ," << valToGet[cntrGet - 1] << "\n";
        }

        if (!(map & (0x1 << posCurrEnd2))){
            valToGet[cntrGet++] = arr[posCurrEnd2];
            execRep << "Adding to Get from posCurrEnd2 : ," << valToGet[cntrGet - 1] << "\n";
        }

        if (!(map & (0x1 << posCurrEnd))){
            valToGet[cntrGet++] = arr[posCurrEnd];
            execRep << "Adding to Get from posCurrEnd : ," << valToGet[cntrGet - 1] << "\n";
        }

        //------------------------------------------------------------------------------
        // define which positions shall newVals[MAX_IDX].val be written to outside of end indexes:
        if (!(mapPos & (0x1 << newVals[MAX_IDX].pos))){
            arr[newVals[MAX_IDX].pos] = valToGet[--cntrGet];
            execRep << "Putting to pos : ," << newVals[MAX_IDX].pos << ", value : ," << arr[newVals[MAX_IDX].pos] << "\n";
        }

        if (!(mapPos & (0x1 << newVals[MAX2_IDX].pos))) {
            arr[newVals[MAX2_IDX].pos] = valToGet[--cntrGet];
            execRep << "Putting to pos : ," << newVals[MAX2_IDX].pos << ", value : ," << arr[newVals[MAX2_IDX].pos] << "\n";
        }

        if (!(mapPos & (0x1 << newVals[MIN2_IDX].pos))) {
            arr[newVals[MIN2_IDX].pos] = valToGet[--cntrGet];
            execRep << "Putting to pos : ," << newVals[MIN2_IDX].pos << ", value : ," << arr[newVals[MIN2_IDX].pos] << "\n";
        }

        if (!(mapPos & (0x1 << newVals[MIN_IDX].pos))) {
            arr[newVals[MIN_IDX].pos] = valToGet[--cntrGet];
            execRep << "Putting to pos : ," << newVals[MIN_IDX].pos << ", value : ," << arr[newVals[MIN_IDX].pos] << "\n";
        }

        arr[posCurrStart] = newVals[MIN_IDX].val;
        arr[posCurrStart2] = newVals[MIN2_IDX].val;
        arr[posCurrEnd2] = newVals[MAX2_IDX].val;
        arr[posCurrEnd] = newVals[MAX_IDX].val;

        if (4 < (posCurrEnd - posCurrStart)) {
            posCurrStart += 2;
            posCurrEnd -= 2;
        }
        else { // ALGO EXECUTION FINISHED
            // execRep.flush();
            // execRep.close();
            break;
        }
    }
}

void RusevSwapSort4_ImprovedIfs_32_V3(int arr[], const unsigned int size) {
    unsigned int i, posCurrStart = 0, posCurrEnd = 31;

    uint32_t map = 0, mapPos = 0;
    uint32_t mapBottom = 0x3;
    uint32_t mapTop = 0x3 << 30; // TODO CHECK THIS!
    
    ValuePos_t newVals[LIMITER];
    int valToGet[LIMITER] = {};
    unsigned int cntrGet = 0;

    unsigned int posCurrStart2, posCurrEnd2;

    int currVal;

    //------------------------------------------------------------------------------------------    
    // main cycle
    while (1) {
        // we initialize here that by default the minimum is at start, and the maximum is at end.
        // then we iterate through the numbers to check this. This initialization is crucially important.

        posCurrStart2 = posCurrStart + 1;
        posCurrEnd2 = posCurrEnd - 1;

        newVals[MIN_IDX].val = arr[posCurrStart];
        newVals[MIN2_IDX].val = arr[posCurrStart2];
        newVals[MAX2_IDX].val = arr[posCurrEnd2];
        newVals[MAX_IDX].val = arr[posCurrEnd];

        newVals[MIN_IDX].pos = posCurrStart;
        newVals[MIN2_IDX].pos = posCurrStart2;
        newVals[MAX2_IDX].pos = posCurrEnd2;
        newVals[MAX_IDX].pos = posCurrEnd;

        // iterating through numbers
        for (i = posCurrStart; i <= posCurrEnd; i++) {

            currVal = arr[i];

            if (i > posCurrStart2) { // we need this check so that at the first iteration we jump over the initial two numbers we took from posCurrStart and posCurrStart2
                // finding the smallest number - get next smallest only if it is really smaller. Thus if we have smallest in the beginning we will not require swap.
                if (newVals[MIN_IDX].val >= newVals[MIN2_IDX].val) {
                    if (currVal < newVals[MIN_IDX].val) {
                        newVals[MIN_IDX].val = currVal;
                        newVals[MIN_IDX].pos = i;
                    }
                }
                else {
                    if (currVal < newVals[MIN2_IDX].val) {
                        newVals[MIN2_IDX].val = currVal;
                        newVals[MIN2_IDX].pos = i;
                    }
                }
            }

            if (i < posCurrEnd2) { // we need this check so that at the first iteration we jump over the final two numbers we took from posCurrEnd and posCurrEnd2
                // finding the biggest number. Get only if it is greater.
                if (newVals[MAX_IDX].val < newVals[MAX2_IDX].val) {
                    if (currVal > newVals[MAX_IDX].val) {
                        newVals[MAX_IDX].val = currVal;
                        newVals[MAX_IDX].pos = i;
                    }
                }
                else {
                    if (currVal > newVals[MAX2_IDX].val) {
                        newVals[MAX2_IDX].val = currVal;
                        newVals[MAX2_IDX].pos = i;
                    }
                }
            }
        }

        if (newVals[MAX2_IDX].val > newVals[MAX_IDX].val) {
            swapInl(&newVals[MAX2_IDX].val, &newVals[MAX_IDX].val);
            swapInl(&newVals[MAX2_IDX].pos, &newVals[MAX_IDX].pos);
        };

        if (newVals[MIN_IDX].val > newVals[MIN2_IDX].val) {
            swapInl(&newVals[MIN_IDX].val, &newVals[MIN2_IDX].val);
            swapInl(&newVals[MIN_IDX].pos, &newVals[MIN2_IDX].pos);
        };

        map = 0;
        cntrGet = 0;

        map |= (0x1 << newVals[MIN_IDX].pos);
        map |= (0x1 << newVals[MIN2_IDX].pos);
        map |= (0x1 << newVals[MAX2_IDX].pos);
        map |= (0x1 << newVals[MAX_IDX].pos);

        mapPos |= mapBottom;
        mapPos |= mapTop;

        if (!(map & (0x1 << posCurrStart))) {
            valToGet[cntrGet] = arr[posCurrStart];
            cntrGet++;
        }

        if (!(map & (0x1 << posCurrStart2))) {
            valToGet[cntrGet] = arr[posCurrStart2];
            cntrGet++;
        }

        if (!(map & (0x1 << posCurrEnd2))) {
            valToGet[cntrGet] = arr[posCurrEnd2];
            cntrGet++;
        }

        if (!(map & (0x1 << posCurrEnd))) {
            valToGet[cntrGet] = arr[posCurrEnd];
            cntrGet++;
        }

        //------------------------------------------------------------------------------
        // define which positions shall newVals[MAX_IDX].val be written to outside of end indexes:
        if (!(mapPos & (0x1 << newVals[MAX_IDX].pos))) {
            if (cntrGet > 0) cntrGet--;
            arr[newVals[MAX_IDX].pos] = valToGet[cntrGet];
        }

        if (!(mapPos & (0x1 << newVals[MAX2_IDX].pos))) {
            if (cntrGet > 0) cntrGet--;
            arr[newVals[MAX2_IDX].pos] = valToGet[cntrGet];
        }

        if (!(mapPos & (0x1 << newVals[MIN2_IDX].pos))) {
            if (cntrGet > 0) cntrGet--;
            arr[newVals[MIN2_IDX].pos] = valToGet[cntrGet];
        }

        if (!(mapPos & (0x1 << newVals[MIN_IDX].pos))) {
            if (cntrGet > 0) cntrGet--;
            arr[newVals[MIN_IDX].pos] = valToGet[cntrGet];
        }

        arr[posCurrStart] = newVals[MIN_IDX].val;
        arr[posCurrStart2] = newVals[MIN2_IDX].val;
        arr[posCurrEnd2] = newVals[MAX2_IDX].val;
        arr[posCurrEnd] = newVals[MAX_IDX].val;

        if (4 < (posCurrEnd - posCurrStart)) {
            posCurrStart += 2;
            posCurrEnd -= 2;
            mapBottom = mapBottom << 2;
            mapTop = mapTop >> 2;
        }
        else { // ALGO EXECUTION FINISHED            
            break;
        }
    }
}



// this is with DYNAMIC ALLOCATION OF STACKS
template <const int T>
void RusevUltraBasedOn4_V3_integral(int arr[], unsigned int size) {

    unsigned int i;

    unsigned int partsCntr, temp;

    int tempInt;

    bool notSorted = false, notRevSorted = false;

    int prev = arr[0];

    for (i = 1; i < size; i++) {
        if (arr[i] < prev)
            notSorted = true;

        if (arr[i] > prev)
            notRevSorted = true;

        prev = arr[i];
        if (notRevSorted && notSorted) {
            break;
        }
    }

    if (notSorted) {
        if (notRevSorted) {

            partsCntr = (size / T);

            // sorting each single piece
            for (i = 0; i < partsCntr; i++)
                RusevSwapSort4_ImprovedIfs_32_V3((arr + i * T), T);

            temp = size % T;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp)
                sortNumsInsertionMin2((arr + i * T), temp);

            //now merging all pieces:

            int* leftAr = new int[size];
            int* rightAr = new int[size];
            // start merging from midSz T. It will merge form midSz e.g. 32, then 64, 128 and so on 
            for (unsigned int midSz = T; midSz < size; midSz = 2 * midSz)
            {
                // pick starting point of left sub array. We
                // are going to merge arr[left..left+midSz-1]
                // and arr[left+midSz, left+2*midSz-1]
                // After every merge, we increase left by 2*midSz
                for (unsigned int left = 0; left < size; left += 2 * midSz)
                {
                    // find ending point of left sub array
                    // mid+1 is starting point of right sub array
                    unsigned int mid = left + midSz - 1;
                    if (mid > size - 1) {
                        break;
                    }
                    unsigned int right = min((left + 2 * midSz - 1), (size - 1));

                    // merge sub array arr[left.....mid] & arr[mid+1....right]
                    // merge_Rusev_impr(int arr[], unsigned int leftInput, unsigned int midInput, unsigned int rightInput, int* leftAr, int* rightAr)
                    merge_Rusev_impr(arr, left, mid, right, leftAr, rightAr);
                }
            }

            delete[] leftAr;
            delete[] rightAr;
        }
        else {
            //-----------------------------------------------
            // do the reversing!

            for (i = 0; i < size / 2; i++) {
                tempInt = arr[i];
                arr[i] = arr[size - i - 1];
                arr[size - i - 1] = tempInt;
            }
        }
    }
    else {
        //---------------------------------------
        // Do nothing - the array is sorted !
    }
}



void RusevSwapSort4_ImprovedIfs_32_V3_printout(int arr[], const unsigned int size) {
    unsigned int i, posCurrStart = 0, posCurrEnd = 31;

    uint32_t map = 0, mapPos = 0;
    uint32_t mapBottom = 0x3;
    uint32_t mapTop = 0x3 << 30; // TODO CHECK THIS!
    execRep << " INIT mapTop : ," << intToBits(mapTop) << "\n";

    ValuePos_t newVals[LIMITER];
    int valToGet[LIMITER] = {};
    unsigned int cntrGet = 0;

    unsigned int posCurrStart2, posCurrEnd2;

    int currVal;

    static unsigned cntrCyc = 1;

    //------------------------------------------------------------------------------------------
    // main cycle
    while (1) {
        execRep << "Iteration: " << cntrCyc++ << ",";
        // printArrToStream(execRep, arr, size);

        printArray(arr, size);

        // we initialize here that by default the minimum is at start, and the maximum is at end.
        // then we iterate through the numbers to check this. This initialization is crucially important.

        posCurrStart2 = posCurrStart + 1;
        posCurrEnd2 = posCurrEnd - 1;

        newVals[MIN_IDX].val = arr[posCurrStart];
        newVals[MIN2_IDX].val = arr[posCurrStart2];
        newVals[MAX2_IDX].val = arr[posCurrEnd2];
        newVals[MAX_IDX].val = arr[posCurrEnd];

        newVals[MIN_IDX].pos = posCurrStart;
        newVals[MIN2_IDX].pos = posCurrStart2;
        newVals[MAX2_IDX].pos = posCurrEnd2;
        newVals[MAX_IDX].pos = posCurrEnd;

        execRep << "posCurrStart posCurrStart2 posCurrEnd2 posCurrEnd : ," << posCurrStart << "," << posCurrStart2 << "," << posCurrEnd2 << "," << posCurrEnd << "\n";        

        // iterating through numbers
        for (i = posCurrStart; i <= posCurrEnd; i++) {

            currVal = arr[i];
            execRep << " Current Value: ," << currVal << "   " << " min  min2 max2 max : " << newVals[MIN_IDX].val << "  " << newVals[MIN2_IDX].val << "  " << newVals[MAX2_IDX].val << "  " << newVals[MAX_IDX].val << "  ";

            if (i > posCurrStart2) { // we need this check so that at the first iteration we jump over the initial two numbers we took from posCurrStart and posCurrStart2
                // finding the smallest number - get next smallest only if it is really smaller. Thus if we have smallest in the beginning we will not require swap.
                if (newVals[MIN_IDX].val >= newVals[MIN2_IDX].val) {
                    if (currVal < newVals[MIN_IDX].val) {
                        newVals[MIN_IDX].val = currVal;
                        newVals[MIN_IDX].pos = i;
                        execRep << "  New min0  " << currVal << "  " << "at pos: , " << i << "  ";
                    }
                }
                else {
                    if (currVal < newVals[MIN2_IDX].val) {
                        newVals[MIN2_IDX].val = currVal;
                        newVals[MIN2_IDX].pos = i;
                        execRep << "  New min1  " << currVal << "  " << "at pos: , " << i << "  ";
                    }
                }
            }

            if (i < posCurrEnd2) { // we need this check so that at the first iteration we jump over the final two numbers we took from posCurrEnd and posCurrEnd2
                // finding the biggest number. Get only if it is greater.
                if (newVals[MAX_IDX].val < newVals[MAX2_IDX].val) {
                    if (currVal > newVals[MAX_IDX].val) {
                        newVals[MAX_IDX].val = currVal;
                        newVals[MAX_IDX].pos = i;
                        execRep << "  New max  " << currVal << "  " << "at pos: , " << i << "  ";
                    }
                }
                else {
                    if (currVal > newVals[MAX2_IDX].val) {
                        newVals[MAX2_IDX].val = currVal;
                        newVals[MAX2_IDX].pos = i;
                        execRep << "  New max2  " << currVal << "  " << "at pos: , " << i << "  ";
                    }
                }
            }
            execRep << "\n";
        }

        if (newVals[MAX2_IDX].val > newVals[MAX_IDX].val) {
            swapInl(&newVals[MAX2_IDX].val, &newVals[MAX_IDX].val);
            swapInl(&newVals[MAX2_IDX].pos, &newVals[MAX_IDX].pos);
            execRep << "  SWAPPING MAXes max2 max after SWAP: ," << newVals[MAX2_IDX].val << "," << newVals[MAX_IDX].val << "\n";
        };

        if (newVals[MIN_IDX].val > newVals[MIN2_IDX].val) {
            swapInl(&newVals[MIN_IDX].val, &newVals[MIN2_IDX].val);
            swapInl(&newVals[MIN_IDX].pos, &newVals[MIN2_IDX].pos);
            execRep << "  SWAPPING MINs min0 min2 after SWAP: ," << newVals[MIN_IDX].val << "," << newVals[MIN2_IDX].val << "\n";
        };
        
        map = 0;
        map |= (0x1 << newVals[MIN_IDX].pos);
        map |= (0x1 << newVals[MIN2_IDX].pos);
        map |= (0x1 << newVals[MAX2_IDX].pos);
        map |= (0x1 << newVals[MAX_IDX].pos);

        execRep << " MAP after current Iter: ," << intToBits(map) << ",";
        // OPTIMIZE !!!
        /*mapPos |= (0x1 << posCurrStart);
        mapPos |= (0x1 << posCurrStart2);
        mapPos |= (0x1 << posCurrEnd2);
        mapPos |= (0x1 << posCurrEnd);*/

        mapPos |= mapBottom;
        mapPos |= mapTop;

        execRep << " MAPpos after current Iter: ," << intToBits(mapPos) << "\n";

        cntrGet = 0;

        if (!(map & (0x1 << posCurrStart))) {
            valToGet[cntrGet] = arr[posCurrStart];
            cntrGet++;
            execRep << "Adding to Get from posCurrStart : ," << valToGet[cntrGet - 1] << "\n";
        }

        if (!(map & (0x1 << posCurrStart2))) {
            valToGet[cntrGet] = arr[posCurrStart2];
            cntrGet++;
            execRep << "Adding to Get from posCurrStart2 : ," << valToGet[cntrGet - 1] << "\n";
        }

        if (!(map & (0x1 << posCurrEnd2))) {
            valToGet[cntrGet] = arr[posCurrEnd2];
            cntrGet++;
            execRep << "Adding to Get from posCurrEnd2 : ," << valToGet[cntrGet - 1] << "\n";
        }

        if (!(map & (0x1 << posCurrEnd))) {
            valToGet[cntrGet] = arr[posCurrEnd];
            cntrGet++;
            execRep << "Adding to Get from posCurrEnd : ," << valToGet[cntrGet - 1] << "\n";
        }

        //------------------------------------------------------------------------------
        // define which positions shall newVals[MAX_IDX].val be written to outside of end indexes:
        if (!(mapPos & (0x1 << newVals[MAX_IDX].pos))) {
            if (cntrGet > 0) cntrGet--;
            arr[newVals[MAX_IDX].pos] = valToGet[cntrGet];            
            execRep << "Putting to pos : ," << newVals[MAX_IDX].pos << ", value : ," << arr[newVals[MAX_IDX].pos] << "\n";
        }

        if (!(mapPos & (0x1 << newVals[MAX2_IDX].pos))) {
            if (cntrGet > 0) cntrGet--;
            arr[newVals[MAX2_IDX].pos] = valToGet[cntrGet];            
            execRep << "Putting to pos : ," << newVals[MAX2_IDX].pos << ", value : ," << arr[newVals[MAX2_IDX].pos] << "\n";
        }

        if (!(mapPos & (0x1 << newVals[MIN2_IDX].pos))) {
            if (cntrGet > 0) cntrGet--;
            arr[newVals[MIN2_IDX].pos] = valToGet[cntrGet];            
            execRep << "Putting to pos : ," << newVals[MIN2_IDX].pos << ", value : ," << arr[newVals[MIN2_IDX].pos] << "\n";
        }

        if (!(mapPos & (0x1 << newVals[MIN_IDX].pos))) {
            if (cntrGet > 0) cntrGet--;
            arr[newVals[MIN_IDX].pos] = valToGet[cntrGet];            
            execRep << "Putting to pos : ," << newVals[MIN_IDX].pos << ", value : ," << arr[newVals[MIN_IDX].pos] << "\n";
        }

        arr[posCurrStart] = newVals[MIN_IDX].val;
        arr[posCurrStart2] = newVals[MIN2_IDX].val;
        arr[posCurrEnd2] = newVals[MAX2_IDX].val;
        arr[posCurrEnd] = newVals[MAX_IDX].val;

        if (4 < (posCurrEnd - posCurrStart)) {
            posCurrStart += 2;
            posCurrEnd -= 2;
            mapBottom = mapBottom << 2;
            mapTop = mapTop >> 2;
        }
        else { // ALGO EXECUTION FINISHED            
            break;
        }
    }
}


void RusevSwapSort2ImprIdx_Ultra(int arr[], unsigned int size) {
    bool finished = false;

    // these are the smallest and the biggest numbers
    int currMin, currMax, temp, temp2;
    unsigned int i, posCurrMin = 0, posCurrMax = 0, posCurrStart = 0, posCurrEnd = size - 1;


    //------------------------------------------------------------------------------------------
    // Do the regular Rusev Sort
    // main cycle
    while (!finished) {

        // we initialize here that by default the minimum is at start, and the maximum is at end.
        // then we iterate through the numbers to check this. This initialization is crucially important.
        currMin = arr[posCurrStart];
        posCurrMin = posCurrStart;
        currMax = arr[posCurrEnd];
        posCurrMax = posCurrEnd;

        // iterating through numbers
        for (i = posCurrStart; i <= posCurrEnd; i++) {


            // finding the smallest number - get next smallest only if it is really smaller. Thus if we have smallest in the beginning we will not require swap.
            if (arr[i] < currMin) {
                currMin = arr[i];
                posCurrMin = i;
            }

            // finding the biggest number. Get only if it is greater.
            if (arr[i] > currMax) {
                currMax = arr[i];
                posCurrMax = i;
            }
        }

        // Improved performance of our cases:

        if (posCurrMin == posCurrEnd) {

            if (posCurrMax == posCurrStart) {
                // 2. swap ends
                arr[posCurrStart] = currMin;
                arr[posCurrEnd] = currMax;

            }
            else { // means posCurrMax == somwhere in the middle
             // 3. 3 nums, collide at end
                temp = arr[posCurrStart];
                arr[posCurrStart] = currMin;
                arr[posCurrEnd] = currMax;
                arr[posCurrMax] = temp;
            }
        }
        else {
            if (posCurrMin == posCurrStart) {

                if (posCurrMax == posCurrEnd) {
                    // 1. Do nothing - everything in correct place
                }
                else { // means posCurrMax == somwhere in the middle
                    // 7. Swap only max with end
                    temp = arr[posCurrEnd];
                    arr[posCurrMax] = temp;
                    arr[posCurrEnd] = currMax;
                }
            }
            else { // this means we are somwhere in the middle for the current minimal value!

                if (posCurrMax == posCurrEnd) {
                    // 6. Swap only min with start
                    temp = arr[posCurrStart];
                    arr[posCurrMin] = temp;
                    arr[posCurrStart] = currMin;
                }
                else { // means posCurrMax == somwhere in the middle

                    if (posCurrMax == posCurrStart) {
                        // 4. 3 nums, collide at start
                        temp = arr[posCurrEnd];
                        arr[posCurrStart] = currMin;
                        arr[posCurrEnd] = currMax;
                        arr[posCurrMin] = temp;
                    }
                    else { // means posCurrMax == somwhere in the middle
                     // 5. double 2 swaps
                        temp = arr[posCurrEnd];
                        temp2 = arr[posCurrStart];

                        arr[posCurrMax] = temp;
                        arr[posCurrMin] = temp2;

                        arr[posCurrStart] = currMin;
                        arr[posCurrEnd] = currMax;
                    }
                }
            }
        }

        if (2 < (posCurrEnd - posCurrStart)) {
            posCurrStart++;
            posCurrEnd--;
        }
        else {
            finished = true;
            break;
        }
    }
}


void RusevSwapSort2ImprIdx_Original(int arr[], unsigned int size) {
    bool finished = false;

    // these are the smallest and the biggest numbers
    int currMin, currMax, temp, temp2;
    unsigned int i, posCurrMin = 0, posCurrMax = 0, posCurrStart = 0, posCurrEnd = size - 1;


    //------------------------------------------------------------------------------------------
    // Do the regular Rusev Sort
    // main cycle
    while (!finished) {

        // we initialize here that by default the minimum is at start, and the maximum is at end.
        // then we iterate through the numbers to check this. This initialization is crucially important.
        currMin = arr[posCurrStart];
        posCurrMin = posCurrStart;
        currMax = arr[posCurrEnd];
        posCurrMax = posCurrEnd;

        // iterating through numbers
        for (i = posCurrStart; i <= posCurrEnd; i++) {


            // finding the smallest number - get next smallest only if it is really smaller. Thus if we have smallest in the beginning we will not require swap.
            if (arr[i] < currMin) {
                currMin = arr[i];
                posCurrMin = i;
            }

            // finding the biggest number. Get only if it is greater.
            if (arr[i] > currMax) {
                currMax = arr[i];
                posCurrMax = i;
            }
        }

        // Improved performance of our cases:

        if (posCurrMin == posCurrEnd) {

            if (posCurrMax == posCurrStart) {
                // 2. swap ends
                arr[posCurrStart] = currMin;
                arr[posCurrEnd] = currMax;

            }
            else { // means posCurrMax == somwhere in the middle
             // 3. 3 nums, collide at end
                temp = arr[posCurrStart];
                arr[posCurrStart] = currMin;
                arr[posCurrEnd] = currMax;
                arr[posCurrMax] = temp;
            }
        }
        else {
            if (posCurrMin == posCurrStart) {

                if (posCurrMax == posCurrEnd) {
                    // 1. Do nothing - everything in correct place
                }
                else { // means posCurrMax == somwhere in the middle
                    // 7. Swap only max with end
                    temp = arr[posCurrEnd];
                    arr[posCurrMax] = temp;
                    arr[posCurrEnd] = currMax;
                }
            }
            else { // this means we are somwhere in the middle for the current minimal value!

                if (posCurrMax == posCurrEnd) {
                    // 6. Swap only min with start
                    temp = arr[posCurrStart];
                    arr[posCurrMin] = temp;
                    arr[posCurrStart] = currMin;
                }
                else { // means posCurrMax == somwhere in the middle

                    if (posCurrMax == posCurrStart) {
                        // 4. 3 nums, collide at start
                        temp = arr[posCurrEnd];
                        arr[posCurrStart] = currMin;
                        arr[posCurrEnd] = currMax;
                        arr[posCurrMin] = temp;
                    }
                    else { // means posCurrMax == somwhere in the middle
                     // 5. double 2 swaps
                        temp = arr[posCurrEnd];
                        temp2 = arr[posCurrStart];

                        arr[posCurrMax] = temp;
                        arr[posCurrMin] = temp2;

                        arr[posCurrStart] = currMin;
                        arr[posCurrEnd] = currMax;
                    }
                }
            }
        }

        if (2 < (posCurrEnd - posCurrStart)) {
            posCurrStart++;
            posCurrEnd--;
        }
        else {
            finished = true;
            break;
        }
    }
}


void RusevSwapSort4_Original(int arr[], unsigned int size) {
    bool finished = false;

    int temp0, tempStart, tempStart2, tempEnd2, tempEnd;
    unsigned int i, posCurrStart = 0, posCurrEnd = size - 1;

    ValuePos_t newVals[LIMITER];
    int valToGet[LIMITER] = {};
    unsigned int cntrGet = 0;

    unsigned int posCurrStart2 = posCurrStart + 1, posCurrEnd2 = posCurrEnd - 1;

    unsigned int totalPositionsToWrite = 0;

    int currVal;

    //------------------------------------------------------------------------------------------
    // Do the regular Rusev Sort
    // main cycle
    while (!finished) {
        // we initialize here that by default the minimum is at start, and the maximum is at end.
        // then we iterate through the numbers to check this. This initialization is crucially important.

        posCurrStart2 = posCurrStart + 1;
        posCurrEnd2 = posCurrEnd - 1;

        tempStart = arr[posCurrStart];
        tempStart2 = arr[posCurrStart2];
        tempEnd2 = arr[posCurrEnd2];
        tempEnd = arr[posCurrEnd];

        newVals[MIN_IDX].val = tempStart;
        newVals[MIN2_IDX].val = tempStart2;
        newVals[MAX2_IDX].val = tempEnd2;
        newVals[MAX_IDX].val = tempEnd;

        newVals[MIN_IDX].pos = posCurrStart;
        newVals[MIN2_IDX].pos = posCurrStart2;
        newVals[MAX2_IDX].pos = posCurrEnd2;
        newVals[MAX_IDX].pos = posCurrEnd;

        cntrGet = 0;

        // iterating through numbers
        for (i = posCurrStart; i <= posCurrEnd; i++) {

            currVal = arr[i];

            // finding the smallest number - get next smallest only if it is really smaller. Thus if we have smallest in the beginning we will not require swap.
            if (newVals[MIN_IDX].val >= newVals[MIN2_IDX].val) {
                if (currVal < newVals[MIN_IDX].val) {
                    newVals[MIN_IDX].val = currVal;
                    newVals[MIN_IDX].pos = i;
                }
            }
            else {
                if (currVal < newVals[MIN2_IDX].val) {
                    newVals[MIN2_IDX].val = currVal;
                    newVals[MIN2_IDX].pos = i;
                }
            }

            // finding the biggest number. Get only if it is greater.
            if (newVals[MAX_IDX].val < newVals[MAX2_IDX].val) {
                if (currVal > newVals[MAX_IDX].val) {
                    newVals[MAX_IDX].val = currVal;
                    newVals[MAX_IDX].pos = i;
                }
            }
            else {
                if (currVal > newVals[MAX2_IDX].val) {
                    newVals[MAX2_IDX].val = currVal;
                    newVals[MAX2_IDX].pos = i;
                }
            }
        }

        if (newVals[MAX2_IDX].val > newVals[MAX_IDX].val) {
            swapInl(&newVals[MAX2_IDX].val, &newVals[MAX_IDX].val);
            swapInl(&newVals[MAX2_IDX].pos, &newVals[MAX_IDX].pos);
        };

        if (newVals[MIN_IDX].val > newVals[MIN2_IDX].val) {
            swapInl(&newVals[MIN_IDX].val, &newVals[MIN2_IDX].val);
            swapInl(&newVals[MIN_IDX].pos, &newVals[MIN2_IDX].pos);
        };

        if ((newVals[MIN_IDX].pos != posCurrStart) &&
            (newVals[MIN2_IDX].pos != posCurrStart) &&
            (newVals[MAX2_IDX].pos != posCurrStart) &&
            (newVals[MAX_IDX].pos != posCurrStart)) {
            valToGet[cntrGet] = arr[posCurrStart];
            cntrGet++;
        };

        if ((newVals[MIN_IDX].pos != posCurrStart2) &&
            (newVals[MIN2_IDX].pos != posCurrStart2) &&
            (newVals[MAX2_IDX].pos != posCurrStart2) &&
            (newVals[MAX_IDX].pos != posCurrStart2)) {
            valToGet[cntrGet] = arr[posCurrStart2];
            cntrGet++;
        };

        if ((newVals[MIN_IDX].pos != posCurrEnd2) &&
            (newVals[MIN2_IDX].pos != posCurrEnd2) &&
            (newVals[MAX2_IDX].pos != posCurrEnd2) &&
            (newVals[MAX_IDX].pos != posCurrEnd2)) {
            valToGet[cntrGet] = arr[posCurrEnd2];
            cntrGet++;
        };

        if ((newVals[MIN_IDX].pos != posCurrEnd) &&
            (newVals[MIN2_IDX].pos != posCurrEnd) &&
            (newVals[MAX2_IDX].pos != posCurrEnd) &&
            (newVals[MAX_IDX].pos != posCurrEnd)) {
            valToGet[cntrGet] = arr[posCurrEnd];
            cntrGet++;
        };

        //------------------------------------------------------------------------------
        // define which positions shall newVals[MAX_IDX].val be written to outside of end indexes:
        if ((newVals[MAX_IDX].pos > posCurrStart2) && (newVals[MAX_IDX].pos < posCurrEnd2)) {
            cntrGet--;
            arr[newVals[MAX_IDX].pos] = valToGet[cntrGet];
        }

        if ((newVals[MAX2_IDX].pos > posCurrStart2) && (newVals[MAX2_IDX].pos < posCurrEnd2)) {
            cntrGet--;
            arr[newVals[MAX2_IDX].pos] = valToGet[cntrGet];
        }

        if ((newVals[MIN2_IDX].pos > posCurrStart2) && (newVals[MIN2_IDX].pos < posCurrEnd2)) {
            cntrGet--;
            arr[newVals[MIN2_IDX].pos] = valToGet[cntrGet];
        }

        if ((newVals[MIN_IDX].pos > posCurrStart2) && (newVals[MIN_IDX].pos < posCurrEnd2)) {
            cntrGet--;
            arr[newVals[MIN_IDX].pos] = valToGet[cntrGet];
        }

        arr[posCurrStart] = newVals[MIN_IDX].val;
        arr[posCurrStart2] = newVals[MIN2_IDX].val;
        arr[posCurrEnd2] = newVals[MAX2_IDX].val;
        arr[posCurrEnd] = newVals[MAX_IDX].val;

        if (4 < (posCurrEnd - posCurrStart)) {
            posCurrStart += 2;
            posCurrEnd -= 2;
        }
        else {
            finished = true;
            break;
        }
    }
}


template void RusevUltraBasedOn4Rusev<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);
template void RusevUltraBasedOn4RusevV2<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);
template void RusevUltraBasedOn4_V3_integral<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);
