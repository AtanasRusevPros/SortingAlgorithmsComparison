/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file RusevSwapSort2.cpp
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
#include <cstring>
#include <climits>

#include "../Tools/AlgorithmSupport.h"

void RusevSwapSort2(int arr[], unsigned int size) {
    bool finished = false;

    // these are the smallest and the biggest numbers
    int currMin = INT_MAX, currMax = INT_MIN, temp, temp2;
    unsigned int i, posCurrMin = 0, posCurrMax = 0, posCurrStart = 0, posCurrEnd = size - 1;

    // main cycle
    while (!finished) {
        
        // iterating through numbers
        for (i = posCurrStart; i <= posCurrEnd; i++) {
            
            // finding the smallest number - get next smallest only if it is really smaller. Thus if we have smallest in the beginning we will not require swap.
            if (arr[i] < currMin) {
                currMin = arr[i];
                posCurrMin = i;
            }

            // finding the biggest number. Get even if it is equal. Thus if the biggest number is at the end - we will do no swap.
            if (arr[i] >= currMax) {
                currMax = arr[i];
                posCurrMax = i;
            }
        }

        // cases:
        // 1. do nothing - when biggest and samllest are at ends
        // 2. swap ends
        // 3. 3 nums, collide at end
        // 4. 3 nums collide at start
        // 5. double 2 swaps
        // 6. Swap only min with start
        // 7. Swap only max with end

        // Improved performance of our cases:

        if (posCurrMin == posCurrEnd) {

            if (posCurrMax == posCurrStart) {
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

        // how to fix issue with 3 numbers left
        /**
          First of all - if we work with even number of inputs - then it is easy.
          If the number is not even - then we might have an issue.
          Later making a version for fixed amount of inputs might be helpful, but it is not sure.
          We have a problem only when having odd inputs.
          What is interesting - when we have 3 numbers left - we will automatically select the correct maximum and minimum.

          So simply lifting the limit shall help!
          */

        if (2 < (posCurrEnd - posCurrStart)) {
            posCurrStart++;
            posCurrEnd--;
            currMin = INT_MAX;
            currMax = INT_MIN;
        }
        else {
            finished = true;
            break;
        }
    }
}

void RusevSwapSort2ImprIdx(int arr[], unsigned int size) {
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

void RusevSwapSort2withCheck(int arr[], unsigned int size) {
    bool finished = false;

    // these are the smallest and the biggest numbers
    int currMin = INT_MAX, currMax = INT_MIN, tempInt, tempInt2;
    unsigned int i, posCurrMin = 0, posCurrMax = 0, posCurrStart = 0, posCurrEnd = size - 1;


    //------------------------------------------------------------------------------------------
    //--          Check for whether the array is really shuffled      --------------------------
    //------------------------------------------------------------------------------------------
    // We have arr[], unsigned int size

    bool notSorted = false, notRevSorted = false;
    for (i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1])
            notSorted = true;

        if (arr[i] > arr[i - 1])
            notRevSorted = true;

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
                
                // iterating through numbers
                for (i = posCurrStart; i <= posCurrEnd; i++) {

                    // finding the smallest number - get next smallest only if it is really smaller. Thus if we have smallest in the beginning we will not require swap.
                    if (arr[i] < currMin) {
                        currMin = arr[i];
                        posCurrMin = i;
                    }

                    // finding the biggest number. Get even if it is equal. Thus if the biggest number is at the end - we will do no swap.
                    if (arr[i] >= currMax) {
                        currMax = arr[i];
                        posCurrMax = i;
                    }
                }

                // cases:
                // 1. do nothing - when biggest and samllest are at ends
                // 2. swap ends
                // 3. 3 nums, collide at end
                // 4. 3 nums collide at start
                // 5. double 2 swaps
                // 6. Swap only min with start
                // 7. Swap only max with end

                // Improved performance of our cases:

                if (posCurrMin == posCurrEnd) {

                    if (posCurrMax == posCurrStart) {
                        arr[posCurrStart] = currMin;
                        arr[posCurrEnd] = currMax;

                    }
                    else { // means posCurrMax == somwhere in the middle
                     // 3. 3 nums, collide at end
                        tempInt = arr[posCurrStart];
                        arr[posCurrStart] = currMin;
                        arr[posCurrEnd] = currMax;
                        arr[posCurrMax] = tempInt;
                    }

                }
                else {
                    if (posCurrMin == posCurrStart) {

                        if (posCurrMax == posCurrEnd) {
                            // 1. Do nothing - everything in correct place

                        }
                        else { // means posCurrMax == somwhere in the middle
                            // 7. Swap only max with end
                            tempInt = arr[posCurrEnd];
                            arr[posCurrMax] = tempInt;
                            arr[posCurrEnd] = currMax;
                        }

                    }
                    else { // this means we are somwhere in the middle for the current minimal value!

                        if (posCurrMax == posCurrEnd) {
                            // 6. Swap only min with start
                            tempInt = arr[posCurrStart];
                            arr[posCurrMin] = tempInt;
                            arr[posCurrStart] = currMin;

                        }
                        else { // means posCurrMax == somwhere in the middle

                            if (posCurrMax == posCurrStart) {
                                // 4. 3 nums, collide at start
                                tempInt = arr[posCurrEnd];
                                arr[posCurrStart] = currMin;
                                arr[posCurrEnd] = currMax;
                                arr[posCurrMin] = tempInt;

                            }
                            else { // means posCurrMax == somwhere in the middle
                             // 5. double 2 swaps
                                tempInt = arr[posCurrEnd];
                                tempInt2 = arr[posCurrStart];

                                arr[posCurrMax] = tempInt;
                                arr[posCurrMin] = tempInt2;

                                arr[posCurrStart] = currMin;
                                arr[posCurrEnd] = currMax;
                            }
                        }
                    }
                }

                // how to fix issue with 3 numbers left
                /**
                  First of all - if we work with even number of inputs - then it is easy.
                  If the number is not even - then we might have an issue.
                  Later making a version for fixed amount of inputs might be helpful, but it is not sure.
                  We have a problem only when having odd inputs.
                  What is interesting - when we have 3 numbers left - we will automatically select the correct maximum and minimum.

                  So simply lifting the limit shall help!
                  */

                if (2 < (posCurrEnd - posCurrStart)) {
                    posCurrStart++;
                    posCurrEnd--;
                    currMin = INT_MAX;
                    currMax = INT_MIN;
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

void RusevSwapSort2withCheckImprIdx(int arr[], unsigned int size) {
    bool finished = false;
    
    // these are the smallest and the biggest numbers
    int currMin, currMax, tempInt, tempInt2;
    unsigned int i, posCurrMin = 0, posCurrMax = 0, posCurrStart = 0, posCurrEnd = size - 1;

    //------------------------------------------------------------------------------------------
    //--          Check for whether the array is really shuffled      --------------------------
    //------------------------------------------------------------------------------------------
    // We have arr[], unsigned int size

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

                // cases:
                // 1. do nothing - when biggest and samllest are at ends
                // 2. swap ends
                // 3. 3 nums, collide at end
                // 4. 3 nums collide at start
                // 5. double 2 swaps
                // 6. Swap only min with start
                // 7. Swap only max with end

                // Improved performance of our cases:

                if (posCurrMin == posCurrEnd) {

                    if (posCurrMax == posCurrStart) {
                        // 2. swap ends
                        arr[posCurrStart] = currMin;
                        arr[posCurrEnd] = currMax;

                    }
                    else { // means posCurrMax == somwhere in the middle
                     // 3. 3 nums, collide at end
                        tempInt = arr[posCurrStart];
                        arr[posCurrStart] = currMin;
                        arr[posCurrEnd] = currMax;
                        arr[posCurrMax] = tempInt;
                    }

                }
                else {
                    if (posCurrMin == posCurrStart) {

                        if (posCurrMax == posCurrEnd) {
                            // 1. Do nothing - everything in correct place

                        }
                        else { // means posCurrMax == somwhere in the middle
                            // 7. Swap only max with end
                            tempInt = arr[posCurrEnd];
                            arr[posCurrMax] = tempInt;
                            arr[posCurrEnd] = currMax;
                        }

                    }
                    else { // this means we are somwhere in the middle for the current minimal value!

                        if (posCurrMax == posCurrEnd) {
                            // 6. Swap only min with start
                            tempInt = arr[posCurrStart];
                            arr[posCurrMin] = tempInt;
                            arr[posCurrStart] = currMin;

                        }
                        else { // means posCurrMax == somwhere in the middle

                            if (posCurrMax == posCurrStart) {
                                // 4. 3 nums, collide at start
                                tempInt = arr[posCurrEnd];
                                arr[posCurrStart] = currMin;
                                arr[posCurrEnd] = currMax;
                                arr[posCurrMin] = tempInt;

                            }
                            else { // means posCurrMax == somwhere in the middle
                             // 5. double 2 swaps
                                tempInt = arr[posCurrEnd];
                                tempInt2 = arr[posCurrStart];

                                arr[posCurrMax] = tempInt;
                                arr[posCurrMin] = tempInt2;

                                arr[posCurrStart] = currMin;
                                arr[posCurrEnd] = currMax;
                            }
                        }
                    }
                }

                // how to fix issue with 3 numbers left
                /**
                  First of all - if we work with even number of inputs - then it is easy.
                  If the number is not even - then we might have an issue.
                  Later making a version for fixed amount of inputs might be helpful, but it is not sure.
                  We have a problem only when having odd inputs.
                  What is interesting - when we have 3 numbers left - we will automatically select the correct maximum and minimum.

                  So simply lifting the limit shall help!
                  */

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

