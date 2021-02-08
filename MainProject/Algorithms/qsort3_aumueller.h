/******************************************************************************
 * qsort3_aumueller.h 
 *
 * from src/algorithms/qsort3.h (available at http://eiche.theoinf.tu-ilmenau.de/quicksort-experiments/) 
 * modified (added sort()) by Armin Weiß <armin.weiss@fmi.uni-stuttgart.de>
 *
 * Sorting using Quicksort, three pivots.  
 * Pretty much the algorithm of Kushagra et al. (2014) at ALENEX.
 *
 ******************************************************************************
 * Copyright (C) 2014 Martin Aumueller <martin.aumueller@tu-ilmenau.de>
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
* Code initially taken from https://github.com/weissan/BlockQuicksort under GPLv3.0
*/

#ifndef QSORT3_AUMUELLER_H
#define QSORT3_AUMUELLER_H

void QuickSortDualPivot_Qsort3_aumueller(int* arr, unsigned int size);
#endif // QSORT3_AUMUELLER_H