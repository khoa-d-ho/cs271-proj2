//========================================================
// Khoa Ho, Hoang Ngo
// minqueue.cpp
// February 2024
// This file contains the class methods for the
// MinQueue Priority Queue using heaps.
//========================================================

#include <iostream>
#include "minqueue.h"
#include <string>
#include <chrono>
#include <sstream> 
#include <algorithm>
using namespace std;

//========================================================
// MinQueue
// Default constructor creating an empty min-priority queue.
// This constructor initializes a min-priority queue with a default capacity.The queue
// starts with no elements, and is ready to have elements inserted.
// Parameters: None
// Return Value: None
//========================================================
template <class T>
		MinQueue<T>::MinQueue		( void )
{
    capacity = 1; // initial capacity
    heapSize = 0; // initial heap size, which is an empty heap
	heap = new T[capacity]; // allocate the heap to the initial capacity
}

//========================================================
// MinQueue
// Constructor: creates a min priority queue from an existing array of elements.
// This constructor copies elements from the given array into the heap structure
// and builds a min-heap to ensure the min priority queue maintained.
// Parameters:
// T* array - Pointer to the array of elements to be copied into the queue.
// int size - Number of elements in the array to be copied.
// Return Value: None
//========================================================
template <class T>
        MinQueue<T>::MinQueue       ( T* A, int n ) 
{
    capacity = n * 2; // initial capacity to 2 times the size in case the heap growth
    heapSize = n; // initial the heapSizw to the size of the array
    heap = new T[capacity]; // allocate the heap with the capacity
    for (int i = 0; i < n; i++) 
    {
        heap[i] = A[i]; // copy elements from the array to the heap
    }
    build_heap(); // Reorganize the copied elements to a min-heap
}

//==============================================================
// ~MinQueue
// Destructor to clean up the memory of the set.
// Parameters: None
// Return Value: None
//==============================================================
template <class T>
        MinQueue<T>::~MinQueue      ( void ) 
{
    delete[] heap;
}

//========================================================
// insert
// Inserts a new element into the min-priority queue.
// Parameters: const T& x - The value to insert into the queue.
// Return Value: None
//========================================================
template <class T>
void    MinQueue<T>::insert         ( const T& x ) 
{
    if (heapSize == capacity) 
    {
        allocate(capacity * 2);
    }
    int i = heapSize++;
    heap[i] = x;
    
    while (i != 0 && heap[parent(i)] > heap[i]) 
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

//========================================================
// min
// Returns the smallest element in the min-priority queue without removing it.
// Parameters: None
// Return Value: The smallest element in the min-priority queue.
//========================================================
template <class T>
T       MinQueue<T>::min               ( void )   const {
    if (heapSize == 0) {
        cout << "MinQueue is empty 1." << endl;
        return T(); // Return a default-constructed object of type T
    }
    // If heapSize is not 0, return the smallest element
    return heap[0]; // Smallest element is at the root of the heap.
}


//========================================================
// extractMin
// Removes and returns the smallest element in the min-priority queue.
// Parameters: None
// Return Value: The smallest element in the min-priority queue, or a default-constructed object of type T if the queue is empty.
//========================================================
template <class T>
T       MinQueue<T>::extract_min     ( void ) 
{
    if (heapSize == 0) 
    {
        cout << "MinQueue is empty 2." << endl;
        return T();
    }

    T min = heap[0]; // Get the min value of the heap
    heap[0] = heap[heapSize-1]; // Move the last element of the heap to the root
    heapSize--; // Decrease the heap size by 1

    min_heapify(0); // heapify to maintain the min-heap property.

    return min; // return the minimum element that was removed form the heap
}

//========================================================
// decreaseKey
// Decreases the value of an element at index i in the heap to k and
// maintained the min-heap property.
// Parameters:
// int i - The index of the element to decrease.
// T k - The new value for the element.
// Return Value: None
//========================================================
template <class T>
void    MinQueue<T>::decrease_key        ( int i, T k ) 
{
    if (i < 0 || i >= heapSize) 
    {
        return; // if the index is out of bound, return.
    }

    if (k >= heap[i]) // check if the new value is actually less than the current value at index i.
    {
        return; // if the new value is not less, return.
    }

    heap[i] = k; // replace the k with the current value at index i.

    while (i != 0 && heap[parent(i)] > heap[i]) // maintaining the heap property.
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }

}

//========================================================
// heapify
// Adjusts the subtree rooted at index i to satisfy the min-heap property.
// Parameters: int i - The index of the root of the subtree to be heapified.
// Return Value: None
//========================================================
template <class T>
void    MinQueue<T>::min_heapify            ( int i ) 
{
    int l = left(i); // index of the left child
    int r = right(i); // index of the right child
    int smallest = i; // initialize smallest as root

    if (l < heapSize && heap[l] < heap[smallest]) // if the left child is smaller than i
    {
        smallest = l; // make the left child the smallest
    }

    if (r < heapSize && heap[r] < heap[smallest]) // if the right child is smaller than i
    {
        smallest = r; // make the right child the smallest
    }
    if (smallest != i) // if the smallest is not at the root
    {
        swap(heap[i], heap[smallest]); // swap the root with the smallest child
        min_heapify(smallest); // continue heapify
    }
}

//========================================================
// build_heap
// Constructs a min-heap from an unsorted array. This method iterates over all non-leaf nodes
// of the heap and applies heapify to each one in a bottom-up manner, ensuring the entire
// array satisfies the min-heap property by the end.
// Parameters: None
// Return Value: None
//========================================================
template <class T>
void    MinQueue<T>::build_heap     ( void ) 
{
    for (int i = (heapSize / 2); i >= 0; i--) // start form the last non-leaf node and work to the root.
    {
        min_heapify(i);
    }
}

//========================================================
// sort
// Sorts the elements of the min-heap into ascending order and stores the result in an array A.
// Parameters: T* A - Pointer to the array where sorted elements will be stored.
// Preconditions: A is assumed to have enough space to store all elements of the heap.
// Return Value: None
//========================================================

template <class T>
void    MinQueue<T>::sort               (T* A) 
{
    int size = heapSize; // get the original heapSize because the extract_min function will change the heapSize

    for (int i = 0; i < size; i++)
    {
        A[i] = extract_min(); // adding value in array in ascending order.
    }
}

//========================================================
// to_string
// Returns a string representation of the min-heap.
// Parameters: None
// Preconditions: None
// Return Value: A string representation of the heap.
//========================================================
template <class T>
string  MinQueue<T>::to_string          ( void ) const 
{
    stringstream ss; 

    for (int i = 0; i < heapSize ; ++i) {
        ss << heap[i];
        if (i < heapSize - 1) 
        { 
            ss << " "; // if it is not the last element, add space
        }
    }

    return ss.str(); // Convert the stringstream to a string and return it    
}


// template <class T>
// string MinQueue<T>::to_string( void ) const
// {
//     stringstream result;
//     for(int i = 0; i <= heapSize; i++)
//     {
//         result << heap[i] << " ";
//     }

//     return result.str();
// }

//========================================================
// set
// Directly sets the value of the element at index i in the heap to a new value.
// Parameters:
// int i - The index of the element to modify.
// T val - The new value for the element at index i.
// Preconditions: The index i must be within the bounds of the heap.
// Return Value: None
//========================================================
template <class T>
void    MinQueue<T>::set                ( int i, T val ) 
{
    if (i == heapSize && i < capacity) 
    {
        heapSize++;
    }

    if (i >= 0 && i < heapSize) 
    {
        // Directly set the value at index i
        heap[i] = val;
    }
}

//========================================================
// allocate
// Resizes the heap's storage array to a new capacity. 
// Parameters: int n - The new capacity for the heap array.
// Return Value: None
//========================================================
template <class T>
void    MinQueue<T>::allocate           ( int n ) 
{
    if (n <= capacity) 
    {
        return;
    }

    T* newHeap = new T[n]; // Allocate a new array with the new capacity

    for (int i = 0; i < heapSize; ++i) // Copy existing elements to the new array
    {
        newHeap[i] = heap[i];
    }

    delete[] heap; // Delete the old array and update the pointer
    heap = newHeap;

    capacity = n; // Update the capacity to the new value
}













