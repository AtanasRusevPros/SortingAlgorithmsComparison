/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file main.cpp
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
*  \brief Main Test Structures and Types definitions.
*  \details For full explanation on why and how this project was designed please
*     check the pdf version of the accompanying article in the docs directory
*
*  \author Atanas Georgiev Rusev (https://github.com/AtanasRusevPros)
*  \author Please add your name for additional contributions
*
*/


/************************************************************************ 
* A SHORT README or my initial thoughts of deisgning this code:

* We have a big amount of Sorting algorithms for integers to test.
*
* Before we start - sorting is based on two main operations - compare and reorder. Compare is simply check - bigger, equal or smaller. Reorder may be transfer to helping array, swap with another number, shift in the current array. Comparison is the single fastest operation. Array access to given element might be fast in L1 cache, slower in L2/L3, super slow in RAM. Reorder is fast in L1 cache, slower in L2/L3, super slow in RAM.
* Assessing algorithms is based on 3 factors: speed, required additional memory, stability of results. In big O notaion we have the average results of many sorting algorithms in Wikipedia here:
* https://en.wikipedia.org/wiki/Sorting_algorithm
*
* In order to test sorting we must consider the following inputs:
*
// 1. random with some repeating numbers
// 2. random array with no repeating numbers
// 3. sorted array
// 4. Reverse sorted array
// 5. Non-repeat sorted, with zeroes inserted
// 6. All numbers equal
// 7. All numbers , not only equal, but explicitly zero
// 8. Super big amount of data - (e.g. over 1,000,000 values)

// crucial point is that specially for sorted and reverse sorted arrays those will be proven before and after the operations. This means that the data input and output will be checked, to confirm the validity of the test SW.

// Second point during testing is that the shuffled data will be checked for number of pivots. This means that each shuffled array will be checked how many times the next number is smaller than the preiouvs and smaller from the next one, or vice versa, effectively counting how many times we change the type of data when going in consecutive order of the indeces. So if we start with rising data and ten times switch to reducing data, then to rising, then to reducing - we shall have 10 pivots. 10 times changing from rising to falling data, or vice versa. The name of the check function will be actually inversion counter, as it will count inversions.
What is the purpose of this action? To check what is the dispersion of our data with some relative metric, as this will not tell us e.g. how far a given number is from his correct final location. We will just know that the data is shuffled, IS dispersed, IS in NOT ORDERED sequence.

// The algorithms have different implementations, checks, some are recursive, some hybrid, others direct. This means the implementations are SERIOUS point of consideration.
// One shall obligatory keep in mind that different compilers have different optimization schemes, use different implementations of the basics C/C++ functions.
// Even from this starting point we already have serious potential difference in productivity.

// We will use the data to proive a dependence of the results from:

//  - Algorithm / Implementation
//  - Compiler (Qt Creator, Mingw G++), Clang, MSVC 2019
//  - Target machine

// Combining those three dependencies might be problematic. The expectance is that:
//  1. FASTEST ALGORITHM: The fastest algorithms will be fastest on most machines. In general the machines shall not change critically the general effectiveness of algorithms
//  2. DATA SPLITTING: The size of chunks shall improve the algorithms signifcantly, giving the hybrid algorithms significant advantage over non-hybrid
//  2.1 DATA ALIGNMENT: Aligning the beginning of an array shall improve the performance. Check will be done for all arrays when aligned and when not aligned.
//  3. COMPILER: Clang is expected to be better in most cases. The total amount of time shall be assessed. This means - to say that given compiler is the best - it shall be better in almost / all test cases :).
//  4. WILL THERE BE A FASTEST ALGO AT ALL: The most interesting question is which algorithm may turn out to be best, and whether there will be such at all.
//  5. POTENTIAL CONCLUSIONS FOR IMPROVEMENT: It is clear that more data will require more compuntations. What is expected to be checked is at what amount of data we have serious degrading of the effectiveness.
//  5.1 METRIC FOR SORTING: For the purpose of calculating 5. a metric shall be established, which is amount of time in ns per sorting of 1 piece. I.e. if 100 ns are required for 50 pieces - then the amount is 2 ns. If 10000 ns is required for 1000 pieces - the amount is 10 ns per piece.

// Few additional points:
//  1. ADDITIONAL CHECKS IN ALGOS: Crucial is that some algorithms are quite faster thanks to additional checks in some specific cases with already partially sorted data, or with reverse sorted data. This study shall help understand how those additional checks affect the performance.
//  2. STAIBLITY IS NOT TESTED HERE! All the algorithms here will NOT BE EVALUATED for stability!!!
//  3. EFFECT FROM EQUALS IN DATA: Some algorithms are faster when equal numbers exist in the amount of data. One of the purposes is to see whether some of them perform better with presence of equal numbers
//  4. VALIDATE 1: Zeroes or all elements equal might also be an issue sometimes. To evaluate effectiveness in this case such tests are also present
//  5. VALIDATE 2: This SW has also the purpose to fully validate the implementation of the given sort algorithm. If there is a single error - your algorithm needs debug and check. If all cases pass - it works.
//  6. VALIDATE 3: The validation is considered also for arbitrary number of input values - odd, even amounts, divisible by 2,4, etc, powers of 2 and such which are not powers of 2. It also checks from the smallest to the biggest amount of data. Why? Because we want to know that the given implementation is 100% free of bugs. Otherwise - go back and debug it ;)

//  7. TESTING FOR IMPROVEMENTS ON YOUR TARGET PLATFORM: Once all from above is clarified - this testing shall be of help as well on checking which size of chunks processing is the best for given platform. So if you have to implement a sorting algo for a dedicated platform - knowing what chunks is best for you might lead to several times improvement of the necessary amount of time!

//  8. CONCLUSIONS AND RECOMMENDATIONS AT THE END: Finally - the results of the study will be used to result in a number of recommendations for algorithms implementation as well.

// The main purpose however will be to see which algoirthm performs best on an average.
// And also whether specific type of approach (in particular separating the target array to chunks of different size - 64, 128, 256, 512) helps a lot or not, and how those results will perform on different machines

// MULTITHREADING POINT: the only point which remains questionable is usage of such algorithms on multi-core machines, with final combination of results. Reason - splitting the tasks is not enough to increase performance. One shall consider also cache, cache pages access, data alignment and other points, which are NOT PART OF THIS STUDY. They might be considered in a separate one. If all points are considered many algorithms might be transformed ina way which will increase the performance e.g. for jumping from 1 core machine to 8 effective cores - close to 7.x times, and this is SIGNIFCANT in many BIG DATA areas!


// Test targets:
// Xeon 2630 v0 64 bit, CPU released  Q1'2012,  with 24 GB RAM, Windows 8.1 Pro // https://ark.intel.com/content/www/us/en/ark/products/64593/intel-xeon-processor-e5-2630-15m-cache-2-30-ghz-7-20-gt-s-intel-qpi.html
// Intel Core i7-8750H (6 core with Hyperthreading, 9MB cache, 2.2GHz), Released Q2'2018 16GB DDR4 2666MHz, Windows 10 // https://ark.intel.com/content/www/us/en/ark/products/134906/intel-core-i7-8750h-processor-9m-cache-up-to-4-10-ghz.html
// CPU Intel Celeron J1800 2,41 GHz, dual core, 64 bit, 1 MB L2 Cache,  Q4'2013,  RAM 4 GB DDR3 1333 MHz, Manjaro Linux 19.2 Kyria    //  https://ark.intel.com/content/www/us/en/ark/products/78866/intel-celeron-processor-j1800-1m-cache-up-to-2-58-ghz.html
// Raspberry Pi 4 with Manjaro Linux 19.2 Kyria:
//      • Quad core 64-bit ARM-Cortex A72 running at 1.5GHz, core released from ARM in 2016, ARMv8-A
//      • 1, 2 and 4 Gigabyte LPDDR4 RAM options (mine is with 4 GB of RAM)
// https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2711/README.md
// https://en.wikipedia.org/wiki/ARM_Cortex-A72
// https://en.wikipedia.org/wiki/ARM_architecture#64/32-bit_architecture



// REGARDING CPUs: Nowadays the CPUs are extremely complex. We shall consider:
// core, cache, instruction pipeline and prediction, ram access, optimizations, internal instruction interpreter, not aligned memory access, etc.
// in addition we have Operating system, cores, RAM speed, Chipset specifics (change the way the CPU accesses data from RAM, and if relevant - also from HDD)
// The conclusion here is to define whether a certain approach will be better than others in most cases, also to define worst cases for most algorithms.


* One of the purposes of this program is to check the results in relation to: G++ x86_64-w64-mingw32
* Thread model: posix gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
*
* Then - we shall consider the first testing machine: 64 bit Intel Xeon 2630 v0 (2012), 6 core with Hyperthreading (12 effective cores reported),
* L1 Cache: Instruction: 6 x 32 KBytes, Data: 6 x 32 KBytes
* L2 Cache: Integrated: 6 x 256 KBytes
* L3 Cache: 15 MBytes
* Instruction TLB: 2MB/4MB Pages, Fully associative, 8 entries
* Data TLB: 4 KB Pages, 4-way set associative, 64 entries
*
* Motherboard Chipset: Intel C606 (Patsburg-D) [Upgrade ROM4 (T0)]
*
* 6x4 GB DDR3 SDRAM 1333 MHz
*
*  Windows 8.1 Pro
*
*
// Part of the work - a short TODO list
// 1. random array - DONE
// 2. random with some repeating numbers - DONE
// 3. random with different repeating numbers - DONE
// 4. array with equal numbers - DONE
// 5. sorted array  - DONE
// 6. reverse sorted - DONE
// 7. with zeroes - DONE
// -----------------
// All those tests shall be repeated for several sizes - DONE
// 128, 256.....32768 members - powers of 2 - DONE
// arrays with odd length - DONE
// arrays with even length, but divisible e.g. by 4 - DONE
// short array under 64 elements - DONE
// Super Long arrays - 512 KB of elements - DONE
// ------------------
// tests with GCC, MSVC, Clang
// tests for Windows, Linux
// -------------
// reporting of RusevSort, QuickSort with double Pivot, TimSort, Merge Sort... DONE
// Comparison of end results for each type of input
// check for result arrays whether those are all correct
// also make the checks for aligned and not aligned data !!!
*/

#include <iostream>
#include <chrono>
#include <ratio>
#include <thread>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>

#include <filesystem>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <random>
#include <cstddef>
#include <memory>
#include <limits>
#include <cstdlib>
#include <exception>

// Generated test data include:

#include "Tools/TimeMeasureChrono_ns.h"
#include "Tools/TestDescriptor.h"
#include "Tools/ResultsDescriptior.h"
#include "Tools/GenericMergeData.h"
#include "Tools/Arrays_Tools.h"
#include "Tools/AlgorithmSupport.h"


#include "Algorithms/BubbleSort.h"
#include "Algorithms/stl_StableSort.h"
#include "Algorithms/QuickSortRusev.h"
#include "Algorithms/TimSortRusev.h"
#include "Algorithms/RusevMergeSort32.h"
#include "Algorithms/RusevSwapSort2.h"
#include "Algorithms/RusevSwapSort4.h"
#include "Algorithms/RusevUltra.h"
#include "Algorithms/blocked_double_pivot_check_mosqrt.h"
#include "Algorithms/Yaroslavskiy.h"
#include "Algorithms/qsort3_aumueller.h"
#include "Algorithms/svpv_qsort_macro/svpv_sorting_funcs.h"

using namespace std;
using namespace std::chrono;
using std::cout;
using std::endl;
using std::vector;
using std::string;
// --------------------------------------------------------------------------
// Additional debug print
// change this to DEBUG_PRINTS_ON to enable full console debug reporting
#define DEBUG_PRINTS_OFF
#ifdef DEBUG_PRINTS_ON
#define pout cout
#else
#define pout 0 && cout
#endif

#define DEBUG_PRINTS_RUNTIME_LISTING_ARRAYS_OFF
#ifdef DEBUG_PRINTS_RUNTIME_LISTING_ARRAYS_ON
#define lout cout
#else
#define lout 0 && cout
#endif


#define DEBUG_PRINTS_MERGE_ALGO_OFF
#ifdef DEBUG_PRINTS_MERGE_ALGO_ON
#define mdout cout
#else
#define mdout 0 && cout
#endif

nanoseconds execTime_32;

nanoseconds startTimeStamp_32;

// operators to be able to iterate over all TestDataType enumeration values

TestDataType operator++(TestDataType& x) {
    return x = (TestDataType)(std::underlying_type<TestDataType>::type(x) + 1);
}

TestDataType operator*(TestDataType c) {
    return c;
}

TestDataType begin() {
    return TestDataType::First;
}

TestDataType end() {
    TestDataType l = TestDataType::Last;
    return ++l;
}

const TestDataType TestDataTypes[] = { TestDataType::RAND_with_Repeats, TestDataType::REV_SORTED, TestDataType::RAND_NO_REPEATS_SHUFFLED, TestDataType::SORTED, TestDataType::SORTED_WITH_SOME_ZEROES_INSERTED, TestDataType::ONE_NUMBER, TestDataType::ONLY_ZEROES };

vector<TestDataType> testDataTypeListing{ TestDataType::RAND_with_Repeats, TestDataType::REV_SORTED, TestDataType::RAND_NO_REPEATS_SHUFFLED, TestDataType::SORTED, TestDataType::SORTED_WITH_SOME_ZEROES_INSERTED, TestDataType::ONE_NUMBER, TestDataType::ONLY_ZEROES };

///**********************************************************************************///
///****    TEST DATA GENERATION CLASSES       ***************************************///
///**********************************************************************************///

std::string retStringTestDataType(TestDataType type) {
    switch (type) {
    case TestDataType::RAND_with_Repeats: return "RAND_with_Repeats";
    case TestDataType::REV_SORTED: return "REV_SORTED";
    case TestDataType::RAND_NO_REPEATS_SHUFFLED: return "RAND_NO_REPEATS_SHUFFLED";
    case TestDataType::SORTED: return "SORTED";
    case TestDataType::SORTED_WITH_SOME_ZEROES_INSERTED: return "SORTED_WITH_SOME_ZEROES_INSERTED";
    case TestDataType::ONLY_ZEROES: return "ONLY_ZEROES";
    case TestDataType::ONE_NUMBER: return "ONE_NUMBER";
    default: return "INVALID TYPE !!!!!";
    }
};

std::string retStringHwType(targetHwListing type) {
    switch (type) {
    case targetHwListing::Intel_Celeron_J1800: return "Intel_Celeron_J1800";
    case targetHwListing::Intel_Xeon2630: return "Intel_Xeon2630";
    case targetHwListing::Intel_Core_i7_8750H: return "Intel_Core_i7_8750H";
    case targetHwListing::Broadcom_BCM2711_ARM_Cortex_A72: return "Broadcom_BCM2711_ARM_Cortex_A72";
    default: return "INVALID TYPE !!!!!";
    }
};

std::string retStringAlgoID(AlgorithmID type) {
    switch (type) {
    case AlgorithmID::RusevSwapSort2: return "RusevSwapSort2";
    case AlgorithmID::RusevSwapSort2ImprIdx: return "RusevSwapSort2ImprIdx";
    case AlgorithmID::RusevSwapSort2withCheck: return "RusevSwapSort2withCheck";
    case AlgorithmID::RusevSwapSort2withCheckImprIdx: return "RusevSwapSort2withCheckImprIdx";
    case AlgorithmID::RusevSwapSort4: return "RusevSwapSort4";
    case AlgorithmID::RusevSwapSort4fullWithCheck: return "RusevSwapSort4fullWithCheck";
    case AlgorithmID::RusevSwapSort4fullWithCheckAndVolatile: return "RusevSwapSort4fullWithCheckAndVolatile";
        
    case AlgorithmID::RusevMergeSort32basedOn2: return "RusevMergeSort32basedOn2";
    case AlgorithmID::RusevMergeSort32basedOn4_2: return "RusevMergeSort32basedOn4_2";

    case AlgorithmID::RusevMergeSort64basedOn2: return "RusevMergeSort64basedOn2";
    case AlgorithmID::RusevMergeSort64basedOn4_2: return "RusevMergeSort64basedOn4_2";

    case AlgorithmID::RusevMergeSort128basedOn2: return "RusevMergeSort128basedOn2";
    case AlgorithmID::RusevMergeSort128basedOn4_2: return "RusevMergeSort128basedOn4_2";

    case AlgorithmID::RusevMergeSort256basedOn2: return "RusevMergeSort256basedOn2";
    case AlgorithmID::RusevMergeSort256basedOn4_2: return "RusevMergeSort256basedOn4_2";

    case AlgorithmID::RusevMergeSort512basedOn2: return "RusevMergeSort512basedOn2";
    case AlgorithmID::RusevMergeSort512basedOn4_2: return "RusevMergeSort512basedOn4_2";

    case AlgorithmID::RusevMergeSort1024basedOn2: return "RusevMergeSort1024basedOn2";
    case AlgorithmID::RusevMergeSort1024basedOn4_2: return "RusevMergeSort1024basedOn4_2";

    case AlgorithmID::RusevMergeSort2048basedOn2: return "RusevMergeSort2048basedOn2";
    case AlgorithmID::RusevMergeSort2048basedOn4_2: return "RusevMergeSort2048basedOn4_2";


    case AlgorithmID::RusevMergeSortBasedOn2_3rd_merge_improve: return "RusevMergeSortBasedOn2_3rd_merge_improve";
    case AlgorithmID::RusevMergeSortBasedOn4_3rd_merge_improve: return "RusevMergeSortBasedOn4_3rd_merge_improve";

    case AlgorithmID::RusevUltraBasedOn4Rusev: return "RusevUltraBasedOn4Rusev";
    case AlgorithmID::RusevUltraBasedOn4RusevV2: return "RusevUltraBasedOn4RusevV2";
    case AlgorithmID::RusevUltraBasedOn4_V3_integral: return "RusevUltraBasedOn4_V3_integral";

    case AlgorithmID::RusevMergeSortBasedOn2_32StaticStacksNoOpt: return "RusevMergeSortBasedOn2_32StaticStacksNoOpt";
    case AlgorithmID::RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED: return "RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED";       
    case AlgorithmID::RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED_Dyn: return "RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED_Dyn";
            
    case AlgorithmID::QuicksortSinglePivot: return "QuicksortSinglePivot";
    case AlgorithmID::QuicksortSinglePivotWithCheck: return "QuicksortSinglePivotWithCheck";
    case AlgorithmID::QuicksortSinglePivot_RusevOptimized: return "QuicksortSinglePivot_RusevOptimized";
    case AlgorithmID::QuickSortDualPivotRusev: return "QuickSortDualPivotRusev";
    case AlgorithmID::QuickSortDualPivotRusev_WithCheck: return "QuickSortDualPivotRusev_WithCheck";
    case AlgorithmID::QuickSortDualPivotRusevMerge: return "QuickSortDualPivotRusevMerge";
    case AlgorithmID::QuickSortDualPivotRusevMerge_3rd_merge_improve: return "QuickSortDualPivotRusevMerge_3rd_merge_improve";
        
    case AlgorithmID::QuickSortDualPivot: return "QuickSortDualPivot";
    case AlgorithmID::QuickSortDualPivot_WithCheck: return "QuickSortDualPivot_WithCheck";
    case AlgorithmID::QuickSortDualPivotMerge: return "QuickSortDualPivotMerge";

    case AlgorithmID::blocked_double_pivot_check_mosqrt_sort: return "blocked_double_pivot_check_mosqrt_sort";
    case AlgorithmID::QuickSortDualPivot_Yaroslavskiy: return "QuickSortDualPivot_Yaroslavskiy";
    case AlgorithmID::QuickSortDualPivot_Qsort3_aumueller: return "QuickSortDualPivot_Qsort3_aumueller";

    case AlgorithmID::stl_StableSort: return "stl_StableSort";
    case AlgorithmID::stl_sortRegular: return "stl_sortRegular";

    case AlgorithmID::svpv_stdlib_isort: return "svpv_stdlib_isort";
    case AlgorithmID::svpv_stl_isort: return "svpv_stl_isort";
    case AlgorithmID::svpv_isort_qsort: return "svpv_isort_qsort";
    case AlgorithmID::svpv_stl_isort_RusevMerge: return "svpv_stl_isort_RusevMerge";
    case AlgorithmID::svpv_isort_qsort_RusevMerge: return "svpv_isort_qsort_RusevMerge";
        

    case AlgorithmID::BubbleSort: return "BubbleSort";
    case AlgorithmID::timSort_Rusev: return "timSort_Rusev";
    case AlgorithmID::timSort_Rusev_With_Checks: return "timSort_Rusev_With_Checks";
    case AlgorithmID::timSort_Rusev_WithMerge: return "timSort_Rusev_WithMerge";
    case AlgorithmID::timSort_Rusev_With_Checks_imprMerge: return "timSort_Rusev_With_Checks_imprMerge";        
        
    case AlgorithmID::MergeSort: return "MergeSort";
    case AlgorithmID::Other: return "Other";
    default: return "INVALID TYPE !!!!!";
    }
};

alignas(4) mtDataNotAligned_t dataNotAligned_b = {};
alignas(4096) int dataArrayAligned_b[DATA_CONTAINER_MAX_ELEMENTS] = {};

class TestExecutor {

private:
    TestData* testData_p;

    // We need here the big temporary array for data. And it shall hold really big pieces. The current size of the data is of up to 2,096,128 ints.
    // And 8 MB of data are 2,097,152 bytes.
    // The best would be to think in the future. So let's allocate really big container. This will be a piece of 64 MB of data.
    // 64 MB are normally 1,048,576 * 64 = 67,108,864

    mtDataNotAligned_t* dataNotAligned;
    int* dataArrayAligned;
    bool saveToCsvPerRun;
    bool enableTimeLimit;

    unsigned int testCycles;

    // the string to hold the CSV data. 
    string finalComparisonRes{};

    // Saving current set of iterations with one single algorithm in a csv file
    void saveToCsvFilePerRun(vector<ResultsDescriptor> &singleAlgoAllRunsResults, std::string AlgoId);
    
    string csvHeaderLine{};
    
    const unsigned long long singleRunLimit_10sec_in_ns = 10000000000;
    const unsigned long long singleRunLimit_2sec_in_ns = 2000000000;
    const unsigned long long singleRunLimit_1sec_in_ns = 1000000000;
    const unsigned long long singleRunLimit_500ms_in_ns = 500000000;
    const unsigned long long singleRunLimit_10ms_in_ns = 10000000;
    const unsigned long long singleRunLimit_2ms_in_ns = 2000000;

public:
    TestExecutor(unsigned int cyclesPerTest, TestExecutionLength execLength, TestSelection testSelect,  bool _saveToCsvPerRun = false, bool _enableTimeLimit = true) : saveToCsvPerRun(_saveToCsvPerRun), enableTimeLimit(_enableTimeLimit){
        testCycles = cyclesPerTest;
        unsigned long long maxTestDataBytes = DATA_CONTAINER_MAX_ELEMENTS*sizeof(int);            

        testData_p = new TestData(maxTestDataBytes,
            targetHwListing::Intel_Xeon2630,
            targetMachineListing::WORKSTATION_Xeon2630,
            targetCompilerListing::QtCreator_GCC_8_1_0,
            targetOsListing::Windows_8_1_Pro,
            testSelect,
            execLength);

        dataNotAligned = &dataNotAligned_b;
        dataArrayAligned = dataArrayAligned_b;

        string outFileName = "Results_Summary" + retStringHwType(testData_p->m_hw) + std::to_string(getTime_Since_Epoch_ns().count()) + ".CSV";
        csvHeaderLine = "Algo Name : ALL Results averaged from " + to_string(cyclesPerTest) + " test cycles and if error - no results printed, Total Time , Average Small, Average Big, Average Super Big,  ";

        std::ofstream outFile(outFileName);

        // adding to the csv header line to have the string prepared
        for (const auto& c : testDataTypeListing) {
            csvHeaderLine.append("SMALL Avrg " + retStringTestDataType(c) + ", ");
        }
        for (const auto& c : testDataTypeListing) {
            csvHeaderLine.append("BIG Avrg " + retStringTestDataType(c) + ", ");
        }
        for (const auto& c : testDataTypeListing) {
            csvHeaderLine.append("SUP BIG Avrg " + retStringTestDataType(c) + ", ");
        }
        csvHeaderLine.append("\n");

        // For e.g. 50 algorithms we may have up to 1000 characters per line * 50 = 50000
        const unsigned int finalDataStringLength = 50000;
        finalComparisonRes.reserve(finalDataStringLength);
        finalComparisonRes.append(csvHeaderLine);
    };

    void multiTestDynamicData(AlgorithmID algoID, std::string genInf, sortFuncPtr sortFunc, bool testAligned = true);
    void saveFinalSummary();

};

void TestExecutor::multiTestDynamicData(AlgorithmID algoID, std::string genInf, sortFuncPtr sortFunc, bool testAligned) {
    
    string algoNameStr = retStringAlgoID(algoID);
    string latestErr{};
    string slowAlgo{};
    string slowAlgoAligned{};
    bool completeTestErrFlag = false;
    nanoseconds execTime;

    vector<ResultsDescriptor> singleAlgoAllRunsResults;
    singleAlgoAllRunsResults.reserve(testCycles);

    // structures for accumulating final averages
    vector<finalAverages_s> finAvrgNotAlignedAll;
    vector<finalAverages_s> finAvrgAlignedAll;

    finAvrgNotAlignedAll.reserve(testCycles);
    finAvrgAlignedAll.reserve(testCycles);

    // two error counters for the arrays, which are all checked
    // before and after sorting to ensure data correctness for tests
    unsigned int errorCntrInput = 0;
    unsigned int errorCntrOutput = 0;

    unsigned int checkGenericNotAligned = 0, checkGenericAligned = 0;

    cout << "----------------------------------------------------------------" << endl;
    cout << "Started Test of " << testCycles << "  testCycles for algorithm " << algoNameStr << endl;

    string outFileName = "RESULTS " + algoNameStr + ".txt";

    std::ofstream detailedTextReport(outFileName);

    for (unsigned int cyclesCntr = 0; cyclesCntr < testCycles; cyclesCntr++) {
        
        unsigned int totalTestsCurrCycle = 0;

        volatile bool markCurrentAlgoSLOW = false;
        volatile bool markCurrentAlgoSLOWaligned = false;

        singleAlgoAllRunsResults.push_back(ResultsDescriptor());

        ResultsDescriptor* allResultsDetailedData_p = &singleAlgoAllRunsResults.back();

        allResultsDetailedData_p->algoName = algoNameStr;
        allResultsDetailedData_p->algoID = algoID;
        allResultsDetailedData_p->info = genInf;

        detailedTextReport << "########################################################\n";
        detailedTextReport << "Starting run " << cyclesCntr + 1 << " out of " << testCycles << endl;

        ///********************************************************
        // 1. TEST FOR NOT ALIGNED DATA:
        ///********************************************************
        // list the input vectors:
        for (SingleTestContainer* input : testData_p->testVect) {

            // each time we enter the function we have new data to be tested.
            // So - as we want the aligned data to be aligned, and the non-aligned data to be at a non-even location -
            // and we have the int alignas(4096) dataArray[67108864] = {}; in the class private data - then let's see how we can do it:

            // First we clear the buffer:
            auto szTmp = sizeof(dataNotAligned_b);
            std::memset(reinterpret_cast<void*>(dataNotAligned), 0, szTmp);

            // The single test container holds only a pointer to the data. The real data is statically allocated. So we simply copy it
            std::memcpy(dataNotAligned->arr, input->array, input->byteSize);

            // outFile << " \n Testing Not Aligned ADDRESS: " << dataNotAligned->arr << "  INFO: " << input->info << endl; // std::to_string(static_cast<unsigned long>(
            lout << " \n Testing Not Aligned ADDRESS: " << dataNotAligned->arr << "  INFO: " << input->info << endl; // std::to_string(static_cast<unsigned long>(

            auto errCheck = checkArrayInputBeforeForMultiTest(dataNotAligned->arr, input);

            totalTestsCurrCycle++;

            if (TestDataType_ERROR::ARRAY_OK != errCheck) {
                cout << " CRITICAL ERROR!!! TEST INPUT ARRAY WRONG!!! Skipping: " << input->info << endl;
                detailedTextReport << " CRITICAL ERROR!!! TEST INPUT ARRAY WRONG!!! Skipping: " << input->info << endl;
                input->err = errCheck;
                errorCntrInput++;
            }
            else {

                // record start time:
                auto startTimeStamp = getTime_Since_Epoch_ns();

                // call the function
                try {
                    sortFunc(dataNotAligned->arr, input->size);
                }
                catch (std::exception& e) {
                    cout << "Algorithm " << algoNameStr << " raised an exception: " << e.what() << '\n';
                    cout << "BREAKING THIS TEST! \n";                    
                    errorCntrOutput++;
                }
                catch (...) { 
                    cout << "Unhandled Exception in Algorithm : " << algoNameStr << endl; 
                    cout << "BREAKING THIS TEST! \n";                     
                    errorCntrOutput++;
                }

                // record end time, calculate execution time, write result:
                execTime = getTime_Since_Epoch_ns() - startTimeStamp;

                if (checkIfArrSorted(dataNotAligned->arr, input->size)) {
                    // here add error handling
                    cout << "CRITICAL ERROR !!! ARRAY NOT SORTED AFTER sort algorithm execution !!! Array info: " << input->info << endl;
                    detailedTextReport << "CRITICAL ERROR !!! ARRAY NOT SORTED AFTER sort algorithm execution !!! Array info: " << input->info << endl;
                    errorCntrOutput++;
                }
                else {

                    ///********************************************************
                    // 1.1 PUSHING RESULTS TO RESULT VECTORS not aligned DATA:
                    ///********************************************************

                    // We have to insert now the result in the correct container:

                    SingleResult resObj;
                    resObj.size = input->size;
                    resObj.sizeClass = input->sizeClass;
                    resObj.dataType = input->dataType;
                    resObj.execTime = static_cast<unsigned long long>(execTime.count());

                    switch (resObj.sizeClass) {
                    case TestDataSizeType::SMALL_32_2050: {
                        allResultsDetailedData_p->results_small[resObj.dataType].push_back(resObj);
                        if ((resObj.execTime >= singleRunLimit_10ms_in_ns) && enableTimeLimit) {
                            markCurrentAlgoSLOW = true;
                        }
                        break;
                    }
                    case TestDataSizeType::BIG_32768_524288: {
                        allResultsDetailedData_p->results_big[resObj.dataType].push_back(resObj);
                        if ((resObj.execTime >= singleRunLimit_1sec_in_ns) && enableTimeLimit) {
                            markCurrentAlgoSLOW = true;
                        }
                        break;
                    }
                    case TestDataSizeType::SUPER_BIG_2096128: {
                        allResultsDetailedData_p->results_superBig[resObj.dataType].push_back(resObj);
                        if ((resObj.execTime >= singleRunLimit_2sec_in_ns) && enableTimeLimit) {
                            markCurrentAlgoSLOW = true;
                        }
                        break;
                    }
                    default: {
                        cout << "Critical ERROR while decoding size general class!!!" << endl; // should never happen!
                        break;
                    }
                    }
                }
                lout << "Execution Time: " << convLng_ns(execTime.count()) << endl;
            }
            detailedTextReport.flush();

            if (markCurrentAlgoSLOW) break;
        }

        ///********************************************************
        // 2. TEST FOR THE ALIGNED DATA:
        ///********************************************************
        // list the input vectors:
        if (testAligned) {
            for (SingleTestContainer* input : testData_p->testVectAligned) {

                // each time we enter the function we have new data to be tested.
                // So - as we want the aligned data to be aligned, and the non-aligned data to be at a non-even location -
                // and we have the int alignas(4096) dataArray[67108864] = {}; in the class private data - then let's see how we can do it:

                // First we clear the buffer:
                auto szTmp = sizeof(dataArrayAligned_b);
                std::memset(reinterpret_cast<void*>(dataArrayAligned), 0, szTmp);

                // The single test container holds only a pointer to the data. The real data is statically allocated. So we simply copy it
                std::memcpy(dataArrayAligned, input->array, input->byteSize);

                lout << " \n Testing ALIGNED ADDRESS: " << dataArrayAligned << "  INFO: " << input->info << endl; // std::to_string(static_cast<unsigned long>(

                // outFile << " \n Testing ALIGNED ADDRESS: " << dataArrayAligned << "  INFO: " << input->info << endl; // std::to_string(static_cast<unsigned long>(

                auto errCheck = checkArrayInputBeforeForMultiTest(dataArrayAligned, input);

                totalTestsCurrCycle++;

                if (TestDataType_ERROR::ARRAY_OK != errCheck) {
                    cout << " CRITICAL ERROR!!! TEST INPUT ARRAY WRONG!!! Skipping: " << input->info << endl;
                    detailedTextReport << " CRITICAL ERROR!!! TEST INPUT ARRAY WRONG!!! Skipping: " << input->info << endl;
                    input->err = errCheck;
                    errorCntrInput++;
                }
                else {
                    // record start time:
                    auto startTimeStamp = getTime_Since_Epoch_ns();


                    // call the function
                    try {
                        sortFunc(dataArrayAligned, input->size);
                    }
                    catch (std::exception& e) {
                        cout << "Algorithm " << algoNameStr << " raised an exception: " << e.what() << '\n';
                        cout << "BREAKING THIS TEST! \n";
                        errorCntrOutput++;
                    }
                    catch (...) {
                        cout << "Unhandled Exception in Algorithm : " << algoNameStr << endl;
                        cout << "BREAKING THIS TEST! \n";
                        errorCntrOutput++;
                    }
                    

                    // record end time, calculate execution time, write result:
                    execTime = getTime_Since_Epoch_ns() - startTimeStamp;

                    if (checkIfArrSorted(dataArrayAligned, input->size)) {
                        // here add error handling
                        cout << "CRITICAL ERROR !!! ARRAY NOT SORTED AFTER sort algorithm execution !!! Array info: " << input->info << endl;
                        detailedTextReport << "CRITICAL ERROR !!! ARRAY NOT SORTED AFTER sort algorithm execution !!! Array info: " << input->info << endl;
                        errorCntrOutput++;
                    }
                    else {

                        ///********************************************************
                        // 2.1 PUSHING RESULTS TO RESULT VECTORS - ALIGNED DATA:
                        ///********************************************************

                        // We have to insert now the result in the correct container:

                        SingleResult resObj;
                        resObj.size = input->size;
                        resObj.sizeClass = input->sizeClass;
                        resObj.dataType = input->dataType;
                        resObj.execTime = static_cast<unsigned long long>(execTime.count());

                        switch (resObj.sizeClass) {
                        case TestDataSizeType::SMALL_32_2050: {
                            allResultsDetailedData_p->results_small_al[resObj.dataType].push_back(resObj);
                            if ((resObj.execTime >= singleRunLimit_10ms_in_ns) && enableTimeLimit) {
                                markCurrentAlgoSLOWaligned = true;
                            }
                            break;
                        }
                        case TestDataSizeType::BIG_32768_524288: {
                            allResultsDetailedData_p->results_big_al[resObj.dataType].push_back(resObj);
                            if ((resObj.execTime >= singleRunLimit_1sec_in_ns) && enableTimeLimit) {
                                markCurrentAlgoSLOWaligned = true;
                            }
                            break;
                        }
                        case TestDataSizeType::SUPER_BIG_2096128: {
                            allResultsDetailedData_p->results_superBig_al[resObj.dataType].push_back(resObj);
                            if ((resObj.execTime >= singleRunLimit_2sec_in_ns) && enableTimeLimit) {
                                markCurrentAlgoSLOWaligned = true;
                            }
                            break;
                        }
                        default: {
                            cout << "Critical ERROR while decoding size general class!!!" << endl; // should never happen!
                            break;
                        }
                        }
                    }
                    lout << "Execution Time: " << convLng_ns(execTime.count()) << endl;
                }
                detailedTextReport.flush();

                if (markCurrentAlgoSLOWaligned) break;
            }
        }

        ///********************************************************
        // 3. OUTPUTTING ALL RESULT VECTORS:
        ///********************************************************

        detailedTextReport << "*************************************************************" << endl;
        detailedTextReport << "**     Detailed report one per one for each input data array " << endl;
        detailedTextReport << "*************************************************************" << endl;

        // Here we iterate over the correct container to prepare statistics:
        for (auto& kvp : allResultsDetailedData_p->results_small) // kvp - acronym for Key-Value pair
        {
            for (const auto& testRes : kvp.second) {
                detailedTextReport << "Test Results for Small Not Aligned : " << retStringTestDataType(testRes.dataType) << " Size: " << testRes.size << " Time : " << convLng_ns(testRes.execTime) << endl;
            }
        }

        // Here we iterate over the correct container to prepare statistics:
        for (auto& kvp : allResultsDetailedData_p->results_big) // kvp - acronym for Key-Value pair
        {
            for (const auto& testRes : kvp.second) {
                detailedTextReport << "Test Results for BIG Not Aligned : " << retStringTestDataType(testRes.dataType) << " Size: " << testRes.size << " Time : " << convLng_ns(testRes.execTime) << endl;
            }
        }

        // Here we iterate over the correct container to prepare statistics:
        for (auto& kvp : allResultsDetailedData_p->results_superBig) // kvp - acronym for Key-Value pair
        {
            for (const auto& testRes : kvp.second) {
                detailedTextReport << "Test Results for Super-BIG Not Aligned : " << retStringTestDataType(testRes.dataType) << " Size: " << testRes.size << " Time : " << convLng_ns(testRes.execTime) << endl;
            }
        }

        if (testAligned) {
            // Here we iterate over the correct container to prepare statistics:
            for (auto& kvp : allResultsDetailedData_p->results_small_al) // kvp - acronym for Key-Value pair
            {
                for (const auto& testRes : kvp.second) {
                    detailedTextReport << "Test Results for Small ALIGNED : " << retStringTestDataType(testRes.dataType) << " Size: " << testRes.size << " Time : " << convLng_ns(testRes.execTime) << endl;
                }
            }

            // Here we iterate over the correct container to prepare statistics:
            for (auto& kvp : allResultsDetailedData_p->results_big_al) // kvp - acronym for Key-Value pair
            {
                for (const auto& testRes : kvp.second) {
                    detailedTextReport << "Test Results for BIG ALIGNED : " << retStringTestDataType(testRes.dataType) << " Size: " << testRes.size << " Time : " << convLng_ns(testRes.execTime) << endl;
                }
            }

            // Here we iterate over the correct container to prepare statistics:
            for (auto& kvp : allResultsDetailedData_p->results_superBig_al) // kvp - acronym for Key-Value pair
            {
                for (const auto& testRes : kvp.second) {
                    detailedTextReport << "Test Results for Super-BIG ALIGNED : " << retStringTestDataType(testRes.dataType) << " Size: " << testRes.size << " Time : " << convLng_ns(testRes.execTime) << endl;
                }
            }
        }

        detailedTextReport << "*************************************************************" << endl;
        detailedTextReport << "** END Detailed report one per one for each input data array " << endl;
        detailedTextReport << "*************************************************************" << endl;

        ///********************************************************
        // 4. Statistics preparation:
        ///********************************************************

        auto accumLambda = [](unsigned long long& total, SingleListResultsVect& results) -> unsigned long long {

            unsigned long long accum = 0;
            unsigned int cntr = 0;

            for (auto& kvp : results) // kvp - acronym for Key-Value pair
            {
                for (const auto& testRes : kvp.second) {
                    total += testRes.execTime;
                    accum += testRes.execTime;
                    cntr++;
                }
            }
            if (0 < cntr)
                return accum / cntr;
            return 0;
        };

        //---------------------------------------
        //  NOT ALIGNED
        //---------------------------------------

        finalAverages_s totalAccum;
        finalAverages_s totalAccumAligned;

        totalAccum.totalTimes.AvrgSmallTime_ns = allResultsDetailedData_p->notAlignedTotals.AvrgSmallTime_ns = accumLambda(allResultsDetailedData_p->notAlignedTotals.TotalTime_ns, allResultsDetailedData_p->results_small);
        totalAccum.totalTimes.AvrgBigTime_ns = allResultsDetailedData_p->notAlignedTotals.AvrgBigTime_ns = accumLambda(allResultsDetailedData_p->notAlignedTotals.TotalTime_ns, allResultsDetailedData_p->results_big);
        totalAccum.totalTimes.AvrgSuperBigTime_ns = allResultsDetailedData_p->notAlignedTotals.AvrgSuperBigTime_ns = accumLambda(allResultsDetailedData_p->notAlignedTotals.TotalTime_ns, allResultsDetailedData_p->results_superBig);

        totalAccum.totalTimes.TotalTime_ns = allResultsDetailedData_p->notAlignedTotals.TotalTime_ns;
        
                        
        //---------------------------------------
        //  ALIGNED
        //---------------------------------------

        if (testAligned) {            

            totalAccumAligned.totalTimes.AvrgSmallTime_ns = allResultsDetailedData_p->alignedTotals.AvrgSmallTime_ns = accumLambda(allResultsDetailedData_p->alignedTotals.TotalTime_ns, allResultsDetailedData_p->results_small_al);
            totalAccumAligned.totalTimes.AvrgBigTime_ns = allResultsDetailedData_p->alignedTotals.AvrgBigTime_ns = accumLambda(allResultsDetailedData_p->alignedTotals.TotalTime_ns, allResultsDetailedData_p->results_big_al);
            totalAccumAligned.totalTimes.AvrgSuperBigTime_ns = allResultsDetailedData_p->alignedTotals.AvrgSuperBigTime_ns = accumLambda(allResultsDetailedData_p->alignedTotals.TotalTime_ns, allResultsDetailedData_p->results_superBig_al);

            totalAccumAligned.totalTimes.TotalTime_ns = allResultsDetailedData_p->alignedTotals.TotalTime_ns;
        }

        // Finally we have the generic averages and the total. Now comes the second part - per type:
        auto perGroupLambda = [](SingleListResultsVect& singleResultsFromGroup, ResultsAveragedPerDataType& avrgResultForGroup, ResultsAveragedPerDataType& finalTestAccumulation){
            
            unsigned int cntr = 0;            

            for (auto& kvp : singleResultsFromGroup) // For each Type - RAND, SORTED, etc.
            {
                for (const auto& testRes : kvp.second) { // list all vectors values
                    avrgResultForGroup[kvp.first] += testRes.execTime;
                    cntr++;
                }
                if (0 < cntr) {
                    avrgResultForGroup[kvp.first] /= cntr;
                    finalTestAccumulation[kvp.first] = avrgResultForGroup[kvp.first];
                }
                else {
                    avrgResultForGroup[kvp.first] = 0; // the type initializes, but we better be sure this is a 0, hence the redundancy
                }
                cntr = 0;
            }
        };

        // here we have for each small/big/super_big   AND RAND/SORTED/etc - the averaged sum extracted from each SingleListResultsVector vector of values.
        perGroupLambda(allResultsDetailedData_p->results_small, allResultsDetailedData_p->AvrgSmall, totalAccum.resultsSmall);
        perGroupLambda(allResultsDetailedData_p->results_big, allResultsDetailedData_p->AvrgBig, totalAccum.resultsBig);
        perGroupLambda(allResultsDetailedData_p->results_superBig, allResultsDetailedData_p->AvrgSuperBig, totalAccum.resultsSuperBig);

        if (testAligned) {
            perGroupLambda(allResultsDetailedData_p->results_small_al, allResultsDetailedData_p->AvrgSmallAligned, totalAccumAligned.resultsSmall);
            perGroupLambda(allResultsDetailedData_p->results_big_al, allResultsDetailedData_p->AvrgBigAligned, totalAccumAligned.resultsBig);
            perGroupLambda(allResultsDetailedData_p->results_superBig_al, allResultsDetailedData_p->AvrgSuperBigAligned, totalAccumAligned.resultsSuperBig);
        }

        finAvrgNotAlignedAll.push_back(totalAccum);
        finAvrgAlignedAll.push_back(totalAccumAligned);

        ///********************************************************
        // 5. Final Results Printing:
        ///********************************************************

        detailedTextReport << endl << "*****************************************************" << endl;
        detailedTextReport << "Printing Final results !!! : " << endl;
        detailedTextReport << "*****************************************************" << endl;

        detailedTextReport << "Algorithm Name: " << algoNameStr << "  INFO: " << allResultsDetailedData_p->info << endl << endl;

        detailedTextReport << "Total Time NOT Aligned: " << convLng_ns(allResultsDetailedData_p->notAlignedTotals.TotalTime_ns) << endl;
        detailedTextReport << "Average Small Time NOT Aligned: " << convLng_ns(allResultsDetailedData_p->notAlignedTotals.AvrgSmallTime_ns) << endl;
        detailedTextReport << "Average Big Time NOT Aligned: " << convLng_ns(allResultsDetailedData_p->notAlignedTotals.AvrgBigTime_ns) << endl;
        detailedTextReport << "Average Super Big Time NOT Aligned: " << convLng_ns(allResultsDetailedData_p->notAlignedTotals.AvrgSuperBigTime_ns) << endl << endl;

        if (testAligned) {
            detailedTextReport << "Total Time Aligned: " << convLng_ns(allResultsDetailedData_p->alignedTotals.TotalTime_ns) << endl;
            detailedTextReport << "Average Small Time Aligned: " << convLng_ns(allResultsDetailedData_p->alignedTotals.AvrgSmallTime_ns) << endl;
            detailedTextReport << "Average Big Time Aligned: " << convLng_ns(allResultsDetailedData_p->alignedTotals.AvrgBigTime_ns) << endl;
            detailedTextReport << "Average Super Big Time Aligned: " << convLng_ns(allResultsDetailedData_p->alignedTotals.AvrgSuperBigTime_ns) << endl << endl;
        }

        unsigned long long checkGen = 0, checkGenAligned = 0;

        for (const auto& kv : allResultsDetailedData_p->AvrgSmall) {
            auto total = allResultsDetailedData_p->results_small[kv.first].size();
            detailedTextReport << "Small Tests: " << retStringTestDataType(kv.first) << ", Total: " << total << ", Average: " << convLng_ns(kv.second) << endl;
            checkGen += (total * kv.second);
        }

        for (const auto& kv : allResultsDetailedData_p->AvrgBig) {
            auto total = allResultsDetailedData_p->results_big[kv.first].size();
            detailedTextReport << "Big Tests " << retStringTestDataType(kv.first) << ", Total: " << total << ", Average: " << convLng_ns(kv.second) << endl;
            checkGen += (total * kv.second);
        }

        for (const auto& kv : allResultsDetailedData_p->AvrgSuperBig) {
            auto total = allResultsDetailedData_p->results_superBig[kv.first].size();
            detailedTextReport << "Super Big: " << retStringTestDataType(kv.first) << ", Total: " << total << ", Average: " << convLng_ns(kv.second) << endl;
            checkGen += (total * kv.second);
        }


        if (testAligned) {
            for (const auto& kv : allResultsDetailedData_p->AvrgSmallAligned) {
                auto total = allResultsDetailedData_p->results_small_al[kv.first].size();
                detailedTextReport << "Small Aligned: " << retStringTestDataType(kv.first) << ", Total: " << total << ", Average: " << convLng_ns(kv.second) << endl;
                checkGenAligned += (total * kv.second);
            }

            for (const auto& kv : allResultsDetailedData_p->AvrgBigAligned) {
                auto total = allResultsDetailedData_p->results_big_al[kv.first].size();
                detailedTextReport << "Big Aligned: " << retStringTestDataType(kv.first) << ", Total: " << total << ", Average: " << convLng_ns(kv.second) << endl;
                checkGenAligned += (total * kv.second);
            }

            for (const auto& kv : allResultsDetailedData_p->AvrgSuperBigAligned) {
                auto total = allResultsDetailedData_p->results_superBig_al[kv.first].size();
                detailedTextReport << "Super Big Aligned: " << retStringTestDataType(kv.first) << ", Total: " << total << ", Average: " << convLng_ns(kv.second) << endl;
                checkGenAligned += (total * kv.second);
            }
        }

        ///********************************************************
        // 6. Checking final errors:
        ///********************************************************

        int maxDeviationNanosec = MICROSECONDS_100_IN_NANOSEC;

        // Check the general time in ns - in particular - considering that the total time of testing takes at least several seconds - we allow error not bigger than 100 microseconds total
        if (std::abs(static_cast<long long int>(checkGen - allResultsDetailedData_p->notAlignedTotals.TotalTime_ns)) < maxDeviationNanosec) {            
            cout << "ITERATION " << cyclesCntr << " : Total sum of checked time for NOT Aligned tests OK: " << convLng_ns(checkGen) << endl;
            detailedTextReport << "ITERATION " << cyclesCntr << " : Total sum of checked time for NOT Aligned tests OK: " << convLng_ns(checkGen) << endl;
        }
        else {
            checkGenericNotAligned++;
            latestErr = " Fatal Error in total sum of NOT Aligned tests execution time against averages calculation!!!";
            cout << latestErr << endl;
            detailedTextReport << latestErr << endl;
        }

        if (testAligned) {
            if (std::abs(static_cast<long long int>(checkGenAligned - allResultsDetailedData_p->alignedTotals.TotalTime_ns)) < maxDeviationNanosec) {                
                cout << "ITERATION " << cyclesCntr << " : Total sum of checked time for Aligned tests OK: " << convLng_ns(checkGenAligned) << endl;
                detailedTextReport << "ITERATION " << cyclesCntr << " : Total sum of checked time for ALIGNED tests OK: " << convLng_ns(checkGenAligned) << endl;
            }
            else {
                checkGenericAligned++;
                latestErr = " Fatal Error in total sum of ALIGNED tests execution time against averages calculation!!!";
                cout << latestErr << endl;
                detailedTextReport << latestErr << endl;
            }
        }

        if (0 < errorCntrInput) {
            latestErr = " Critical error in INPUT! Number of wrong arrays: " + std::to_string(errorCntrInput) + "  out of total : " + std::to_string(totalTestsCurrCycle);
            cout << latestErr << endl;
            detailedTextReport << latestErr << endl;
        }

        if (0 < errorCntrOutput) {
            latestErr = " Critical error in OUTPUT RESULT! Number of wrong arrays: " + std::to_string(errorCntrOutput) + "  out of total : " + std::to_string(totalTestsCurrCycle);
            cout << latestErr << endl;
            detailedTextReport << latestErr << endl;
        }

        if (markCurrentAlgoSLOW || markCurrentAlgoSLOWaligned) {
            slowAlgo = " This Algorithm is TOO SLOW!";
            cout << " CRITICAL ERROR  - " << slowAlgo << endl;
            detailedTextReport << " CRITICAL ERROR  - " << slowAlgo << endl;
        }

        
        if ((0 < errorCntrOutput) || (0 < errorCntrInput) || (0 < checkGenericAligned) || (0 < checkGenericNotAligned) || markCurrentAlgoSLOW || markCurrentAlgoSLOWaligned) {
            completeTestErrFlag = true;
            cout << "Breaking Test Cycle after iteration " << cyclesCntr << "!\n";
            detailedTextReport << "Breaking Test Cycle after iteration " << cyclesCntr << "!\n";
            break;
        }
    }

    ///********************************************************
    // 7. Make averages for all runs
    ///********************************************************
    
    finalAverages_s finAvrgNotAligned;
    finalAverages_s finAvrgAligned;

    // checks! TODO FIX !!!! We need all numbers to be testCycles big!!!

    ///// ------------------------------------------------
    ///// NOT ALIGNED

    // Accumulating for NOT ALIGNED:
    for (auto& elem : finAvrgNotAlignedAll) {
        finAvrgNotAligned.totalTimes.TotalTime_ns += elem.totalTimes.TotalTime_ns;
        finAvrgNotAligned.totalTimes.AvrgSmallTime_ns += elem.totalTimes.AvrgSmallTime_ns;
        finAvrgNotAligned.totalTimes.AvrgBigTime_ns += elem.totalTimes.AvrgBigTime_ns;
        finAvrgNotAligned.totalTimes.AvrgSuperBigTime_ns += elem.totalTimes.AvrgSuperBigTime_ns;

        for (auto& type : elem.resultsSmall) {
            finAvrgNotAligned.resultsSmall[type.first] += type.second;
        }

        for (auto& type : elem.resultsBig) {
            finAvrgNotAligned.resultsBig[type.first] += type.second;
        }

        for (auto& type : elem.resultsSuperBig) {
            finAvrgNotAligned.resultsSuperBig[type.first] += type.second;
        }
    }

    // Averaging for NOT ALIGNED:
    finAvrgNotAligned.totalTimes.TotalTime_ns /= testCycles;
    finAvrgNotAligned.totalTimes.AvrgSmallTime_ns /= testCycles;
    finAvrgNotAligned.totalTimes.AvrgBigTime_ns /= testCycles;
    finAvrgNotAligned.totalTimes.AvrgSuperBigTime_ns /= testCycles;

    for (auto& elem : finAvrgNotAligned.resultsSmall) {
        elem.second /= testCycles;
    }

    for (auto& elem : finAvrgNotAligned.resultsBig) {
        elem.second /= testCycles;
    }

    for (auto& elem : finAvrgNotAligned.resultsSuperBig) {
        elem.second /= testCycles;
    }

    ///// ------------------------------------------------
    ///// ALIGNED

    if (testAligned) {
        // Accumulating for NOT ALIGNED:
        for (auto& elem : finAvrgAlignedAll) {
            finAvrgAligned.totalTimes.TotalTime_ns += elem.totalTimes.TotalTime_ns;
            finAvrgAligned.totalTimes.AvrgSmallTime_ns += elem.totalTimes.AvrgSmallTime_ns;
            finAvrgAligned.totalTimes.AvrgBigTime_ns += elem.totalTimes.AvrgBigTime_ns;
            finAvrgAligned.totalTimes.AvrgSuperBigTime_ns += elem.totalTimes.AvrgSuperBigTime_ns;

            for (auto& type : elem.resultsSmall) {
                finAvrgAligned.resultsSmall[type.first] += type.second;
            }

            for (auto& type : elem.resultsBig) {
                finAvrgAligned.resultsBig[type.first] += type.second;
            }

            for (auto& type : elem.resultsSuperBig) {
                finAvrgAligned.resultsSuperBig[type.first] += type.second;
            }
        }

        // Averaging For Aligned:
        finAvrgAligned.totalTimes.TotalTime_ns /= testCycles;
        finAvrgAligned.totalTimes.AvrgSmallTime_ns /= testCycles;
        finAvrgAligned.totalTimes.AvrgBigTime_ns /= testCycles;
        finAvrgAligned.totalTimes.AvrgSuperBigTime_ns /= testCycles;

        for (auto& elem : finAvrgAligned.resultsSmall) {
            elem.second /= testCycles;
        }

        for (auto& elem : finAvrgAligned.resultsBig) {
            elem.second /= testCycles;
        }

        for (auto& elem : finAvrgAligned.resultsSuperBig) {
            elem.second /= testCycles;
        }
    }


    // checks! TODO FIX !!!! We need all averages not to be bigger or smaller than the biggest or smallest!


    // Finally append the results to the report:
    if (completeTestErrFlag){
        if (latestErr.length()) {
            finalComparisonRes.append(algoNameStr + latestErr + ",\n");
            finalComparisonRes.append(algoNameStr + latestErr + " ALIGNED,\n");
        }
        else {
            if (slowAlgo.length()) {
                finalComparisonRes.append(algoNameStr + slowAlgo + ",\n");
                finalComparisonRes.append(algoNameStr + slowAlgo + " ALIGNED,\n");
            }
            else {
                cout << "\n*****************************\n CRITICAL ERROR IN TEST ERROR CONDITIONS EVALUATIONS! DEBUG IMMEDIATELY FRAMEWORK!!! Error marked present, but latestErr and slowAlgo strings are empty! \n*****************************\n ";
            }
        }
    }
    else {
        finalComparisonRes.append(algoNameStr + ",");
        finalComparisonRes.append(std::to_string(finAvrgNotAligned.totalTimes.TotalTime_ns) + ",");
        finalComparisonRes.append(std::to_string(finAvrgNotAligned.totalTimes.AvrgSmallTime_ns) + ",");
        finalComparisonRes.append(std::to_string(finAvrgNotAligned.totalTimes.AvrgBigTime_ns) + ",");
        finalComparisonRes.append(std::to_string(finAvrgNotAligned.totalTimes.AvrgSuperBigTime_ns) + ",");

        for (auto& elem : finAvrgNotAligned.resultsSmall) {
            finalComparisonRes.append(std::to_string(elem.second) + ",");
        }

        for (auto& elem : finAvrgNotAligned.resultsBig) {
            finalComparisonRes.append(std::to_string(elem.second) + ",");
        }

        for (auto& elem : finAvrgNotAligned.resultsSuperBig) {
            finalComparisonRes.append(std::to_string(elem.second) + ",");
        }

        finalComparisonRes.append("\n");

        if (testAligned) {

            // Finally append the results to the report:
            finalComparisonRes.append(algoNameStr + " ALIGNED,");
            finalComparisonRes.append(std::to_string(finAvrgAligned.totalTimes.TotalTime_ns) + ",");
            finalComparisonRes.append(std::to_string(finAvrgAligned.totalTimes.AvrgSmallTime_ns) + ",");
            finalComparisonRes.append(std::to_string(finAvrgAligned.totalTimes.AvrgBigTime_ns) + ",");
            finalComparisonRes.append(std::to_string(finAvrgAligned.totalTimes.AvrgSuperBigTime_ns) + ",");

            for (auto& elem : finAvrgAligned.resultsSmall) {
                finalComparisonRes.append(std::to_string(elem.second) + ",");
            }

            for (auto& elem : finAvrgAligned.resultsBig) {
                finalComparisonRes.append(std::to_string(elem.second) + ",");
            }

            for (auto& elem : finAvrgAligned.resultsSuperBig) {
                finalComparisonRes.append(std::to_string(elem.second) + ",");
            }

            finalComparisonRes.append("\n");
        }
    }

    ///********************************************************
    // 8. Finally eavluate completely the test - no error shall be delivered in order to have a valid test:
    ///********************************************************
    if (!completeTestErrFlag) {
        cout << " TEST SUCCESSFUL !!! Total runs to average : " << testCycles << endl;
        detailedTextReport << " TEST SUCCESSFUL !!! Total runs to average : " << testCycles << endl;
    }
    else {
        cout << " TEST ERROR !!! " << endl;
        detailedTextReport << " TEST ERROR !!! " << endl;
    }

    detailedTextReport.flush();
    detailedTextReport.close();

    if (saveToCsvPerRun) {
        saveToCsvFilePerRun(singleAlgoAllRunsResults, algoNameStr);
    }

}
void TestExecutor::saveFinalSummary() {
    std::ofstream outFileFinalSummary("Results_Summary_ALL_Algorithms_" + std::to_string(getTime_Since_Epoch_ns().count()) + ".csv");
    outFileFinalSummary << finalComparisonRes;
    outFileFinalSummary.flush();
    outFileFinalSummary.close();
}

// then all the results shall be saved in a csv file
void  TestExecutor::saveToCsvFilePerRun(vector<ResultsDescriptor> &singleAlgoAllRunsResults, std::string algoName) {

    std::ofstream outFileDetailed("Results_Summary_Detailed_RUNS_" + algoName + "_" + std::to_string(getTime_Since_Epoch_ns().count()) + ".csv");

    outFileDetailed << csvHeaderLine;

    for (auto& result : singleAlgoAllRunsResults) {

        outFileDetailed << algoName << "," << result.notAlignedTotals.TotalTime_ns << "," << result.notAlignedTotals.AvrgSmallTime_ns << "," << result.notAlignedTotals.AvrgBigTime_ns << "," << result.notAlignedTotals.AvrgSuperBigTime_ns << ",";

        for (const auto& c : TestDataTypes) {
            outFileDetailed << result.AvrgSmall[c] << ", ";
        }
        for (const auto& c : TestDataTypes) {
            outFileDetailed << result.AvrgBig[c] << ", ";
        }
        for (const auto& c : TestDataTypes) {
            outFileDetailed << result.AvrgSuperBig[c] << ", ";
        }

        outFileDetailed << endl;


        outFileDetailed << algoName + " ALIGNED " << "," << result.alignedTotals.TotalTime_ns << "," << result.alignedTotals.AvrgSmallTime_ns << "," << result.alignedTotals.AvrgBigTime_ns << "," << result.alignedTotals.AvrgSuperBigTime_ns << ",";

        for (const auto& c : TestDataTypes) {
            outFileDetailed << result.AvrgSmallAligned[c] << ", ";
        }
        for (const auto& c : TestDataTypes) {
            outFileDetailed << result.AvrgBigAligned[c] << ", ";
        }
        for (const auto& c : TestDataTypes) {
            outFileDetailed << result.AvrgSuperBigAligned[c] << ", ";
        }

        outFileDetailed << endl;
    }

    outFileDetailed.flush();
    outFileDetailed.close();
}

///**********************************************************************************///
///**********************************************************************************///

void memoryOverFlowException(int* A, unsigned int n) {
    int * errorArr = new int[20];
    for (int a = 0; a < n; a++) {
        errorArr[a] = A[a];
    }

    QuickSortDualPivot_Yaroslavskiy(A, n);

    for (int a = 0; a < n; a++) {
        errorArr[a] = A[a];
    }
}


void badTypeIdException(int* A, unsigned int n) {
    void * p = nullptr;
    // std::cout << typeid(*p).name() << '\n';
    QuickSortDualPivot_Yaroslavskiy(A, n);
    // std::cout << typeid(*p).name() << '\n';
}

// Single tests for basic evaulation:
int testArr1[20] = { 2, 13,27, 6, 7, 9, 12, 5, 18, 44, 32, 67, 49, 55, 9, 12, 3, 5, 7, 0 };
int testArr2[21] = { 2, 13,27, 6, 7, 9, 12, 5, 18, 44, 32, 67, 49, 55, 9, 12, 3, 5, 23, 0, 1 };
int testArr3[41] = { 2, 13,27, 6, 7, 9, 12, 5, 18, 44, 32, 67, 49, 55, 9, 12, 3, 5, 7, 0, 2, 13,27, 6, 7, 9, 12, 5, 18, 44, 32, 67, 49, 55, 9, 12, 3, 5, 23, 0, 1 };

int main(void)// int argc, char *argv[])
{

    auto totalTime = getTime_Since_Epoch_ns();

    // slowestBubbleSort(testArr1, 20);
    /*
    // QuickSortDualPivotRusev(testArr1, 20);
    // QuicksortSinglePivotWithCheck(testArr1, 20);
    // QuicksortSinglePivot_RusevOptimized(testArr2, 21);
    // RusevMergeSort128(arrayNonRepeat_Shuffled_NotAligned_512.arr, SIZE_Non_Rep_Shuffled512);
    // blocked_double_pivot_check_mosqrt_sort(testArr1, 20);
    // QuickSortDualPivot_Qsort3_aumueller(testArr2, 21);

    slowestBubbleSort(testArr1, 20);
    svpv_stdlib_isort(testArr2, 21);
    svpv_stl_isort(testArr3, 41);
    svpv_isort_qsort(testArr1, 20);

    cout << "Binary Search in testArr3 for 5  idx result: " << binarySearch(testArr1, 0, 19, 5) << endl;
    cout << "Binary Search in testArr3 for 5  idx result: " << binarySearch(testArr2, 0, 20, 5) << endl;
    cout << "Binary Search in testArr3 for 5  idx result: " << binarySearch(testArr3, 0, 40, 5) << endl;
    */

    /*
    sortNumsInsertionMin2(testArr1,20);
    printArray(testArr1, 20);
    sortNumsInsertionMin2(testArr2,21);
    printArray(testArr2, 21);
    sortNumsInsertionMin2(testArr3,41);
    printArray(testArr3, 41);

    int test41[4] = {0,3,7,9};
    int test42[4] = {9,7,3,0};
    int test43[4] = {9,3,7,0};
    int test44[4] = {3,3,9,7};
    int test45[4] = {0,3,3,1};

    sort0_to_4NumsWithIfs(test41,4);
    printArray(test41, 4);
    sort0_to_4NumsWithIfs(test42,4);
    printArray(test42, 4);
    sort0_to_4NumsWithIfs(test43,4);
    printArray(test43, 4);
    sort0_to_4NumsWithIfs(test44,4);
    printArray(test44, 4);
    sort0_to_4NumsWithIfs(test45,4);
    printArray(test45, 4);



    int test31[3] = { 0,3,7 };
    int test32[3] = { 9,7,3 };
    int test33[3] = { 9,3,7 };
    int test34[3] = { 3,3,0 };
    sort3NumsWithIfsRusev(test31,3);
    printArray(test31, 3);
    sort3NumsWithIfsRusev(test32,3);
    printArray(test32, 3);
    sort3NumsWithIfsRusev(test33,3);
    printArray(test33, 3);
    sort3NumsWithIfsRusev(test34,3);
    printArray(test34, 3);

    int test51[4] = { 0,3,7,9 };
    int test52[4] = { 9,7,3,0 };
    int test53[4] = { 9,3,7,0 };
    int test54[4] = { 3,3,9,7 };
    int test55[4] = { 0,3,3,1 };

    sort4NumsWithIfsRusev(test51, 4);
    printArray(test51, 4);
    sort4NumsWithIfsRusev(test52, 4);
    printArray(test52, 4);
    sort4NumsWithIfsRusev(test53, 4);
    printArray(test53, 4);
    sort4NumsWithIfsRusev(test54, 4);
    printArray(test54, 4);
    sort4NumsWithIfsRusev(test55, 4);
    printArray(test55, 4);

    std::cout << "\n -----------------\n TESTING THE 8 !!! \n";
    int test81[8] = { 0,3,7,9, 12,15,16,16 }; // wr
    int test82[8] = { 9,7,3,0, 3,3,0,0 };
    int test83[8] = { 9,3,7,0, 4, 4, 4, 4};
    int test84[8] = { 3,3,9,7, 10, 10, 10, 10};
    int test85[8] = { 0,3,3,1, 2, 6, 9, 2}; // wr
    int test86[8] = { 0,3,3,1, -5, 13, -10, 99}; // wr
    int test87[8] = { 2,6,2,6, 2,6,2,6};
    int test88[8] = { 1,1,1,1, 1,1,1,1 };

    sort8NumsWithIfsRusev(test81,8); // wr
    printArray(test81, 8);
    sort8NumsWithIfsRusev(test82,8);
    printArray(test82, 8);
    sort8NumsWithIfsRusev(test83,8);
    printArray(test83, 8);
    sort8NumsWithIfsRusev(test84,8);
    printArray(test84, 8);
    sort8NumsWithIfsRusev(test85,8);
    printArray(test85, 8);
    sort8NumsWithIfsRusev(test86,8); // wr
    printArray(test86, 8);
    sort8NumsWithIfsRusev(test87,8);
    printArray(test87, 8);
    sort8NumsWithIfsRusev(test88,8);
    printArray(test88, 8);


    std::cout << "\n -----------------\n TESTING THE 16 !!! \n";
    int test161[16] = { 0,3,7,9, 12,15,16,16, 0,3,7,9, 12,15,16,16 };
    int test162[16] = { 9,7,3,0, 3,3,0,0, 9,7,3,0, 3,3,0,0 };
    int test163[16] = { 9,3,7,0, 4, 4, 4, 4, 9,3,7,0, 4, 4, 4, 4 };
    int test164[16] = { 3,3,9,7, 10, 10, 10, 10, 3,3,9,7, 10, 10, 10, 10 };
    int test165[16] = { 0,3,3,1, 2, 6, 9, 2, 0,3,3,1, 2, 6, 9, 2 };
    int test166[16] = { 0,3,3,1, -5, 13, -10, 99, 0,3,3,1, -5, 13, -10, 99 };
    int test167[16] = { 2,6,2,6, 2,6,2,6, 2,6,2,6, 2,6,2,6 };
    int test168[16] = { 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1 };

    sort16NumsWithIfsRusev(test161, 16); // wr
    printArray(test161, 16);
    sort16NumsWithIfsRusev(test162, 16);
    printArray(test162, 16);
    sort16NumsWithIfsRusev(test163, 16);
    printArray(test163, 16);
    sort16NumsWithIfsRusev(test164, 16);
    printArray(test164, 16);
    sort16NumsWithIfsRusev(test165, 16);
    printArray(test165, 16);
    sort16NumsWithIfsRusev(test166, 16); // wr
    printArray(test166, 16);
    sort16NumsWithIfsRusev(test167, 16);
    printArray(test167, 16);
    sort16NumsWithIfsRusev(test168, 16);
    printArray(test168, 16);
    */


    /*
    std::cout << "\n -----------------\n TESTING THE 32 !!! \n";
    int test321[32] = { 0,3,7,9, 12,15,16,16, 0,3,7,9, 12,15,16,16,  0,3,7,9, 12,15,16,16, 0,3,7,9, 12,15,16,16 };
    int test322[32] = { 9,7,3,0, 3,3,0,0, 9,7,3,0, 3,3,0,0,   9,7,3,0, 3,3,0,0, 9,7,3,0, 3,3,0,0 };
    int test323[32] = { 9,3,7,0, 4, 4, 4, 4, 9,3,7,0, 4, 4, 4, 4,  9,3,7,0, 4, 4, 4, 4, 9,3,7,0, 4, 4, 4, 4 };
    int test324[32] = { 3,3,9,7, 10, 10, 10, 10, 3,3,9,7, 10, 10, 10, 10,  3,3,9,7, 10, 10, 10, 10, 3,3,9,7, 10, 10, 10, 10 };
    int test325[32] = { 0,3,3,1, 2, 6, 9, 2, 0,3,3,1, 2, 6, 9, 2,  0,3,3,1, 2, 6, 9, 2, 0,3,3,1, 2, 6, 9, 2 };
    int test326[32] = { 0,3,3,1, -5, 13, -10, 99, 0,3,3,1, -5, 13, -10, 99,  0,3,3,1, -5, 13, -10, 99, 0,3,3,1, -5, 13, -10, 99 };
    int test327[32] = { 2,6,2,6, 2,6,2,6, 2,6,2,6, 2,6,2,6,  2,6,2,6, 2,6,2,6, 2,6,2,6, 2,6,2,6 };
    int test328[32] = { 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,   1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1 };
    */

    /*
    printArray(test321, 32);
    RusevSwapSort4_ImprovedIfsV2(test321, 32);
    printArray(test321, 32);
    cout << endl;

    printArray(test322, 32);
    RusevSwapSort4_ImprovedIfsV2(test322, 32);
    printArray(test322, 32);
    cout << endl;

    printArray(test323, 32);
    RusevSwapSort4_ImprovedIfsV2(test323, 32);
    printArray(test323, 32);
    cout << endl;
    
    printArray(test324, 32);
    RusevSwapSort4_ImprovedIfsV2(test324, 32);
    printArray(test324, 32);
    cout << endl;
    
    printArray(test325, 32);
    RusevSwapSort4_ImprovedIfsV2(test325, 32);
    printArray(test325, 32);
    cout << endl;
    
    printArray(test326, 32);
    RusevSwapSort4_ImprovedIfsV2(test326, 32);
    printArray(test326, 32);
    cout << endl;
    
    printArray(test327, 32);
    RusevSwapSort4_ImprovedIfsV2(test327, 32);
    printArray(test327, 32);
    cout << endl;
    
    
    printArray(test328, 32);
    RusevSwapSort4_ImprovedIfsV2(test328, 32);
    printArray(test328, 32);
    cout << endl;
        */
    /*
    void RusevUltraSwapSort4(int arr[], unsigned int size);
    void RusevSwapSort4_ImprovedIfs(int arr[], unsigned int size);
    void RusevSwapSort4_Original(int arr[], unsigned int size);
    */


    /*
    printArray(test321, 32);
    RusevSwapSort4_ImprovedIfs_32_V3(test321, 32);
    printArray(test321, 32); cout << endl;

    printArray(test322, 32);
    RusevSwapSort4_ImprovedIfs_32_V3(test322, 32);
    printArray(test322, 32); cout << endl;

    printArray(test323, 32);
    RusevSwapSort4_ImprovedIfs_32_V3(test323, 32);
    printArray(test323, 32); cout << endl;
    
    printArray(test324, 32);
    RusevSwapSort4_ImprovedIfs_32_V3(test324, 32);
    printArray(test324, 32); cout << endl;
    
    printArray(test325, 32);
    RusevSwapSort4_ImprovedIfs_32_V3(test325, 32);
    printArray(test325, 32); cout << endl;
    
    printArray(test326, 32);
    RusevSwapSort4_ImprovedIfs_32_V3(test326, 32);
    printArray(test326, 32); cout << endl;
    
    printArray(test327, 32);
    RusevSwapSort4_ImprovedIfs_32_V3(test327, 32);
    printArray(test327, 32); cout << endl;
    
    printArray(test328, 32);
    RusevSwapSort4_ImprovedIfs_32_V3(test328, 32);
    printArray(test328, 32); cout << endl;
    */



    pout << "\n";
    std::cout << alignof(std::max_align_t) << '\n';
    cout << "SYSTEM DATA : " << endl;
    cout << " LONG_MAX : " << LONG_MAX << endl;
    cout << " UINT_MAX : " << UINT_MAX << endl;
    cout << " INT_MAX : " << INT_MAX << endl;
    cout << " ULLONG_MAX : " << ULLONG_MAX << endl;

    const unsigned int RUNS_PER_ALGO = 20;

     // Now doing the calls for Rusev sort:
    bool saveToCsvPerRun = true;
    bool enableTimeLimit = true;
    
    TestExecutor testObj(RUNS_PER_ALGO, TestExecutionLength::LONG, TestSelection::ALL, saveToCsvPerRun, enableTimeLimit);


    /*
    testObj.multiTestDynamicData(AlgorithmID::RusevUltraBasedOn4Rusev, "", RusevUltraBasedOn4Rusev<32>);
    testObj.multiTestDynamicData(AlgorithmID::RusevUltraBasedOn4RusevV2, "", RusevUltraBasedOn4RusevV2<32>);
    */

    testObj.multiTestDynamicData(AlgorithmID::stl_StableSort, "", stl_StableSort);
    testObj.multiTestDynamicData(AlgorithmID::stl_sortRegular, "", stl_sortRegular);
    /*
    testObj.multiTestDynamicData(AlgorithmID::svpv_stdlib_isort, "", svpv_stdlib_isort);    
    // testObj.multiTestDynamicData(AlgorithmID::Other, "", memoryOverFlowException);
    // testObj.multiTestDynamicData(AlgorithmID::Other, "", badTypeIdException);
    testObj.multiTestDynamicData(AlgorithmID::QuickSortDualPivot_Yaroslavskiy, "", QuickSortDualPivot_Yaroslavskiy);
    testObj.multiTestDynamicData(AlgorithmID::QuickSortDualPivot_Qsort3_aumueller, "", QuickSortDualPivot_Qsort3_aumueller);


    testObj.multiTestDynamicData(AlgorithmID::RusevUltraBasedOn4_V3_integral, "", RusevUltraBasedOn4_V3_integral<32>);

    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSortBasedOn2_3rd_merge_improve, "", RusevMergeSortBasedOn2_3rd_merge_improve<32>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSortBasedOn4_3rd_merge_improve, "", RusevMergeSortBasedOn4_3rd_merge_improve<32>);


    
    testObj.multiTestDynamicData(AlgorithmID::RusevSwapSort2, "", RusevSwapSort2);
    testObj.multiTestDynamicData(AlgorithmID::RusevSwapSort2ImprIdx, "", RusevSwapSort2ImprIdx);
    testObj.multiTestDynamicData(AlgorithmID::RusevSwapSort2withCheck, "", RusevSwapSort2withCheck);
    testObj.multiTestDynamicData(AlgorithmID::RusevSwapSort2withCheckImprIdx, "", RusevSwapSort2withCheckImprIdx);
    testObj.multiTestDynamicData(AlgorithmID::RusevSwapSort4, "", RusevSwapSort4);
    testObj.multiTestDynamicData(AlgorithmID::RusevSwapSort4fullWithCheck, "", RusevSwapSort4fullWithCheck);
    testObj.multiTestDynamicData(AlgorithmID::RusevSwapSort4fullWithCheckAndVolatile, "", RusevSwapSort4fullWithCheckAndVolatile);
    


    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort32basedOn2, "", RusevMergeSortBasedOn2<32>);   
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort32basedOn4_2, "", RusevMergeSortBasedOn4_2<32>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSortBasedOn2_32StaticStacksNoOpt, "", RusevMergeSortBasedOn2_32StaticStacksNoOpt);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED, "", RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED);
    */
    /*
    testObj.multiTestDynamicData(AlgorithmID::QuicksortSinglePivotWithCheck, "", QuicksortSinglePivotWithCheck);
    testObj.multiTestDynamicData(AlgorithmID::QuicksortSinglePivot_RusevOptimized, "", QuicksortSinglePivot_RusevOptimized);
    testObj.multiTestDynamicData(AlgorithmID::QuickSortDualPivotRusev_WithCheck, "", QuickSortDualPivotRusev_WithCheck);
    // SUPER SLOW - 60 seconds per test
    testObj.multiTestDynamicData(AlgorithmID::blocked_double_pivot_check_mosqrt_sort, "", blocked_double_pivot_check_mosqrt_sort);

    testObj.multiTestDynamicData(AlgorithmID::QuickSortDualPivot, "", QuickSortDualPivot);

    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort64basedOn2, "", RusevMergeSortBasedOn2<64>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort64basedOn4_2, "", RusevMergeSortBasedOn4_2<64>);
    
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort128basedOn2, "", RusevMergeSortBasedOn2<128>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort128basedOn4_2, "", RusevMergeSortBasedOn4_2<128>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort256basedOn2, "", RusevMergeSortBasedOn2<256>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort256basedOn4_2, "", RusevMergeSortBasedOn4_2<256>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort512basedOn2, "", RusevMergeSortBasedOn2<512>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort512basedOn4_2, "", RusevMergeSortBasedOn4_2<512>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort1024basedOn2, "", RusevMergeSortBasedOn2<1024>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort1024basedOn4_2, "", RusevMergeSortBasedOn4_2<1024>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort2048basedOn2, "", RusevMergeSortBasedOn2<2048>);
    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSort2048basedOn4_2, "", RusevMergeSortBasedOn4_2<2048>);
    */
    /*

    testObj.multiTestDynamicData(AlgorithmID::RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED_Dyn, "", RusevMergeSortBasedOn2_32StaticStacksOPTIMIZED_Dyn);
    testObj.multiTestDynamicData(AlgorithmID::timSort_Rusev, "", timSort_Rusev);
    testObj.multiTestDynamicData(AlgorithmID::timSort_Rusev_With_Checks, "", timSort_Rusev_With_Checks);
    testObj.multiTestDynamicData(AlgorithmID::timSort_Rusev_With_Checks_imprMerge, "", timSort_Rusev_With_Checks_imprMerge);
    testObj.multiTestDynamicData(AlgorithmID::timSort_Rusev_WithMerge, "", timSort_Rusev_WithMerge);
    
    testObj.multiTestDynamicData(AlgorithmID::QuickSortDualPivotRusevMerge, "", QuickSortDualPivotRusevMerge);
    testObj.multiTestDynamicData(AlgorithmID::QuickSortDualPivotRusevMerge_3rd_merge_improve, "", QuickSortDualPivotRusevMerge_3rd_merge_improve);
    testObj.multiTestDynamicData(AlgorithmID::QuickSortDualPivotMerge, "", QuickSortDualPivotMerge);
    testObj.multiTestDynamicData(AlgorithmID::svpv_stl_isort, "", svpv_stl_isort);
    testObj.multiTestDynamicData(AlgorithmID::svpv_isort_qsort, "", svpv_isort_qsort);
    testObj.multiTestDynamicData(AlgorithmID::svpv_stl_isort_RusevMerge, "", svpv_stl_isort_RusevMerge);
    testObj.multiTestDynamicData(AlgorithmID::svpv_isort_qsort_RusevMerge, "", svpv_isort_qsort_RusevMerge);    
    
    */
    testObj.saveFinalSummary();
    
    totalTime = getTime_Since_Epoch_ns() - totalTime;
    cout << "\n-------------------------------------------------------------------------\n";

    cout << "Total Execution Time : " << convLng_ns(totalTime.count()) << endl;
        
    auto break_key = "b";
    char input;

    do { 
        cout << " Press \"b\" and hit \"Enter\" to end the program! \n"; 
        cin.get(input); 
    } while (input != *break_key);

    return 0;
}
