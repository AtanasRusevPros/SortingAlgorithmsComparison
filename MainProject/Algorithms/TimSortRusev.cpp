/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file TimSort.cpp
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

using namespace std;
static const int ONE_CHUNK_SZ_32 = 32;

//------------------------------------------------------------------------------------------
//---------        Rusev Impl Insertion Sort :    ------------------------------------------
//------------------------------------------------------------------------------------------

// this function performs simple insertion sort
// it does NO checks, it shall be used only when you know that boundaries 
// of the input array would never be violated!
// This is the reason of defining it here and explicitly static.
// Inlining might help the code if the optimizer doesn't do it for you.
static inline void insertionInternSort_Rusev(int arr[], unsigned int left, unsigned int right)
{
    // arr, left , right

    unsigned int prevIdxCmp, i;
    int currValueToCompare;

    for (unsigned int currIdx = left + 1; currIdx <= right; currIdx++)
    {
        currValueToCompare = arr[currIdx];
        prevIdxCmp = currIdx;
                
        // check all previous numbers to find the right position
        while (prevIdxCmp > left)
        {
            if (currValueToCompare < arr[prevIdxCmp-1]) {
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
                arr[i] = arr[i-1];
            };
            arr[i] = currValueToCompare;
        }
    }
}


void timSort_Rusev(int* arr, unsigned int size)
{    
    for (unsigned int i = 0; i < size; i += ONE_CHUNK_SZ_32)
        insertionInternSort_Rusev(arr, i, min((i + 31), (size - 1)));

    // start merging from midSz ONE_CHUNK_SZ_32. It will merge
    // to form midSz 64, then 128, 256 and so on ....
    for (unsigned int midSz = ONE_CHUNK_SZ_32; midSz < size; midSz = 2 * midSz)
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
            merge_Rusev_3param(arr, left, mid, right);
        }
    }
}



void timSort_Rusev_With_Checks(int* arr, unsigned int size)
{
    // Sort individual subarrays of size ONE_CHUNK_SZ_32

    bool notSorted = false, notRevSorted = false;
    unsigned int i = 1;

    int tempInt;

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

            for (unsigned int i = 0; i < size; i += ONE_CHUNK_SZ_32)
                insertionInternSort_Rusev(arr, i, min((i + 31), (size - 1)));
            
            // start merging from midSz ONE_CHUNK_SZ_32. It will merge
            // to form midSz 64, then 128, 256 and so on ....
            for (unsigned int midSz = ONE_CHUNK_SZ_32; midSz < size; midSz = 2 * midSz)
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

                    // merge sub array arr[left.....mid] &
                    // arr[mid+1....right]
                    merge_Rusev_3param(arr, left, mid, right);
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

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------
//---------        TimSort with improved Merge :    ------------------------------------------
//------------------------------------------------------------------------------------------


void timSort_Rusev_With_Checks_imprMerge(int* arr, unsigned int size)
{
    bool notSorted = false, notRevSorted = false;
    unsigned int i = 1;

    int tempInt;

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

            for (unsigned int i = 0; i < size; i += ONE_CHUNK_SZ_32)
                insertionInternSort_Rusev(arr, i, min((i + 31), (size - 1)));

            int* leftAr = new int[size];
            int* rightAr = new int[size];
            // start merging from midSz ONE_CHUNK_SZ_32. It will merge
            // to form midSz 64, then 128, 256 and so on ....
            for (unsigned int midSz = ONE_CHUNK_SZ_32; midSz < size; midSz = 2 * midSz)
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

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------

mergePartsStackOpt_t TSG_mergeStk1, TSG_mergeStk2;

void timSort_Rusev_WithMerge(int* arr, unsigned int size){

    unsigned long i;

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
            partsCntr = (size / SINGLE_PIECE_SIZE_128);

            TSG_mergeStk1.cntr = 0;
            TSG_mergeStk2.cntr = 0;

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                timSort_Rusev((arr + i * (unsigned long)SINGLE_PIECE_SIZE_128), SINGLE_PIECE_SIZE_128);
                TSG_mergeStk1.pieces[TSG_mergeStk1.cntr].start = (arr + i * (unsigned long)SINGLE_PIECE_SIZE_128);
                TSG_mergeStk1.pieces[TSG_mergeStk1.cntr].size = SINGLE_PIECE_SIZE_128;
                TSG_mergeStk1.cntr++;
            }

            temp = size % SINGLE_PIECE_SIZE_128;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                timSort_Rusev((arr + i * (unsigned long)SINGLE_PIECE_SIZE_128), temp);
                TSG_mergeStk1.pieces[TSG_mergeStk1.cntr].start = (arr + i * (unsigned long)SINGLE_PIECE_SIZE_128 + SINGLE_PIECE_SIZE_128 + 1);
                TSG_mergeStk1.pieces[TSG_mergeStk1.cntr].size = temp;
                TSG_mergeStk1.cntr++;
            }


            //now merging all pieces:
            while (1) {
                if (TSG_mergeStk1.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < TSG_mergeStk1.cntr - 1; i += 2) {
                        merge_Rusev(TSG_mergeStk1.pieces[i].start, TSG_mergeStk1.pieces[i].size, TSG_mergeStk1.pieces[i + 1].size);
                        TSG_mergeStk2.pieces[TSG_mergeStk2.cntr].start = TSG_mergeStk1.pieces[i].start;
                        TSG_mergeStk2.pieces[TSG_mergeStk2.cntr].size = TSG_mergeStk1.pieces[i].size + TSG_mergeStk1.pieces[i + 1].size;
                        TSG_mergeStk2.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (TSG_mergeStk1.cntr - i) {
                        TSG_mergeStk2.pieces[TSG_mergeStk2.cntr].start = TSG_mergeStk1.pieces[i].start;
                        TSG_mergeStk2.pieces[TSG_mergeStk2.cntr].size = TSG_mergeStk1.pieces[i].size;
                        TSG_mergeStk2.cntr++;
                    }
                    TSG_mergeStk1.cntr = 0;
                }
                else {
                    break;
                }

                if (TSG_mergeStk2.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < TSG_mergeStk2.cntr - 1; i += 2) {
                        merge_Rusev(TSG_mergeStk2.pieces[i].start, TSG_mergeStk2.pieces[i].size, TSG_mergeStk2.pieces[i + 1].size);
                        TSG_mergeStk1.pieces[TSG_mergeStk1.cntr].start = TSG_mergeStk2.pieces[i].start;
                        TSG_mergeStk1.pieces[TSG_mergeStk1.cntr].size = TSG_mergeStk2.pieces[i].size + TSG_mergeStk2.pieces[i + 1].size;
                        TSG_mergeStk1.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (TSG_mergeStk2.cntr - i) {
                        TSG_mergeStk1.pieces[TSG_mergeStk1.cntr].start = TSG_mergeStk2.pieces[i].start;
                        TSG_mergeStk1.pieces[TSG_mergeStk1.cntr].size = TSG_mergeStk2.pieces[i].size;
                        TSG_mergeStk1.cntr++;
                    }
                    TSG_mergeStk2.cntr = 0;
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
