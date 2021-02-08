/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file GenericMergeData.h
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
#ifndef GENERICMERGEDATA_H
#define GENERICMERGEDATA_H


typedef struct partDescriptorOpt_s {
    int* start;
    unsigned int size;
}partDescriptorOpt_t;


typedef struct partDescriptor_s {
    int* start;
    int* end;
    unsigned int size;
}partDescriptor_t;

// Make the potential sub-array static in size
#define MAX_PARTS_NUM_16384 16384 // 32*16384 = 524,288
#define MAX_PARTS_NUM_BIG_65536 65536 // 32*16384*4 = 2,097,152
#define SINGLE_PIECE_SIZE_32 32
#define SINGLE_PIECE_SIZE_64 64
#define SINGLE_PIECE_SIZE_128 128
#define SINGLE_PIECE_SIZE_256 256
#define SINGLE_PIECE_SIZE_512 512
#define SINGLE_PIECE_SIZE_1024 1024
#define SINGLE_PIECE_SIZE_2048 2048

typedef struct mergePartsStack_s {
    partDescriptor_t pieces[MAX_PARTS_NUM_BIG_65536];
    unsigned int cntr;
}mergePartsStack_t;

typedef struct mergePartsStackOpt_s{
    partDescriptorOpt_t pieces[MAX_PARTS_NUM_BIG_65536];
    unsigned int cntr;
}mergePartsStackOpt_t;

// merging two adjacent pieces by keeping the order - the first array shall be always with the smaller index!
// considering that we don't know whether we will have all the pieces before or after the array - we have to keep the values in a separate array!
void merge_Rusev(int* arr, unsigned int leftSize, unsigned int rightSize);
void merge_Rusev_3param(int arr[], unsigned int leftInput, unsigned int midInput, unsigned int rightInput);
void merge_Rusev_impr(int arr[], unsigned int leftInput, unsigned int midInput, unsigned int rightInput, int* leftAr, int* rightAr);

#endif // GENERICMERGEDATA_H
