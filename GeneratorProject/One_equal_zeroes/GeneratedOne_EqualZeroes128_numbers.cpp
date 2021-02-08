#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayOne_EqualNumZeroes128 128
typedef struct arrayOne_EqualNumZeroes_NotAligned_128_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayOne_EqualNumZeroes128];
} arrayOne_EqualNumZeroes_NotAligned_128_t;

alignas(4) arrayOne_EqualNumZeroes_NotAligned_128_t arrayOne_EqualNumZeroes_NotAligned_128 = { offset_alignment, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }};
alignas(4096) int arrayOne_EqualNumZeroes_Aligned_128 [128] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
SingleTestContainer arrayOne_EqualNumZeroes_NotAligned_128_c(arrayOne_EqualNumZeroes_NotAligned_128.arr, (unsigned long)128 , TestDataType::ONLY_ZEROES, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayOne_EqualNumZeroes_NotAligned_128.arr), "arrayOne_EqualNumZeroes_NotAligned_128");
SingleTestContainer arrayOne_EqualNumZeroes_Aligned_128_c(arrayOne_EqualNumZeroes_Aligned_128, (unsigned long)128 , TestDataType::ONLY_ZEROES, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayOne_EqualNumZeroes_Aligned_128), "arrayOne_EqualNumZeroes_Aligned_128");
