#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayRAND_Repeats256 256
typedef struct arrayRAND_Repeats_NotAligned_256_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayRAND_Repeats256];
} arrayRAND_Repeats_NotAligned_256_t;

alignas(4) arrayRAND_Repeats_NotAligned_256_t arrayRAND_Repeats_NotAligned_256 = { offset_alignment, {16995, 55207, 18755, -10028, 83913, 116681, -7485, -24126, 128145, 150626, -1186, -14047, 184814, 186365, 8080, 558, 231770, 283310, 7893, -19676, 332178, 349963, -13400, -19136, 400276, 405292, -17530, 5310, 442278, 463276, 1770, 20698, 485968, 499378, 2386, 7119, 559455, 564446, -24264, -25894, 588002, 620123, 28696, 9783, 667693, 685526, 6767, 2337, 700122, 705410, -30791, -15915, 764357, 795156, 8818, 16782, 817165, 814019, 6165, -21366, 868375, 872271, -26337, 6659, 943245, 969975, -26356, -11210, 995672, 979843, -29097, 6238, 1034411, 1039674, -19843, -10568, 1069048, 1076457, 16890, -3455, 1137913, 1133282, 15434, 498, 1188522, 1221115, -23576, 3658, 1302091, 1285262, -16815, 21442, 1344609, 1352053, -11264, 408, 1420723, 1429781, -3982, -1527, 1459279, 1491538, -24028, 4687, 1536132, 1539989, 14991, -11610, 1590759, 1590220, 3633, -18868, 1683537, 1668968, -19322, -5253, 1745117, 1764701, -14326, 4976, 1800940, 1794087, -22984, 614, 1851682, 1846977, 12173, -102, 1868391, 1890733, 1925, 1352, 1967847, 1982448, -11109, 171, 2047252, 2071572, 77, -28160, 2123425, 2146598, -2284, -13181, 2229639, 2234296, -6034, -2448, 2263297, 2284254, 1752, -14078, 2341521, 2364722, -14389, 12406, 2419450, 2448850, -23610, 3079, 2514758, 2544989, 22083, -4622, 2588095, 2614011, -25152, -9356, 2702071, 2699604, -1098, 3270, 2803394, 2812821, -2909, 11559, 2881847, 2898545, -12285, 6865, 2949046, 2949405, 22610, 9985, 3000795, 3005007, 6923, 22002, 3061388, 3069256, 10411, -24863, 3113201, 3109575, 21678, 11274, 3173752, 3170836, -2673, 6825, 3225295, 3243509, 9420, 15096, 3291882, 3312057, -289, 20534, 3401733, 3419699, 25412, -12131, 3467674, 3487415, 13432, 9579, 3544425, 3542557, 6135, -5414, 3577973, 3603395, -18884, -20441, 3662857, 3645578, -1340, 14221, 3693232, 3716057, -11252, -18872, 3718459, 3768472, -3187, 5270, 3823549, 3842612, 3525, -21071, 3927695, 3932575, 6704, 4055, 3959631, 3969615, 4938, -17343, 3983835, 4017980, -18801, 26414, 4048216, 4093924, -15238, 14296, }};
alignas(4096) int arrayRAND_Repeats_Aligned_256 [256] = {16995, 55207, 18755, -10028, 83913, 116681, -7485, -24126, 128145, 150626, -1186, -14047, 184814, 186365, 8080, 558, 231770, 283310, 7893, -19676, 332178, 349963, -13400, -19136, 400276, 405292, -17530, 5310, 442278, 463276, 1770, 20698, 485968, 499378, 2386, 7119, 559455, 564446, -24264, -25894, 588002, 620123, 28696, 9783, 667693, 685526, 6767, 2337, 700122, 705410, -30791, -15915, 764357, 795156, 8818, 16782, 817165, 814019, 6165, -21366, 868375, 872271, -26337, 6659, 943245, 969975, -26356, -11210, 995672, 979843, -29097, 6238, 1034411, 1039674, -19843, -10568, 1069048, 1076457, 16890, -3455, 1137913, 1133282, 15434, 498, 1188522, 1221115, -23576, 3658, 1302091, 1285262, -16815, 21442, 1344609, 1352053, -11264, 408, 1420723, 1429781, -3982, -1527, 1459279, 1491538, -24028, 4687, 1536132, 1539989, 14991, -11610, 1590759, 1590220, 3633, -18868, 1683537, 1668968, -19322, -5253, 1745117, 1764701, -14326, 4976, 1800940, 1794087, -22984, 614, 1851682, 1846977, 12173, -102, 1868391, 1890733, 1925, 1352, 1967847, 1982448, -11109, 171, 2047252, 2071572, 77, -28160, 2123425, 2146598, -2284, -13181, 2229639, 2234296, -6034, -2448, 2263297, 2284254, 1752, -14078, 2341521, 2364722, -14389, 12406, 2419450, 2448850, -23610, 3079, 2514758, 2544989, 22083, -4622, 2588095, 2614011, -25152, -9356, 2702071, 2699604, -1098, 3270, 2803394, 2812821, -2909, 11559, 2881847, 2898545, -12285, 6865, 2949046, 2949405, 22610, 9985, 3000795, 3005007, 6923, 22002, 3061388, 3069256, 10411, -24863, 3113201, 3109575, 21678, 11274, 3173752, 3170836, -2673, 6825, 3225295, 3243509, 9420, 15096, 3291882, 3312057, -289, 20534, 3401733, 3419699, 25412, -12131, 3467674, 3487415, 13432, 9579, 3544425, 3542557, 6135, -5414, 3577973, 3603395, -18884, -20441, 3662857, 3645578, -1340, 14221, 3693232, 3716057, -11252, -18872, 3718459, 3768472, -3187, 5270, 3823549, 3842612, 3525, -21071, 3927695, 3932575, 6704, 4055, 3959631, 3969615, 4938, -17343, 3983835, 4017980, -18801, 26414, 4048216, 4093924, -15238, 14296, };
SingleTestContainer arrayRAND_Repeats_NotAligned_256_c(arrayRAND_Repeats_NotAligned_256.arr, (unsigned long)256 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayRAND_Repeats_NotAligned_256.arr), "arrayRAND_Repeats_NotAligned_256");
SingleTestContainer arrayRAND_Repeats_Aligned_256_c(arrayRAND_Repeats_Aligned_256, (unsigned long)256 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayRAND_Repeats_Aligned_256), "arrayRAND_Repeats_Aligned_256");
