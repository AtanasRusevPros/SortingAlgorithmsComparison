#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayOne_EqualNum37 37
typedef struct arrayOne_EqualNum_NotAligned_37_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayOne_EqualNum37];
} arrayOne_EqualNum_NotAligned_37_t;

alignas(4) arrayOne_EqualNum_NotAligned_37_t arrayOne_EqualNum_NotAligned_37 = { offset_alignment, {123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, }};
alignas(4096) int arrayOne_EqualNum_Aligned_37 [37] = {123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, };
SingleTestContainer arrayOne_EqualNum_NotAligned_37_c(arrayOne_EqualNum_NotAligned_37.arr, (unsigned long)37 , TestDataType::ONE_NUMBER, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayOne_EqualNum_NotAligned_37.arr), "arrayOne_EqualNum_NotAligned_37");
SingleTestContainer arrayOne_EqualNum_Aligned_37_c(arrayOne_EqualNum_Aligned_37, (unsigned long)37 , TestDataType::ONE_NUMBER, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayOne_EqualNum_Aligned_37), "arrayOne_EqualNum_Aligned_37");
