#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayNonRepeat_Shuffled32 32
typedef struct arrayNonRepeat_Shuffled_NotAligned_32_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayNonRepeat_Shuffled32];
} arrayNonRepeat_Shuffled_NotAligned_32_t;

alignas(4) arrayNonRepeat_Shuffled_NotAligned_32_t arrayNonRepeat_Shuffled_NotAligned_32 = { offset_alignment, {-2147475062, -2147457890, -2147479355, -2147452166, -2147467907, -2147465045, -2147469338, -2147447873, -2147442149, -2147480786, -2147482217, -2147443580, -2147460752, -2147456459, -2147483648, -2147440718, -2147445011, -2147462183, -2147453597, -2147472200, -2147476493, -2147449304, -2147477924, -2147455028, -2147470769, -2147473631, -2147439287, -2147450735, -2147459321, -2147466476, -2147463614, -2147446442, }};
alignas(4096) int arrayNonRepeat_Shuffled_Aligned_32 [32] = {-2147475062, -2147457890, -2147479355, -2147452166, -2147467907, -2147465045, -2147469338, -2147447873, -2147442149, -2147480786, -2147482217, -2147443580, -2147460752, -2147456459, -2147483648, -2147440718, -2147445011, -2147462183, -2147453597, -2147472200, -2147476493, -2147449304, -2147477924, -2147455028, -2147470769, -2147473631, -2147439287, -2147450735, -2147459321, -2147466476, -2147463614, -2147446442, };
SingleTestContainer arrayNonRepeat_Shuffled_NotAligned_32_c(arrayNonRepeat_Shuffled_NotAligned_32.arr, (unsigned long)32 , TestDataType::RAND_NO_REPEATS_SHUFFLED, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayNonRepeat_Shuffled_NotAligned_32.arr), "arrayNonRepeat_Shuffled_NotAligned_32");
SingleTestContainer arrayNonRepeat_Shuffled_Aligned_32_c(arrayNonRepeat_Shuffled_Aligned_32, (unsigned long)32 , TestDataType::RAND_NO_REPEATS_SHUFFLED, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayNonRepeat_Shuffled_Aligned_32), "arrayNonRepeat_Shuffled_Aligned_32");
