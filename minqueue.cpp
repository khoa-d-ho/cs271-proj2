//========================================================
// Khoa Ho, Hoang Ngo
// minqueue.cpp
// February 2024
// This file contains the class methods for the
// MinQueue Priority Queue using heaps.
//========================================================

#include "minqueue.h"
#include <string>
#include <sstream>
using namespace std;

template <class T>
		MinQueue<T>::Minqueue		( void )
{
	heap = new T[capacity];
}

template <class T>
MinQueue<T>::MinQueue(T* array, int arraySize) 
{
    heap = new T[capacity];
    for (int i = 0; i < arraySize; i++) 
    {
        heap[i] = array[i];
    }
    for (int i = (heapSize / 2) - 1; i >= 0; --i) {
        heapify(i);
    }
}

template <class T>
MinQueue<T>::~MinQueue() {
    delete[] heap;
}

template <class T>
void MinQueue<T>::insert(const T& value) {
    if (heapSize == capacity) {
        resizeHeap();
    }
    heapSize++;
    int i = heapSize - 1;
    heap[i] = value;
    
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template <class T>
T MinQueue<T>::min() const {
    if (isEmpty()) {
        cout << "MinQueue is empty." << endl;
        return T();
    return heap[0];
}

template <class T>
T MinQueue<T>::extractMin() {
    if (isEmpty()) {
        cout << "MinQueue is empty." << endl;
        return T();
    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }

    T root = heap[0];
    heap[0] = heap[heapSize-1];
    heapSize--;
    minHeapify(0);

    return root;
}

template <class T>
void MinQueue<T>::decreaseKey(int i, T newValue) {
    heap[i] = newValue;
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template <class T>
void MinQueue<T>::heapify(int i) 
{
    int l = left(i);
    int r = right(i);

    if (l <= heapSize && heap[l] < heap[smallest]) 
    {
        smallest = l;
    }
    else smallest = i;

    if (r <= heapSize && heap[r] < heap[smallest]) 
    {
        smallest = r;
    }
    if (smallest != i) 
    {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

template <class T>
void MinQueue<T>::build_min_heap(void) 
{
    headSize = T[capacity]
    for (int i = (heapSize / 2) - 1; i >= 0; i--) 
    {
        heapify(i);
    }
}

template <class T>
void MinQueue<T>::sort(T* outArray) 
{
    build_min_heap();
    
    int originalSize = heapSize;
    
    for (int i = 0; i < originalSize; i++) 
    {
        outArray[i] = extractMin(); 
    }

    heapSize = originalSize;
    for (int i = 0; i < heapSize; i++) 
    {
        insert(outArray[i]);
    }
}








