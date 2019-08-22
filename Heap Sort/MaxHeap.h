/*
 * MaxHeap.h
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include "ArrayOperations.h"
#include <stddef.h>

template <typename E>
class MaxHeap {
private:
	E* heap;
	int maxSize;
	int size;

	// Sift item down in heap until everything below it is smaller
	void siftDown(int pos) {
		while (!isLeaf(pos)) {
			int greaterChild = leftChild(pos); int otherChild = rightChild(pos);
			if ((otherChild < size) && heap[otherChild] > heap[greaterChild]) {
				greaterChild = otherChild;
			}
			if (heap[pos] > heap[greaterChild]) {
				return;
			}
			swap(heap,pos,greaterChild);
			pos = greaterChild;
		}
	}

	// Sift item in heap upward until it's smaller than it's parent.
	void siftUp(int pos) {
		while (pos != 0 && heap[pos] > heap[parent(pos)]) {
			swap(heap, pos, parent(pos));
			pos = parent(pos);
		}
	}

public:
	// Constructor with default arguments. Automagically heapifys array.
	MaxHeap(E* h = nullptr, int num = NULL, int max = NULL) {
		heap = h;
		size = num;
		maxSize = max;
		buildHeap();
	}

	// Destructor
	~MaxHeap() {}

	// Return current heap size
	int getSize() {
		return size;
	}

	// Determine whether position is a leaf
	bool isLeaf(int pos) {
		return (pos >= size/2) && (pos < size);
	}

	// Determine left child of position
	int leftChild(int pos) {
		return 2*pos + 1;
	}

	// Determine right child of position
	int rightChild(int pos) {
		return 2*pos + 2;
	}

	// Determine parent of position
	int parent(int pos) {
		return (pos-1)/2;
	}

	// Build heap. Sifts down every leaf position, which swaps parents into position.
	void buildHeap() {
		for (int i = size/2-1; i >= 0; --i) {
			siftDown(i);
		}
	}

	// Insert item into heap. Start at end and sift up.
	void insert(const E& element) {
		if (size >= maxSize) throw "Heap is full.";
		int curPos = size++;
		heap[curPos] = element;
		siftUp(curPos);
	}

	// Pop first (max) item. Swap root and last element, then sift down old last element.
	E removeFirst() {
		if (size <= 0) throw "Heap is empty.";
		swap(heap, 0, --size);
		if (size != 0) siftDown(0);
		return heap[size];
	}

	// Pop from arbitrary postition.
	// Swap position and last element, then sift up old last element (in case it's been moved e.g. to the other side), then sift down
	E remove(int pos) {
		if (pos < 0 || pos > size) throw "Position out of range.";
		if (pos == size-1) {
			size--;
		} else {
			swap(heap, pos, --size);
			siftUp(pos);
			if (size != 0) {
				siftDown(pos);
			}
		}
		return heap[size];
	}

	// Find item in heap. Sequential search. Returns -1 if not found.
	int find(const E& element) {
		for (int i = 0; i < size; ++i) {
			if (element == heap[i]) {
				return i;
			}
		}
		return -1;
	}
};

#endif /* MAXHEAP_H_ */
