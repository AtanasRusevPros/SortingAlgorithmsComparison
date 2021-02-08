/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file RusevMergeSort32.cpp
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
#include "RusevSwapSort4.h"
#include "RusevSwapSort2.h"


#define ADDITIONAL_DEBUG_OFF
#ifdef ADDITIONAL_DEBUG_ON
#define adDbg cout
#define printArrayAdDbg printArray
#else 
#define adDbg 0 && cout
#define printArrayAdDbg(a,b) 
#endif

// this is with DYNAMIC ALLOCATION OF STACKS
template <const int T>
inline void RusevMergeSortBasedOn2(int arr[], unsigned int size) {

    unsigned int i, cntr1, cntr2;

    unsigned int partsCntr, temp;

    int tempInt;

    partDescriptorOpt_t* stk1, * stk2;

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

            stk1 = new partDescriptorOpt_t[partsCntr + 1];
            stk2 = new partDescriptorOpt_t[partsCntr + 1];

            cntr1 = 0;
            cntr2 = 0;

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                RusevSwapSort2ImprIdx((arr + i * T), T);
                stk1[cntr1].start = (arr + i * T);
                stk1[cntr1].size = T;
                cntr1++;
            }

            temp = size % T;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                RusevSwapSort2ImprIdx((arr + i * T), temp);
                stk1[cntr1].start = (arr + i * T + T + 1);
                stk1[cntr1].size = temp;
                cntr1++;
            }

            //now merging all pieces:
            while (1) {
                if (cntr1 > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < cntr1 - 1; i += 2) {
                        merge_Rusev(stk1[i].start, stk1[i].size, stk1[i + 1].size);
                        stk2[cntr2].start = stk1[i].start;
                        stk2[cntr2].size = stk1[i].size + stk1[i + 1].size;
                        cntr2++;
                    }

                    // if there is one more piece left - just take it over:
                    if (cntr1 - i) {
                        stk2[cntr2].start = stk1[i].start;
                        stk2[cntr2].size = stk1[i].size;
                        cntr2++;
                    }
                    cntr1 = 0;
                }
                else {
                    break;
                }

                if (cntr2 > 1) {
                    // merge all in second array, send to first array
                    for (i = 0; i < cntr2 - 1; i += 2) {
                        merge_Rusev(stk2[i].start, stk2[i].size, stk2[i + 1].size);
                        stk1[cntr1].start = stk2[i].start;
                        stk1[cntr1].size = stk2[i].size + stk2[i + 1].size;
                        cntr1++;
                    }

                    // if there is one more piece left - just take it over:
                    if (cntr2 - i) {
                        stk1[cntr1].start = stk2[i].start;
                        stk1[cntr1].size = stk2[i].size;
                        cntr1++;
                    }
                    cntr2 = 0;
                }
                else {
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

// this is with DYNAMIC ALLOCATION OF STACKS
template <const int T>
inline void RusevMergeSortBasedOn2_3rd_merge_improve(int arr[], unsigned int size) {

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
                RusevSwapSort2ImprIdx((arr + i * T), T);            

            temp = size % T;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) 
                RusevSwapSort2ImprIdx((arr + i * T), temp);            

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
inline void RusevMergeSortBasedOn4_3rd_merge_improve(int arr[], unsigned int size) {

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
                RusevSwapSort4((arr + i * T), T);

            temp = size % T;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp)
                RusevSwapSort2ImprIdx((arr + i * T), temp);

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

template <const int T>
inline void RusevMergeSortBasedOn4_2(int arr[], unsigned int size) {

    unsigned int i, cntr1, cntr2;

    unsigned int partsCntr, temp;

    int tempInt;

    partDescriptorOpt_t* stk1, * stk2;

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

            stk1 = new partDescriptorOpt_t[partsCntr + 1];
            stk2 = new partDescriptorOpt_t[partsCntr + 1];

            cntr1 = 0;
            cntr2 = 0;

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                RusevSwapSort4((arr + i * T), T);
                stk1[cntr1].start = (arr + i * T);
                stk1[cntr1].size = T;
                cntr1++;
            }

            temp = size % T;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                RusevSwapSort2ImprIdx((arr + i * T), temp);
                stk1[cntr1].start = (arr + i * T + T + 1);
                stk1[cntr1].size = temp;
                cntr1++;
            }

            //now merging all pieces:
            while (1) {
                if (cntr1 > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < cntr1 - 1; i += 2) {
                        merge_Rusev(stk1[i].start, stk1[i].size, stk1[i + 1].size);
                        stk2[cntr2].start = stk1[i].start;
                        stk2[cntr2].size = stk1[i].size + stk1[i + 1].size;
                        cntr2++;
                    }

                    // if there is one more piece left - just take it over:
                    if (cntr1 - i) {
                        stk2[cntr2].start = stk1[i].start;
                        stk2[cntr2].size = stk1[i].size;
                        cntr2++;
                    }
                    cntr1 = 0;
                }
                else {
                    break;
                }

                if (cntr2 > 1) {
                    // merge all in second array, send to first array
                    for (i = 0; i < cntr2 - 1; i += 2) {
                        merge_Rusev(stk2[i].start, stk2[i].size, stk2[i + 1].size);
                        stk1[cntr1].start = stk2[i].start;
                        stk1[cntr1].size = stk2[i].size + stk2[i + 1].size;
                        cntr1++;
                    }

                    // if there is one more piece left - just take it over:
                    if (cntr2 - i) {
                        stk1[cntr1].start = stk2[i].start;
                        stk1[cntr1].size = stk2[i].size;
                        cntr1++;
                    }
                    cntr2 = 0;
                }
                else {
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



template void RusevMergeSortBasedOn2_3rd_merge_improve<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);
template void RusevMergeSortBasedOn4_3rd_merge_improve<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);

template void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);
template void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);

template void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_64>(int arr[], unsigned int size);
template void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_64>(int arr[], unsigned int size);

template void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_128>(int arr[], unsigned int size);
template void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_128>(int arr[], unsigned int size);

template void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_256>(int arr[], unsigned int size);
template void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_256>(int arr[], unsigned int size);

template void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_512>(int arr[], unsigned int size);
template void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_512>(int arr[], unsigned int size);

template void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_1024>(int arr[], unsigned int size);
template void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_1024>(int arr[], unsigned int size);

template void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_2048>(int arr[], unsigned int size);
template void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_2048>(int arr[], unsigned int size);


//  OLD CODE TO CHECK !!!

mergePartsStack_t stk1;
mergePartsStack_t stk2;

// this is with STATIC STACKS
void RusevMergeSortBasedOn2_32StaticStacksNoOpt(int arr[], unsigned int size) {

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

            partsCntr = (size / SINGLE_PIECE_SIZE_32);

            stk1.cntr = 0;
            stk2.cntr = 0;

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                RusevSwapSort2ImprIdx((arr + i * SINGLE_PIECE_SIZE_32), SINGLE_PIECE_SIZE_32);
                stk1.pieces[stk1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32);
                stk1.pieces[stk1.cntr].end = (arr + i * SINGLE_PIECE_SIZE_32 + SINGLE_PIECE_SIZE_32);
                stk1.pieces[stk1.cntr].size = SINGLE_PIECE_SIZE_32;
                stk1.cntr++;
            }

            temp = size % SINGLE_PIECE_SIZE_32;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                RusevSwapSort2ImprIdx((arr + i * SINGLE_PIECE_SIZE_32), temp);
                stk1.pieces[stk1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32 + SINGLE_PIECE_SIZE_32 + 1);
                stk1.pieces[stk1.cntr].end = (arr + i * SINGLE_PIECE_SIZE_32 + SINGLE_PIECE_SIZE_32 + 1 + temp);
                stk1.pieces[stk1.cntr].size = temp;
                stk1.cntr++;
                partsCntr += 1;
            }


            //now merging all pieces:
            while (1) {
                if (stk1.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < stk1.cntr - 1; i += 2) {
                        merge_Rusev(stk1.pieces[i].start, stk1.pieces[i].size, stk1.pieces[i + 1].size);
                        stk2.pieces[stk2.cntr].start = stk1.pieces[i].start;
                        stk2.pieces[stk2.cntr].end = stk1.pieces[i + 1].end;
                        stk2.pieces[stk2.cntr].size = stk1.pieces[i].size + stk1.pieces[i + 1].size;
                        stk2.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (stk1.cntr - i) {
                        stk2.pieces[stk2.cntr].start = stk1.pieces[i].start;
                        stk2.pieces[stk2.cntr].end = stk1.pieces[i].end;
                        stk2.pieces[stk2.cntr].size = stk1.pieces[i].size;
                        stk2.cntr++;
                    }
                    stk1.cntr = 0;
                }
                else {
                    break;
                }

                if (stk2.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < stk2.cntr - 1; i += 2) {

                        merge_Rusev(stk2.pieces[i].start, stk2.pieces[i].size, stk2.pieces[i + 1].size);
                        stk1.pieces[stk1.cntr].start = stk2.pieces[i].start;
                        stk1.pieces[stk1.cntr].end = stk2.pieces[i + 1].end;
                        stk1.pieces[stk1.cntr].size = stk2.pieces[i].size + stk2.pieces[i + 1].size;
                        stk1.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (stk2.cntr - i) {
                        stk1.pieces[stk1.cntr].start = stk2.pieces[i].start;
                        stk1.pieces[stk1.cntr].end = stk2.pieces[i].end;
                        stk1.pieces[stk1.cntr].size = stk2.pieces[i].size;
                        stk1.cntr++;
                    }
                    stk2.cntr = 0;
                }
                else {
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

mergePartsStackOpt_t stkOpt1, stkOpt2;

void RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED(int arr[], unsigned int size) {

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
            partsCntr = (size / SINGLE_PIECE_SIZE_32);

            stkOpt1.cntr = 0;
            stkOpt2.cntr = 0;

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                RusevSwapSort2ImprIdx((arr + i * SINGLE_PIECE_SIZE_32), SINGLE_PIECE_SIZE_32);
                stkOpt1.pieces[stkOpt1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32);
                stkOpt1.pieces[stkOpt1.cntr].size = SINGLE_PIECE_SIZE_32;
                stkOpt1.cntr++;
            }

            temp = size % SINGLE_PIECE_SIZE_32;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                RusevSwapSort2ImprIdx((arr + i * SINGLE_PIECE_SIZE_32), temp);
                stkOpt1.pieces[stkOpt1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32 + SINGLE_PIECE_SIZE_32 + 1);
                stkOpt1.pieces[stkOpt1.cntr].size = temp;
                stkOpt1.cntr++;
            }


            //now merging all pieces:
            while (1) {
                if (stkOpt1.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < stkOpt1.cntr - 1; i += 2) {
                        merge_Rusev(stkOpt1.pieces[i].start, stkOpt1.pieces[i].size, stkOpt1.pieces[i + 1].size);
                        stkOpt2.pieces[stkOpt2.cntr].start = stkOpt1.pieces[i].start;
                        stkOpt2.pieces[stkOpt2.cntr].size = stkOpt1.pieces[i].size + stkOpt1.pieces[i + 1].size;
                        stkOpt2.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (stkOpt1.cntr - i) {
                        stkOpt2.pieces[stkOpt2.cntr].start = stkOpt1.pieces[i].start;
                        stkOpt2.pieces[stkOpt2.cntr].size = stkOpt1.pieces[i].size;
                        stkOpt2.cntr++;
                    }
                    stkOpt1.cntr = 0;
                }
                else {
                    break;
                }

                if (stkOpt2.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < stkOpt2.cntr - 1; i += 2) {
                        merge_Rusev(stkOpt2.pieces[i].start, stkOpt2.pieces[i].size, stkOpt2.pieces[i + 1].size);
                        stkOpt1.pieces[stkOpt1.cntr].start = stkOpt2.pieces[i].start;
                        stkOpt1.pieces[stkOpt1.cntr].size = stkOpt2.pieces[i].size + stkOpt2.pieces[i + 1].size;
                        stkOpt1.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (stkOpt2.cntr - i) {
                        stkOpt1.pieces[stkOpt1.cntr].start = stkOpt2.pieces[i].start;
                        stkOpt1.pieces[stkOpt1.cntr].size = stkOpt2.pieces[i].size;
                        stkOpt1.cntr++;
                    }
                    stkOpt2.cntr = 0;
                }
                else {
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

void RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED_Dyn(int arr[], unsigned int size) {

    unsigned int i;

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
            unsigned int partsCntr, temp;

            partsCntr = (size / SINGLE_PIECE_SIZE_32);

            partDescriptorOpt_t *pieces1 = new partDescriptorOpt_t[partsCntr+1];
            partDescriptorOpt_t *pieces2 = new partDescriptorOpt_t[partsCntr+1];
            unsigned int cntr1 = 0, cntr2 = 0;


            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                RusevSwapSort2((arr + i * SINGLE_PIECE_SIZE_32), SINGLE_PIECE_SIZE_32);
                pieces1[cntr1].start = (arr + i * SINGLE_PIECE_SIZE_32);
                pieces1[cntr1].size = SINGLE_PIECE_SIZE_32;
                cntr1++;
            }

            temp = size % SINGLE_PIECE_SIZE_32;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                RusevSwapSort2ImprIdx((arr + i * SINGLE_PIECE_SIZE_32), temp);
                pieces1[cntr1].start = (arr + i * SINGLE_PIECE_SIZE_32 + SINGLE_PIECE_SIZE_32 + 1);
                pieces1[cntr1].size = temp;
                cntr1++;
            }


            //now merging all pieces:
            while (1) {
                if (cntr1 > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < cntr1 - 1; i += 2) {
                        // mergeTwoPieces(pieces1[i].start, pieces1[i].size, pieces1[i + 1].start, pieces1[i + 1].size);                        
                        merge_Rusev(pieces1[i].start, pieces1[i].size, pieces1[i + 1].size);
                        pieces2[cntr2].start = pieces1[i].start;
                        pieces2[cntr2].size = pieces1[i].size + pieces1[i + 1].size;
                        cntr2++;
                    }

                    // if there is one more piece left - just take it over:
                    if (cntr1 - i) {
                        pieces2[cntr2].start = pieces1[i].start;
                        pieces2[cntr2].size = pieces1[i].size;
                        cntr2++;
                    }
                    cntr1 = 0;
                }
                else {
                    break;
                }

                if (cntr2 > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < cntr2 - 1; i += 2) {
                        //mergeTwoPieces(pieces2[i].start, pieces2[i].size, pieces2[i + 1].start, pieces2[i + 1].size);

                        merge_Rusev(pieces2[i].start, pieces2[i].size, pieces2[i + 1].size);

                        pieces1[cntr1].start = pieces2[i].start;
                        pieces1[cntr1].size = pieces2[i].size + pieces2[i + 1].size;
                        cntr1++;
                    }

                    // if there is one more piece left - just take it over:
                    if (cntr2 - i) {
                        pieces1[cntr1].start = pieces2[i].start;
                        pieces1[cntr1].size = pieces2[i].size;
                        cntr1++;
                    }
                    cntr2 = 0;
                }
                else {
                    break;
                }
            }
            delete[]pieces1;
            delete[]pieces2;
        }
        else {
            //-----------------------------------------------
            // do the reversing!

            int tempInt;

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

