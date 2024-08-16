/*
* Atanas Rusev Sorting Algorithms Comparison Project
* 
* \file TestDescriptor.h 
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

#ifndef TESTDESCRIPTOR_H
#define TESTDESCRIPTOR_H

#include <iostream>
#include <string>

#include <vector>


typedef struct {
    char offsetData[92];
}Offset_Struct_92Bytes_t;

 
#define DATA_CONTAINER_64MB_VAL 67108864
#define DATA_CONTAINER_64MB 16777216 // 67108864/4
#define DATA_CONTAINER_16MB 4194304 // 16777216/4
#define DATA_CONTAINER__8MB 2097152 // 2097152*4 (max array 2097152 - 2096128 = 1024)
#define DATA_CONTAINER_MAX_ELEMENTS DATA_CONTAINER__8MB
#define offset_alignment {{0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, \
                0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,\
                0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,\
                0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,\
                0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,\
                0,0,0,0, 0,0,0,0, 0,0,0,0 }}


typedef struct mtDataNotAligned_s {
    Offset_Struct_92Bytes_t off;
    int arr[DATA_CONTAINER_MAX_ELEMENTS]; // 8 MB !
}mtDataNotAligned_t;


enum class TestDataType {
    RAND_with_Repeats = 0,
    REV_SORTED = 1,
    RAND_NO_REPEATS_SHUFFLED = 2,
    SORTED = 3,
    SORTED_WITH_SOME_ZEROES_INSERTED = 4,
    ONE_NUMBER = 5,
    ONLY_ZEROES = 6,
    First=RAND_with_Repeats,
    Last=ONLY_ZEROES
};

enum class TestDataType_ERROR {
    ARRAY_OK,
    RAND_ARRAY_NOT_RAND,
    REV_SORTED_NOT_REVERSE_SORTED,
    SORTED_NOT_SORTED
};

enum class TestDataSizeType {
    SMALL_32_2050,
    BIG_32768_524288,
    SUPER_BIG_2096128,
    GIGA_BIG_2147483648,
    TERA_BIG_1099511627776,
};

enum class TestDataAlignment {
    ALIGNED,
    NOT_ALIGNED
};


enum class TestExecutionLength {
    SHORT,
    NORMAL,
    LONG
};


enum class TestSelection {
    ALL,
    ONLY_SHUFFLED_NO_SORTED_REV,
    ONLY_EQUALS_SHORT,
    ONLY_SORTED_SHORT,
    ONLY_REV_SORTED_SHORT,
    ONLY_DIVISIBLE_BY_4_NORMAL,
    REV_AND_EQUALS_SORTED_SHORT,
    SPECIAL_SHORT_SELECTED_512
};



enum class targetHwListing : unsigned int {
    Intel_Celeron_J1800, // Intel_Celeron_J1800_2_4_Ghz_2_Core_64bit_1MB_L2_Cache_RAM_4GB_DDR3_1333,
    Intel_Xeon2630, // Intel_Xeon2630_3_Ghz_6_Core_64bit_15MB_L3_Cache_Bit_24_GB_RAM_DDR3_ECC_1333,
    Intel_Core_i7_8750H, // Intel_Core_i7_8750H_6_Core_64_bit_9MB_Cache_16_GB_DDR4_2666_MHz,
    Broadcom_BCM2711_ARM_Cortex_A72 // Broadcom_BCM2711_ARM_Cortex_A72_64bit_1MB_L2_Cache_1_5_Ghz_4_Core_4GB_LPDDR4
};

enum class targetMachineListing : unsigned int {
    WORKSTATION_Xeon2630,
    LAPTOP_Core_i7,
    Fanless_Celeron_J1800,
    RaspberryPi4_ARM_Cortex_A72
};

enum class targetCompilerListing : unsigned int {
    MSVC_2019,
    QtCreator_GCC_8_1_0,
    CLANG_
};

enum class targetOsListing : unsigned int {
    MANJARO_Linux,
    Windows_10,
    Windows_8_1_Pro
};

struct SingleTestContainer {
    int * array;
    unsigned long size;
    unsigned long long byteSize;
    // classification
    TestDataType dataType;
    TestDataSizeType sizeClass;
    // aligned
    TestDataAlignment align;
    std::string info;
    unsigned long long execTime_ns = 0;
    TestDataType_ERROR err;

    SingleTestContainer(int * ptr,
                        unsigned long sz,
                        TestDataType tp,
                        TestDataSizeType szCls,
                        TestDataAlignment ali,
                        unsigned long long btSz,
                        std::string descr) : array(ptr), size(sz), byteSize(btSz), dataType(tp), sizeClass(szCls), align(ali), info(descr), err(TestDataType_ERROR::ARRAY_OK){
    };
};



struct TestData {
    std::vector<SingleTestContainer*> testVect; // a vector of pointers to all NOT aligned arrays to sort
    std::vector<SingleTestContainer*> testVectAligned; // a vector of pointers to all ALIGNED arrays to sort
    std::vector<SingleTestContainer*> testVect_all; // a vector of pointers to all NOT aligned arrays to sort
    std::vector<SingleTestContainer*> testVectAligned_all; // a vector of pointers to all ALIGNED arrays to sort

    targetHwListing m_hw;
    targetMachineListing m_machine;
    targetCompilerListing m_compiler;
    targetOsListing m_os;
    unsigned long long m_maxBytes;

    TestData(unsigned long long maxTestDataBytes, targetHwListing hw_, targetMachineListing mach_, targetCompilerListing cmpl_, targetOsListing os_, TestSelection sel, TestExecutionLength length);

    void addNotAlignedTest(SingleTestContainer* newTest);
    void addAlignedTest(SingleTestContainer* newTest);
    void addNotAlignedTest_All(SingleTestContainer* newTest);
    void addAlignedTest_All(SingleTestContainer* newTest);

private:
    void initAllTests(TestExecutionLength length);
};

#endif // TESTDESCRIPTOR_H
