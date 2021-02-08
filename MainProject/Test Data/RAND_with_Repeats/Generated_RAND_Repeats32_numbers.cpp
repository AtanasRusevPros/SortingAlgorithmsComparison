#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayRAND_Repeats32 32
typedef struct arrayRAND_Repeats_NotAligned_32_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayRAND_Repeats32];
} arrayRAND_Repeats_NotAligned_32_t;

alignas(4) arrayRAND_Repeats_NotAligned_32_t arrayRAND_Repeats_NotAligned_32 = { offset_alignment, {52197, 64645, -11393, -18347, 117997, 120263, 10960, -11255, 193600, 219589, -11745, -21031, 273719, 278761, -6137, 13602, 289618, 300805, 13860, -3010, 356145, 364617, -3822, 20619, 412571, 400972, 30830, -13724, 436859, 443661, 5842, 15653, }};
alignas(4096) int arrayRAND_Repeats_Aligned_32 [32] = {52197, 64645, -11393, -18347, 117997, 120263, 10960, -11255, 193600, 219589, -11745, -21031, 273719, 278761, -6137, 13602, 289618, 300805, 13860, -3010, 356145, 364617, -3822, 20619, 412571, 400972, 30830, -13724, 436859, 443661, 5842, 15653, };
SingleTestContainer arrayRAND_Repeats_NotAligned_32_c(arrayRAND_Repeats_NotAligned_32.arr, (unsigned long)32 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayRAND_Repeats_NotAligned_32.arr), "arrayRAND_Repeats_NotAligned_32");
SingleTestContainer arrayRAND_Repeats_Aligned_32_c(arrayRAND_Repeats_Aligned_32, (unsigned long)32 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayRAND_Repeats_Aligned_32), "arrayRAND_Repeats_Aligned_32");
