#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayRAND_Repeats1024 1024
typedef struct arrayRAND_Repeats_NotAligned_1024_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayRAND_Repeats1024];
} arrayRAND_Repeats_NotAligned_1024_t;

alignas(4) arrayRAND_Repeats_NotAligned_1024_t arrayRAND_Repeats_NotAligned_1024 = { offset_alignment, {49762, 33194, -8528, -547, 60388, 95002, 5412, -6076, 96629, 115095, 22592, -19741, 167606, 197472, -12703, 16596, 269224, 277080, -1823, -16330, 324019, 358665, -3041, -5597, 399519, 411546, 14196, -15691, 451485, 477407, -10947, -9972, 542271, 565067, 15062, 1858, 616828, 627189, -3940, -19852, 688304, 684443, -9750, 2748, 777882, 769436, -2789, 19254, 805468, 821499, -25714, -1535, 857213, 859999, -15972, 10295, 879591, 879127, -18781, 12789, 979690, 988431, -6914, -428, 1053751, 1045468, 4616, 16243, 1152997, 1156790, 7711, -19858, 1210480, 1245049, -15201, -8352, 1275831, 1287845, -9245, -9884, 1340412, 1343582, 5445, -360, 1408230, 1429867, 15653, 14360, 1484928, 1516600, -1315, -17921, 1550393, 1568215, 4298, 17256, 1613284, 1667832, -25530, -8591, 1716406, 1731828, -10833, 8245, 1794636, 1797833, 20576, -5936, 1876900, 1870357, -17739, 9054, 1944097, 1946653, 7690, -31236, 2032778, 2026182, 7867, 20933, 2060297, 2070944, 15397, 4821, 2092334, 2080472, 4259, -8120, 2135275, 2150466, 4496, 7226, 2207127, 2220119, 20299, 13256, 2260972, 2294577, 13612, 24332, 2321418, 2323346, -13933, 24868, 2342515, 2389980, -4647, 18475, 2442510, 2459415, 7773, 11581, 2532390, 2534895, -19848, -2953, 2616169, 2634677, -25465, 3316, 2714348, 2719579, -22042, 12496, 2770979, 2800763, 17138, -23258, 2839275, 2867277, -21754, -1515, 2890369, 2895541, -16258, 19126, 2933386, 2940726, 15542, -730, 3020812, 3047927, 29706, 642, 3073650, 3081412, 5591, 5862, 3116169, 3127307, -5001, 363, 3166598, 3191779, 7496, -11215, 3242495, 3243266, -5978, 11346, 3316973, 3303874, -5653, -3606, 3324081, 3360551, -10380, 6164, 3409935, 3423698, -15715, -8977, 3479338, 3503883, -10300, 2452, 3545232, 3572158, -25023, 12832, 3635759, 3635068, -18316, -2640, 3717721, 3727736, -23626, 15966, 3734726, 3792265, 30821, 328, 3825552, 3834668, 10716, -375, 3870773, 3901568, -14730, 318, 3940506, 3974985, 14226, -24702, 4004868, 4047344, 393, -1423, 4086814, 4114559, 953, -474, 4136441, 4152743, -18308, 8639, 4216581, 4242363, -2768, 10071, 4311577, 4348339, 10800, -9205, 4381811, 4411436, 8920, -10250, 4467375, 4488805, 17797, 15924, 4546000, 4583234, 21393, -799, 4603964, 4619848, -22181, 3353, 4657855, 4668583, -452, 13048, 4727177, 4724269, 9361, 15772, 4757804, 4765262, -13898, -14563, 4823965, 4828449, -18936, -2918, 4887864, 4904035, 3298, -18898, 4936125, 4945011, 3231, 1782, 5001550, 4991318, 20126, 11533, 5070193, 5081011, 1848, -1650, 5135891, 5145046, -14901, -30569, 5205631, 5213358, 13490, 323, 5223020, 5244112, -9912, -10834, 5303021, 5329777, -11285, 757, 5393280, 5428081, -24585, -11981, 5443329, 5469773, -11321, 4995, 5491895, 5515563, 24757, 26628, 5541188, 5568977, -11487, -2097, 5611447, 5634987, 4709, -18687, 5713531, 5729481, 8414, 9399, 5772387, 5806813, 23526, 2828, 5829034, 5867587, 15322, 16156, 5898472, 5918964, 5144, 24836, 5975068, 5984146, 21241, 7133, 6021545, 6062685, 16858, -6713, 6138196, 6139968, -15081, 16347, 6191435, 6213061, 7181, 30263, 6245146, 6267420, -24298, 24567, 6320310, 6335515, 2448, 7990, 6400372, 6407991, 9687, -7921, 6453009, 6492303, 8516, 7583, 6566570, 6589407, 16951, -10237, 6644162, 6654093, -22007, -8617, 6671168, 6669985, 5401, 2484, 6737008, 6740934, 6848, -453, 6811134, 6805578, -4773, -5373, 6863103, 6892581, -26042, -13781, 6900716, 6933485, -13858, 8397, 6959003, 6985182, -130, -16632, 7007309, 7042774, -9854, -11, 7102117, 7098203, 20806, -30286, 7163051, 7182483, -1242, 3418, 7224006, 7227723, 18047, 1801, 7274697, 7305971, -16981, -549, 7347941, 7360160, -14840, -15380, 7426737, 7442951, 24562, 13912, 7466024, 7480453, -6461, -708, 7529128, 7576601, -12072, 19379, 7612915, 7613033, -4211, 8153, 7685939, 7717306, 12096, 715, 7775727, 7830010, 22345, 18595, 7875866, 7878073, -13816, -12161, 7934980, 7964457, -15146, -15239, 7993188, 8017187, 8209, -9808, 8040021, 8044578, 3860, 4157, 8085335, 8111943, -8134, -3267, 8181066, 8203604, 15586, 22733, 8262776, 8265138, -5787, -24057, 8335242, 8360302, 1313, -1271, 8379535, 8418359, -13712, 6894, 8473083, 8456543, -12624, 979, 8565668, 8556768, -15812, -15662, 8665026, 8662099, -20368, -20472, 8743928, 8750076, 16297, -20845, 8827465, 8825789, -3775, -4980, 8867352, 8865819, -7785, 8976, 8927539, 8942406, 2052, -10692, 8960199, 9003532, -2331, 5418, 9056872, 9062625, -25706, 14840, 9126157, 9142493, -396, 10689, 9210384, 9268411, 730, 5281, 9294384, 9313755, 10019, 13749, 9360016, 9386306, -15186, 4887, 9424310, 9444503, -12332, -16923, 9495693, 9519908, 6131, 4666, 9546596, 9562843, 1894, -2254, 9600751, 9632081, 25480, 7914, 9673029, 9707708, 3255, -14724, 9758430, 9749752, -16817, 30214, 9804699, 9805956, 20138, 16547, 9897919, 9906566, -4315, 1135, 9940209, 9975492, -5091, -21882, 9999162, 10020011, 27885, -6396, 10083850, 10074697, 13298, -1786, 10133812, 10161748, -8570, -5465, 10221037, 10234913, 9478, -12029, 10309585, 10336430, 6864, 3126, 10359265, 10409883, -4547, 1885, 10445693, 10457132, 10410, -1902, 10503532, 10547782, -4493, 8434, 10544857, 10550136, 16117, 3227, 10598997, 10632176, 13450, -11610, 10701520, 10730372, -15216, -10960, 10768547, 10821289, -157, 342, 10847878, 10881915, 20572, -28877, 10927771, 10964668, -16933, -15902, 10991458, 10993870, 10553, -22655, 11088068, 11070138, 3796, -9940, 11125002, 11135787, -14840, 15101, 11168228, 11213681, -16081, 15377, 11267428, 11269247, -12890, -27003, 11297537, 11351022, -11318, 3957, 11373720, 11419898, 5878, -18694, 11463524, 11456898, -2682, 10292, 11506955, 11521802, 10454, -14019, 11552914, 11566010, -31422, 2865, 11649893, 11687774, 14887, -21973, 11720274, 11715686, 4575, -4790, 11745932, 11791589, -20024, -6489, 11839147, 11855763, -9666, -19617, 11903911, 11934925, 9883, 15247, 12001762, 12020625, 19772, -3502, 12078622, 12095108, -8323, 5572, 12134016, 12173551, 2492, 28417, 12210069, 12231611, -11439, 4645, 12265801, 12280441, -8548, 7757, 12329970, 12359772, -22282, -620, 12375365, 12383551, 19133, 9494, 12406110, 12427931, -18612, -11024, 12463035, 12478608, -770, -10180, 12547135, 12554979, 1330, -15081, 12592176, 12621306, 21569, 15518, 12683066, 12710882, -13943, -21779, 12733547, 12771658, 24420, -30946, 12835636, 12855942, -5328, 4942, 12871792, 12900495, -8888, 7322, 12929879, 12948992, 264, 15132, 12980872, 12997656, -17203, 4594, 13031687, 13021116, -11791, 3895, 13097786, 13112949, 7379, -21497, 13126636, 13151083, 21708, -21377, 13199692, 13200497, 19513, -8263, 13226476, 13244154, 12406, -8237, 13310405, 13356318, -13856, -11800, 13377325, 13400728, 15314, 9748, 13443049, 13466057, -15193, -10380, 13536792, 13531316, -578, 11298, 13575489, 13606400, 7024, -2756, 13647695, 13659643, -21221, -12579, 13691282, 13725586, -8934, 24609, 13777339, 13767002, -20280, -25820, 13820643, 13848205, -14205, -765, 13896324, 13898757, -24665, -12840, 13950332, 13985089, -13170, -7998, 14050576, 14074215, 16533, -11303, 14162915, 14141501, 2073, -12227, 14205699, 14229294, 2677, -13817, 14284509, 14292556, 18949, -16299, 14353476, 14355786, 9254, -703, 14417265, 14424192, 4402, -10775, 14454526, 14444010, -7032, -5527, 14521574, 14508582, 3201, 26076, 14577553, 14589306, -11654, -16803, 14620867, 14643405, 6863, -2806, 14645416, 14672554, -23331, 22014, 14711502, 14732355, 19198, 14421, 14770984, 14794344, 17040, 15915, 14869260, 14853781, -9234, 5276, 14904886, 14922723, 17012, -19514, 14962629, 14973971, 15487, 7873, 15007547, 15032458, 27497, -23636, 15054208, 15086414, 2960, -25693, 15122909, 15145994, 13392, 10944, 15212290, 15219985, -26621, 33, 15255554, 15276115, 17414, 5600, 15322451, 15316075, -8010, -3812, 15378897, 15401363, -3730, 25069, 15423417, 15466155, 5258, -15501, 15508912, 15507002, -15514, 15304, 15584186, 15592290, 4702, -1017, 15614021, 15625971, -3889, 78, 15682846, 15717466, -5869, 20409, 15721592, 15748782, -8056, -17310, 15807977, 15842725, -10358, 9062, 15893358, 15897242, -22157, -21278, 15906403, 15922575, 19616, 3057, 15971469, 15968806, 4717, -16721, 16020754, 16037032, 26424, -12744, 16078207, 16105217, 4697, 3753, 16133824, 16137664, -2512, -8420, 16198183, 16209176, -12266, -5712, 16275054, 16317922, -1943, 25469, 16317613, 16345754, -23932, 19618, 16397668, 16428126, -25406, 12346, 16498037, 16488435, 4226, -7070, 16550696, 16575168, -15843, 18997, 16622376, 16658388, 20721, 3535, 16723331, 16737500, -2216, 26188, }};
alignas(4096) int arrayRAND_Repeats_Aligned_1024 [1024] = {49762, 33194, -8528, -547, 60388, 95002, 5412, -6076, 96629, 115095, 22592, -19741, 167606, 197472, -12703, 16596, 269224, 277080, -1823, -16330, 324019, 358665, -3041, -5597, 399519, 411546, 14196, -15691, 451485, 477407, -10947, -9972, 542271, 565067, 15062, 1858, 616828, 627189, -3940, -19852, 688304, 684443, -9750, 2748, 777882, 769436, -2789, 19254, 805468, 821499, -25714, -1535, 857213, 859999, -15972, 10295, 879591, 879127, -18781, 12789, 979690, 988431, -6914, -428, 1053751, 1045468, 4616, 16243, 1152997, 1156790, 7711, -19858, 1210480, 1245049, -15201, -8352, 1275831, 1287845, -9245, -9884, 1340412, 1343582, 5445, -360, 1408230, 1429867, 15653, 14360, 1484928, 1516600, -1315, -17921, 1550393, 1568215, 4298, 17256, 1613284, 1667832, -25530, -8591, 1716406, 1731828, -10833, 8245, 1794636, 1797833, 20576, -5936, 1876900, 1870357, -17739, 9054, 1944097, 1946653, 7690, -31236, 2032778, 2026182, 7867, 20933, 2060297, 2070944, 15397, 4821, 2092334, 2080472, 4259, -8120, 2135275, 2150466, 4496, 7226, 2207127, 2220119, 20299, 13256, 2260972, 2294577, 13612, 24332, 2321418, 2323346, -13933, 24868, 2342515, 2389980, -4647, 18475, 2442510, 2459415, 7773, 11581, 2532390, 2534895, -19848, -2953, 2616169, 2634677, -25465, 3316, 2714348, 2719579, -22042, 12496, 2770979, 2800763, 17138, -23258, 2839275, 2867277, -21754, -1515, 2890369, 2895541, -16258, 19126, 2933386, 2940726, 15542, -730, 3020812, 3047927, 29706, 642, 3073650, 3081412, 5591, 5862, 3116169, 3127307, -5001, 363, 3166598, 3191779, 7496, -11215, 3242495, 3243266, -5978, 11346, 3316973, 3303874, -5653, -3606, 3324081, 3360551, -10380, 6164, 3409935, 3423698, -15715, -8977, 3479338, 3503883, -10300, 2452, 3545232, 3572158, -25023, 12832, 3635759, 3635068, -18316, -2640, 3717721, 3727736, -23626, 15966, 3734726, 3792265, 30821, 328, 3825552, 3834668, 10716, -375, 3870773, 3901568, -14730, 318, 3940506, 3974985, 14226, -24702, 4004868, 4047344, 393, -1423, 4086814, 4114559, 953, -474, 4136441, 4152743, -18308, 8639, 4216581, 4242363, -2768, 10071, 4311577, 4348339, 10800, -9205, 4381811, 4411436, 8920, -10250, 4467375, 4488805, 17797, 15924, 4546000, 4583234, 21393, -799, 4603964, 4619848, -22181, 3353, 4657855, 4668583, -452, 13048, 4727177, 4724269, 9361, 15772, 4757804, 4765262, -13898, -14563, 4823965, 4828449, -18936, -2918, 4887864, 4904035, 3298, -18898, 4936125, 4945011, 3231, 1782, 5001550, 4991318, 20126, 11533, 5070193, 5081011, 1848, -1650, 5135891, 5145046, -14901, -30569, 5205631, 5213358, 13490, 323, 5223020, 5244112, -9912, -10834, 5303021, 5329777, -11285, 757, 5393280, 5428081, -24585, -11981, 5443329, 5469773, -11321, 4995, 5491895, 5515563, 24757, 26628, 5541188, 5568977, -11487, -2097, 5611447, 5634987, 4709, -18687, 5713531, 5729481, 8414, 9399, 5772387, 5806813, 23526, 2828, 5829034, 5867587, 15322, 16156, 5898472, 5918964, 5144, 24836, 5975068, 5984146, 21241, 7133, 6021545, 6062685, 16858, -6713, 6138196, 6139968, -15081, 16347, 6191435, 6213061, 7181, 30263, 6245146, 6267420, -24298, 24567, 6320310, 6335515, 2448, 7990, 6400372, 6407991, 9687, -7921, 6453009, 6492303, 8516, 7583, 6566570, 6589407, 16951, -10237, 6644162, 6654093, -22007, -8617, 6671168, 6669985, 5401, 2484, 6737008, 6740934, 6848, -453, 6811134, 6805578, -4773, -5373, 6863103, 6892581, -26042, -13781, 6900716, 6933485, -13858, 8397, 6959003, 6985182, -130, -16632, 7007309, 7042774, -9854, -11, 7102117, 7098203, 20806, -30286, 7163051, 7182483, -1242, 3418, 7224006, 7227723, 18047, 1801, 7274697, 7305971, -16981, -549, 7347941, 7360160, -14840, -15380, 7426737, 7442951, 24562, 13912, 7466024, 7480453, -6461, -708, 7529128, 7576601, -12072, 19379, 7612915, 7613033, -4211, 8153, 7685939, 7717306, 12096, 715, 7775727, 7830010, 22345, 18595, 7875866, 7878073, -13816, -12161, 7934980, 7964457, -15146, -15239, 7993188, 8017187, 8209, -9808, 8040021, 8044578, 3860, 4157, 8085335, 8111943, -8134, -3267, 8181066, 8203604, 15586, 22733, 8262776, 8265138, -5787, -24057, 8335242, 8360302, 1313, -1271, 8379535, 8418359, -13712, 6894, 8473083, 8456543, -12624, 979, 8565668, 8556768, -15812, -15662, 8665026, 8662099, -20368, -20472, 8743928, 8750076, 16297, -20845, 8827465, 8825789, -3775, -4980, 8867352, 8865819, -7785, 8976, 8927539, 8942406, 2052, -10692, 8960199, 9003532, -2331, 5418, 9056872, 9062625, -25706, 14840, 9126157, 9142493, -396, 10689, 9210384, 9268411, 730, 5281, 9294384, 9313755, 10019, 13749, 9360016, 9386306, -15186, 4887, 9424310, 9444503, -12332, -16923, 9495693, 9519908, 6131, 4666, 9546596, 9562843, 1894, -2254, 9600751, 9632081, 25480, 7914, 9673029, 9707708, 3255, -14724, 9758430, 9749752, -16817, 30214, 9804699, 9805956, 20138, 16547, 9897919, 9906566, -4315, 1135, 9940209, 9975492, -5091, -21882, 9999162, 10020011, 27885, -6396, 10083850, 10074697, 13298, -1786, 10133812, 10161748, -8570, -5465, 10221037, 10234913, 9478, -12029, 10309585, 10336430, 6864, 3126, 10359265, 10409883, -4547, 1885, 10445693, 10457132, 10410, -1902, 10503532, 10547782, -4493, 8434, 10544857, 10550136, 16117, 3227, 10598997, 10632176, 13450, -11610, 10701520, 10730372, -15216, -10960, 10768547, 10821289, -157, 342, 10847878, 10881915, 20572, -28877, 10927771, 10964668, -16933, -15902, 10991458, 10993870, 10553, -22655, 11088068, 11070138, 3796, -9940, 11125002, 11135787, -14840, 15101, 11168228, 11213681, -16081, 15377, 11267428, 11269247, -12890, -27003, 11297537, 11351022, -11318, 3957, 11373720, 11419898, 5878, -18694, 11463524, 11456898, -2682, 10292, 11506955, 11521802, 10454, -14019, 11552914, 11566010, -31422, 2865, 11649893, 11687774, 14887, -21973, 11720274, 11715686, 4575, -4790, 11745932, 11791589, -20024, -6489, 11839147, 11855763, -9666, -19617, 11903911, 11934925, 9883, 15247, 12001762, 12020625, 19772, -3502, 12078622, 12095108, -8323, 5572, 12134016, 12173551, 2492, 28417, 12210069, 12231611, -11439, 4645, 12265801, 12280441, -8548, 7757, 12329970, 12359772, -22282, -620, 12375365, 12383551, 19133, 9494, 12406110, 12427931, -18612, -11024, 12463035, 12478608, -770, -10180, 12547135, 12554979, 1330, -15081, 12592176, 12621306, 21569, 15518, 12683066, 12710882, -13943, -21779, 12733547, 12771658, 24420, -30946, 12835636, 12855942, -5328, 4942, 12871792, 12900495, -8888, 7322, 12929879, 12948992, 264, 15132, 12980872, 12997656, -17203, 4594, 13031687, 13021116, -11791, 3895, 13097786, 13112949, 7379, -21497, 13126636, 13151083, 21708, -21377, 13199692, 13200497, 19513, -8263, 13226476, 13244154, 12406, -8237, 13310405, 13356318, -13856, -11800, 13377325, 13400728, 15314, 9748, 13443049, 13466057, -15193, -10380, 13536792, 13531316, -578, 11298, 13575489, 13606400, 7024, -2756, 13647695, 13659643, -21221, -12579, 13691282, 13725586, -8934, 24609, 13777339, 13767002, -20280, -25820, 13820643, 13848205, -14205, -765, 13896324, 13898757, -24665, -12840, 13950332, 13985089, -13170, -7998, 14050576, 14074215, 16533, -11303, 14162915, 14141501, 2073, -12227, 14205699, 14229294, 2677, -13817, 14284509, 14292556, 18949, -16299, 14353476, 14355786, 9254, -703, 14417265, 14424192, 4402, -10775, 14454526, 14444010, -7032, -5527, 14521574, 14508582, 3201, 26076, 14577553, 14589306, -11654, -16803, 14620867, 14643405, 6863, -2806, 14645416, 14672554, -23331, 22014, 14711502, 14732355, 19198, 14421, 14770984, 14794344, 17040, 15915, 14869260, 14853781, -9234, 5276, 14904886, 14922723, 17012, -19514, 14962629, 14973971, 15487, 7873, 15007547, 15032458, 27497, -23636, 15054208, 15086414, 2960, -25693, 15122909, 15145994, 13392, 10944, 15212290, 15219985, -26621, 33, 15255554, 15276115, 17414, 5600, 15322451, 15316075, -8010, -3812, 15378897, 15401363, -3730, 25069, 15423417, 15466155, 5258, -15501, 15508912, 15507002, -15514, 15304, 15584186, 15592290, 4702, -1017, 15614021, 15625971, -3889, 78, 15682846, 15717466, -5869, 20409, 15721592, 15748782, -8056, -17310, 15807977, 15842725, -10358, 9062, 15893358, 15897242, -22157, -21278, 15906403, 15922575, 19616, 3057, 15971469, 15968806, 4717, -16721, 16020754, 16037032, 26424, -12744, 16078207, 16105217, 4697, 3753, 16133824, 16137664, -2512, -8420, 16198183, 16209176, -12266, -5712, 16275054, 16317922, -1943, 25469, 16317613, 16345754, -23932, 19618, 16397668, 16428126, -25406, 12346, 16498037, 16488435, 4226, -7070, 16550696, 16575168, -15843, 18997, 16622376, 16658388, 20721, 3535, 16723331, 16737500, -2216, 26188, };
SingleTestContainer arrayRAND_Repeats_NotAligned_1024_c(arrayRAND_Repeats_NotAligned_1024.arr, (unsigned long)1024 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayRAND_Repeats_NotAligned_1024.arr), "arrayRAND_Repeats_NotAligned_1024");
SingleTestContainer arrayRAND_Repeats_Aligned_1024_c(arrayRAND_Repeats_Aligned_1024, (unsigned long)1024 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayRAND_Repeats_Aligned_1024), "arrayRAND_Repeats_Aligned_1024");