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
MinQueue<T>::MinQueue(T* array, int arraySize) {
    heap = new T[capacity];
    for (int i = 0; i < arraySize; ++i) {
        heap[i] = array[i];
    }
    for (int i = (heapSize / 2) - 1; i >= 0; --i) {
        minHeapify(i);
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
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template <class T>
T MinQueue<T>::min() const {
    if (isEmpty())
        throw std::runtime_error("MinQueue is empty");
    return heap[0];
}

template <class T>
T MinQueue<T>::extractMin() {
    if (isEmpty())
        throw std::runtime_error("MinQueue is empty");
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
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}











