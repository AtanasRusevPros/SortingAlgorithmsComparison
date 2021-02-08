#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayRAND_Repeats64 64
typedef struct arrayRAND_Repeats_NotAligned_64_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayRAND_Repeats64];
} arrayRAND_Repeats_NotAligned_64_t;

alignas(4) arrayRAND_Repeats_NotAligned_64_t arrayRAND_Repeats_NotAligned_64 = { offset_alignment, {8036, 28579, 9602, -26839, 41424, 46142, -24801, -23359, 77460, 111498, -15335, -9771, 185259, 170642, -21747, 7617, 208690, 225734, 5525, -3359, 242794, 258551, -20401, -18799, 307385, 334171, 21206, -7890, 364713, 393359, 16326, 17938, 386280, 421778, -6981, 21404, 501576, 504517, -26030, -11483, 540607, 569328, 25637, 10506, 608615, 604990, 12499, 5287, 661373, 666685, -26124, -4006, 719459, 733920, 9256, 29051, 771229, 781438, -248, -6038, 856025, 866513, -15055, 128, }};
alignas(4096) int arrayRAND_Repeats_Aligned_64 [64] = {8036, 28579, 9602, -26839, 41424, 46142, -24801, -23359, 77460, 111498, -15335, -9771, 185259, 170642, -21747, 7617, 208690, 225734, 5525, -3359, 242794, 258551, -20401, -18799, 307385, 334171, 21206, -7890, 364713, 393359, 16326, 17938, 386280, 421778, -6981, 21404, 501576, 504517, -26030, -11483, 540607, 569328, 25637, 10506, 608615, 604990, 12499, 5287, 661373, 666685, -26124, -4006, 719459, 733920, 9256, 29051, 771229, 781438, -248, -6038, 856025, 866513, -15055, 128, };
SingleTestContainer arrayRAND_Repeats_NotAligned_64_c(arrayRAND_Repeats_NotAligned_64.arr, (unsigned long)64 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayRAND_Repeats_NotAligned_64.arr), "arrayRAND_Repeats_NotAligned_64");
SingleTestContainer arrayRAND_Repeats_Aligned_64_c(arrayRAND_Repeats_Aligned_64, (unsigned long)64 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayRAND_Repeats_Aligned_64), "arrayRAND_Repeats_Aligned_64");
