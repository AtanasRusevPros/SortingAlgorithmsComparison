#include "../../Tools/TestDescriptor.h"
#define SIZE_arrayRAND_Repeats1024 1024
typedef struct arrayRAND_Repeats_NotAligned_1024_s{
    Offset_Struct_92Bytes_t offStruct;
    int arr[SIZE_arrayRAND_Repeats1024];
} arrayRAND_Repeats_NotAligned_1024_t;

alignas(4) arrayRAND_Repeats_NotAligned_1024_t arrayRAND_Repeats_NotAligned_1024 = { offset_alignment, {36813, 49938, -24590, -19591, 72520, 82264, -11268, 13002, 129679, 170494, -3282, 9406, 236302, 250086, -16875, 13729, 328547, 336737, -21445, -1857, 380002, 414009, -21460, 10339, 481809, 501162, -7306, -6692, 545966, 573540, 28324, -1678, 614822, 663178, -24255, 4723, 695452, 713655, -14885, -30932, 774246, 811764, -8707, 5351, 880657, 911298, 25139, 8178, 937947, 933654, 520, -3177, 1056312, 1048662, 25609, 548, 1121486, 1119841, -6717, 9442, 1153401, 1181828, -9280, -9184, 1222470, 1213316, -11891, -28887, 1283963, 1286809, -13898, -13238, 1323659, 1341552, -569, 2252, 1356069, 1366057, 7756, -7938, 1439015, 1433174, 4817, -10197, 1508003, 1489410, -17951, 6303, 1521890, 1553832, 10506, -19547, 1592157, 1605687, -4905, -7797, 1669829, 1685012, -14124, -15972, 1707516, 1714712, 30605, 6692, 1772313, 1797773, -5490, -26514, 1814630, 1842740, 2658, 4295, 1879396, 1893697, -2410, 15996, 1940422, 1952349, 17847, 982, 2013297, 2045859, 17743, 10789, 2055298, 2081699, -17940, 8626, 2111048, 2144867, -24809, -15926, 2212422, 2254424, 26464, -30535, 2294835, 2300273, -17328, 23499, 2359289, 2356747, -16781, 18252, 2388663, 2390012, 17752, 16007, 2476993, 2473355, -24696, -9269, 2516382, 2494581, -11633, 8288, 2555657, 2567914, -9477, -19307, 2618353, 2643086, -5033, -22604, 2700921, 2720633, 12590, 12299, 2754552, 2788663, 2830, -5403, 2814457, 2841544, 21121, 7308, 2850619, 2882208, 5909, -4016, 2929842, 2973607, 24405, 14458, 3033732, 3044409, -5940, 11863, 3122443, 3137062, 26631, -19917, 3182041, 3180723, -14190, 2906, 3222704, 3239320, -4871, -22503, 3293318, 3317248, 28360, -8775, 3381382, 3378060, -8565, 10377, 3427601, 3477839, 975, -5163, 3520696, 3554513, 7453, -19994, 3551554, 3561231, -24572, 27659, 3604652, 3616122, -1777, -19826, 3677732, 3709684, -13367, -31556, 3745550, 3789014, 12992, 2275, 3839999, 3858413, -129, -13238, 3917250, 3932535, 31377, -31934, 4003417, 4038698, 9092, -14060, 4061686, 4104492, -3870, -8179, 4137981, 4123930, -28616, -3718, 4195340, 4241669, -23022, -12891, 4226802, 4231024, 3581, 11226, 4286385, 4266324, -25981, -5529, 4307073, 4335388, 21809, -12648, 4393933, 4389289, 16019, 17591, 4412723, 4442958, 3637, 8209, 4479623, 4495572, -3421, -9486, 4582608, 4598390, 20841, 22181, 4612426, 4644071, 1811, 7031, 4737633, 4762183, -22740, -26442, 4812987, 4846384, 15426, 25769, 4885550, 4884398, 2015, -863, 4930756, 4943937, -15727, 1255, 4965311, 4978398, -9246, 2249, 5012625, 5009389, 14943, 14993, 5051871, 5063496, -1131, 13196, 5081732, 5125439, -19442, -19449, 5167761, 5205912, 12119, -7348, 5276745, 5294730, -20484, 4007, 5356835, 5363138, 12169, -4505, 5401290, 5415264, 7819, -9260, 5463067, 5523191, 9356, 6973, 5554732, 5583505, 24601, 5868, 5630276, 5647272, 9917, 8240, 5681627, 5676588, -15098, -20655, 5720484, 5743492, -16769, -23650, 5776511, 5819268, 3508, 865, 5846403, 5875066, -7120, 15336, 5924861, 5966119, -5504, -7811, 6019179, 6037437, 49, -4243, 6114688, 6106342, -1074, -30715, 6156581, 6199230, -5406, 13455, 6244723, 6271955, -11782, -23208, 6353337, 6375979, -4958, 29100, 6427514, 6447677, 28007, -10281, 6463341, 6474485, -16942, -732, 6538879, 6579125, 15986, 11745, 6632142, 6661455, -31021, 7513, 6684843, 6712075, -23170, 9688, 6748065, 6781863, 24578, 2217, 6849384, 6869585, -3350, 11802, 6941936, 6956975, -11839, 25974, 7000925, 7027415, -6379, 9480, 7070980, 7101014, 21617, -13794, 7166066, 7187756, -19872, -9982, 7218532, 7257037, 20592, 15617, 7273934, 7289121, -2773, 2152, 7341784, 7342981, -25057, -19327, 7393757, 7411144, -16427, -7783, 7476586, 7487533, 1501, 5884, 7579203, 7586157, 4800, 758, 7614562, 7645111, 16395, 15059, 7647214, 7676326, -8630, -1313, 7711304, 7735123, -2807, 26214, 7776003, 7775042, 724, -14413, 7825637, 7846769, 15670, 20500, 7923435, 7952976, -12098, 22484, 7996738, 7985091, 8436, 7743, 8031823, 8036898, -30618, 2464, 8088489, 8111930, 6306, -6331, 8134426, 8142154, 23088, 11127, 8223649, 8252421, 3230, -20090, 8330864, 8320405, -6535, -1092, 8366065, 8404885, 21835, -3229, 8434878, 8436758, -16991, 10443, 8459940, 8483483, -17657, 4925, 8539559, 8538395, -8182, -12026, 8569088, 8588549, -2508, -6286, 8665112, 8666168, 15890, 716, 8721295, 8752646, 12080, -18846, 8767031, 8797241, -18407, 15487, 8850968, 8883213, -421, 13935, 8908141, 8918835, 7810, -4995, 8971174, 8967372, -5097, 3575, 9037411, 9036402, 12713, -3800, 9050750, 9080114, -3902, -11430, 9129218, 9149067, 8688, 6365, 9219117, 9228657, 29885, 3323, 9289842, 9290572, 4022, -24066, 9348472, 9360632, -12184, 12598, 9405211, 9439173, 2909, -17684, 9455210, 9470585, -13278, 9837, 9509543, 9558601, 5443, 517, 9577033, 9575395, 8268, -15616, 9662460, 9671782, -25142, 1450, 9715615, 9755240, -2745, -12978, 9793348, 9803502, 1360, -15301, 9844788, 9866871, -7312, -1095, 9938920, 9955825, -25548, -21482, 9984273, 10010562, -3287, 29855, 10054799, 10050751, 8922, 7071, 10109565, 10145079, 7379, 20065, 10187554, 10200551, -13921, -7885, 10258434, 10292489, 18636, 3935, 10351820, 10355519, 12516, 15154, 10408039, 10448038, -12428, 11768, 10505713, 10541521, 26889, 22525, 10581430, 10621122, -1747, 4237, 10690108, 10671601, -3475, 22005, 10724663, 10745162, -427, 3455, 10774678, 10783536, -17039, 17272, 10813300, 10816883, 1869, -5333, 10892071, 10916956, 10869, 7910, 10958900, 10970025, -21387, -8204, 11052888, 11056009, 2520, -10592, 11122304, 11123102, -2516, 4663, 11186639, 11203075, 7164, 18694, 11252895, 11282500, 23763, 6232, 11313785, 11354208, -28353, 17528, 11395100, 11419594, 18634, -1869, 11455611, 11474540, 2562, 1877, 11532734, 11544481, -28047, -22101, 11609662, 11604792, -26972, -16385, 11629964, 11648632, 551, 4510, 11725163, 11738391, 14215, 3283, 11770577, 11778625, -12211, -30996, 11809514, 11796887, -8951, -971, 11838486, 11847725, 9540, -12297, 11870950, 11900298, -6261, -29566, 11951905, 11971756, 6505, 8990, 12057796, 12047616, 10092, 11290, 12078332, 12084077, -19169, 9920, 12142381, 12157769, -8947, 14685, 12206574, 12238689, -3900, -3778, 12250121, 12274420, -18225, 686, 12322175, 12323513, 13497, 2296, 12343428, 12344790, -9457, -14743, 12415613, 12429032, -9890, -7091, 12492037, 12489982, 21552, -19728, 12556012, 12561563, 10002, -5730, 12619059, 12619962, 9360, -6493, 12669972, 12684229, -10698, -4277, 12738553, 12736669, 15505, -4126, 12811904, 12823444, 3883, 15283, 12865403, 12876659, -880, 19724, 12942836, 12978808, -5554, 1336, 12990758, 13021011, -19216, -4989, 13069694, 13065766, -4095, -3528, 13057440, 13103497, -23025, -21339, 13122403, 13153160, 6309, 6421, 13197523, 13215399, 79, -9261, 13257006, 13274838, -13160, 44, 13314535, 13351550, -7155, 14445, 13372325, 13405051, 25659, -25121, 13419331, 13418525, -7764, 28881, 13478610, 13499433, 10221, -10098, 13507218, 13537751, -1654, 9059, 13574653, 13568722, -12273, 1690, 13664445, 13660475, 7177, -8576, 13721519, 13752485, 1281, 28257, 13781480, 13838103, -22138, 8328, 13886895, 13934096, -8414, -14781, 13987199, 14001024, -3485, -10275, 14051592, 14076617, -6444, -19296, 14100011, 14097860, 14081, 25308, 14152193, 14165438, 5238, -12326, 14225876, 14267509, 10174, 4072, 14351395, 14380319, -12186, 7760, 14438817, 14454115, -6917, 7520, 14456374, 14480987, -3321, 5730, 14559740, 14579100, -232, -18013, 14647875, 14634535, 17591, 7792, 14688909, 14680436, -2444, 786, 14734737, 14768238, -552, 3288, 14788155, 14789751, 15215, 2061, 14850218, 14839908, -14648, 10237, 14885679, 14907771, -20884, 18163, 14903127, 14944378, 14311, -22979, 15018711, 15045263, -24633, 11814, 15077535, 15092319, -9833, -20998, 15143380, 15165697, -12318, 7172, 15218379, 15218435, 9270, -10863, 15274002, 15324516, -4323, -8466, 15331173, 15320727, 37, 9061, 15392952, 15382406, 7641, 13636, 15426355, 15468684, -14908, 3540, 15491632, 15472250, -5005, 19812, 15527486, 15549330, 15730, -1216, 15611425, 15614095, -9394, -14926, 15679441, 15668635, 8080, -15865, 15720823, 15723351, -9529, 11402, 15792754, 15799254, 5247, -22391, 15821909, 15848352, 19265, 79, 15913961, 15919795, -19300, -6872, 15958568, 15981949, -741, 12127, 16004417, 16023011, 2121, 7746, 16060822, 16069693, 12468, 6171, 16145088, 16156758, 2023, -5576, 16182409, 16181872, 5741, -30493, 16217072, 16235582, 7124, 20329, 16279593, 16259561, -12634, 16406, 16335770, 16343820, 7280, -15305, 16415967, 16450487, -5698, -5098, }};
alignas(4096) int arrayRAND_Repeats_Aligned_1024 [1024] = {36813, 49938, -24590, -19591, 72520, 82264, -11268, 13002, 129679, 170494, -3282, 9406, 236302, 250086, -16875, 13729, 328547, 336737, -21445, -1857, 380002, 414009, -21460, 10339, 481809, 501162, -7306, -6692, 545966, 573540, 28324, -1678, 614822, 663178, -24255, 4723, 695452, 713655, -14885, -30932, 774246, 811764, -8707, 5351, 880657, 911298, 25139, 8178, 937947, 933654, 520, -3177, 1056312, 1048662, 25609, 548, 1121486, 1119841, -6717, 9442, 1153401, 1181828, -9280, -9184, 1222470, 1213316, -11891, -28887, 1283963, 1286809, -13898, -13238, 1323659, 1341552, -569, 2252, 1356069, 1366057, 7756, -7938, 1439015, 1433174, 4817, -10197, 1508003, 1489410, -17951, 6303, 1521890, 1553832, 10506, -19547, 1592157, 1605687, -4905, -7797, 1669829, 1685012, -14124, -15972, 1707516, 1714712, 30605, 6692, 1772313, 1797773, -5490, -26514, 1814630, 1842740, 2658, 4295, 1879396, 1893697, -2410, 15996, 1940422, 1952349, 17847, 982, 2013297, 2045859, 17743, 10789, 2055298, 2081699, -17940, 8626, 2111048, 2144867, -24809, -15926, 2212422, 2254424, 26464, -30535, 2294835, 2300273, -17328, 23499, 2359289, 2356747, -16781, 18252, 2388663, 2390012, 17752, 16007, 2476993, 2473355, -24696, -9269, 2516382, 2494581, -11633, 8288, 2555657, 2567914, -9477, -19307, 2618353, 2643086, -5033, -22604, 2700921, 2720633, 12590, 12299, 2754552, 2788663, 2830, -5403, 2814457, 2841544, 21121, 7308, 2850619, 2882208, 5909, -4016, 2929842, 2973607, 24405, 14458, 3033732, 3044409, -5940, 11863, 3122443, 3137062, 26631, -19917, 3182041, 3180723, -14190, 2906, 3222704, 3239320, -4871, -22503, 3293318, 3317248, 28360, -8775, 3381382, 3378060, -8565, 10377, 3427601, 3477839, 975, -5163, 3520696, 3554513, 7453, -19994, 3551554, 3561231, -24572, 27659, 3604652, 3616122, -1777, -19826, 3677732, 3709684, -13367, -31556, 3745550, 3789014, 12992, 2275, 3839999, 3858413, -129, -13238, 3917250, 3932535, 31377, -31934, 4003417, 4038698, 9092, -14060, 4061686, 4104492, -3870, -8179, 4137981, 4123930, -28616, -3718, 4195340, 4241669, -23022, -12891, 4226802, 4231024, 3581, 11226, 4286385, 4266324, -25981, -5529, 4307073, 4335388, 21809, -12648, 4393933, 4389289, 16019, 17591, 4412723, 4442958, 3637, 8209, 4479623, 4495572, -3421, -9486, 4582608, 4598390, 20841, 22181, 4612426, 4644071, 1811, 7031, 4737633, 4762183, -22740, -26442, 4812987, 4846384, 15426, 25769, 4885550, 4884398, 2015, -863, 4930756, 4943937, -15727, 1255, 4965311, 4978398, -9246, 2249, 5012625, 5009389, 14943, 14993, 5051871, 5063496, -1131, 13196, 5081732, 5125439, -19442, -19449, 5167761, 5205912, 12119, -7348, 5276745, 5294730, -20484, 4007, 5356835, 5363138, 12169, -4505, 5401290, 5415264, 7819, -9260, 5463067, 5523191, 9356, 6973, 5554732, 5583505, 24601, 5868, 5630276, 5647272, 9917, 8240, 5681627, 5676588, -15098, -20655, 5720484, 5743492, -16769, -23650, 5776511, 5819268, 3508, 865, 5846403, 5875066, -7120, 15336, 5924861, 5966119, -5504, -7811, 6019179, 6037437, 49, -4243, 6114688, 6106342, -1074, -30715, 6156581, 6199230, -5406, 13455, 6244723, 6271955, -11782, -23208, 6353337, 6375979, -4958, 29100, 6427514, 6447677, 28007, -10281, 6463341, 6474485, -16942, -732, 6538879, 6579125, 15986, 11745, 6632142, 6661455, -31021, 7513, 6684843, 6712075, -23170, 9688, 6748065, 6781863, 24578, 2217, 6849384, 6869585, -3350, 11802, 6941936, 6956975, -11839, 25974, 7000925, 7027415, -6379, 9480, 7070980, 7101014, 21617, -13794, 7166066, 7187756, -19872, -9982, 7218532, 7257037, 20592, 15617, 7273934, 7289121, -2773, 2152, 7341784, 7342981, -25057, -19327, 7393757, 7411144, -16427, -7783, 7476586, 7487533, 1501, 5884, 7579203, 7586157, 4800, 758, 7614562, 7645111, 16395, 15059, 7647214, 7676326, -8630, -1313, 7711304, 7735123, -2807, 26214, 7776003, 7775042, 724, -14413, 7825637, 7846769, 15670, 20500, 7923435, 7952976, -12098, 22484, 7996738, 7985091, 8436, 7743, 8031823, 8036898, -30618, 2464, 8088489, 8111930, 6306, -6331, 8134426, 8142154, 23088, 11127, 8223649, 8252421, 3230, -20090, 8330864, 8320405, -6535, -1092, 8366065, 8404885, 21835, -3229, 8434878, 8436758, -16991, 10443, 8459940, 8483483, -17657, 4925, 8539559, 8538395, -8182, -12026, 8569088, 8588549, -2508, -6286, 8665112, 8666168, 15890, 716, 8721295, 8752646, 12080, -18846, 8767031, 8797241, -18407, 15487, 8850968, 8883213, -421, 13935, 8908141, 8918835, 7810, -4995, 8971174, 8967372, -5097, 3575, 9037411, 9036402, 12713, -3800, 9050750, 9080114, -3902, -11430, 9129218, 9149067, 8688, 6365, 9219117, 9228657, 29885, 3323, 9289842, 9290572, 4022, -24066, 9348472, 9360632, -12184, 12598, 9405211, 9439173, 2909, -17684, 9455210, 9470585, -13278, 9837, 9509543, 9558601, 5443, 517, 9577033, 9575395, 8268, -15616, 9662460, 9671782, -25142, 1450, 9715615, 9755240, -2745, -12978, 9793348, 9803502, 1360, -15301, 9844788, 9866871, -7312, -1095, 9938920, 9955825, -25548, -21482, 9984273, 10010562, -3287, 29855, 10054799, 10050751, 8922, 7071, 10109565, 10145079, 7379, 20065, 10187554, 10200551, -13921, -7885, 10258434, 10292489, 18636, 3935, 10351820, 10355519, 12516, 15154, 10408039, 10448038, -12428, 11768, 10505713, 10541521, 26889, 22525, 10581430, 10621122, -1747, 4237, 10690108, 10671601, -3475, 22005, 10724663, 10745162, -427, 3455, 10774678, 10783536, -17039, 17272, 10813300, 10816883, 1869, -5333, 10892071, 10916956, 10869, 7910, 10958900, 10970025, -21387, -8204, 11052888, 11056009, 2520, -10592, 11122304, 11123102, -2516, 4663, 11186639, 11203075, 7164, 18694, 11252895, 11282500, 23763, 6232, 11313785, 11354208, -28353, 17528, 11395100, 11419594, 18634, -1869, 11455611, 11474540, 2562, 1877, 11532734, 11544481, -28047, -22101, 11609662, 11604792, -26972, -16385, 11629964, 11648632, 551, 4510, 11725163, 11738391, 14215, 3283, 11770577, 11778625, -12211, -30996, 11809514, 11796887, -8951, -971, 11838486, 11847725, 9540, -12297, 11870950, 11900298, -6261, -29566, 11951905, 11971756, 6505, 8990, 12057796, 12047616, 10092, 11290, 12078332, 12084077, -19169, 9920, 12142381, 12157769, -8947, 14685, 12206574, 12238689, -3900, -3778, 12250121, 12274420, -18225, 686, 12322175, 12323513, 13497, 2296, 12343428, 12344790, -9457, -14743, 12415613, 12429032, -9890, -7091, 12492037, 12489982, 21552, -19728, 12556012, 12561563, 10002, -5730, 12619059, 12619962, 9360, -6493, 12669972, 12684229, -10698, -4277, 12738553, 12736669, 15505, -4126, 12811904, 12823444, 3883, 15283, 12865403, 12876659, -880, 19724, 12942836, 12978808, -5554, 1336, 12990758, 13021011, -19216, -4989, 13069694, 13065766, -4095, -3528, 13057440, 13103497, -23025, -21339, 13122403, 13153160, 6309, 6421, 13197523, 13215399, 79, -9261, 13257006, 13274838, -13160, 44, 13314535, 13351550, -7155, 14445, 13372325, 13405051, 25659, -25121, 13419331, 13418525, -7764, 28881, 13478610, 13499433, 10221, -10098, 13507218, 13537751, -1654, 9059, 13574653, 13568722, -12273, 1690, 13664445, 13660475, 7177, -8576, 13721519, 13752485, 1281, 28257, 13781480, 13838103, -22138, 8328, 13886895, 13934096, -8414, -14781, 13987199, 14001024, -3485, -10275, 14051592, 14076617, -6444, -19296, 14100011, 14097860, 14081, 25308, 14152193, 14165438, 5238, -12326, 14225876, 14267509, 10174, 4072, 14351395, 14380319, -12186, 7760, 14438817, 14454115, -6917, 7520, 14456374, 14480987, -3321, 5730, 14559740, 14579100, -232, -18013, 14647875, 14634535, 17591, 7792, 14688909, 14680436, -2444, 786, 14734737, 14768238, -552, 3288, 14788155, 14789751, 15215, 2061, 14850218, 14839908, -14648, 10237, 14885679, 14907771, -20884, 18163, 14903127, 14944378, 14311, -22979, 15018711, 15045263, -24633, 11814, 15077535, 15092319, -9833, -20998, 15143380, 15165697, -12318, 7172, 15218379, 15218435, 9270, -10863, 15274002, 15324516, -4323, -8466, 15331173, 15320727, 37, 9061, 15392952, 15382406, 7641, 13636, 15426355, 15468684, -14908, 3540, 15491632, 15472250, -5005, 19812, 15527486, 15549330, 15730, -1216, 15611425, 15614095, -9394, -14926, 15679441, 15668635, 8080, -15865, 15720823, 15723351, -9529, 11402, 15792754, 15799254, 5247, -22391, 15821909, 15848352, 19265, 79, 15913961, 15919795, -19300, -6872, 15958568, 15981949, -741, 12127, 16004417, 16023011, 2121, 7746, 16060822, 16069693, 12468, 6171, 16145088, 16156758, 2023, -5576, 16182409, 16181872, 5741, -30493, 16217072, 16235582, 7124, 20329, 16279593, 16259561, -12634, 16406, 16335770, 16343820, 7280, -15305, 16415967, 16450487, -5698, -5098, };
SingleTestContainer arrayRAND_Repeats_NotAligned_1024_c(arrayRAND_Repeats_NotAligned_1024.arr, (unsigned long)1024 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::NOT_ALIGNED, sizeof(arrayRAND_Repeats_NotAligned_1024.arr), "arrayRAND_Repeats_NotAligned_1024");
SingleTestContainer arrayRAND_Repeats_Aligned_1024_c(arrayRAND_Repeats_Aligned_1024, (unsigned long)1024 , TestDataType::RAND_with_Repeats, TestDataSizeType::SMALL_32_2050, TestDataAlignment::ALIGNED, sizeof(arrayRAND_Repeats_Aligned_1024), "arrayRAND_Repeats_Aligned_1024");