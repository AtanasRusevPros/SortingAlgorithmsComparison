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


enum class TestDataType {
    RAND_with_Repeats,
    REV_SORTED,
    RAND_NO_REPEATS_SHUFFLED,
    SORTED,
    SORTED_WITH_SOME_ZEROES_INSERTED,
    ONE_NUMBER,
    ONLY_ZEROES,
    First = RAND_with_Repeats,
    Last = ONLY_ZEROES
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
    SUPER_BIG_2096128
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
    ONLY_EQUALS_SHORT,
    ONLY_SORTED_SHORT,
    ONLY_REV_SORTED_SHORT,
    ONLY_DIVISIBLE_BY_4_NORMAL,
    REV_AND_EQUALS_SORTED_SHORT,
    SPECIAL_SHORT_SELECTED_512
};



string listOfFiles, listContain_RAND_with_REPEATS, listContain_REV_SORTED, listContain_RAND_NO_REPEATS_SHUFFLED, listContain_SORTED, listContain_SORTED_WITH_SOME_ZEROES_INSERTED, listContain_ONE_NUMBER, listContain_ONLY_ZEROES, listContain_ALL;

using namespace std;
using namespace std::chrono;


using std::cout;
using std::endl;
using std::string;

inline nanoseconds getTime_Since_Epoch_ns() {
    high_resolution_clock::time_point t1;
    t1 = high_resolution_clock::now();
    auto time = time_point_cast<nanoseconds>(t1);
    return time.time_since_epoch();
}




// tests:
// 1. random array - yes
// 2. random with some repeating numbers - yes
// 3. random with different repeating numbers - yes
// 4. array with equal numbers - yes
// 5. sorted array  - yes
// 6. reverse sorted - yes
// 7. with zeroes - yes
// -----------------
// All those tests shall be repeated for several sizes - yes
// 128, 256.....32768 members - powers of 2 - yes
// arrays with odd length - yes
// arrays with even length, but divisible e.g. by 4 - yes
// short array under 64 elements - yes
// Super Long arrays - 512 KB of elements - yes
// ------------------
// tests with GCC, MSVC, Clang
// tests for Windows, Linux
// -------------
// reporting of RusevSort, QuickSort with double Pivot, TimSort, Merge Sort...?
// Comparison of end results for each type of input
// check for result arrays whether those are all correct
// also make the checks for aligned and not aligned data !!!
//

void generateNumbers_Rand_With_Repeats(std::string &outputString, unsigned int size) {

    int adder, subtractor, negative, number;

    auto time_ns = getTime_Since_Epoch_ns();
    pout << "Time_ns.count to srand(): " << time_ns.count();
    std::srand(time_ns.count()); 

    adder = std::rand();
    subtractor = std::rand() - adder;
    negative = std::rand();
    if (negative > 0) {
        negative = -negative;
    }

    pout << "adder : " << adder << "  subtractor : " << subtractor << "  negative : " << negative << endl;

    for (unsigned int i = 0; i < size; i++) {

        number = std::rand();
        switch (i & 0x2) {
        case 0x0: {number += adder; break; };
        case 0x1: {number -= subtractor; break; }; // todo check fix
        case 0x2: {number += negative; break; };
        default: {number -= subtractor; break; };
        }

        adder = std::rand() + adder;
        subtractor = std::rand() - adder;
        negative = std::rand();
        if (negative > 0) {
            negative = -negative;
        }
        
        outputString.append(std::to_string(number));
        outputString.append(", ");
    }
}

void generate_int32_Numbers_Rand_NO_RepeatsSorted_incr_1431(int * newArr, unsigned int size) {

    auto time_ns = getTime_Since_Epoch_ns();

    pout << "Time_ns.count to srand(): " << time_ns.count();
    
    const int increment = 1431;
    newArr[0] = INT_MIN;
    int prevNum = INT_MIN;
    
    for (unsigned int i = 1; i < size; i++) {    
        prevNum += increment;
        newArr[i] = prevNum;
    }

}

inline void convertArrayToString(std::string& outputString, int * arr, unsigned int size) {

    for (unsigned int i = 0; i < size; i++) {
        outputString.append(std::to_string(arr[i]));
        outputString.append(",");
    }
}

inline void convertArrayToStringReversed(std::string& outputString, int* arr, unsigned int size) {

    for (unsigned int i = 0; i < size; i++) {
        outputString.append(std::to_string(arr[size-i-1]));
        outputString.append(",");
    }
}


// now after generating those arrays, the next thing is to generate such arrays without repeating numbers.
// for this we will generate such arrays with rising numbers, then shuffle them.
inline void appendListsData(std::string & arrayNameNotAligned, std::string& arrayNameAligned, TestDataType dataType) {
    std::string listData{};
    
    listData.append("addNotAlignedTest(&");
    listData.append(arrayNameNotAligned + "_c);\n");
    listData.append("addAlignedTest(&");
    listData.append(arrayNameAligned + "_c);\n");
    
    switch (dataType) {
        case TestDataType::RAND_with_Repeats: {listContain_RAND_with_REPEATS.append(listData); break; }
        case TestDataType::REV_SORTED: {listContain_REV_SORTED.append(listData); break; }
        case TestDataType::RAND_NO_REPEATS_SHUFFLED: {listContain_RAND_NO_REPEATS_SHUFFLED.append(listData); break; }
        case TestDataType::SORTED: {listContain_SORTED.append(listData); break; }
        case TestDataType::SORTED_WITH_SOME_ZEROES_INSERTED: {listContain_SORTED_WITH_SOME_ZEROES_INSERTED.append(listData); break; }
        case TestDataType::ONE_NUMBER: {listContain_ONE_NUMBER.append(listData); break; }
        case TestDataType::ONLY_ZEROES: {listContain_ONLY_ZEROES.append(listData); break; }
        default: {cout << "Critical ERROR During AppendList - DataType wrong !!!" << endl; }
    }    
    
    listData.clear();
    listData.append("addNotAlignedTest_All(&");
    listData.append(arrayNameNotAligned + "_c);\n");
    listData.append("addAlignedTest_All(&");
    listData.append(arrayNameAligned + "_c);\n");

    listContain_ALL.append(listData);
}

inline string testDataTypeToStr(TestDataType dataType) {

    switch (dataType) {
    case TestDataType::RAND_with_Repeats: {return "RAND_with_Repeats"; }
    case TestDataType::REV_SORTED: {return "REV_SORTED"; }
    case TestDataType::RAND_NO_REPEATS_SHUFFLED: {return "RAND_NO_REPEATS_SHUFFLED"; }
    case TestDataType::SORTED: {return "SORTED"; }
    case TestDataType::SORTED_WITH_SOME_ZEROES_INSERTED: {return "SORTED_WITH_SOME_ZEROES_INSERTED"; }
    case TestDataType::ONE_NUMBER: {return "ONE_NUMBER"; }
    case TestDataType::ONLY_ZEROES: {return "ONLY_ZEROES"; }
    default: {cout << "Critical ERROR During TestDataTypeToStr - DataType wrong !!!" << endl; return " ERROR DURING GENERATION !!!"; }
    }
}
inline void prepareStringBefBetAfterAppndLst(std::string &strBefore, std::string& strBetween, std::string& strAfter, std::string& strHeader, std::string& arrayName, std::string& sizeStr, unsigned int size, TestDataType dataType) {
    // BEFORE    
    string arrayNameNotAligned(arrayName + "_NotAligned_" + sizeStr);
    string arrayNameAligned(arrayName + "_Aligned_" + sizeStr);
    
    strBefore.append("#include \"../../Tools/TestDescriptor.h\"\n");

    string defineSize("SIZE_" + arrayName + sizeStr);
    string structS_name = arrayNameNotAligned + "_s";
    string structT_name = arrayNameNotAligned + "_t";

    strBefore.append("#define " + defineSize + " " + sizeStr + "\n");

    strBefore.append("typedef struct " + structS_name + "{\n" + "    Offset_Struct_92Bytes_t offStruct;\n" + "    int arr[" + defineSize + "];\n" + "} " + structT_name + ";\n\n");

    strBefore.append("alignas(4) " + structT_name + " " + arrayNameNotAligned + " = { offset_alignment, {");

    // BETWEEN
    strBetween.append("}};\nalignas(4096) int " + arrayNameAligned + " [" + sizeStr + "]" + " = {");
    // AFTER
    strAfter.append("};\nSingleTestContainer " + arrayNameNotAligned + "_c(" + arrayNameNotAligned + ".arr, (unsigned long)" + sizeStr + " , TestDataType::" + testDataTypeToStr(dataType) + ", TestDataSizeType::");

    if (size < 4000) {
        strAfter.append("SMALL_32_2050");
    }
    else {
        if (size < 525000) {
            strAfter.append("BIG_32768_524288");
        }
        else {
            strAfter.append("SUPER_BIG_2096128");
        }
    };

    strAfter.append(", TestDataAlignment::NOT_ALIGNED, sizeof(" + arrayNameNotAligned + ".arr), \"" + arrayNameNotAligned + "\");\n");

    strAfter.append("SingleTestContainer " + arrayNameAligned + "_c(" + arrayNameAligned + ", (unsigned long)" + sizeStr + " , TestDataType::" + testDataTypeToStr(dataType) + ", TestDataSizeType::");
    if (size < 4000) {
        strAfter.append("SMALL_32_2050");
    }
    else {
        if (size < 525000) {
            strAfter.append("BIG_32768_524288");
        }
        else {
            strAfter.append("SUPER_BIG_2096128");
        }
    };

    strAfter.append(", TestDataAlignment::ALIGNED, sizeof(" + arrayNameAligned + "), \"" + arrayNameAligned + "\");\n");

    appendListsData(arrayNameNotAligned, arrayNameAligned, dataType);

    // Preparing the STRING FOR THE HEADER
    strHeader.append("#ifndef GENERATED_" + arrayName + sizeStr + "\n#define GENERATED_" + arrayName + sizeStr + "\n");
    strHeader.append("extern SingleTestContainer " + arrayNameNotAligned + "_c;\n");
    strHeader.append("extern SingleTestContainer " + arrayNameAligned + "_c;\n");
    strHeader.append("#endif\n");
}

// Now that we have the data working - next thing is the generation of bigger arrays and checking them
// then take the correct extraction of time.

// rand - make fast a good one. Then transfer the data to a file! Reason - ecah time generating makes everything slower later. And good rand is quite a nice task. Good rand is slow.
// I have succeeded in doing it some years ago. It was for a task
// rand needs seed. We can seed with the current time.
// then we shall always perform some strange calculations on it. This means - addition, extraction, making negative
// addition and extraction shall be done with different numbers each time.
// in order to break partially the dependence one shall
// NOTA BENE !!! Never use this function like it is in real code on a frequent basis - it is with expected BAD PERFORMANCE. Distribution may be good, but keep in mind the extra amount of operations!
// Conclusion - use it to generate fixed values in advance, or as a seldom called function in real code!
void generateRealRandsWithRepeatingNums(unsigned int size) {

    ////******************************************************////////******************************************************////
    //          RAND_with_Repeats        //
    ////******************************************************////


    string sizeStr = to_string(size);
    string outFileName = "RAND_with_Repeats/Generated_RAND_Repeats" + sizeStr + "_numbers.cpp";
    string outFileNameHeader = "RAND_with_Repeats/Generated_RAND_Repeats" + sizeStr + "_numbers.h";


    listOfFiles.append(string("#include \"../Test Data/") + outFileNameHeader + "\" \n");

    std::ofstream outFile(outFileName);
    std::ofstream outFileHeader(outFileNameHeader);

    string arrayName("arrayRAND_Repeats");

    string generatedNumbersStr{};
    generatedNumbersStr.reserve(size * 2);
    string strBeforeNumbers{};
    string strBetweenNumbers{};
    string strAfterNumbers{};
    string strHeader{};
    strHeader.reserve(400);
    strBeforeNumbers.reserve(1000);
    strBetweenNumbers.reserve(1000);
    strAfterNumbers.reserve(1000);

    prepareStringBefBetAfterAppndLst(strBeforeNumbers, strBetweenNumbers, strAfterNumbers, strHeader, arrayName, sizeStr, size, TestDataType::RAND_with_Repeats);
    generateNumbers_Rand_With_Repeats(generatedNumbersStr, size);

    outFile << strBeforeNumbers << generatedNumbersStr << strBetweenNumbers << generatedNumbersStr << strAfterNumbers;
    outFileHeader << strHeader;

    outFileHeader.flush();
    outFileHeader.close();

    outFile.flush();
    outFile.close();

}

void generateRealRandsNoRepeat(unsigned int size) {

    int* newArr = new int[size];

    ////******************************************************////////******************************************************////
    //          RANDS NO REPEAT, for SORTED        //
    ////******************************************************////

    string sizeStr = to_string(size);
    string generatedNumbersStr{};
    generatedNumbersStr.reserve(size*2);
    string strBeforeNumbers{};
    string strBetweenNumbers{};
    string strAfterNumbers{};
    string strHeader{};
    strHeader.reserve(400);
    strBeforeNumbers.reserve(1000);
    strBetweenNumbers.reserve(1000);
    strAfterNumbers.reserve(1000);

    string arrayName("arrayNonRepeatSorted");

    string outFileName = "NonRepeat_Sorted/GeneratedNonRepeatSorted_" + sizeStr + "_numbers.cpp";
    string outFileNameHeader = "NonRepeat_Sorted/GeneratedNonRepeatSorted_" + sizeStr + "_numbers.h";

    listOfFiles.append(string("#include \"../Test Data/") + outFileNameHeader + "\" \n");

    std::ofstream outFile(outFileName);
    std::ofstream outFileHeader(outFileNameHeader);

    prepareStringBefBetAfterAppndLst(strBeforeNumbers, strBetweenNumbers, strAfterNumbers, strHeader, arrayName, sizeStr, size, TestDataType::SORTED);

    if (size > 2096120) {
        cout << "Generating super big array : \n";
    }
    generate_int32_Numbers_Rand_NO_RepeatsSorted_incr_1431(newArr, size);
    convertArrayToString(generatedNumbersStr, newArr, size);

    outFile << strBeforeNumbers << generatedNumbersStr << strBetweenNumbers << generatedNumbersStr << strAfterNumbers;
    outFileHeader << strHeader;

    outFileHeader.flush();
    outFileHeader.close();

    outFile.flush();
    outFile.close();

    ////******************************************************////////******************************************************////
    //          REV_SORTED        //
    ////******************************************************////

    outFileName.clear();

    outFileName = "NonRepeat_Reverse_Sorted/GeneratedNonRepeatREVERSE_Sorted_" + sizeStr + "_numbers.cpp";
    outFileNameHeader = "NonRepeat_Reverse_Sorted/GeneratedNonRepeatREVERSE_Sorted_" + sizeStr + "_numbers.h";

    listOfFiles.append(string("#include \"../Test Data/") + outFileNameHeader + "\" \n");

    strBeforeNumbers.clear();
    strBetweenNumbers.clear();
    strAfterNumbers.clear();
    strHeader.clear();
    strHeader.reserve(400);
    strBeforeNumbers.reserve(1000);
    strBetweenNumbers.reserve(1000);
    strAfterNumbers.reserve(1000);

    generatedNumbersStr.clear();
    generatedNumbersStr.reserve(size * 2);

    std::ofstream outFileRev(outFileName);
    std::ofstream outFileRevHeader(outFileNameHeader);

    arrayName = "arrayNonRepeat_REVERSE_Sorted";    

    prepareStringBefBetAfterAppndLst(strBeforeNumbers, strBetweenNumbers, strAfterNumbers, strHeader, arrayName, sizeStr, size, TestDataType::REV_SORTED);

    convertArrayToStringReversed(generatedNumbersStr, newArr, size);

    outFileRev << strBeforeNumbers << generatedNumbersStr << strBetweenNumbers << generatedNumbersStr << strAfterNumbers;
    outFileRevHeader << strHeader;

    outFileRevHeader.flush();
    outFileRevHeader.close();

    outFileRev.flush();
    outFileRev.close();


    ////******************************************************////////******************************************************////
    //          RAND_NO_REPEATS_SHUFFLED        //
    ////******************************************************////

    std::vector<int> shuffledVec(newArr, newArr + size);

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(shuffledVec.begin(), shuffledVec.end(), g);

    outFileName.clear();

    outFileName = "NonRepeat_Shuffled/GeneratedNonRepeatShuffled" + sizeStr + "_numbers.cpp";
    outFileNameHeader = "NonRepeat_Shuffled/GeneratedNonRepeatShuffled" + sizeStr + "_numbers.h";

    listOfFiles.append(string("#include \"../Test Data/") + outFileNameHeader + "\" \n");

    strBeforeNumbers.clear();
    strBetweenNumbers.clear();
    strAfterNumbers.clear();
    strHeader.clear();
    strHeader.reserve(400);
    strBeforeNumbers.reserve(1000);
    strBetweenNumbers.reserve(1000);
    strAfterNumbers.reserve(1000);

    generatedNumbersStr.clear();
    generatedNumbersStr.reserve(size * 2);

    std::ofstream outFileShuff(outFileName);
    std::ofstream outFileShuffHeader(outFileNameHeader);

    arrayName = "arrayNonRepeat_Shuffled";
    
    for (int a : shuffledVec) {
        generatedNumbersStr.append(std::to_string(a));
        generatedNumbersStr.append(", ");
    }

    prepareStringBefBetAfterAppndLst(strBeforeNumbers, strBetweenNumbers, strAfterNumbers, strHeader, arrayName, sizeStr, size, TestDataType::RAND_NO_REPEATS_SHUFFLED);

    outFileShuff << strBeforeNumbers << generatedNumbersStr << strBetweenNumbers << generatedNumbersStr << strAfterNumbers;
    outFileShuffHeader << strHeader;

    outFileShuffHeader.flush();
    outFileShuffHeader.close();

    outFileShuff.flush();
    outFileShuff.close();

    ////******************************************************////////******************************************************////
    //          SORTED_WITH_SOME_ZEROES_INSERTED        //
    ////******************************************************////

    outFileName.clear();

    outFileName = "NonRepeat_Sorted_with_some_Zeroes/GeneratedNonRepeatSorted_SomeZeroes" + sizeStr + "_numbers.cpp";
    outFileNameHeader = "NonRepeat_Sorted_with_some_Zeroes/GeneratedNonRepeatSorted_SomeZeroes" + sizeStr + "_numbers.h";

    listOfFiles.append(string("#include \"../Test Data/") + outFileNameHeader + "\" \n");

    strBeforeNumbers.clear();
    strBetweenNumbers.clear();
    strAfterNumbers.clear();
    strHeader.clear();
    strHeader.reserve(400);
    strBeforeNumbers.reserve(1000);
    strBetweenNumbers.reserve(1000);
    strAfterNumbers.reserve(1000);

    generatedNumbersStr.clear();
    generatedNumbersStr.reserve(size * 2);

    std::ofstream outFileSomeZeroes(outFileName);
    std::ofstream outFileSomeZeroesHeader(outFileNameHeader);

    arrayName = "arrayNonRepeatSorted_SomeZeroes";    

    for (unsigned int i = 0; i < size; i++) {
        if (i % 5) {
            generatedNumbersStr.append(std::to_string(newArr[i]));
            generatedNumbersStr.append(", ");

        }
        else {
            generatedNumbersStr.append("0, ");
        }

    }

    prepareStringBefBetAfterAppndLst(strBeforeNumbers, strBetweenNumbers, strAfterNumbers, strHeader, arrayName, sizeStr, size, TestDataType::SORTED_WITH_SOME_ZEROES_INSERTED);

    outFileSomeZeroes << strBeforeNumbers << generatedNumbersStr << strBetweenNumbers << generatedNumbersStr << strAfterNumbers;
    outFileSomeZeroesHeader << strHeader;

    outFileSomeZeroesHeader.flush();
    outFileSomeZeroesHeader.close();

    outFileSomeZeroes.flush();
    outFileSomeZeroes.close();


    ////******************************************************////////******************************************************////
    //          ONE_NUMBER        //
    ////******************************************************////

    outFileName.clear();

    outFileName = "One_equal/GeneratedOne_Equal" + sizeStr + "_numbers.cpp";
    outFileNameHeader = "One_equal/GeneratedOne_Equal" + sizeStr + "_numbers.h";

    listOfFiles.append(string("#include \"../Test Data/") + outFileNameHeader + "\" \n");

    strBeforeNumbers.clear();
    strBetweenNumbers.clear();
    strAfterNumbers.clear();
    strHeader.clear();
    strHeader.reserve(400);
    strBeforeNumbers.reserve(1000);
    strBetweenNumbers.reserve(1000);
    strAfterNumbers.reserve(1000);

    generatedNumbersStr.clear();
    generatedNumbersStr.reserve(size * 2);

    std::ofstream outFileEq(outFileName);
    std::ofstream outFileEqHeader(outFileNameHeader);
    
    arrayName = "arrayOne_EqualNum";    

    for (unsigned int i = 0; i < size; i++) {        
        generatedNumbersStr.append("123, ");
    }

    prepareStringBefBetAfterAppndLst(strBeforeNumbers, strBetweenNumbers, strAfterNumbers, strHeader, arrayName, sizeStr, size, TestDataType::ONE_NUMBER);

    outFileEq << strBeforeNumbers << generatedNumbersStr << strBetweenNumbers << generatedNumbersStr << strAfterNumbers;
    outFileEqHeader << strHeader;

    outFileEqHeader.flush();
    outFileEqHeader.close();

    outFileEq.flush();
    outFileEq.close();

    ////******************************************************////////******************************************************////
    //          ONLY_ZEROES        //
    ////******************************************************////

    outFileName.clear();

    outFileName = "One_equal_zeroes/GeneratedOne_EqualZeroes" + sizeStr + "_numbers.cpp";
    outFileNameHeader = "One_equal_zeroes/GeneratedOne_EqualZeroes" + sizeStr + "_numbers.h";

    listOfFiles.append(string("#include \"../Test Data/") + outFileNameHeader + "\" \n");

    strBeforeNumbers.clear();
    strBetweenNumbers.clear();
    strAfterNumbers.clear();
    strHeader.clear();
    strHeader.reserve(400);
    strBeforeNumbers.reserve(1000);
    strBetweenNumbers.reserve(1000);
    strAfterNumbers.reserve(1000);

    generatedNumbersStr.clear();
    generatedNumbersStr.reserve(size * 2);

    std::ofstream outFileZeroes(outFileName);
    std::ofstream outFileZeroesHeader(outFileNameHeader);
    
    arrayName = "arrayOne_EqualNumZeroes";
    

    for (unsigned int i = 0; i < size; i++) {        
        generatedNumbersStr.append("0, ");
    }

    prepareStringBefBetAfterAppndLst(strBeforeNumbers, strBetweenNumbers, strAfterNumbers, strHeader, arrayName, sizeStr, size, TestDataType::ONLY_ZEROES);

    outFileZeroes << strBeforeNumbers << generatedNumbersStr << strBetweenNumbers << generatedNumbersStr << strAfterNumbers;
    outFileZeroesHeader << strHeader;

    outFileZeroesHeader.flush();
    outFileZeroesHeader.close();

    outFileZeroes.flush();
    outFileZeroes.close();

    delete[]newArr;
}

// tests:
// 1. random array - yes
// 2. random with some repeating numbers - yes
// 3. random with different repeating numbers - yes
// 4. array with equal numbers - yes
// 5. sorted array  - yes
// 6. reverse sorted - yes
// 7. with zeroes - yes
// -----------------
// All those tests shall be repeated for several sizes - yes
// 128, 256.....32768 members - powers of 2 - yes
// arrays with odd length - yes
// arrays with even length, but divisible e.g. by 4 - yes
// short array under 64 elements - yes
// Super Long arrays - 512 KB of elements - yes
// ------------------
// tests with GCC, MSVC, Clang
// tests for Windows, Linux
// -------------
// reporting of RusevSort, QuickSort with double Pivot, TimSort, Merge Sort...?
// Comparison of end results for each type of input
// check for result arrays whether those are all correct
// also make the checks for aligned and not aligned data !!!
//

int main(int argc, char* argv[])
{

    generateRealRandsWithRepeatingNums(32);
    generateRealRandsWithRepeatingNums(37);
    generateRealRandsWithRepeatingNums(64);
    generateRealRandsWithRepeatingNums(128);
    generateRealRandsWithRepeatingNums(256);
    generateRealRandsWithRepeatingNums(512);
    generateRealRandsWithRepeatingNums(1024);
    generateRealRandsWithRepeatingNums(2048);
    generateRealRandsWithRepeatingNums(2049);
    generateRealRandsWithRepeatingNums(2050);

    generateRealRandsWithRepeatingNums(32768);
    generateRealRandsWithRepeatingNums(32760);
    generateRealRandsWithRepeatingNums(32724);
    generateRealRandsWithRepeatingNums(32756);
    generateRealRandsWithRepeatingNums(32710);
    generateRealRandsWithRepeatingNums(32713);
    generateRealRandsWithRepeatingNums(32717);
    generateRealRandsWithRepeatingNums(32711);
    generateRealRandsWithRepeatingNums(32715);

    generateRealRandsWithRepeatingNums(65536);
    generateRealRandsWithRepeatingNums(131072); // int 4 Bytes -> 500KB
    generateRealRandsWithRepeatingNums(524288);
    generateRealRandsWithRepeatingNums(2096128); // 2,097,152 - 1024 bytes


    generateRealRandsNoRepeat(32);
    generateRealRandsNoRepeat(37);
    generateRealRandsNoRepeat(64);
    generateRealRandsNoRepeat(128);
    generateRealRandsNoRepeat(256);
    generateRealRandsNoRepeat(512);
    generateRealRandsNoRepeat(1024);
    generateRealRandsNoRepeat(2048);
    generateRealRandsNoRepeat(2049);
    generateRealRandsNoRepeat(2050);



    generateRealRandsNoRepeat(32768);
    generateRealRandsNoRepeat(32760);
    generateRealRandsNoRepeat(32724);
    generateRealRandsNoRepeat(32756);
    generateRealRandsNoRepeat(32710);
    generateRealRandsNoRepeat(32713);
    generateRealRandsNoRepeat(32717);
    generateRealRandsNoRepeat(32711);
    generateRealRandsNoRepeat(32715);



    generateRealRandsNoRepeat(65536);
    generateRealRandsNoRepeat(131072); // int 4 Bytes -> 500KB
    generateRealRandsNoRepeat(524288);
    generateRealRandsNoRepeat(2096128); // 2,097,152 - 1024 bytes

    string outFileName = "Generated_Arrays_Includes.h";

    std::ofstream outFile(outFileName);
    outFile << "#include \"../Tools/TestDescriptor.h\"\n";
    outFile << listOfFiles;

    outFile.close();

    outFileName = "Generated_Arrays_ContainList_RAND_With_Rep.h";

    outFile.open(outFileName);
    outFile << listContain_RAND_with_REPEATS;

    outFile.close();

    outFileName = "Generated_Arrays_ContainList_REV_SORTED.h";

    outFile.open(outFileName);
    outFile << listContain_REV_SORTED;

    outFile.close();
        
    outFileName = "Generated_Arrays_ContainList_RAND_NoRep_Shuff.h";

    outFile.open(outFileName);
    outFile << listContain_RAND_NO_REPEATS_SHUFFLED;

    outFile.close();

    outFileName = "Generated_Arrays_ContainList_SORTED.h";

    outFile.open(outFileName);
    outFile << listContain_SORTED;

    outFile.close();

    outFileName = "Generated_Arrays_ContainList_SORTED_SOME_ZEROES.h";

    outFile.open(outFileName);
    outFile << listContain_SORTED_WITH_SOME_ZEROES_INSERTED;

    outFile.close();

    outFileName = "Generated_Arrays_ContainList_ONE_NUM.h";

    outFile.open(outFileName);
    outFile << listContain_ONE_NUMBER;

    outFile.close();


    outFileName = "Generated_Arrays_ContainList_ONLY_ZEROES.h";

    outFile.open(outFileName);
    outFile << listContain_ONLY_ZEROES;

    outFile.close();

    outFileName = "Generated_Arrays_ContainList_ALL.h";

    outFile.open(outFileName);
    outFile << listContain_ALL;

    outFile.close();   

    return 0;
}








