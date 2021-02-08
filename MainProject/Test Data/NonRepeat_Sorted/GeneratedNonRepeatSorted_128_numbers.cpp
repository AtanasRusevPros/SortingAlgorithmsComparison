#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayNonRepeatSorted128 128
typedef struct arrayNonRepeatSorted_NotAligned_128_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayNonRepeatSorted128];
} arrayNonRepeatSorted_NotAligned_128_t;

alignas(4) arrayNonRepeatSorted_NotAligned_128_t arrayNonRepeatSorted_NotAligned_128 = { offset_alignment, {-2147483648,-2147482217,-2147480786,-2147479355,-2147477924,-2147476493,-2147475062,-2147473631,-2147472200,-2147470769,-2147469338,-2147467907,-2147466476,-2147465045,-2147463614,-2147462183,-2147460752,-2147459321,-2147457890,-2147456459,-2147455028,-2147453597,-2147452166,-2147450735,-2147449304,-2147447873,-2147446442,-2147445011,-2147443580,-2147442149,-2147440718,-2147439287,-2147437856,-2147436425,-2147434994,-2147433563,-2147432132,-2147430701,-2147429270,-2147427839,-2147426408,-2147424977,-2147423546,-2147422115,-2147420684,-2147419253,-2147417822,-2147416391,-2147414960,-2147413529,-2147412098,-2147410667,-2147409236,-2147407805,-2147406374,-2147404943,-2147403512,-2147402081,-2147400650,-2147399219,-2147397788,-2147396357,-2147394926,-2147393495,-2147392064,-2147390633,-2147389202,-2147387771,-2147386340,-2147384909,-2147383478,-2147382047,-2147380616,-2147379185,-2147377754,-2147376323,-2147374892,-2147373461,-2147372030,-2147370599,-2147369168,-2147367737,-2147366306,-2147364875,-2147363444,-2147362013,-2147360582,-2147359151,-2147357720,-2147356289,-2147354858,-2147353427,-2147351996,-2147350565,-2147349134,-2147347703,-2147346272,-2147344841,-2147343410,-2147341979,-2147340548,-2147339117,-2147337686,-2147336255,-2147334824,-2147333393,-2147331962,-2147330531,-2147329100,-2147327669,-2147326238,-2147324807,-2147323376,-2147321945,-2147320514,-2147319083,-2147317652,-2147316221,-2147314790,-2147313359,-2147311928,-2147310497,-2147309066,-2147307635,-2147306204,-2147304773,-2147303342,-2147301911,}};
alignas(4096) int arrayNonRepeatSorted_Aligned_128 [128] = {-2147483648,-2147482217,-2147480786,-2147479355,-2147477924,-2147476493,-2147475062,-2147473631,-2147472200,-2147470769,-2147469338,-2147467907,-2147466476,-2147465045,-2147463614,-2147462183,-2147460752,-2147459321,-2147457890,-2147456459,-2147455028,-2147453597,-2147452166,-2147450735,-2147449304,-2147447873,-2147446442,-2147445011,-2147443580,-2147442149,-2147440718,-2147439287,-2147437856,-2147436425,-2147434994,-2147433563,-2147432132,-2147430701,-2147429270,-2147427839,-2147426408,-2147424977,-2147423546,-2147422115,-2147420684,-2147419253,-2147417822,-2147416391,-2147414960,-2147413529,-2147412098,-2147410667,-2147409236,-2147407805,-2147406374,-2147404943,-2147403512,-2147402081,-2147400650,-2147399219,-2147397788,-2147396357,-2147394926,-2147393495,-2147392064,-2147390633,-2147389202,-2147387771,-2147386340,-2147384909,-2147383478,-2147382047,-2147380616,-2147379185,-2147377754,-2147376323,-2147374892,-2147373461,-2147372030,-2147370599,-2147369168,-2147367737,-2147366306,-2147364875,-2147363444,-2147362013,-2147360582,-2147359151,-2147357720,-2147356289,-2147354858,-2147353427,-2147351996,-2147350565,-2147349134,-2147347703,-2147346272,-2147344841,-2147343410,-2147341979,-2147340548,-2147339117,-2147337686,-2147336255,-2147334824,-2147333393,-2147331962,-2147330531,-2147329100,-2147327669,-2147326238,-2147324807,-2147323376,-2147321945,-2147320514,-2147319083,-2147317652,-2147316221,-2147314790,-2147313359,-2147311928,-2147310497,-2147309066,-2147307635,-2147306204,-2147304773,-2147303342,-2147301911,};
SingleTestContainer arrayNonRepeatSorted_NotAligned_128_c(arrayNonRepeatSorted_NotAligned_128.arr, (unsigned long)128 , TestDataType::SORTED, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayNonRepeatSorted_NotAligned_128.arr), "arrayNonRepeatSorted_NotAligned_128");
SingleTestContainer arrayNonRepeatSorted_Aligned_128_c(arrayNonRepeatSorted_Aligned_128, (unsigned long)128 , TestDataType::SORTED, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayNonRepeatSorted_Aligned_128), "arrayNonRepeatSorted_Aligned_128");
