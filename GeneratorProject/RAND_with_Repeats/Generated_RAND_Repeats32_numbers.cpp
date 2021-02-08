#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayRAND_Repeats32 32
typedef struct arrayRAND_Repeats_NotAligned_32_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayRAND_Repeats32];
} arrayRAND_Repeats_NotAligned_32_t;

alignas(4) arrayRAND_Repeats_NotAligned_32_t arrayRAND_Repeats_NotAligned_32 = { offset_alignment, {17082, 48343, -485, 20586, 107519, 136106, 11114, 11799, 178621, 193677, -17841, -10442, 251989, 267762, -5929, 11665, 354262, 371262, 3084, -9738, 425222, 444620, -12294, 3119, 471644, 497386, -2129, -17655, 508166, 536793, -25290, 25681, }};
alignas(4096) int arrayRAND_Repeats_Aligned_32 [32] = {17082, 48343, -485, 20586, 107519, 136106, 11114, 11799, 178621, 193677, -17841, -10442, 251989, 267762, -5929, 11665, 354262, 371262, 3084, -9738, 425222, 444620, -12294, 3119, 471644, 497386, -2129, -17655, 508166, 536793, -25290, 25681, };
SingleTestContainer arrayRAND_Repeats_NotAligned_32_c(arrayRAND_Repeats_NotAligned_32.arr, (unsigned long)32 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayRAND_Repeats_NotAligned_32.arr), "arrayRAND_Repeats_NotAligned_32");
SingleTestContainer arrayRAND_Repeats_Aligned_32_c(arrayRAND_Repeats_Aligned_32, (unsigned long)32 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayRAND_Repeats_Aligned_32), "arrayRAND_Repeats_Aligned_32");
