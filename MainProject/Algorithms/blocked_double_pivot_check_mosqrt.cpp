/* Github link:
* Code initially taken from https://github.com/weissan/BlockQuicksort under GPLv3.0
*/
#include "blocked_double_pivot_check_mosqrt.h"

using namespace blocked_double_pivot_check_mosqrt;

#define PRINT_LOAD_SAVE_TIMES_OFF

#ifdef PRINT_LOAD_SAVE_TIMES_ON
#include "../Tools/Time_Measure_Chrono_ns.h"
#endif

void blocked_double_pivot_check_mosqrt_sort(int* arr, unsigned int size) {
#ifdef PRINT_LOAD_SAVE_TIMES_ON
	auto startTimeStamp = getTime_Since_Epoch_ns();
	nanoseconds execTime;	
#endif // PRINT_LOAD_SAVE_TIMES_ON

	std::vector<int> testArray(arr, (arr+size));
#ifdef PRINT_LOAD_SAVE_TIMES_ON
	execTime = getTime_Since_Epoch_ns() - startTimeStamp;
	auto timeNS = static_cast<unsigned long long>(execTime.count());
	std::cout << "-------------------\nLoad time for array of size : " << size << "  time : " << timeNS << endl;
	
	startTimeStamp = getTime_Since_Epoch_ns();

#endif

	sort<int>(testArray);

#ifdef PRINT_LOAD_SAVE_TIMES_ON
	execTime = getTime_Since_Epoch_ns() - startTimeStamp;
	timeNS = static_cast<unsigned long long>(execTime.count());
	std::cout << "SORT time for array of size : " << size << "  time : " << timeNS << endl;

	startTimeStamp = getTime_Since_Epoch_ns();

#endif // PRINT_LOAD_SAVE_TIMES_ON
	for (int i = 0; i < testArray.size(); i++) {
		arr[i] = testArray[i];
	}

#ifdef PRINT_LOAD_SAVE_TIMES_ON
	execTime = getTime_Since_Epoch_ns() - startTimeStamp;
	timeNS = static_cast<unsigned long long>(execTime.count());
	std::cout << "SAVE time for array of size : " << size << "  time : " << timeNS << "\n-------------------\n";
#endif


}
