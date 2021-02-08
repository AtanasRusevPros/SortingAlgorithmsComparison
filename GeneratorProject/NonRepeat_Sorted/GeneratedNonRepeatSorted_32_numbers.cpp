#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayNonRepeatSorted32 32
typedef struct arrayNonRepeatSorted_NotAligned_32_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayNonRepeatSorted32];
} arrayNonRepeatSorted_NotAligned_32_t;

alignas(4) arrayNonRepeatSorted_NotAligned_32_t arrayNonRepeatSorted_NotAligned_32 = { offset_alignment, {-2147483648,-2147482217,-2147480786,-2147479355,-2147477924,-2147476493,-2147475062,-2147473631,-2147472200,-2147470769,-2147469338,-2147467907,-2147466476,-2147465045,-2147463614,-2147462183,-2147460752,-2147459321,-2147457890,-2147456459,-2147455028,-2147453597,-2147452166,-2147450735,-2147449304,-2147447873,-2147446442,-2147445011,-2147443580,-2147442149,-2147440718,-2147439287,}};
alignas(4096) int arrayNonRepeatSorted_Aligned_32 [32] = {-2147483648,-2147482217,-2147480786,-2147479355,-2147477924,-2147476493,-2147475062,-2147473631,-2147472200,-2147470769,-2147469338,-2147467907,-2147466476,-2147465045,-2147463614,-2147462183,-2147460752,-2147459321,-2147457890,-2147456459,-2147455028,-2147453597,-2147452166,-2147450735,-2147449304,-2147447873,-2147446442,-2147445011,-2147443580,-2147442149,-2147440718,-2147439287,};
SingleTestContainer arrayNonRepeatSorted_NotAligned_32_c(arrayNonRepeatSorted_NotAligned_32.arr, (unsigned long)32 , TestDataType::SORTED, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayNonRepeatSorted_NotAligned_32.arr), "arrayNonRepeatSorted_NotAligned_32");
SingleTestContainer arrayNonRepeatSorted_Aligned_32_c(arrayNonRepeatSorted_Aligned_32, (unsigned long)32 , TestDataType::SORTED, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayNonRepeatSorted_Aligned_32), "arrayNonRepeatSorted_Aligned_32");
