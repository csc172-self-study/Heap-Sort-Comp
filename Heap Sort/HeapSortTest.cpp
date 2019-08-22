/*
 * HeapSortTestComp.cpp
 *
 *  Created on: Aug 22, 2019
 *      Author: alex
 */

#include "HeapSort.h"
#include <ctime>
#include <random>
#include <iostream>
using std::cout;

int main() {

	const int SIZE = 100;

	clock_t start;

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<> posDistr(0,SIZE);

	int array[SIZE]; int array1[SIZE]; int array2[SIZE]; int* sortedArray1; int* sortedArray2;
	for (int i = 0; i < SIZE; ++i) {
		array[i] = posDistr(eng);
		array1[i] = array[i];
		array2[i] = array[i];
	}

	start = clock();
	sortedArray1 = HeapSort<int>(array1, SIZE);
	double orig_sift_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	start = clock();
	sortedArray2 = HeapSort2<int>(array2, SIZE);
	double new_sift_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	for (int i = 1; i < SIZE; ++i) {
		if (sortedArray1[i] > sortedArray1[i-1]) {
			cout << "Array1 was sorted incorrectly.\n";
		}
		if (sortedArray2[i] > sortedArray2[i-1]) {
			cout << "Array2 was sorted incorrectly.\n";
		}

//		cout << "Arrays were not sorted the same. Something wrong.\n";
//					cout << sortedArray1[i] << " != " << sortedArray2[i] << "\n";
	}

	cout << "Original siftdown method took " << orig_sift_time << " s.\n";
	cout << "New siftdown method took " << new_sift_time << " s.\n";
}
