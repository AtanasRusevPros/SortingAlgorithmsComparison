#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayOne_EqualNum64 64
typedef struct arrayOne_EqualNum_NotAligned_64_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayOne_EqualNum64];
} arrayOne_EqualNum_NotAligned_64_t;

alignas(4) arrayOne_EqualNum_NotAligned_64_t arrayOne_EqualNum_NotAligned_64 = { offset_alignment, {123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, }};
alignas(4096) int arrayOne_EqualNum_Aligned_64 [64] = {123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, };
SingleTestContainer arrayOne_EqualNum_NotAligned_64_c(arrayOne_EqualNum_NotAligned_64.arr, (unsigned long)64 , TestDataType::ONE_NUMBER, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayOne_EqualNum_NotAligned_64.arr), "arrayOne_EqualNum_NotAligned_64");
SingleTestContainer arrayOne_EqualNum_Aligned_64_c(arrayOne_EqualNum_Aligned_64, (unsigned long)64 , TestDataType::ONE_NUMBER, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayOne_EqualNum_Aligned_64), "arrayOne_EqualNum_Aligned_64");
