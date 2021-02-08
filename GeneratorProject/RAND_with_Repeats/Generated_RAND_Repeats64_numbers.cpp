#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayRAND_Repeats64 64
typedef struct arrayRAND_Repeats_NotAligned_64_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayRAND_Repeats64];
} arrayRAND_Repeats_NotAligned_64_t;

alignas(4) arrayRAND_Repeats_NotAligned_64_t arrayRAND_Repeats_NotAligned_64 = { offset_alignment, {46987, 77342, -28833, -23348, 93871, 122564, 435, -10000, 205662, 240170, 12529, 1442, 269484, 313904, 6466, 13513, 340287, 337547, 13781, 8021, 358481, 415167, 16596, -4817, 441009, 450091, -3221, -2747, 467905, 505596, -14905, -637, 537210, 526648, -20717, -1323, 584291, 635061, 25980, 20773, 672924, 687392, 7724, 4961, 745688, 766710, 19794, -15500, 816735, 838798, -6633, 4683, 918794, 949005, 6826, 8146, 968263, 976752, 7221, -17677, 1039897, 1061766, -9500, 8604, }};
alignas(4096) int arrayRAND_Repeats_Aligned_64 [64] = {46987, 77342, -28833, -23348, 93871, 122564, 435, -10000, 205662, 240170, 12529, 1442, 269484, 313904, 6466, 13513, 340287, 337547, 13781, 8021, 358481, 415167, 16596, -4817, 441009, 450091, -3221, -2747, 467905, 505596, -14905, -637, 537210, 526648, -20717, -1323, 584291, 635061, 25980, 20773, 672924, 687392, 7724, 4961, 745688, 766710, 19794, -15500, 816735, 838798, -6633, 4683, 918794, 949005, 6826, 8146, 968263, 976752, 7221, -17677, 1039897, 1061766, -9500, 8604, };
SingleTestContainer arrayRAND_Repeats_NotAligned_64_c(arrayRAND_Repeats_NotAligned_64.arr, (unsigned long)64 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayRAND_Repeats_NotAligned_64.arr), "arrayRAND_Repeats_NotAligned_64");
SingleTestContainer arrayRAND_Repeats_Aligned_64_c(arrayRAND_Repeats_Aligned_64, (unsigned long)64 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayRAND_Repeats_Aligned_64), "arrayRAND_Repeats_Aligned_64");
