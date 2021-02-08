/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file QuickSort.cpp
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
using std::cout;
using std::endl;


#define DEBUG_PRINTS_OFF
#ifdef DEBUG_PRINTS_ON
#define pout cout
#else
#define pout 0 && cout
#endif

static inline void swapInl(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// This partition function is wrong !!!
// Now I need a new partition function - one which:
/* Takes a current array - moves the pivot to the correct place, putting all numbers smaller on the left, all numbers bigger on the right
* So the pivot is now at the correct place.
* Next - we call again the function with new range and pivot:
* We either have to choose the pivot in the middle, or at the end
* 
* Actually - I might have a problem, as working with recursive functions and already sorted arrays - we will end up with too many levels of recursion, putting the 
* algorithm at risk of stack overflow :)
* 
* Trying with the checked data - gain the same issue.
* 
* Actually choosing the pivot doesn't define where we go. But still the best is simply to use any pivot.... hmmm.... 
* 
* In any case I have to verify the algorithm!
* 
* It definitely looks wrong!!!
* 
* So - making the new partition: 
* 
* For single pivot what we will do: 
*   For each current number - if it is 
* 
*/ 
unsigned int partitionAndSortSingleClassic_Rusev(int* arr, unsigned int size) {
    unsigned int currPos = 0, pivotPos = size - 1;
    int temp;

    pout << "partitionAndSortSingleClassic_Rusev() \n";
    // printArray(arr, size);

    while (currPos < pivotPos - 1) {
        if (arr[currPos] > arr[pivotPos]) {
            pout << "Moving pivotPos " << pivotPos << " with value " << arr[pivotPos] << "; PrevNum " << arr[pivotPos -1] << " to currPos: " << currPos  << "\n \n ";
            temp = arr[pivotPos - 1];
            arr[pivotPos - 1] = arr[pivotPos];
            arr[pivotPos] = arr[currPos];
            arr[currPos] = temp;
            pivotPos--;
        }
        else {
            pout << "Just skipping and incrementing currPos as value is " << arr[currPos] << " currPos: " << currPos << endl;
            currPos++;
        }        

        // printArray(arr, size);
    }

    if (pivotPos == (currPos + 1)) {
        if (arr[currPos] > arr[pivotPos]) {
            temp = arr[pivotPos];
            arr[pivotPos] = arr[currPos];
            arr[currPos] = temp;
            pivotPos = currPos;
        }
    }
    pout << "partitionAndSortSingleClassic_Rusev() AFTER: pivot now : " << pivotPos << endl;
    // printArray(arr, size);

    return pivotPos;
}

/*
* Here comes a reduction of the swaps with the price of a bit more comparisons.
* What we do here - we move the pivot only and only when we find a next smaller number to move down on the position
* of the other bigger number which has to go on the right!
* 
* The tests showed that this version is only a bit faster than the original.
*/
int partitionAndSortSingleOptimized_Rusev(int* arr, unsigned int size) {

    pout << "partitionAndSortSingleOptimized_Rusev() \n";
    // printArray(arr, size);

    unsigned int currPos = 0, nextLeftNumPos, pivotPos = size - 1; ;
    int temp;
    while (currPos < pivotPos - 1) {
        if (arr[currPos] > arr[pivotPos]) {

            nextLeftNumPos = pivotPos - 1;
            while ((arr[nextLeftNumPos] > arr[pivotPos]) && (nextLeftNumPos > currPos)) { // here we pracitcally "jump" over all next numbers, bigger than the current pivot!
                nextLeftNumPos--;
            }
            pout << "Moving pivotPos " << pivotPos << " with value " << arr[pivotPos] << "; nextLeftNumPos " << nextLeftNumPos << " : VALUE: " <<  arr[nextLeftNumPos] << " to currPos: " << currPos << "\n \n ";

            if (nextLeftNumPos > currPos) {
                temp = arr[nextLeftNumPos];
                arr[nextLeftNumPos] = arr[pivotPos];
                arr[pivotPos] = arr[currPos];
                arr[currPos] = temp;
                pivotPos = nextLeftNumPos;
            } else { // otherwise they are equal, no other option
                temp = arr[currPos];
                arr[currPos] = arr[pivotPos];
                arr[pivotPos] = temp;
                pivotPos = nextLeftNumPos;
                break; // 
            }
        }
        else {
            pout << "Just skipping and incrementing currPos as value is " << arr[currPos] << " currPos: " << currPos << endl;
            currPos++;
        }
        // printArray(arr, size);
    }

    
    if (pivotPos == (currPos + 1)) {
        if (arr[currPos] > arr[pivotPos]) {
            temp = arr[pivotPos];
            arr[pivotPos] = arr[currPos];
            arr[currPos] = temp;
            pivotPos = currPos;
        }
    }

    // printArray(arr, size);

    return pivotPos;
}

void QuicksortSinglePivot(int* arr, unsigned int size) {
    pout << "-----------------------------\n New cyclic run \n -----------------------------\n ";
    if (size > 1)
    {
        int pivot;
        pivot = partitionAndSortSingleClassic_Rusev(arr, size);
        QuicksortSinglePivot(arr, pivot);
        QuicksortSinglePivot((int *)(arr + pivot + 1), size - pivot - 1);
    }
}


void QuicksortSinglePivotWithCheck(int* arr, unsigned int size) {
    int tempInt;
    unsigned int i = 0;
    //------------------------------------------------------------------------------------------
    //--          Check for whether the array is already sorted       --------------------------
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
            QuicksortSinglePivot(arr, size); 
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


void QuicksortSinglePivot_Optimized(int* arr, unsigned int size) {
    pout << "-----------------------------\n New cyclic run \n -----------------------------\n ";
    if (size > 1)
    {
        int pivot;
        pivot = partitionAndSortSingleOptimized_Rusev(arr, size);
        QuicksortSinglePivot_Optimized(arr, pivot);
        QuicksortSinglePivot_Optimized((int*)(arr + pivot + 1), size - pivot - 1);
    }
}


void QuicksortSinglePivot_RusevOptimized(int* arr, unsigned int size) {
    int tempInt;
    unsigned int i = 0;
    //------------------------------------------------------------------------------------------
    //--          Check for whether the array is already sorted       --------------------------
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
            QuicksortSinglePivot_Optimized(arr, size);
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

/*
* The function returns in lftPivot the new left Pivot, in the return statement - the new right Pivot
*/
int partitionAndSortDual_Rusev(int* arr, int leftPidx, int rightPidx, int *lftPivot) {

    pout << "************** Entering partitionAndSortDual_Rusev() with LeftPivot " << leftPidx << "   Right Pivot :"  << rightPidx << endl;
    

    if (arr[leftPidx] > arr[rightPidx]) {
        swapInl(&arr[leftPidx], &arr[rightPidx]);
        pout << " SWAPPED Ends \n";
    }
    

    
    int currPos = rightPidx - 1, midArrIdx = leftPidx;
    int initArrLeft = leftPidx, initArrSize = rightPidx - leftPidx+1;
    int temp;

    // printArray(&arr[initArrLeft], initArrSize);

    while (currPos > midArrIdx) {

        // this shall go on the right part
        if (arr[currPos] > arr[rightPidx]) {

            pout << "Increasing the Right part moving currPos " << currPos << " value " << arr[currPos] << " to idx RightPivot " << rightPidx << "\n \n ";

            swapInl(&arr[rightPidx], &arr[currPos]);
            rightPidx = currPos;
            currPos--;
        }
        else {
            // this shall go on the left part
            if (arr[currPos] < arr[leftPidx]) {
                pout << "Increasing the LEFT part moving currPos " << currPos << " value " << arr[currPos] << " to idx LeftPivot " << leftPidx << " midArrIdx now : " << midArrIdx+1  << " LEFT PIVOT : " << arr[leftPidx] << "\n \n ";

                swapInl(&arr[currPos], &arr[leftPidx]);
                swapInl(&arr[currPos], &arr[midArrIdx + 1]);
                swapInl(&arr[leftPidx + 1], &arr[midArrIdx + 1]);
                leftPidx++;
                midArrIdx++;
                
            }
            // this number shall remain in the middle
            else {
                pout << "INCREASING MIDDLE ARRAY leftPidx before: " << leftPidx << " with value " << arr[leftPidx] <<  "\n \n ";

                swapInl(&arr[currPos], &arr[midArrIdx+1]);                
                midArrIdx++;
            }
        }
        // printArray(&arr[initArrLeft], initArrSize);
    }

    /*
    if (pivotPos == (currPos + 1)) {
        if (arr[currPos] > arr[pivotPos]) {
            temp = arr[pivotPos];
            arr[pivotPos] = arr[currPos];
            arr[currPos] = temp;
            pivotPos = currPos;
        }
    }*/


    // Update final pivots:
    *lftPivot = leftPidx;

    pout << " PIVOTS NOW: Left Pivot  " << leftPidx << "  RIGHT Pivot: " << rightPidx << endl;
    return rightPidx;
}


/*
* The function returns in lftPivot the new left Pivot, in the return statement - the new right Pivot
*/

int partition1Optimized(int* arr, int left, int right, int* lftPivot)
{
    int temp;
    if (arr[left] > arr[right]) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    int j = left + 1;
    int nextRightPivot = right - 1, nextLeftPivot = left + 1, leftPivot = arr[left], rightPivot = arr[right];
    while (nextLeftPivot <= nextRightPivot)
    {

        // if elements are less than the left pivot
        if (arr[nextLeftPivot] < leftPivot)
        {
            temp = arr[j];
            arr[j] = arr[nextLeftPivot];
            arr[nextLeftPivot] = temp;
            j++;
        }

        // if elements are greater than or equal to the right pivot
        else if (arr[nextLeftPivot] >= rightPivot)
        {
            while (arr[nextRightPivot] > rightPivot && nextLeftPivot < nextRightPivot)
                nextRightPivot--;
            // swap
            temp = arr[nextRightPivot];
            arr[nextRightPivot] = arr[nextLeftPivot];
            arr[nextLeftPivot] = temp;
            
            nextRightPivot--;
            if (arr[nextLeftPivot] < leftPivot)
            {
                // swap
                temp = arr[j];
                arr[j] = arr[nextLeftPivot];
                arr[nextLeftPivot] = temp;
                j++;
            }
        }
        nextLeftPivot++;
    }
    j--;
    nextRightPivot++;

    // bring pivots to their appropriate positions.
    
    // swap
    temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    // swap
    temp = arr[nextRightPivot];
    arr[nextRightPivot] = arr[right];
    arr[right] = temp;

    // returning the indices of the pivots.
    *lftPivot = j;

    return nextRightPivot;
}


int partitionAndSortDualOptimized_Rusev(int* arr, int leftPidx, int rightPidx, int* lftPivot) {

    pout << "************** Entering partitionAndSortDualOptimized_Rusev() with LeftPivot " << leftPidx << "   Right Pivot :" << rightPidx << endl;
    int temp;

    if (arr[leftPidx] > arr[rightPidx]) {
        temp = arr[leftPidx];
        arr[rightPidx] = arr[leftPidx];
        arr[leftPidx] = temp;
        pout << " SWAPPED Ends \n";
    }



    int currPos = rightPidx - 1, midArrIdx = leftPidx;
    int initArrLeft = leftPidx, initArrSize = rightPidx - leftPidx + 1;
    

    // printArray(&arr[initArrLeft], initArrSize);

    while (currPos > midArrIdx) {

        // this shall go on the right part
        if (arr[currPos] > arr[rightPidx]) {

            pout << "Increasing the Right part moving currPos " << currPos << " value " << arr[currPos] << " to idx RightPivot " << rightPidx << "\n \n ";

            temp = arr[rightPidx];
            arr[rightPidx] = arr[currPos];
            arr[currPos] = temp;

            rightPidx = currPos;
            currPos--;
        }
        else {
            // this shall go on the left part
            if (arr[currPos] < arr[leftPidx]) {
                pout << "Increasing the LEFT part moving currPos " << currPos << " value " << arr[currPos] << " to idx LeftPivot " << leftPidx << " midArrIdx now : " << midArrIdx + 1 << " LEFT PIVOT : " << arr[leftPidx] << "\n \n ";

                temp = arr[leftPidx];
                arr[leftPidx] = arr[currPos];
                arr[currPos] = arr[midArrIdx + 1];
                arr[midArrIdx + 1] = arr[leftPidx + 1];
                arr[leftPidx + 1] = temp;

                leftPidx++;
                midArrIdx++;

            }
            // this number shall remain in the middle
            else {
                pout << "INCREASING MIDDLE ARRAY leftPidx before: " << leftPidx << " with value " << arr[leftPidx] << "\n \n ";

                temp = arr[currPos];
                arr[currPos] = arr[midArrIdx + 1];
                arr[midArrIdx + 1] = temp;
                
                midArrIdx++;
            }
        }
        // printArray(&arr[initArrLeft], initArrSize);
    }

    /*
    if (pivotPos == (currPos + 1)) {
        if (arr[currPos] > arr[pivotPos]) {
            temp = arr[pivotPos];
            arr[pivotPos] = arr[currPos];
            arr[currPos] = temp;
            pivotPos = currPos;
        }
    }*/


    // Update final pivots:
    * lftPivot = leftPidx;

    pout << " PIVOTS NOW: Left Pivot  " << leftPidx << "  RIGHT Pivot: " << rightPidx << endl;
    return rightPidx;
}

void QuickSortDualPivotBaseRusev(int* arr, int leftPidx, int rightPidx)
{
    pout << "  ------------------- MAIN QuickSortDualPivotBaseRusev ------------------------------------------------------------------------ \n";


    if (leftPidx < rightPidx + 1)
    {
        int lftPivot, rightPivot;
        rightPivot = partitionAndSortDualOptimized_Rusev(arr, leftPidx, rightPidx, &lftPivot);

        // calling recursively only if there is enough length in the given pieces
        if (leftPidx < lftPivot - 1) {
            pout << " Entering the sub-function with LEFT part leftPidx  " << leftPidx << "   Right p IDX  " << lftPivot - 1 << endl;
            QuickSortDualPivotBaseRusev(arr, leftPidx, lftPivot - 1);
        }

        if (lftPivot + 1 < rightPivot - 1){

            pout << " Entering the sub-function with MID part leftPidx  " << lftPivot + 1 << "   Right p IDX  " << rightPivot - 1 << endl;
            QuickSortDualPivotBaseRusev(arr, lftPivot + 1, rightPivot - 1);
        }

        if (rightPivot + 1 < rightPidx){

            pout << " Entering the sub-function with RIGHT part leftPidx  " << rightPivot + 1 << "   Right p IDX  " << rightPidx << endl;
            QuickSortDualPivotBaseRusev(arr, rightPivot + 1, rightPidx);
        }   
    }
}


void QuickSortDualPivotRusev(int* arr, unsigned int size) {

    QuickSortDualPivotBaseRusev(arr, 0, size - 1);

    pout << " EXIT func" << endl;
}


void QuickSortDualPivotRusev_WithCheck(int* arr, unsigned int size) {
    int tempInt;

    unsigned int i = 0;
    //------------------------------------------------------------------------------------------
    //--          Check for whether the array is already sorted       --------------------------
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
            QuickSortDualPivotBaseRusev(arr, 0, size - 1);
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



void QuickSortDualPivotRusevMerge(int * arr, unsigned int size) {

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

            mergePartsStackOpt_t QS_mergeStk1, QS_mergeStk2; // goes on stack! // todo fixme!!! Stack grows too big!

            partsCntr = (size / SINGLE_PIECE_SIZE_32);

            QS_mergeStk1.cntr = 0;
            QS_mergeStk2.cntr = 0;

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                QuickSortDualPivotRusev((arr + i * SINGLE_PIECE_SIZE_32), SINGLE_PIECE_SIZE_32);
                QS_mergeStk1.pieces[QS_mergeStk1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32);
                QS_mergeStk1.pieces[QS_mergeStk1.cntr].size = SINGLE_PIECE_SIZE_32;
                QS_mergeStk1.cntr++;
            }

            temp = size % SINGLE_PIECE_SIZE_32;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                QuickSortDualPivotRusev((arr + i * SINGLE_PIECE_SIZE_32), temp);
                QS_mergeStk1.pieces[QS_mergeStk1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32 + SINGLE_PIECE_SIZE_32 + 1);
                QS_mergeStk1.pieces[QS_mergeStk1.cntr].size = temp;
                QS_mergeStk1.cntr++;
            }


            //now merging all pieces:
            while (1) {
                if (QS_mergeStk1.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < QS_mergeStk1.cntr - 1; i += 2) {
                        merge_Rusev(QS_mergeStk1.pieces[i].start, QS_mergeStk1.pieces[i].size, QS_mergeStk1.pieces[i + 1].size);
                        QS_mergeStk2.pieces[QS_mergeStk2.cntr].start = QS_mergeStk1.pieces[i].start;
                        QS_mergeStk2.pieces[QS_mergeStk2.cntr].size = QS_mergeStk1.pieces[i].size + QS_mergeStk1.pieces[i + 1].size;
                        QS_mergeStk2.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (QS_mergeStk1.cntr - i) {
                        QS_mergeStk2.pieces[QS_mergeStk2.cntr].start = QS_mergeStk1.pieces[i].start;
                        QS_mergeStk2.pieces[QS_mergeStk2.cntr].size = QS_mergeStk1.pieces[i].size;
                        QS_mergeStk2.cntr++;
                    }
                    QS_mergeStk1.cntr = 0;
                }
                else {
                    break;
                }

                if (QS_mergeStk2.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < QS_mergeStk2.cntr - 1; i += 2) {
                        merge_Rusev(QS_mergeStk2.pieces[i].start, QS_mergeStk2.pieces[i].size, QS_mergeStk2.pieces[i + 1].size);
                        QS_mergeStk1.pieces[QS_mergeStk1.cntr].start = QS_mergeStk2.pieces[i].start;
                        QS_mergeStk1.pieces[QS_mergeStk1.cntr].size = QS_mergeStk2.pieces[i].size + QS_mergeStk2.pieces[i + 1].size;
                        QS_mergeStk1.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (QS_mergeStk2.cntr - i) {
                        QS_mergeStk1.pieces[QS_mergeStk1.cntr].start = QS_mergeStk2.pieces[i].start;
                        QS_mergeStk1.pieces[QS_mergeStk1.cntr].size = QS_mergeStk2.pieces[i].size;
                        QS_mergeStk1.cntr++;
                    }
                    QS_mergeStk2.cntr = 0;
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



void QuickSortDualPivotRusevMerge_3rd_merge_improve(int* arr, unsigned int size) {

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

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) 
                QuickSortDualPivotRusev((arr + i * SINGLE_PIECE_SIZE_32), SINGLE_PIECE_SIZE_32);

            temp = size % SINGLE_PIECE_SIZE_32;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) 
                QuickSortDualPivotRusev((arr + i * SINGLE_PIECE_SIZE_32), temp);

            //now merging all pieces:

            int* leftAr = new int[size];
            int* rightAr = new int[size];
            // start merging from midSz ONE_CHUNK_SZ_32. It will merge
            // to form midSz 64, then 128, 256 and so on ....
            for (unsigned int midSz = SINGLE_PIECE_SIZE_32; midSz < size; midSz = 2 * midSz)
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

int partition(int* arr, int left, int right, int* lftPivot)
{
    if (arr[left] > arr[right])
        swapInl(&arr[left], &arr[right]);

    int j = left + 1;
    int nextRightPivot = right - 1, nextLeftPivot = left + 1, leftPivot = arr[left], rightPivot = arr[right];
    while (nextLeftPivot <= nextRightPivot)
    {

        // if elements are less than the left pivot
        if (arr[nextLeftPivot] < leftPivot)
        {
            swapInl(&arr[nextLeftPivot], &arr[j]);
            j++;
        }

        // if elements are greater than or equal to the right pivot
        else if (arr[nextLeftPivot] >= rightPivot)
        {
            while (arr[nextRightPivot] > rightPivot && nextLeftPivot < nextRightPivot)
                nextRightPivot--;
            swapInl(&arr[nextLeftPivot], &arr[nextRightPivot]);
            nextRightPivot--;
            if (arr[nextLeftPivot] < leftPivot)
            {
                swapInl(&arr[nextLeftPivot], &arr[j]);
                j++;
            }
        }
        nextLeftPivot++;
    }
    j--;
    nextRightPivot++;

    // bring pivots to their appropriate positions.
    swapInl(&arr[left], &arr[j]);
    swapInl(&arr[right], &arr[nextRightPivot]);

    // returning the indices of the pivots.
    *lftPivot = j;

    return nextRightPivot;
}

void QuickSortDualPivotBase(int* arr, int leftPidx, int rightPidx)
{
    if (leftPidx < rightPidx)
    {
        int lftPivot, rightPivot;
        rightPivot = partition1Optimized(arr, leftPidx, rightPidx, &lftPivot);
        QuickSortDualPivotBase(arr, leftPidx, lftPivot - 1);
        QuickSortDualPivotBase(arr, lftPivot + 1, rightPivot - 1);
        QuickSortDualPivotBase(arr, rightPivot + 1, rightPidx);
    }
}

void QuickSortDualPivot(int* arr, unsigned int size) {

    QuickSortDualPivotBase(arr, 0, size - 1);
}

void QuickSortDualPivot_WithCheck(int* arr, unsigned int size) {
    int tempInt;

    unsigned int i = 0;
    //------------------------------------------------------------------------------------------
    //--          Check for whether the array is already sorted       --------------------------
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
            QuickSortDualPivotBase(arr, 0, size - 1);
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



void QuickSortDualPivotMerge(int * arr, unsigned int size) {

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
            
            mergePartsStackOpt_t QS_mergeStk1, QS_mergeStk2; // goes on stack! // todo fixme!!! Stack grows too big!

            partsCntr = (size / SINGLE_PIECE_SIZE_32);

            QS_mergeStk1.cntr = 0;
            QS_mergeStk2.cntr = 0;

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                QuickSortDualPivot((arr + i * SINGLE_PIECE_SIZE_32), SINGLE_PIECE_SIZE_32);
                QS_mergeStk1.pieces[QS_mergeStk1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32);
                QS_mergeStk1.pieces[QS_mergeStk1.cntr].size = SINGLE_PIECE_SIZE_32;
                QS_mergeStk1.cntr++;
            }

            temp = size % SINGLE_PIECE_SIZE_32;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                QuickSortDualPivot((arr + i * SINGLE_PIECE_SIZE_32), temp);
                QS_mergeStk1.pieces[QS_mergeStk1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32 + SINGLE_PIECE_SIZE_32 + 1);
                QS_mergeStk1.pieces[QS_mergeStk1.cntr].size = temp;
                QS_mergeStk1.cntr++;
            }


            //now merging all pieces:
            while (1) {
                if (QS_mergeStk1.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < QS_mergeStk1.cntr - 1; i += 2) {
                        merge_Rusev(QS_mergeStk1.pieces[i].start, QS_mergeStk1.pieces[i].size, QS_mergeStk1.pieces[i + 1].size);
                        QS_mergeStk2.pieces[QS_mergeStk2.cntr].start = QS_mergeStk1.pieces[i].start;
                        QS_mergeStk2.pieces[QS_mergeStk2.cntr].size = QS_mergeStk1.pieces[i].size + QS_mergeStk1.pieces[i + 1].size;
                        QS_mergeStk2.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (QS_mergeStk1.cntr - i) {
                        QS_mergeStk2.pieces[QS_mergeStk2.cntr].start = QS_mergeStk1.pieces[i].start;
                        QS_mergeStk2.pieces[QS_mergeStk2.cntr].size = QS_mergeStk1.pieces[i].size;
                        QS_mergeStk2.cntr++;
                    }
                    QS_mergeStk1.cntr = 0;
                }
                else {
                    break;
                }

                if (QS_mergeStk2.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < QS_mergeStk2.cntr - 1; i += 2) {
                        merge_Rusev(QS_mergeStk2.pieces[i].start, QS_mergeStk2.pieces[i].size, QS_mergeStk2.pieces[i + 1].size);
                        QS_mergeStk1.pieces[QS_mergeStk1.cntr].start = QS_mergeStk2.pieces[i].start;
                        QS_mergeStk1.pieces[QS_mergeStk1.cntr].size = QS_mergeStk2.pieces[i].size + QS_mergeStk2.pieces[i + 1].size;
                        QS_mergeStk1.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (QS_mergeStk2.cntr - i) {
                        QS_mergeStk1.pieces[QS_mergeStk1.cntr].start = QS_mergeStk2.pieces[i].start;
                        QS_mergeStk1.pieces[QS_mergeStk1.cntr].size = QS_mergeStk2.pieces[i].size;
                        QS_mergeStk1.cntr++;
                    }
                    QS_mergeStk2.cntr = 0;
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


typedef struct threePivotPos_s {
    unsigned int piv1;
    unsigned int piv2;
    unsigned int piv3;
    unsigned int level;
}threePivotPos_t;

#define DIVIDER_4 4
void QuickSortTriplePivotRusevImpl(int* arr, unsigned int size) {

    unsigned int i, idxProvider, idx1, idx2, idx3;
    int temp1, temp2, temp3;
    bool running = true;

    // It needs three pivots.
    // The best would be if the pivots are from the middle.


    idxProvider = size / DIVIDER_4;
    idx1 = idxProvider - 1;
    idx2 = idxProvider * 2 - 1;
    idx3 = idx2 + idxProvider - 1;

    temp1 = arr[idx1];
    temp2 = arr[idx2];
    temp3 = arr[idx3];

    // sort the pivots
    if (0) {

    }
    // main cycle
    while (running) {
        // Then swaps based on this.
        // going through data
        for (i = 0; i < size; i++) {

        }

        idxProvider = size / DIVIDER_4;
        idx1 = idxProvider - 1;
        idx2 = idxProvider * 2 - 1;
        idx3 = idx2 + idxProvider - 1;

        temp1 = arr[idx1];
        temp2 = arr[idx2];
        temp3 = arr[idx3];
    }
}
