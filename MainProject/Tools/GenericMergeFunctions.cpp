/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file GenericMergeFunctions.cpp
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

// Generated test data include:

using namespace std;
using std::cout;
using std::endl;



// merge function merges the sorted runs
// merging two adjacent pieces by keeping the order - the first array shall be always with the smaller index!
// considering that we don't know whether we will have all the pieces before or after the array - we have to keep the values in a separate array!
void merge_Rusev(int* arr, unsigned int leftSize, unsigned int rightSize)
{
    // original array is broken in two parts
    // left and right array


    int* left = new int[leftSize];
    int* right = new int[rightSize];

    for (unsigned int i = 0; i < leftSize; i++)
        left[i] = arr[i];
    for (unsigned int i = 0; i < rightSize; i++)
        right[i] = arr[leftSize + i];

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

    // after comparing, we merge those two array
    // in the larger main array
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of left, if any
    while (i < leftSize)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    // copy remaining element of right, if any
    while (j < rightSize)
    {
        arr[k] = right[j];
        k++;
        j++;
    }

    delete[] left;
    delete[] right;
}


// merge function merges the sorted chunks
void merge_Rusev_3param(int arr[], unsigned int leftInput, unsigned int midInput, unsigned int rightInput)
{
    // original array is broken in two parts
    // left and right array

    unsigned int len1 = midInput - leftInput + 1, len2 = rightInput - midInput;

    int* left = new int[len1];
    int* right = new int[len2];

    for (unsigned int i = 0; i < len1; i++)
        left[i] = arr[leftInput + i];
    for (unsigned int i = 0; i < len2; i++)
        right[i] = arr[midInput + 1 + i];

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = leftInput;

    // after comparing, we merge those two array
    // in the larger main array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    // copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }

    delete[] left;
    delete[] right;
}


// merge function merges the sorted chunks
void merge_Rusev_impr(int arr[], unsigned int leftInput, unsigned int midInput, unsigned int rightInput, int* leftAr, int* rightAr)
{
    // original array is broken in two parts
    // left and right array

    unsigned int len1 = midInput - leftInput + 1, len2 = rightInput - midInput;

    // first we copy to the temp arrays the parts from the main array which need to be merged
    for (unsigned int i = 0; i < len1; i++)
        leftAr[i] = arr[leftInput + i];
    for (unsigned int i = 0; i < len2; i++)
        rightAr[i] = arr[midInput + 1 + i];

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = leftInput;

    // after comparing, we merge those two array
    // in the larger main array
    while (i < len1 && j < len2)
    {
        if (leftAr[i] <= rightAr[j])
        {
            arr[k] = leftAr[i];
            i++;
        }
        else
        {
            arr[k] = rightAr[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of leftAr, if any
    while (i < len1)
    {
        arr[k] = leftAr[i];
        k++;
        i++;
    }

    // copy remaining element of rightAr, if any
    while (j < len2)
    {
        arr[k] = rightAr[j];
        k++;
        j++;
    }
}