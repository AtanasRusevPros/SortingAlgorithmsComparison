#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayNonRepeat_Shuffled37 37
typedef struct arrayNonRepeat_Shuffled_NotAligned_37_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayNonRepeat_Shuffled37];
} arrayNonRepeat_Shuffled_NotAligned_37_t;

alignas(4) arrayNonRepeat_Shuffled_NotAligned_37_t arrayNonRepeat_Shuffled_NotAligned_37 = { offset_alignment, {-2147457890, -2147477924, -2147466476, -2147462183, -2147472200, -2147453597, -2147450735, -2147436425, -2147460752, -2147447873, -2147459321, -2147482217, -2147480786, -2147446442, -2147443580, -2147437856, -2147432132, -2147455028, -2147475062, -2147440718, -2147476493, -2147469338, -2147439287, -2147433563, -2147449304, -2147467907, -2147483648, -2147479355, -2147434994, -2147445011, -2147470769, -2147463614, -2147442149, -2147473631, -2147465045, -2147452166, -2147456459, }};
alignas(4096) int arrayNonRepeat_Shuffled_Aligned_37 [37] = {-2147457890, -2147477924, -2147466476, -2147462183, -2147472200, -2147453597, -2147450735, -2147436425, -2147460752, -2147447873, -2147459321, -2147482217, -2147480786, -2147446442, -2147443580, -2147437856, -2147432132, -2147455028, -2147475062, -2147440718, -2147476493, -2147469338, -2147439287, -2147433563, -2147449304, -2147467907, -2147483648, -2147479355, -2147434994, -2147445011, -2147470769, -2147463614, -2147442149, -2147473631, -2147465045, -2147452166, -2147456459, };
SingleTestContainer arrayNonRepeat_Shuffled_NotAligned_37_c(arrayNonRepeat_Shuffled_NotAligned_37.arr, (unsigned long)37 , TestDataType::RAND_NO_REPEATS_SHUFFLED, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayNonRepeat_Shuffled_NotAligned_37.arr), "arrayNonRepeat_Shuffled_NotAligned_37");
SingleTestContainer arrayNonRepeat_Shuffled_Aligned_37_c(arrayNonRepeat_Shuffled_Aligned_37, (unsigned long)37 , TestDataType::RAND_NO_REPEATS_SHUFFLED, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayNonRepeat_Shuffled_Aligned_37), "arrayNonRepeat_Shuffled_Aligned_37");
