/*
* Code due to Vladimir Yaroslavskiy
* Retrieved from http://codeblab.com/wp-content/uploads/2009/09/DualPivotQuicksort.pdf
* Converted to C++ by Armin Weiß <armin.weiss@fmi.uni-stuttgart.de>
* Converted to sort inputs larger than 2^32 by Michael Axtmann <michael.axtmann@kit.edu>
* 
* Code in cpp file initially taken from https://github.com/weissan/BlockQuicksort under GPLv3.0
*/

#ifndef YAROSLAVSKIY_H
#define YAROSLAVSKIY_H
void QuickSortDualPivot_Yaroslavskiy(int* arr, unsigned int size);
void QuickSortDualPivot_YaroslavskiyV2(int* arr, unsigned int size);
void QuickSortDualPivotV2_RusevMerge32(int arr[], unsigned int size);
void QuickSortDualPivotV2_RusevMerge64(int arr[], unsigned int size);
void QuickSortTriplePivot_YaroslavskiyV3(int* arr, unsigned int size);
void QuickSortTriplePivot_YaroslavskiyV3_impr(int* arr, unsigned int size);

#endif // YAROSLAVSKIY_H
