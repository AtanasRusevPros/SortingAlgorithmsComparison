#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayRAND_Repeats131072 131072
typedef struct arrayRAND_Repeats_NotAligned_131072_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayRAND_Repeats131072];
} arrayRAND_Repeats_NotAligned_131072_t;

SingleTestContainer arrayRAND_Repeats_NotAligned_131072_c(arrayRAND_Repeats_NotAligned_131072.arr, (unsigned long)131072 , TestDataType::RAND_with_Repeats, TestDataSizeType::BIG_32768_524288, TestDataAlignment::NOT_ALIGNED, sizeof(arrayRAND_Repeats_NotAligned_131072.arr), "arrayRAND_Repeats_NotAligned_131072");
SingleTestContainer arrayRAND_Repeats_Aligned_131072_c(arrayRAND_Repeats_Aligned_131072, (unsigned long)131072 , TestDataType::RAND_with_Repeats, TestDataSizeType::BIG_32768_524288, TestDataAlignment::ALIGNED, sizeof(arrayRAND_Repeats_Aligned_131072), "arrayRAND_Repeats_Aligned_131072");