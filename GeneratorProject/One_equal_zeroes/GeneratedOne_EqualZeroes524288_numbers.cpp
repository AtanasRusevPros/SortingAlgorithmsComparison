#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayOne_EqualNumZeroes524288 524288
typedef struct arrayOne_EqualNumZeroes_NotAligned_524288_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayOne_EqualNumZeroes524288];
} arrayOne_EqualNumZeroes_NotAligned_524288_t;

SingleTestContainer arrayOne_EqualNumZeroes_NotAligned_524288_c(arrayOne_EqualNumZeroes_NotAligned_524288.arr, (unsigned long)524288 , TestDataType::ONLY_ZEROES, TestDataSizeType::BIG_32768_524288, TestDataAlignment::NOT_ALIGNED, sizeof(arrayOne_EqualNumZeroes_NotAligned_524288.arr), "arrayOne_EqualNumZeroes_NotAligned_524288");
SingleTestContainer arrayOne_EqualNumZeroes_Aligned_524288_c(arrayOne_EqualNumZeroes_Aligned_524288, (unsigned long)524288 , TestDataType::ONLY_ZEROES, TestDataSizeType::BIG_32768_524288, TestDataAlignment::ALIGNED, sizeof(arrayOne_EqualNumZeroes_Aligned_524288), "arrayOne_EqualNumZeroes_Aligned_524288");