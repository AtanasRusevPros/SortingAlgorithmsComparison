/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file RusevMergeSort32.h
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

#ifndef RUSEVMERGESORT32_H
#define RUSEVMERGESORT32_H

#include "../Tools/GenericMergeData.h"

template <const int T>
inline void RusevMergeSortBasedOn2(int arr[], unsigned int size);
template <const int T>
inline void RusevMergeSortBasedOn2_3rd_merge_improve(int arr[], unsigned int size);
template <const int T>
inline void RusevMergeSortBasedOn4_3rd_merge_improve(int arr[], unsigned int size);



template <const int T>
inline void RusevMergeSortBasedOn4_2(int arr[], unsigned int size);

void RusevMergeSortBasedOn2_32StaticStacksNoOpt(int arr[], unsigned int size);
void RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED(int arr[], unsigned int size);
void RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED_Dyn(int arr[], unsigned int size);



template<> void RusevMergeSortBasedOn2_3rd_merge_improve<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);
template<> void RusevMergeSortBasedOn4_3rd_merge_improve<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);

template<> void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size) ;
template<> void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_32>(int arr[], unsigned int size);

template<> void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_64>(int arr[], unsigned int size);
template<> void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_64>(int arr[], unsigned int size);

template<> void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_128>(int arr[], unsigned int size);
template<> void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_128>(int arr[], unsigned int size);

template<> void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_256>(int arr[], unsigned int size);
template<> void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_256>(int arr[], unsigned int size);

template<> void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_512>(int arr[], unsigned int size);
template<> void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_512>(int arr[], unsigned int size);

template<> void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_1024>(int arr[], unsigned int size);
template<> void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_1024>(int arr[], unsigned int size);

template<> void RusevMergeSortBasedOn2<(int)SINGLE_PIECE_SIZE_2048>(int arr[], unsigned int size);
template<> void RusevMergeSortBasedOn4_2<(int)SINGLE_PIECE_SIZE_2048>(int arr[], unsigned int size);



#endif // RUSEVMERGESORT32_H
