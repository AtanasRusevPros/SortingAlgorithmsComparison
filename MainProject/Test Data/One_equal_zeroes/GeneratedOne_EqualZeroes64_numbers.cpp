#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayOne_EqualNumZeroes64 64
typedef struct arrayOne_EqualNumZeroes_NotAligned_64_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayOne_EqualNumZeroes64];
} arrayOne_EqualNumZeroes_NotAligned_64_t;

alignas(4) arrayOne_EqualNumZeroes_NotAligned_64_t arrayOne_EqualNumZeroes_NotAligned_64 = { offset_alignment, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }};
alignas(4096) int arrayOne_EqualNumZeroes_Aligned_64 [64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
SingleTestContainer arrayOne_EqualNumZeroes_NotAligned_64_c(arrayOne_EqualNumZeroes_NotAligned_64.arr, (unsigned long)64 , TestDataType::ONLY_ZEROES, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayOne_EqualNumZeroes_NotAligned_64.arr), "arrayOne_EqualNumZeroes_NotAligned_64");
SingleTestContainer arrayOne_EqualNumZeroes_Aligned_64_c(arrayOne_EqualNumZeroes_Aligned_64, (unsigned long)64 , TestDataType::ONLY_ZEROES, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayOne_EqualNumZeroes_Aligned_64), "arrayOne_EqualNumZeroes_Aligned_64");
