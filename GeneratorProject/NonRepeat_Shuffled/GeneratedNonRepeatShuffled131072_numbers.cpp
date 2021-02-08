#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayNonRepeat_Shuffled131072 131072
typedef struct arrayNonRepeat_Shuffled_NotAligned_131072_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayNonRepeat_Shuffled131072];
} arrayNonRepeat_Shuffled_NotAligned_131072_t;

SingleTestContainer arrayNonRepeat_Shuffled_NotAligned_131072_c(arrayNonRepeat_Shuffled_NotAligned_131072.arr, (unsigned long)131072 , TestDataType::RAND_NO_REPEATS_SHUFFLED, TestDataSizeType::BIG_32768_524288, TestDataAlignment::NOT_ALIGNED, sizeof(arrayNonRepeat_Shuffled_NotAligned_131072.arr), "arrayNonRepeat_Shuffled_NotAligned_131072");
SingleTestContainer arrayNonRepeat_Shuffled_Aligned_131072_c(arrayNonRepeat_Shuffled_Aligned_131072, (unsigned long)131072 , TestDataType::RAND_NO_REPEATS_SHUFFLED, TestDataSizeType::BIG_32768_524288, TestDataAlignment::ALIGNED, sizeof(arrayNonRepeat_Shuffled_Aligned_131072), "arrayNonRepeat_Shuffled_Aligned_131072");