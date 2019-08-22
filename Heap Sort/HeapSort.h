/*
 * HeapSort.h
 *
 *  Created on: Jul 22, 2019
 *      Author: alex
 */

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include "MaxHeap.h"
#include "MaxHeap2.h"

template <typename E>
E* HeapSort2(E array[], int size) {
	int* tempArray = new int[size];
	MaxHeap2<E> heap(array, size, size);
	for (int i = 0; i < size; ++i) {
		tempArray[i] = heap.removeFirst();
	}
	return tempArray;
}

template <typename E>
E* HeapSort(E array[], int size) {
	int* tempArray = new int[size];
	MaxHeap<E> heap(array, size, size);
	for (int i = 0; i < size; ++i) {
		tempArray[i] = heap.removeFirst();
	}
	return tempArray;
}

#endif /* HEAPSORT_H_ */
