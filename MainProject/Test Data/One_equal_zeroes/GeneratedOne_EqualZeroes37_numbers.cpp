#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayOne_EqualNumZeroes37 37
typedef struct arrayOne_EqualNumZeroes_NotAligned_37_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayOne_EqualNumZeroes37];
} arrayOne_EqualNumZeroes_NotAligned_37_t;

alignas(4) arrayOne_EqualNumZeroes_NotAligned_37_t arrayOne_EqualNumZeroes_NotAligned_37 = { offset_alignment, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }};
alignas(4096) int arrayOne_EqualNumZeroes_Aligned_37 [37] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
SingleTestContainer arrayOne_EqualNumZeroes_NotAligned_37_c(arrayOne_EqualNumZeroes_NotAligned_37.arr, (unsigned long)37 , TestDataType::ONLY_ZEROES, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayOne_EqualNumZeroes_NotAligned_37.arr), "arrayOne_EqualNumZeroes_NotAligned_37");
SingleTestContainer arrayOne_EqualNumZeroes_Aligned_37_c(arrayOne_EqualNumZeroes_Aligned_37, (unsigned long)37 , TestDataType::ONLY_ZEROES, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayOne_EqualNumZeroes_Aligned_37), "arrayOne_EqualNumZeroes_Aligned_37");
