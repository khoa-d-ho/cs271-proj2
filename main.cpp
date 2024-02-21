//========================================================
// Khoa Ho, Hoang Ngo
// main.cpp
// February 2024
// This file contains the class methods for the
// MinQueue Priority Queue using heaps.
//========================================================

#include "usecase.cpp"
#include <iostream>

using namespace std;

int main() 
{
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    cout << "Output: " << sliding_window(nums, 8, 3) << endl;
    // Expected Output: "-1 -3 -3 -3 3 3"

    int nums2[] = {1};
    k = 1;
    cout << "Output: " << sliding_window(nums2, 1, 1) << endl;
    // Expected Output: "1"

    return 0;
}
