#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayNonRepeat_REVERSE_Sorted64 64
typedef struct arrayNonRepeat_REVERSE_Sorted_NotAligned_64_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayNonRepeat_REVERSE_Sorted64];
} arrayNonRepeat_REVERSE_Sorted_NotAligned_64_t;

alignas(4) arrayNonRepeat_REVERSE_Sorted_NotAligned_64_t arrayNonRepeat_REVERSE_Sorted_NotAligned_64 = { offset_alignment, {-2147393495,-2147394926,-2147396357,-2147397788,-2147399219,-2147400650,-2147402081,-2147403512,-2147404943,-2147406374,-2147407805,-2147409236,-2147410667,-2147412098,-2147413529,-2147414960,-2147416391,-2147417822,-2147419253,-2147420684,-2147422115,-2147423546,-2147424977,-2147426408,-2147427839,-2147429270,-2147430701,-2147432132,-2147433563,-2147434994,-2147436425,-2147437856,-2147439287,-2147440718,-2147442149,-2147443580,-2147445011,-2147446442,-2147447873,-2147449304,-2147450735,-2147452166,-2147453597,-2147455028,-2147456459,-2147457890,-2147459321,-2147460752,-2147462183,-2147463614,-2147465045,-2147466476,-2147467907,-2147469338,-2147470769,-2147472200,-2147473631,-2147475062,-2147476493,-2147477924,-2147479355,-2147480786,-2147482217,-2147483648,}};
alignas(4096) int arrayNonRepeat_REVERSE_Sorted_Aligned_64 [64] = {-2147393495,-2147394926,-2147396357,-2147397788,-2147399219,-2147400650,-2147402081,-2147403512,-2147404943,-2147406374,-2147407805,-2147409236,-2147410667,-2147412098,-2147413529,-2147414960,-2147416391,-2147417822,-2147419253,-2147420684,-2147422115,-2147423546,-2147424977,-2147426408,-2147427839,-2147429270,-2147430701,-2147432132,-2147433563,-2147434994,-2147436425,-2147437856,-2147439287,-2147440718,-2147442149,-2147443580,-2147445011,-2147446442,-2147447873,-2147449304,-2147450735,-2147452166,-2147453597,-2147455028,-2147456459,-2147457890,-2147459321,-2147460752,-2147462183,-2147463614,-2147465045,-2147466476,-2147467907,-2147469338,-2147470769,-2147472200,-2147473631,-2147475062,-2147476493,-2147477924,-2147479355,-2147480786,-2147482217,-2147483648,};
SingleTestContainer arrayNonRepeat_REVERSE_Sorted_NotAligned_64_c(arrayNonRepeat_REVERSE_Sorted_NotAligned_64.arr, (unsigned long)64 , TestDataType::REV_SORTED, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayNonRepeat_REVERSE_Sorted_NotAligned_64.arr), "arrayNonRepeat_REVERSE_Sorted_NotAligned_64");
SingleTestContainer arrayNonRepeat_REVERSE_Sorted_Aligned_64_c(arrayNonRepeat_REVERSE_Sorted_Aligned_64, (unsigned long)64 , TestDataType::REV_SORTED, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayNonRepeat_REVERSE_Sorted_Aligned_64), "arrayNonRepeat_REVERSE_Sorted_Aligned_64");