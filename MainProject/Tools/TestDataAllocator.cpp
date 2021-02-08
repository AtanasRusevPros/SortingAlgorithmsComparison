/*
* Atanas Rusev Sorting Algorithms Comparison Project
*
* \file TestDataAllocator.cpp
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
*  \brief Source of insertion of all generated data arrays to the test vectors.
*  \details For full explanation on why and how this project was designed please
*     check the pdf version of the accompanying article in the docs directory
*
*  \author Atanas Georgiev Rusev (https://github.com/AtanasRusevPros)
*  \author Please add your name for additional contributions
*
*/

#include "TestDescriptor.h"

#include "../Test Data/Generated_Arrays_Includes.h"

#include <iostream>


TestData::TestData(unsigned long long maxTestDataBytes, targetHwListing hw_, targetMachineListing mach_, targetCompilerListing cmpl_, targetOsListing os_, TestSelection sel, TestExecutionLength length) : m_hw(hw_), m_machine(mach_), m_compiler(cmpl_), m_os(os_), m_maxBytes(maxTestDataBytes){
    
    // check for number of elements is at each test addition!

    initAllTests(length);

    switch (sel) {
        case TestSelection::ALL : {
            if (length == TestExecutionLength::LONG) {
                testVectAligned = testVectAligned_all;
                testVect = testVect_all;
                break;
            } else if (length == TestExecutionLength::NORMAL) {
                for (auto test : testVect_all) {
                    if (test->sizeClass != TestDataSizeType::SUPER_BIG_2096128)
                        addNotAlignedTest(test);
                }

                for (auto test : testVectAligned_all) {
                    if (test->sizeClass != TestDataSizeType::SUPER_BIG_2096128)
                        addAlignedTest(test);
                }
                break;
            } else {
                for (auto test : testVect_all) {
                    if (test->sizeClass == TestDataSizeType::SMALL_32_2050)
                        addNotAlignedTest(test);
                }

                for (auto test : testVectAligned_all) {
                    if (test->sizeClass == TestDataSizeType::SMALL_32_2050)
                        addAlignedTest(test);
                }
                break;
            }
            break;
        }

        case TestSelection::SPECIAL_SHORT_SELECTED_512: {

            addNotAlignedTest(&arrayRAND_Repeats_NotAligned_512_c);
            break;
        }
        case TestSelection::ONLY_EQUALS_SHORT :{
            testVect.reserve(20);
            testVectAligned.reserve(20);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_32_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_32_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_37_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_37_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_64_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_64_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_128_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_128_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_256_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_256_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_512_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_512_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_1024_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_1024_c);


            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_32_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_32_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_37_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_37_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_64_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_64_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_128_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_128_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_256_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_256_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_512_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_512_c);
            break;
        }

    case TestSelection::ONLY_DIVISIBLE_BY_4_NORMAL :{
        testVect.reserve(100);

        addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_32_c);
        addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_64_c);
        addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_128_c);
        addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_256_c);
        addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_512_c);
        addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_1024_c);
        addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_2048_c);

        addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_32768_c);

        if (TestExecutionLength::LONG == length){
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_65536_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_131072_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_524288_c);
        }



        addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_32_c);
        addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_64_c);
        addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_128_c);
        addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_256_c);
        addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_512_c);
        addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_1024_c);
        addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_2048_c);

        addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_32768_c);

        if (TestExecutionLength::LONG == length){
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_65536_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_131072_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_524288_c);
        }

        addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_32_c);
        addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_64_c);
        addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_128_c);
        addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_256_c);
        addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_512_c);
        addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_1024_c);
        addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_2048_c);

        addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_32768_c);

        if (TestExecutionLength::LONG == length){
            addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_65536_c);
            addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_131072_c);
            addNotAlignedTest(&arrayNonRepeat_Shuffled_NotAligned_524288_c);
        }

        addNotAlignedTest(&arrayRAND_Repeats_NotAligned_32_c);
        addNotAlignedTest(&arrayRAND_Repeats_NotAligned_64_c);
        addNotAlignedTest(&arrayRAND_Repeats_NotAligned_128_c);
        addNotAlignedTest(&arrayRAND_Repeats_NotAligned_256_c);
        addNotAlignedTest(&arrayRAND_Repeats_NotAligned_512_c);
        addNotAlignedTest(&arrayRAND_Repeats_NotAligned_1024_c);
        addNotAlignedTest(&arrayRAND_Repeats_NotAligned_2048_c);

        addNotAlignedTest(&arrayRAND_Repeats_NotAligned_32768_c);

        if (TestExecutionLength::LONG == length){
            addNotAlignedTest(&arrayRAND_Repeats_NotAligned_65536_c);
            addNotAlignedTest(&arrayRAND_Repeats_NotAligned_131072_c);
            addNotAlignedTest(&arrayRAND_Repeats_NotAligned_524288_c);
        }


        addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_32_c);
        addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_64_c);
        addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_128_c);
        addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_256_c);
        addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_512_c);
        addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_1024_c);
        addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_2048_c);

        addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_32768_c);

        if (TestExecutionLength::LONG == length){
            addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_65536_c);
            addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_131072_c);
            addNotAlignedTest(&arrayNonRepeatSorted_SomeZeroes_NotAligned_524288_c);
        }

        addNotAlignedTest(&arrayOne_EqualNum_NotAligned_32_c);
        addNotAlignedTest(&arrayOne_EqualNum_NotAligned_64_c);
        addNotAlignedTest(&arrayOne_EqualNum_NotAligned_128_c);
        addNotAlignedTest(&arrayOne_EqualNum_NotAligned_256_c);
        addNotAlignedTest(&arrayOne_EqualNum_NotAligned_512_c);
        addNotAlignedTest(&arrayOne_EqualNum_NotAligned_1024_c);

        addNotAlignedTest(&arrayOne_EqualNum_NotAligned_2048_c);
        addNotAlignedTest(&arrayOne_EqualNum_NotAligned_32768_c);

        if (TestExecutionLength::LONG == length){
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_65536_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_131072_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_524288_c);
        }

        addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_32_c);
        addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_64_c);
        addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_128_c);
        addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_256_c);
        addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_512_c);


        addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_1024_c);
        addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_2048_c);
        addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_32768_c);


        if (TestExecutionLength::LONG == length){
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_65536_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_131072_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_524288_c);
        }


        break;
    }
        case TestSelection::ONLY_SORTED_SHORT :{
            testVect.reserve(10);
            testVectAligned.reserve(10);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_32_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_32_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_37_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_37_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_64_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_64_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_128_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_128_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_256_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_256_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_512_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_512_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_1024_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_1024_c);
            break;
        }
        case TestSelection::ONLY_REV_SORTED_SHORT :{
            testVect.reserve(10);
            testVectAligned.reserve(10);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_32_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_32_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_37_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_37_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_64_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_64_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_128_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_128_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_256_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_256_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_512_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_512_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_1024_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_1024_c);
            break;
        }

        case TestSelection::REV_AND_EQUALS_SORTED_SHORT: {
            testVect.reserve(40);
            testVectAligned.reserve(40);

            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_32_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_32_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_37_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_37_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_64_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_64_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_128_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_128_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_256_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_256_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_512_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_512_c);
            addNotAlignedTest(&arrayOne_EqualNum_NotAligned_1024_c);
            addAlignedTest(&arrayOne_EqualNum_Aligned_1024_c);


            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_32_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_32_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_37_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_37_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_64_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_64_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_128_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_128_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_256_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_256_c);
            addNotAlignedTest(&arrayOne_EqualNumZeroes_NotAligned_512_c);
            addAlignedTest(&arrayOne_EqualNumZeroes_Aligned_512_c);



            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_32_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_32_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_37_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_37_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_64_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_64_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_128_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_128_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_256_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_256_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_512_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_512_c);
            addNotAlignedTest(&arrayNonRepeatSorted_NotAligned_1024_c);
            addAlignedTest(&arrayNonRepeatSorted_Aligned_1024_c);

            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_32_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_32_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_37_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_37_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_64_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_64_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_128_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_128_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_256_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_256_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_512_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_512_c);
            addNotAlignedTest(&arrayNonRepeat_REVERSE_Sorted_NotAligned_1024_c);
            addAlignedTest(&arrayNonRepeat_REVERSE_Sorted_Aligned_1024_c);
            break;
        }
                                                  
        default: {
            std::cout << "\n !!!!! FATAL ERROR DURING TESTS INITIALIZATION !!!  \n\n \n ";
            break;
        }
    }

};

void TestData::addNotAlignedTest(SingleTestContainer* newTest) {
    if (newTest->byteSize <= m_maxBytes) {
        testVect.push_back(newTest);
    }
    else {
        std::cout << "Error : Excluding this test due to size too big:" << newTest->info << std::endl;
    }
}
void TestData::addAlignedTest(SingleTestContainer* newTest) {
    if (newTest->byteSize <= m_maxBytes) {
        testVectAligned.push_back(newTest);
    }
    else {
        std::cout << "Error : Excluding this test due to size too big:" << newTest->info << std::endl;
    }
}

void TestData::addNotAlignedTest_All(SingleTestContainer* newTest) {
    if (newTest->byteSize <= m_maxBytes) {
        testVect_all.push_back(newTest);
    }
    else {
        std::cout << "Error : Excluding this test due to size too big:" << newTest->info << std::endl;
    }
}
void TestData::addAlignedTest_All(SingleTestContainer* newTest) {
    if (newTest->byteSize <= m_maxBytes) {
        testVectAligned_all.push_back(newTest);
    }
    else {
        std::cout << "Error : Excluding this test due to size too big:" << newTest->info << std::endl;
    }
}
void TestData::initAllTests(TestExecutionLength length){

    testVect.reserve(256);
    testVectAligned.reserve(256);


#include "../Test Data/Generated_Arrays_ContainList_ALL.h"
}
