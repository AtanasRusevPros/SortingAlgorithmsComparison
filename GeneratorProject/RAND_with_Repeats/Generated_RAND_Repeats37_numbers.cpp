#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayRAND_Repeats37 37
typedef struct arrayRAND_Repeats_NotAligned_37_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayRAND_Repeats37];
} arrayRAND_Repeats_NotAligned_37_t;

alignas(4) arrayRAND_Repeats_NotAligned_37_t arrayRAND_Repeats_NotAligned_37 = { offset_alignment, {22158, 59784, 19845, -2049, 95103, 126562, -2726, -24447, 171910, 191074, -2769, -21506, 236216, 231567, 11152, -15166, 262237, 298856, 11785, -1000, 344046, 371160, 2342, 2638, 448028, 454728, 115, 3758, 542152, 536973, -12677, -12411, 610570, 621555, -6965, -1504, 684589, }};
alignas(4096) int arrayRAND_Repeats_Aligned_37 [37] = {22158, 59784, 19845, -2049, 95103, 126562, -2726, -24447, 171910, 191074, -2769, -21506, 236216, 231567, 11152, -15166, 262237, 298856, 11785, -1000, 344046, 371160, 2342, 2638, 448028, 454728, 115, 3758, 542152, 536973, -12677, -12411, 610570, 621555, -6965, -1504, 684589, };
SingleTestContainer arrayRAND_Repeats_NotAligned_37_c(arrayRAND_Repeats_NotAligned_37.arr, (unsigned long)37 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayRAND_Repeats_NotAligned_37.arr), "arrayRAND_Repeats_NotAligned_37");
SingleTestContainer arrayRAND_Repeats_Aligned_37_c(arrayRAND_Repeats_Aligned_37, (unsigned long)37 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayRAND_Repeats_Aligned_37), "arrayRAND_Repeats_Aligned_37");
