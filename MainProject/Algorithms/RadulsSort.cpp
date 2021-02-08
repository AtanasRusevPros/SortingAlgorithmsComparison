
#include <iostream>
#include <chrono>
#include <random>

#include "Raduls/raduls.h"

using namespace raduls;

void RadulsSortWrap(int arr[], unsigned int size) {
	
	/*
	// explicitly set the thread to 1 - reason - we want to test against the other single-core tested algorithms
	auto n_threads = 1; //  std::thread::hardware_concurrency();

	// our input size is coming as input
	// uint64_t n_recs = 100000000;
	uint32_t key_size = 8;
	
	uint8_t* alignedVersion = nullptr;
		
	if (reinterpret_cast<std::uintptr_t>(arr) % ALIGNMENT) {
		// todo: realign
		alignedVersion = new uint8_t[size * sizeof(uint64_t) + raduls::ALIGNMENT];
		for (unsigned int i = 0; i < size; i++) {
			alignedVersion[i] = arr[i];
		}
	}
	else {
		alignedVersion = reinterpret_cast<uint8_t *>(arr);
	}

	
	auto tempArray = new uint8_t[size * sizeof(uint64_t) + raduls::ALIGNMENT];
	
	auto input = reinterpret_cast<uint64_t*>(alignedVersion);
	auto tmp = reinterpret_cast<uint64_t*>(tempArray);

	while (reinterpret_cast<uintptr_t>(input) % raduls::ALIGNMENT) ++input;
	while (reinterpret_cast<uintptr_t>(tmp) % raduls::ALIGNMENT) ++tmp;

	
	raduls::CleanTmpArray(reinterpret_cast<uint8_t*>(tmp), size, sizeof(uint64_t), n_threads);
	
	raduls::RadixSortMSD(reinterpret_cast<uint8_t*>(input), reinterpret_cast<uint8_t*>(tmp), size, sizeof(uint64_t), key_size, n_threads);
	
	auto result = key_size % 2 ? tmp : input;
	
	delete[] alignedVersion; delete[] tempArray;*/
}