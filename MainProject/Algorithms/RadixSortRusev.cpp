/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file RadixRusev.cpp
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
const int ONE_CHUNK_SZ_32 = 32;



#define LIMIT_KEY_SEQ 8
void radix_Rusev(int* arr, unsigned int size)
{    
    /*
    We accept here an array with a certain length.
    We work in the hexadecimal space. The other option is decimal - but this would increase the amount of comparisons immensely.
    So - the int numbers in hexadecimal use the MSb for sign - if it is 1 - we have a negative number, otherwise it is positive.
    Then - of course we can compare with 0 and then simply use all bits until the sign - but this would pose a problem - how to create our table, i.e. if we have different size of the bit-sets. 
    The hexadecimal numbers from 0 to F give exactly 16 keys. To have the negative keys working - the first pass will define the positive and negative numbers.
    The second pass will not have to care about this any more, as it will know the left and right part already.
    About 32 bit integers - this is practically FF FF FF FF - so these are 8 passes if we have a 16-keys symbol table.
    If we use FF - then we will need 256-keys symbol table. And using also the negatives would pose some issues - we will have a 512-keys table. Even with the mmeory optimizations this leads to quite a big array - we will have one 512 array for indexes count, then we will go over it for each number from the array - this might prove a bit slow. Currently going sequential on the keys leads to going for given numbers from the array to sort to be transferred on the correct location. But this would
    not help me.
    In order to be fast I need to know the indexes. And this is problematic - if I have to keep for 250000 numbers 250000 indexes - there is an issue. If I have to create a brutal amount of data for each key sequence - there is an issue.
    So - one really nice thing would be to first implement the regular 4 bit version - i.e. keys -F to +F
    Then see how this goes. We will have 8 iterations per array. And for the last set - we will use reduced keys - as 1 bit will be taken by the sign.
    */
    /*
    * To feel comfortable - we will use only up to 32 bits arrays.
    */

    int* tempArr = new int(size);

    int keys[0x10] = {0,0,0,0,  0,0,0,0,  0,0,0,0, 0,0,0,0}; // indexes {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF};
    int keysAccum[0x10] = {0,0,0,0,  0,0,0,0,  0,0,0,0, 0,0,0,0}; // indexes {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF};
    int keysNeg[0x10] = { 0,0,0,0,  0,0,0,0,  0,0,0,0, 0,0,0,0 }; // {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF}; // the 0 is kept here only to have the number to work as index
    int keysNegAccum[0x10] = { 0,0,0,0,  0,0,0,0,  0,0,0,0, 0,0,0,0 }; // {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF}; // the 0 is kept here only to have the number to work as index

    // First go over the array for the LSB part:

    // the 8 iterations for 8 digits:
    for (unsigned int keySeq = 0; keySeq < LIMIT_KEY_SEQ; keySeq++) {

        printArrayHex(arr, size);

        // go over the whole input array
        for (unsigned int idx = 0; idx < size; idx++) {
            // get the first digit:
            auto temp = arr[idx];
            auto numDig = temp & (0xF << keySeq);
            if (temp < 0) {
                keysNeg[numDig]++;
            }
            else {
                keys[numDig]++;
            }
        }
        // now we have all numbers
        // so: ACCUMULATE 
        // first negative numbers - do it in reverse order :)
        unsigned int accum = 0;
        for (unsigned int key = 0xF; key > 0; key--) {
            if (keysNeg[key]) {
                accum += keysNeg[key];
                keysNegAccum[key] = accum;
            }
        }
        // now the positive part
        for (unsigned int key = 0x0; key <=0xF; key++) {
            if (keys[key]) {
                accum += keys[key];
                keysAccum[key] = accum;
            }
        }
        
        // Once we are ready we have to now move the numbers: 
        for (int idx = size-1; idx >= 0; idx--) {
            // get the first digit:
            auto temp = arr[idx];
            auto numDig = temp & (0xF << keySeq);
            if (temp < 0) {
                tempArr[keysNeg[numDig] - 1 - 1 + keysNegAccum[numDig--]] = arr[idx];
            }
            else {
                tempArr[keys[numDig] - 1 - 1 + keysAccum[numDig--]] = arr[idx];
            }
        }

        // now we shall have first sorted version of our array. To ease the debugging - let's copy it to the original array and repeat then the cycle :)
        for (unsigned int i = 0; i < size; i++) {
            arr[i] = tempArr[i];
        }

        /*
        * How radix sort works on an iteration:
        * 1. it first goes over all numbers for the given digit position
        * 2. It counts and points out what amount we have from each digit
        * 3. It accumulates the proper position
        * 4. Then for each given number it puts it on the position which is pointed by the given index in the accumulated array
        * 
        * Cons of radix sort: 1. the number of keys
        * 2. We count first the occasions of the digit, then we accumulate, then we move all numbers by putting enough calculation effort just for one move
        */
    }

}
