#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayNonRepeatSorted131072 131072
typedef struct arrayNonRepeatSorted_NotAligned_131072_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayNonRepeatSorted131072];
} arrayNonRepeatSorted_NotAligned_131072_t;

SingleTestContainer arrayNonRepeatSorted_NotAligned_131072_c(arrayNonRepeatSorted_NotAligned_131072.arr, (unsigned long)131072 , TestDataType::SORTED, TestDataSizeType::BIG_32768_524288, TestDataAlignment::NOT_ALIGNED, sizeof(arrayNonRepeatSorted_NotAligned_131072.arr), "arrayNonRepeatSorted_NotAligned_131072");
SingleTestContainer arrayNonRepeatSorted_Aligned_131072_c(arrayNonRepeatSorted_Aligned_131072, (unsigned long)131072 , TestDataType::SORTED, TestDataSizeType::BIG_32768_524288, TestDataAlignment::ALIGNED, sizeof(arrayNonRepeatSorted_Aligned_131072), "arrayNonRepeatSorted_Aligned_131072");