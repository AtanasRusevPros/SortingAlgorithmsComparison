#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayOne_EqualNumZeroes32 32
typedef struct arrayOne_EqualNumZeroes_NotAligned_32_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayOne_EqualNumZeroes32];
} arrayOne_EqualNumZeroes_NotAligned_32_t;

alignas(4) arrayOne_EqualNumZeroes_NotAligned_32_t arrayOne_EqualNumZeroes_NotAligned_32 = { offset_alignment, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }};
alignas(4096) int arrayOne_EqualNumZeroes_Aligned_32 [32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
SingleTestContainer arrayOne_EqualNumZeroes_NotAligned_32_c(arrayOne_EqualNumZeroes_NotAligned_32.arr, (unsigned long)32 , TestDataType::ONLY_ZEROES, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayOne_EqualNumZeroes_NotAligned_32.arr), "arrayOne_EqualNumZeroes_NotAligned_32");
SingleTestContainer arrayOne_EqualNumZeroes_Aligned_32_c(arrayOne_EqualNumZeroes_Aligned_32, (unsigned long)32 , TestDataType::ONLY_ZEROES, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayOne_EqualNumZeroes_Aligned_32), "arrayOne_EqualNumZeroes_Aligned_32");
