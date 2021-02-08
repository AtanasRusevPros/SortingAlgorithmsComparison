/*
 * Copyright (c) 2013, 2017 Alexey Tourbin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* Github link:
* https://github.com/svpv/qsort
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../../Tools/AlgorithmSupport.h"

/* Number of comparisons that a sort function makes. */
size_t ncmp;
#if 1
#define NCMPINC ncmp++
#else
#define NCMPINC (void*)0
#endif

/*
 * Numeric comparison
 */
static int icmp(const void *i1, const void *i2)
{
    NCMPINC;
    return *(int *) i1 - *(int *) i2;
}
void svpv_stdlib_isort(int *A, unsigned int n)
{
    qsort(A, (size_t)n, sizeof(int), icmp);
}

#ifdef __cplusplus
#include <algorithm>
static inline bool iless(int a, int b)
{
    NCMPINC;
    return a < b;
}
void svpv_stl_isort(int *A, unsigned int n)
{
    std::sort(A, A + (size_t)n, iless);
}
#endif

#include "svpv_qsort.h"

void svpv_isort_qsort(int * A, unsigned int n)
{
    int tmp;
#define ILESS(i, j) (NCMPINC, A[i] < A[j])
#define SWAP(i, j) tmp = A[i], A[i] = A[j], A[j] = tmp
    QSORT((size_t)n, ILESS, SWAP);
#undef QSORT
}


void svpv_isort_qsort_RusevMerge(int arr[], unsigned int size) {

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
            mergePartsStackOpt_t stkOpt1, stkOpt2;

            partsCntr = (size / SINGLE_PIECE_SIZE_32);

            stkOpt1.cntr = 0;
            stkOpt2.cntr = 0;

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                svpv_isort_qsort((arr + i * SINGLE_PIECE_SIZE_32), SINGLE_PIECE_SIZE_32);
                stkOpt1.pieces[stkOpt1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32);
                stkOpt1.pieces[stkOpt1.cntr].size = SINGLE_PIECE_SIZE_32;
                stkOpt1.cntr++;
            }

            temp = size % SINGLE_PIECE_SIZE_32;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                svpv_isort_qsort((arr + i * SINGLE_PIECE_SIZE_32), temp);
                stkOpt1.pieces[stkOpt1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32 + SINGLE_PIECE_SIZE_32 + 1);
                stkOpt1.pieces[stkOpt1.cntr].size = temp;
                stkOpt1.cntr++;
            }


            //now merging all pieces:
            while (1) {
                if (stkOpt1.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < stkOpt1.cntr - 1; i += 2) {
                        merge_Rusev(stkOpt1.pieces[i].start, stkOpt1.pieces[i].size, stkOpt1.pieces[i + 1].size);
                        stkOpt2.pieces[stkOpt2.cntr].start = stkOpt1.pieces[i].start;
                        stkOpt2.pieces[stkOpt2.cntr].size = stkOpt1.pieces[i].size + stkOpt1.pieces[i + 1].size;
                        stkOpt2.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (stkOpt1.cntr - i) {
                        stkOpt2.pieces[stkOpt2.cntr].start = stkOpt1.pieces[i].start;
                        stkOpt2.pieces[stkOpt2.cntr].size = stkOpt1.pieces[i].size;
                        stkOpt2.cntr++;
                    }
                    stkOpt1.cntr = 0;
                }
                else {
                    break;
                }

                if (stkOpt2.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < stkOpt2.cntr - 1; i += 2) {
                        merge_Rusev(stkOpt2.pieces[i].start, stkOpt2.pieces[i].size, stkOpt2.pieces[i + 1].size);
                        stkOpt1.pieces[stkOpt1.cntr].start = stkOpt2.pieces[i].start;
                        stkOpt1.pieces[stkOpt1.cntr].size = stkOpt2.pieces[i].size + stkOpt2.pieces[i + 1].size;
                        stkOpt1.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (stkOpt2.cntr - i) {
                        stkOpt1.pieces[stkOpt1.cntr].start = stkOpt2.pieces[i].start;
                        stkOpt1.pieces[stkOpt1.cntr].size = stkOpt2.pieces[i].size;
                        stkOpt1.cntr++;
                    }
                    stkOpt2.cntr = 0;
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


void svpv_stl_isort_RusevMerge(int arr[], unsigned int size) {

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

            mergePartsStackOpt_t stkOpt1, stkOpt2;

            partsCntr = (size / SINGLE_PIECE_SIZE_32);

            stkOpt1.cntr = 0;
            stkOpt2.cntr = 0;

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                svpv_stl_isort((arr + i * SINGLE_PIECE_SIZE_32), SINGLE_PIECE_SIZE_32);
                stkOpt1.pieces[stkOpt1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32);
                stkOpt1.pieces[stkOpt1.cntr].size = SINGLE_PIECE_SIZE_32;
                stkOpt1.cntr++;
            }

            temp = size % SINGLE_PIECE_SIZE_32;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                svpv_stl_isort((arr + i * SINGLE_PIECE_SIZE_32), temp);
                stkOpt1.pieces[stkOpt1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32 + SINGLE_PIECE_SIZE_32 + 1);
                stkOpt1.pieces[stkOpt1.cntr].size = temp;
                stkOpt1.cntr++;
            }


            //now merging all pieces:
            while (1) {
                if (stkOpt1.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < stkOpt1.cntr - 1; i += 2) {
                        merge_Rusev(stkOpt1.pieces[i].start, stkOpt1.pieces[i].size, stkOpt1.pieces[i + 1].size);
                        stkOpt2.pieces[stkOpt2.cntr].start = stkOpt1.pieces[i].start;
                        stkOpt2.pieces[stkOpt2.cntr].size = stkOpt1.pieces[i].size + stkOpt1.pieces[i + 1].size;
                        stkOpt2.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (stkOpt1.cntr - i) {
                        stkOpt2.pieces[stkOpt2.cntr].start = stkOpt1.pieces[i].start;
                        stkOpt2.pieces[stkOpt2.cntr].size = stkOpt1.pieces[i].size;
                        stkOpt2.cntr++;
                    }
                    stkOpt1.cntr = 0;
                }
                else {
                    break;
                }

                if (stkOpt2.cntr > 1) {
                    // merge all in first array, send to second array
                    for (i = 0; i < stkOpt2.cntr - 1; i += 2) {
                        merge_Rusev(stkOpt2.pieces[i].start, stkOpt2.pieces[i].size, stkOpt2.pieces[i + 1].size);
                        stkOpt1.pieces[stkOpt1.cntr].start = stkOpt2.pieces[i].start;
                        stkOpt1.pieces[stkOpt1.cntr].size = stkOpt2.pieces[i].size + stkOpt2.pieces[i + 1].size;
                        stkOpt1.cntr++;
                    }

                    // if there is one more piece left - just take it over:
                    if (stkOpt2.cntr - i) {
                        stkOpt1.pieces[stkOpt1.cntr].start = stkOpt2.pieces[i].start;
                        stkOpt1.pieces[stkOpt1.cntr].size = stkOpt2.pieces[i].size;
                        stkOpt1.cntr++;
                    }
                    stkOpt2.cntr = 0;
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