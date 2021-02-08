#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayRAND_Repeats37 37
typedef struct arrayRAND_Repeats_NotAligned_37_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayRAND_Repeats37];
} arrayRAND_Repeats_NotAligned_37_t;

alignas(4) arrayRAND_Repeats_NotAligned_37_t arrayRAND_Repeats_NotAligned_37 = { offset_alignment, {27457, 18447, 10323, -2784, 74135, 70457, -10316, 13895, 150150, 131172, -30579, 19830, 187866, 215294, -15046, 16841, 261063, 273946, -3306, -6822, 328164, 367986, 4735, -27321, 385068, 398946, -304, -1622, 437758, 478953, -20889, 17825, 524061, 563370, -3428, -2233, 587950, }};
alignas(4096) int arrayRAND_Repeats_Aligned_37 [37] = {27457, 18447, 10323, -2784, 74135, 70457, -10316, 13895, 150150, 131172, -30579, 19830, 187866, 215294, -15046, 16841, 261063, 273946, -3306, -6822, 328164, 367986, 4735, -27321, 385068, 398946, -304, -1622, 437758, 478953, -20889, 17825, 524061, 563370, -3428, -2233, 587950, };
SingleTestContainer arrayRAND_Repeats_NotAligned_37_c(arrayRAND_Repeats_NotAligned_37.arr, (unsigned long)37 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayRAND_Repeats_NotAligned_37.arr), "arrayRAND_Repeats_NotAligned_37");
SingleTestContainer arrayRAND_Repeats_Aligned_37_c(arrayRAND_Repeats_Aligned_37, (unsigned long)37 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayRAND_Repeats_Aligned_37), "arrayRAND_Repeats_Aligned_37");
