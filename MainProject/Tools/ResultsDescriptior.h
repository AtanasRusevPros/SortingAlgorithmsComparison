/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file ResultsDescriptor.h
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
*  \brief Results descriptor header.
*  \details For full explanation on why and how this project was designed please
*     check the pdf version of the accompanying article in the docs directory
*
*  \author Atanas Georgiev Rusev (https://github.com/AtanasRusevPros)
*  \author Please add your name for additional contributions
*
*/

#ifndef RESULTSDESCRIPTIOR_H
#define RESULTSDESCRIPTIOR_H

#include "TestDescriptor.h"
#include <vector>
#include <map>

enum class AlgorithmID{ 
    RusevSwapSort2,
    RusevSwapSort2ImprIdx,
    RusevSwapSort2withCheck,
    RusevSwapSort2withCheckImprIdx,
    RusevSwapSort4,
    RusevSwapSort4fullWithCheck,
    RusevSwapSort4fullWithCheckAndVolatile,

    RusevMergeSortBasedOn2_3rd_merge_improve,
    RusevMergeSortBasedOn4_3rd_merge_improve,

    RusevUltraBasedOn4Rusev,
    RusevUltraBasedOn4RusevV2,
    RusevUltraBasedOn4_V3_integral,
    
    RusevMergeSort32basedOn2,
    RusevMergeSort32basedOn4_2,
    RusevMergeSort64basedOn2,
    RusevMergeSort64basedOn4_2,
    RusevMergeSort128basedOn2,
    RusevMergeSort128basedOn4_2,
    RusevMergeSort256basedOn2,
    RusevMergeSort256basedOn4_2,
    RusevMergeSort512basedOn2,
    RusevMergeSort512basedOn4_2,
    RusevMergeSort1024basedOn2,
    RusevMergeSort1024basedOn4_2,
    RusevMergeSort2048basedOn2,
    RusevMergeSort2048basedOn4_2,

    RusevMergeSortBasedOn2_32StaticStacksNoOpt,
    RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED,
    RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED_Dyn,

    QuicksortSinglePivot,
    QuicksortSinglePivotWithCheck,
    QuicksortSinglePivot_RusevOptimized,

    QuickSortDualPivotRusev,
    QuickSortDualPivotRusev_WithCheck,
    QuickSortDualPivotRusevMerge,

    QuickSortDualPivotRusevMerge_3rd_merge_improve,
    
    QuickSortDualPivot,
    QuickSortDualPivot_WithCheck,
    QuickSortDualPivotMerge,

    blocked_double_pivot_check_mosqrt_sort,
    QuickSortDualPivot_Yaroslavskiy,
    QuickSortDualPivot_YaroslavskiyV2,
    QuickSortDualPivotV2_RusevMerge32,
    QuickSortDualPivotV2_RusevMerge64,
    QuickSortTriplePivot_YaroslavskiyV3,
    QuickSortTriplePivot_YaroslavskiyV3_impr,
    QuickSortDualPivot_Qsort3_aumueller,

    stl_StableSort,
    stl_sortRegular,

    svpv_stdlib_isort,
    svpv_stl_isort,
    svpv_isort_qsort,
    svpv_stl_isort_RusevMerge,
    svpv_isort_qsort_RusevMerge,
    
    BubbleSort,
    timSortWithMerge,
    timSort_Rusev,
    timSort_Rusev_With_Checks,
    timSort_Rusev_WithMerge,
    timSort_Rusev_With_Checks_imprMerge,
    MergeSort,
    Other
};


enum class SortAlg_Test_Error{
    NO_ERROR,
    BAD_INPUT,
    NOT_SORTED_RESULT,
    TYPE_DECODE_ERROR,
    OTHER_ERROR
};


#define RESERVED_AMOUNT_20 20
#define RESERVED_AMOUNT_100 100
using sortFuncPtr = void (*)(int *, unsigned int);

struct SingleResult {
    unsigned long long execTime;
    unsigned long size;
    TestDataSizeType sizeClass;
    TestDataType dataType;
};


using SingleListResultsVect = std::map<TestDataType, std::vector<SingleResult>>;


/* So - we have 7 general types of tests.
/ Then we have for each test 3 sub-types by size, and for each of them up to 10 arrays of data.
/ So haveing a simple map is not enough.
/ The map gives us the 7 types. But no specific designation of which type was tested now and what exact result it delivered.
/ So we need sth more as a descriptor.
/
/ The general results are kept once per algorithm.
/ Now what we need is the secondary division. A vector is good, but it shall not be of simple time resulots, instead of a structure.
/
/ The current code will result in a big list.
/
/ For each type we will have the list - RAND, SORTED, REV_SORTED, etc.
/
/ We also have division of general size classes.
/
/ And another for alignment.
/
/ So we can compare the aligned and not aligned results.
/
/ And we can get the accumulated times per type of data. And per size class.
/
/ At the end we will be able to print also the results. But those will not be sorted.
/
/ So the input shall be sorted. Or the output shall be sorted by size.

/ Finally we have nowall the averages. We need coutners for them.
/ We have all the inputs, and for each test we will have the type, size, size class, also whether it is aligned or not.
/ Counters are crucial for the averages. And for this we will use the vector count.
/
/ So - for aligned and not aligned - completely different pieces of data.
/ For big and small - different pieces of data.
/
/ Then for each piece we have internally for each type of data the given sub-arrays.
/
/ Finally the sub-arrays are practically vectors, which also hold the count of elements in them. So it is great :)
/
/ The vectors are with pre-reserved 20 locations via RESERVED_AMOUNT_20. And this is done via listing of the map of types.
*/

using ResultsAveragedPerDataType = std::map<TestDataType, unsigned long long>;

typedef struct GenericAccumulatedResults_s{
    unsigned long long TotalTime_ns = 0;
    unsigned long long AvrgSmallTime_ns = 0;
    unsigned long long AvrgBigTime_ns = 0;
    unsigned long long AvrgSuperBigTime_ns = 0;
};

class ResultsDescriptor {

public:

    // Total times:
    GenericAccumulatedResults_s notAlignedTotals{};
    GenericAccumulatedResults_s alignedTotals{};

    // Average Times in particular:
    ResultsAveragedPerDataType AvrgSmall{};
    ResultsAveragedPerDataType AvrgBig{};
    ResultsAveragedPerDataType AvrgSuperBig{};
    ResultsAveragedPerDataType AvrgSmallAligned{};
    ResultsAveragedPerDataType AvrgBigAligned{};
    ResultsAveragedPerDataType AvrgSuperBigAligned{};

    AlgorithmID algoID;

    // Results per group:
    SingleListResultsVect results_small;    // Small regular
    SingleListResultsVect results_big;    // Big regular
    SingleListResultsVect results_small_al;    // Small aligned
    SingleListResultsVect results_big_al;    // Big aligned
    SingleListResultsVect results_superBig;    // Small aligned
    SingleListResultsVect results_superBig_al;    // Big aligned

    std::string info{};

    std::string algoName{};

    ResultsDescriptor(){
        for (auto& kvp : results_small) // kvp - acronym for Key-Value pair
        {   auto & vect = kvp.second;
            vect.reserve(RESERVED_AMOUNT_20);
        }

        for (auto& kvp : results_big) // kvp - acronym for Key-Value pair
        {   auto & vect = kvp.second;
            vect.reserve(RESERVED_AMOUNT_20);
        }

        for (auto& kvp : results_small_al) // kvp - acronym for Key-Value pair
        {   auto & vect = kvp.second;
            vect.reserve(RESERVED_AMOUNT_20);
        }

        for (auto& kvp : results_big_al) // kvp - acronym for Key-Value pair
        {   auto & vect = kvp.second;
            vect.reserve(RESERVED_AMOUNT_20);
        }

        for (auto& kvp : results_superBig) // kvp - acronym for Key-Value pair
        {   auto & vect = kvp.second;
            vect.reserve(RESERVED_AMOUNT_20);
        }

        for (auto& kvp : results_superBig_al) // kvp - acronym for Key-Value pair
        {   auto & vect = kvp.second;
            vect.reserve(RESERVED_AMOUNT_20);
        }

        // Average Times in particular:

        const std::vector<TestDataType> testDataTypeListing{ TestDataType::RAND_with_Repeats, TestDataType::REV_SORTED, TestDataType::RAND_NO_REPEATS_SHUFFLED, TestDataType::SORTED, TestDataType::SORTED_WITH_SOME_ZEROES_INSERTED, TestDataType::ONE_NUMBER, TestDataType::ONLY_ZEROES };

        for (const auto& c : testDataTypeListing) {
            AvrgSmall.emplace(std::make_pair(c,0));
            AvrgBig.emplace(std::make_pair(c,0));
            AvrgSuperBig.emplace(std::make_pair(c,0));
            AvrgSmallAligned.emplace(std::make_pair(c,0));
            AvrgBigAligned.emplace(std::make_pair(c,0));
            AvrgSuperBigAligned.emplace(std::make_pair(c,0));
        }
    }

    ~ResultsDescriptor(){};
};

class finalAverages_s {    

    const std::vector<TestDataType> testDataTypeListing{ TestDataType::RAND_with_Repeats, TestDataType::REV_SORTED, TestDataType::RAND_NO_REPEATS_SHUFFLED, TestDataType::SORTED, TestDataType::SORTED_WITH_SOME_ZEROES_INSERTED, TestDataType::ONE_NUMBER, TestDataType::ONLY_ZEROES };

public:
    GenericAccumulatedResults_s totalTimes;
    ResultsAveragedPerDataType resultsSmall{};
    ResultsAveragedPerDataType resultsBig{};
    ResultsAveragedPerDataType resultsSuperBig{};

    finalAverages_s() {
        
        for (const auto& c : testDataTypeListing) {
            resultsSmall.emplace(std::make_pair(c, 0));
            resultsBig.emplace(std::make_pair(c, 0));
            resultsSuperBig.emplace(std::make_pair(c, 0));            
        }
    }
};

#endif // RESULTSDESCRIPTIOR_H
