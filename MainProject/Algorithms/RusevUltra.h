/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file RusevUltra.h
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

#ifndef RUSEVULTRA_H
#define RUSEVULTRA_H

#include "../Tools/GenericMergeData.h"

template <const int T>
void RusevUltraBasedOn4Rusev(int arr[], unsigned int size);
void RusevUltraBasedOn4RusevV2(int arr[], unsigned int size);

void sortNumsInsertionMin2(int arr[], unsigned int size);

void sort0_to_4NumsWithIfs(int arr[], unsigned int size);

void sort2NumsWithIfsRusev(int arr[], unsigned int size);
void sort3NumsWithIfsRusev(int arr[], unsigned int size);
void sort4NumsWithIfsRusev(int arr[], unsigned int size);
void sort8NumsWithIfsRusev(int arr[], unsigned int size);
void sort16NumsWithIfsRusev(int arr[], unsigned int size);
void sort32NumsWithIfsRusev(int arr[], unsigned int size);


void RusevUltraSwapSort4(int arr[], unsigned int size);
void RusevSwapSort4_ImprovedIfs(int arr[], unsigned int size);
void RusevSwapSort4_Original(int arr[], unsigned int size);
void RusevSwapSort4_ImprovedIfsV2(int arr[], unsigned int size);
void RusevSwapSort4_ImprovedIfs_32_V3(int arr[], const unsigned int size);


template <const int T>
inline void RusevUltraBasedOn4Rusev(int arr[], unsigned int size);
template <const int T>
inline void RusevUltraBasedOn4RusevV2(int arr[], unsigned int size);

template <const int T>
void RusevUltraBasedOn4_V3_integral(int arr[], unsigned int size);

template<> void RusevUltraBasedOn4Rusev<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);
template<> void RusevUltraBasedOn4RusevV2<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);
template<> void RusevUltraBasedOn4_V3_integral<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);




// template<> void RusevMergeSortBasedOn2_3rd_merge_improve<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);


#endif // RUSEVULTRA_H
