
/******************************************************************************
* blocked_double_pivot_check_mosqrt.h++
*
* interface for BlockQuicksort with median-of-sqrt(n) and duplicate check
*
******************************************************************************
* Copyright (C) 2016 Stefan Edelkamp <edelkamp@tzi.de>
* Copyright (C) 2016 Armin Weiß <armin.weiss@fmi.uni-stuttgart.de>
*
* This program is free software: you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 3 of the License, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along with
* this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/
/* Github link:
* Code initially taken from https://github.com/weissan/BlockQuicksort under GPLv3.0
*/


#ifndef BLOCKED_DOUBLE_PIVOT_CHECK_MOSQRT_H
#define BLOCKED_DOUBLE_PIVOT_CHECK_MOSQRT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <random>
#include <ctime>
#include <cmath>
#include <assert.h>


#include "BlockedQuickSort_h/blqs_insertionsort.h"
#include "BlockedQuickSort_h/blqs_median.h"
#include "BlockedQuickSort_h/blqs_partition.h"
#include "BlockedQuickSort_h/blqs_quicksort.h"

namespace blocked_double_pivot_check_mosqrt {
	template<typename iter, typename Compare>
	void sort(iter begin, iter end, Compare less) {
		quicksort::qsort_double_pivot_check<partition::Hoare_block_partition_mosqrt>(begin, end, less);
	}
	template<typename T>
	void sort(std::vector<T>& v) {
		typename std::vector<T>::iterator begin = v.begin();
		typename std::vector<T>::iterator end = v.end();
		quicksort::qsort_double_pivot_check<partition::Hoare_block_partition_mosqrt>(begin, end, std::less<T>());
	}
}

void blocked_double_pivot_check_mosqrt_sort(int* arr, unsigned int size);
#endif // BLOCKED_DOUBLE_PIVOT_CHECK_MOSQRT_H
