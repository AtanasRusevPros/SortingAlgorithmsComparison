#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayOne_EqualNum32 32
typedef struct arrayOne_EqualNum_NotAligned_32_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayOne_EqualNum32];
} arrayOne_EqualNum_NotAligned_32_t;

alignas(4) arrayOne_EqualNum_NotAligned_32_t arrayOne_EqualNum_NotAligned_32 = { offset_alignment, {123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, }};
alignas(4096) int arrayOne_EqualNum_Aligned_32 [32] = {123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, };
SingleTestContainer arrayOne_EqualNum_NotAligned_32_c(arrayOne_EqualNum_NotAligned_32.arr, (unsigned long)32 , TestDataType::ONE_NUMBER, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayOne_EqualNum_NotAligned_32.arr), "arrayOne_EqualNum_NotAligned_32");
SingleTestContainer arrayOne_EqualNum_Aligned_32_c(arrayOne_EqualNum_Aligned_32, (unsigned long)32 , TestDataType::ONE_NUMBER, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayOne_EqualNum_Aligned_32), "arrayOne_EqualNum_Aligned_32");
