/*
* Code due to Vladimir Yaroslavskiy
* Retrieved from http://codeblab.com/wp-content/uploads/2009/09/DualPivotQuicksort.pdf
* Converted to C++ by Armin Weiß <armin.weiss@fmi.uni-stuttgart.de>
* Converted to sort inputs larger than 2^32 by Michael Axtmann <michael.axtmann@kit.edu>
* 
* Code initially taken from https://github.com/weissan/BlockQuicksort under GPLv3.0
*/

#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../Tools/GenericMergeData.h"

namespace Yaroslavskiy {
	/*
	private static void swap(long[] a, long i, long j) {
	 long temp = a[i];
	 a[i] = a[j];
	 a[j] = temp;
	}*/
  template<typename iter, typename comparator>
  void dualPivotQuicksort(iter left, iter right, long div, comparator comp) {
    using t = typename std::iterator_traits<iter>::value_type;
	 long len = right - left;
	 if (len < 27) { // insertion sort for tiny array
	 for (iter i = left + 1; i <= right; i++) {
		 for (iter j = i; j > left && comp(*j , *(j - 1)); j--) {
			std::iter_swap(j, j - 1);
		 }
	 }
	 return;
	 }
	 long third = len / div;
	 // "medians"
	 iter m1 = left + third;
	 iter m2 = right - third;
	 if (m1 <= left) {
		 m1 = left + 1;
	 }
	 if (m2 >= right) {
		m2 	= right - 1;
	 }
	 if (comp(*m1, *m2)) {
		 std::iter_swap(m1, left);
		 std::iter_swap(m2, right);
	 }
	 else {
		 std::iter_swap(m1, right);
		 std::iter_swap(m2, left);
	 }
	 // pivots
	 t pivot1 = *left;
	 t pivot2 = *right;
	 // pointers
	 iter less = left + 1;
	 iter great = right - 1;
	 // sorting
	 for (iter k = less; k <= great; k++) {
		 if (comp(*k, pivot1)) {
			std::iter_swap(k, less++);
		 }
		 else if (comp(pivot2 , *k)) {
			 while (k < great && comp(pivot2, *great)) {
				great--;
			 }
			 std::iter_swap(k, great--);
			 if (comp(*k , pivot1)) {
				std::iter_swap(k, less++);
			 }
		 }
	 }
	 // swaps
	 long dist = great - less;
	 if (dist < 13) {
		div++;
	 }
	 std::iter_swap(less - 1, left);
	 std::iter_swap(great + 1, right);
	 // subarrays
	 dualPivotQuicksort(left, less - 2, div, comp );
	 dualPivotQuicksort(great + 2, right, div, comp );
	 
	 // equal elements
	 if (dist > len - 13 && pivot1 != pivot2) {
		 for (iter k = less; k <= great; k++) {
			 if (!comp(pivot1, *k )) {
				std::iter_swap(k, less++);
			 }
			 else if (!comp(*k ,pivot2)) {
				 std::iter_swap(k, great--);
				 if (!comp(pivot1, *k )) {
					std::iter_swap(k, less++);
				 }
			 }
		 }
	 }
	 // subarray
	 if (pivot1 < pivot2) {
		dualPivotQuicksort(less, great, div,comp );
	 }
	}


	template<typename iter, typename comparator>
	void sort(iter begin, iter end, comparator less) {
	 dualPivotQuicksort(begin, end - 1, 3, less);
	}
}

void QuickSortDualPivot_Yaroslavskiy(int* arr, unsigned int size) {

	std::vector<int> testArray(arr, (arr + size));

	Yaroslavskiy::sort<std::vector<int>::iterator, std::less<int>>(testArray.begin(), testArray.end(), std::less<int>());

	for (int i = 0; i < testArray.size(); i++) {
		arr[i] = testArray[i];
	}

}

////////////////////////////////////////////////////////////////////////

namespace YaroslavskiyV2 {
    template<typename iter, typename comparator>
    void dualPivotQuicksortV2(iter left, iter right, long div, comparator comp) {
        using t = typename std::iterator_traits<iter>::value_type;
        long len = std::distance(left, right);
        constexpr long INSERTION_SORT_THRESHOLD = 27;

        if (len < INSERTION_SORT_THRESHOLD) {
            // Use standard library's sort for small ranges
            std::sort(left, right + 1, comp);
            return;
        }

        long third = len / div;
        iter m1 = std::next(left, third);
        iter m2 = std::prev(right, third);

        if (m1 <= left) m1 = std::next(left);
        if (m2 >= right) m2 = std::prev(right);

        if (comp(*m1, *m2)) {
            std::iter_swap(m1, left);
            std::iter_swap(m2, right);
        } else {
            std::iter_swap(m1, right);
            std::iter_swap(m2, left);
        }

        t pivot1 = *left;
        t pivot2 = *right;

        iter less = std::next(left);
        iter great = std::prev(right);

        for (iter k = less; k <= great; ++k) {
            if (comp(*k, pivot1)) {
                std::iter_swap(k, less++);
            } else if (comp(pivot2, *k)) {
                while (k < great && comp(pivot2, *great)) {
                    --great;
                }
                std::iter_swap(k, great--);
                if (comp(*k, pivot1)) {
                    std::iter_swap(k, less++);
                }
            }
        }

        std::iter_swap(std::prev(less), left);
        std::iter_swap(std::next(great), right);

        // Recursively sort the partitions
        dualPivotQuicksortV2(left, std::prev(less, 2), div, comp);
        dualPivotQuicksortV2(std::next(great, 2), right, div, comp);

        if (great - less > len - 13 && pivot1 != pivot2) {
            for (iter k = less; k <= great; ++k) {
                if (!comp(pivot1, *k)) {
                    std::iter_swap(k, less++);
                } else if (!comp(*k, pivot2)) {
                    std::iter_swap(k, great--);
                    if (!comp(pivot1, *k)) {
                        std::iter_swap(k, less++);
                    }
                }
            }
        }

        if (pivot1 < pivot2) {
            dualPivotQuicksortV2(less, great, div, comp);
        }
    }

    template<typename iter, typename comparator>
    void sort(iter begin, iter end, comparator less) {
        if (begin != end) {
            dualPivotQuicksortV2(begin, std::prev(end), 3, less);
        }
    }
}

template<typename T>
void QuickSortDualPivot_YaroslavskiyV2(T* arr, unsigned int size) {
    YaroslavskiyV2::sort(arr, arr + size, std::less<T>());    
}

void QuickSortDualPivot_YaroslavskiyV2(int* arr, unsigned int size) {
    QuickSortDualPivot_YaroslavskiyV2<int>(arr, size);
}


////////////////////////////////////////////////////////////////////////

void QuickSortDualPivotV2_RusevMerge32(int arr[], unsigned int size) {

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
                QuickSortDualPivot_YaroslavskiyV2((arr + i * SINGLE_PIECE_SIZE_32), SINGLE_PIECE_SIZE_32);
                stkOpt1.pieces[stkOpt1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_32);
                stkOpt1.pieces[stkOpt1.cntr].size = SINGLE_PIECE_SIZE_32;
                stkOpt1.cntr++;
            }

            temp = size % SINGLE_PIECE_SIZE_32;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                QuickSortDualPivot_YaroslavskiyV2((arr + i * SINGLE_PIECE_SIZE_32), temp);
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

////////////////////////////////////////////////////////////////////////

void QuickSortDualPivotV2_RusevMerge64(int arr[], unsigned int size) {

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

            partsCntr = (size / SINGLE_PIECE_SIZE_64);

            stkOpt1.cntr = 0;
            stkOpt2.cntr = 0;

            // sorting each single piece
            for (i = 0; i < partsCntr; i++) {
                QuickSortDualPivot_YaroslavskiyV2((arr + i * SINGLE_PIECE_SIZE_64), SINGLE_PIECE_SIZE_64);
                stkOpt1.pieces[stkOpt1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_64);
                stkOpt1.pieces[stkOpt1.cntr].size = SINGLE_PIECE_SIZE_64;
                stkOpt1.cntr++;
            }

            temp = size % SINGLE_PIECE_SIZE_64;

            // checking whether our size divides to our base piece size and sorting the last element
            if (temp) {
                QuickSortDualPivot_YaroslavskiyV2((arr + i * SINGLE_PIECE_SIZE_64), temp);
                stkOpt1.pieces[stkOpt1.cntr].start = (arr + i * SINGLE_PIECE_SIZE_64 + SINGLE_PIECE_SIZE_64 + 1);
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
////////////////////////////////////////////////////////////////////////

#define IS_THRESH 27 // Insertion sort threshold

namespace triple_pivot {

    template<typename iter, typename Compare>
    struct Partitioner {
        static iter partition(iter begin, iter end, Compare comp, int& pivot_length) {
            using t = typename std::iterator_traits<iter>::value_type;
            long len = std::distance(begin, end);

            // Select three pivots
            iter m1 = begin + (len >> 2);
            iter m2 = begin + (len >> 1);
            iter m3 = begin + 3 * (len >> 2);

            // Order the pivots
            if (comp(*m2, *m1)) std::iter_swap(m1, m2);
            if (comp(*m3, *m2)) std::iter_swap(m2, m3);
            if (comp(*m2, *m1)) std::iter_swap(m1, m2);

            // Move pivots to the appropriate positions
            std::iter_swap(begin, m1);
            std::iter_swap(end - 1, m3);

            t pivot1 = *begin;
            t pivot2 = *m2;
            t pivot3 = *(end - 1);

            iter low = begin + 1; // renamed from `less` to avoid shadowing
            iter great = end - 2;
            iter k = low;

            // Partition the array into four parts
            while (k <= great) {
                if (comp(*k, pivot1)) {
                    std::iter_swap(k++, low++);
                } else if (comp(pivot3, *k)) {
                    while (k < great && comp(pivot3, *great)) {
                        --great;
                    }
                    std::iter_swap(k, great--);
                    if (comp(*k, pivot1)) {
                        std::iter_swap(k, low++);
                    }
                    k++;
                } else if (comp(*k, pivot2)) {
                    ++k;
                } else {
                    ++k;
                }
            }

            // Move the pivots to their correct positions
            std::iter_swap(begin, --low);
            std::iter_swap(end - 1, ++great);

            pivot_length = 1;
            return low;
        }
    };

    template<template<class, class> class Partitioner, typename iter, typename Compare>
    inline void qsort_triple_pivot(iter begin, iter end, Compare comp) {
        const int depth_limit = 2 * static_cast<int>(std::log2(end - begin)) + 3;
        iter stack[120];
        iter* s = stack;
        int depth_stack[60];
        int depth = 0;
        int* d_s_top = depth_stack;
        *s = begin;
        *(s + 1) = end;
        s += 2;
        *d_s_top = 0;
        ++d_s_top;
        do {
            if (depth < depth_limit && end - begin > IS_THRESH) {
                iter pivot;
                int pivot_length = 1;
                pivot = Partitioner< iter, Compare>::partition(begin, end, comp, pivot_length);
                if (pivot - begin > end - pivot) {
                    *s = begin;
                    *(s + 1) = pivot;
                    begin = pivot + pivot_length;
                }
                else {
                    *s = pivot + pivot_length;
                    *(s + 1) = end;
                    end = pivot;
                }
                s += 2;
                depth++;
                *d_s_top = depth;
                ++d_s_top;
            }
            else {
                if (end - begin > IS_THRESH) {
                    std::partial_sort(begin, end, end);
                }
                else {
                    std::sort(begin, end, comp); // A custom insertion sort can be used here as needed
                }

                s -= 2;
                begin = *s;
                end = *(s + 1);
                --d_s_top;
                depth = *d_s_top;
            }
        } while (s != stack);
    }

}

template<typename T>
void QuickSortTriplePivot_YaroslavskiyV3(T* arr, unsigned int size) {
    triple_pivot::qsort_triple_pivot<triple_pivot::Partitioner>(arr, arr + size, std::less<T>());
}

void QuickSortTriplePivot_YaroslavskiyV3(int* arr, unsigned int size) {
    QuickSortTriplePivot_YaroslavskiyV3<int>(arr, size);
}
////////////////////////////////////////////////////////////////////////

namespace YaroslavskiyV3_impr {
    template<typename iter, typename comparator>
    void triplePivotQuicksort(iter left, iter right, long div, comparator comp) {
        using t = typename std::iterator_traits<iter>::value_type;
        long len = std::distance(left, right);
        constexpr long INSERTION_SORT_THRESHOLD = 27;

        if (len < INSERTION_SORT_THRESHOLD) {
            std::sort(left, right + 1, comp);
            return;
        }

        long fourth = len / div;
        iter m1 = std::next(left, fourth);
        iter m2 = left + 2 * fourth;
        iter m3 = std::prev(right, fourth);

        if (comp(*m3, *m2)) std::iter_swap(m3, m2);
        if (comp(*m2, *m1)) {
            std::iter_swap(m2, m1);
            if (comp(*m3, *m2)) std::iter_swap(m3, m2);
        }

        std::iter_swap(left, m1);
        std::iter_swap(right, m3);

        t pivot1 = *left;
        t pivot2 = *m2;
        t pivot3 = *right;

        iter less = std::next(left);
        iter mid = less;
        iter great = std::prev(right);

        for (iter k = less; k <= great;) {
            if (comp(*k, pivot1)) {
                std::iter_swap(k++, less++);
            } else if (!comp(pivot2, *k)) {
                if (!comp(*k, pivot2)) {
                    if (comp(pivot3, *k)) {
                        while (k < great && comp(pivot3, *great)) {
                            --great;
                        }
                        std::iter_swap(k, great--);
                        if (comp(*k, pivot2)) std::iter_swap(k, mid++);
                    }
                    k++;
                }
            } else {
                std::iter_swap(k++, mid++);
            }
        }

        std::iter_swap(std::prev(less), left);
        std::iter_swap(mid, right);

        // Tail recursive calls
        triplePivotQuicksort(left, std::prev(less, 1), div, comp);
        triplePivotQuicksort(std::next(less, 1), mid, div, comp);
        triplePivotQuicksort(std::next(mid, 1), right, div, comp);
    }

    template<typename iter, typename comparator>
    void sort(iter begin, iter end, comparator less) {
        if (begin != end) {
            triplePivotQuicksort(begin, std::prev(end), 4, less);
        }
    }
}

template<typename T>
void QuickSortTriplePivot_YaroslavskiyV3_impr(T* arr, unsigned int size) {
    YaroslavskiyV3_impr::sort(arr, arr + size, std::less<T>());
}


void QuickSortTriplePivot_YaroslavskiyV3_impr(int* arr, unsigned int size) {
    QuickSortTriplePivot_YaroslavskiyV3_impr<int>(arr, size);
}


////////////////////////////////////////////////////////////////////////