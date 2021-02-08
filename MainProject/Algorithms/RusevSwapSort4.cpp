/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file RusevSwapSort4.cpp
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

#define DEBUG_PRINTS_OFF
#ifdef DEBUG_PRINTS_ON
#define pout cout
#else
#define pout 0 && cout
#endif


#define DEBUG_PRINTS_IMPR_OFF
#ifdef DEBUG_PRINTS_IMPR_ON
#define pIout cout
#else
#define pIout 0 && cout
#endif

typedef struct ValuePos_s {
    unsigned long long pos;
    int val;
}ValuePos_t;

#define LIMITER 4

#define MIN_IDX 0
#define MIN2_IDX 1
#define MAX2_IDX 2
#define MAX_IDX 3

#define IDX_0 0
#define IDX_1 1
#define IDX_2 2
#define IDX_3 3

inline void swapUintNumbers(unsigned int& a, unsigned int& b) {
    unsigned int temp = a;
    a = b;
    b = temp;
};

inline void swapUllNumbers(unsigned long long& a, unsigned long long& b) {
    unsigned long long temp = a;
    a = b;
    b = temp;
};

inline void swapIntNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
};

void RusevSwapSort4(int arr[], unsigned int size) {
    bool finished = false;

    int temp0, tempStart, tempStart2, tempEnd2, tempEnd;
    unsigned int i, posCurrStart = 0, posCurrEnd = size - 1;

    ValuePos_t newVals[LIMITER];
    int valToGet[LIMITER] = {};
    unsigned int cntrGet = 0;

    unsigned int posCurrStart2 = posCurrStart+1, posCurrEnd2 = posCurrEnd-1;

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

        totalPositionsToWrite = 0;

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
                if (currVal > newVals[MAX2_IDX].val ) {
                    newVals[MAX2_IDX].val = currVal;
                    newVals[MAX2_IDX].pos = i;
                }
            }
        }

        if (newVals[MAX2_IDX].val > newVals[MAX_IDX].val){
            swapIntNumbers(newVals[MAX2_IDX].val, newVals[MAX_IDX].val);
            swapUllNumbers(newVals[MAX2_IDX].pos, newVals[MAX_IDX].pos);
        };

        if (newVals[MIN_IDX].val > newVals[MIN2_IDX].val){
            swapIntNumbers(newVals[MIN_IDX].val, newVals[MIN2_IDX].val);
            swapUllNumbers(newVals[MIN_IDX].pos, newVals[MIN2_IDX].pos);
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
        if ((newVals[MAX_IDX].pos > posCurrStart2) && (newVals[MAX_IDX].pos < posCurrEnd2)){
            cntrGet--;
            arr[newVals[MAX_IDX].pos] = valToGet[cntrGet];
        }

        if ((newVals[MAX2_IDX].pos > posCurrStart2) && (newVals[MAX2_IDX].pos < posCurrEnd2)){
            cntrGet--;
            arr[newVals[MAX2_IDX].pos] = valToGet[cntrGet];
        }

        if ((newVals[MIN2_IDX].pos> posCurrStart2) && (newVals[MIN2_IDX].pos < posCurrEnd2)){
            cntrGet--;
            arr[newVals[MIN2_IDX].pos] = valToGet[cntrGet];
        }

        if ((newVals[MIN_IDX].pos > posCurrStart2) && (newVals[MIN_IDX].pos < posCurrEnd2)){
            cntrGet--;
            arr[newVals[MIN_IDX].pos] = valToGet[cntrGet];
        }

        arr[posCurrStart] = newVals[MIN_IDX].val;
        arr[posCurrStart2] = newVals[MIN2_IDX].val;
        arr[posCurrEnd2] = newVals[MAX2_IDX].val;
        arr[posCurrEnd] = newVals[MAX_IDX].val;

        if (4 < (posCurrEnd - posCurrStart)) {
            posCurrStart+=2;
            posCurrEnd-=2;
        }
        else {
            finished = true;
            break;
        }
    }
}

void RusevSwapSort4fullWithCheckAndVolatile(int arr[], unsigned int size) {
    bool finished = false;
    
    int temp0, tempStart, tempStart2, tempEnd2, tempEnd;
    unsigned int i, posCurrStart = 0, posCurrEnd = size - 1;

    ValuePos_t newVals[LIMITER];
    int valToGet[LIMITER] = {};
    unsigned int cntrGet = 0;

    unsigned int posCurrStart2 = posCurrStart+1, posCurrEnd2 = posCurrEnd-1;    

    unsigned int totalPositionsToWrite = 0;

    volatile int currVal;
    
    //------------------------------------------------------------------------------------------
    //--          Check for whether the array is really shuffled      --------------------------
    //------------------------------------------------------------------------------------------
    // We have arr[], unsigned int size. Super fast check - only goes on if the array is really

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
    //------------------------------------------------------------------------------------------

    if (notSorted) {
        if (notRevSorted) {

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

                totalPositionsToWrite = 0;

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
                        if (currVal > newVals[MAX2_IDX].val ) { 
                            newVals[MAX2_IDX].val = currVal;
                            newVals[MAX2_IDX].pos = i;
                        }
                    }
                }

                if (newVals[MAX2_IDX].val > newVals[MAX_IDX].val){
                    swapIntNumbers(newVals[MAX2_IDX].val, newVals[MAX_IDX].val);
                    swapUllNumbers(newVals[MAX2_IDX].pos, newVals[MAX_IDX].pos);
                };

                if (newVals[MIN_IDX].val > newVals[MIN2_IDX].val){
                    swapIntNumbers(newVals[MIN_IDX].val, newVals[MIN2_IDX].val);
                    swapUllNumbers(newVals[MIN_IDX].pos, newVals[MIN2_IDX].pos);
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
                if ((newVals[MAX_IDX].pos > posCurrStart2) && (newVals[MAX_IDX].pos < posCurrEnd2)){
                    cntrGet--;
                    arr[newVals[MAX_IDX].pos] = valToGet[cntrGet];
                }

                if ((newVals[MAX2_IDX].pos > posCurrStart2) && (newVals[MAX2_IDX].pos < posCurrEnd2)){
                    cntrGet--;
                    arr[newVals[MAX2_IDX].pos] = valToGet[cntrGet];
                }

                if ((newVals[MIN2_IDX].pos> posCurrStart2) && (newVals[MIN2_IDX].pos < posCurrEnd2)){
                    cntrGet--;
                    arr[newVals[MIN2_IDX].pos] = valToGet[cntrGet];
                }

                if ((newVals[MIN_IDX].pos > posCurrStart2) && (newVals[MIN_IDX].pos < posCurrEnd2)){
                    cntrGet--;
                    arr[newVals[MIN_IDX].pos] = valToGet[cntrGet];
                }

                arr[posCurrStart] = newVals[MIN_IDX].val;
                arr[posCurrStart2] = newVals[MIN2_IDX].val;
                arr[posCurrEnd2] = newVals[MAX2_IDX].val;
                arr[posCurrEnd] = newVals[MAX_IDX].val;
                
                if (4 < (posCurrEnd - posCurrStart)) {
                    posCurrStart+=2;
                    posCurrEnd-=2;
                }
                else {
                    finished = true;
                    break;
                }
            }

        }
        else {
            //-----------------------------------------------
            // do the reversing!

            for (i = 0; i < size / 2; i++) {
                temp0 = arr[i];
                arr[i] = arr[size - i - 1];
                arr[size - i - 1] = temp0;
            }
        }
    }
    else {
        //---------------------------------------
        // Do nothing - the array is sorted !
    }
}


void RusevSwapSort4fullWithCheck(int arr[], unsigned int size) {
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
    //--          Check for whether the array is really shuffled      --------------------------
    //------------------------------------------------------------------------------------------
    // We have arr[], unsigned int size. Super fast check - only goes on if the array is really

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
    //------------------------------------------------------------------------------------------

    if (notSorted) {
        if (notRevSorted) {

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

                totalPositionsToWrite = 0;

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
                    swapIntNumbers(newVals[MAX2_IDX].val, newVals[MAX_IDX].val);
                    swapUllNumbers(newVals[MAX2_IDX].pos, newVals[MAX_IDX].pos);
                };

                if (newVals[MIN_IDX].val > newVals[MIN2_IDX].val) {
                    swapIntNumbers(newVals[MIN_IDX].val, newVals[MIN2_IDX].val);
                    swapUllNumbers(newVals[MIN_IDX].pos, newVals[MIN2_IDX].pos);
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
        else {
            //-----------------------------------------------
            // do the reversing!

            for (i = 0; i < size / 2; i++) {
                temp0 = arr[i];
                arr[i] = arr[size - i - 1];
                arr[size - i - 1] = temp0;
            }
        }
    }
    else {
        //---------------------------------------
        // Do nothing - the array is sorted !
    }
}
