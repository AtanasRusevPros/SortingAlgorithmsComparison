/******************************************************************************
 * src/algorithms/inssort.h
 *
 * Insertion sort
 *
 ******************************************************************************
 * Copyright (C) 2014 Timo Bingmann <tb@panthema.net>
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
 /*
  * Code taken from https://github.com/weissan/BlockQuicksort under GPLv3.0
  */


#ifndef BLQS_INSSORT_H
#define BLQS_INSSORT_H

#include <iostream>

template <typename Iterator>
static inline
void InsertionSort(Iterator A, int64_t n)
{
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    for (int64_t i = 1; i < n; ++i)
    {
        value_type tmp, key = A[i];
//        g_assignments++;

        int64_t j = i - 1;
        while (j >= 0 && (tmp = A[j]) > key)
        {
            A[j + 1] = tmp;
//            g_assignments++;
            j--;
        }
        A[j + 1] = key;
//        g_assignments++;
    }
}

#endif // BLQS_INSSORT_H