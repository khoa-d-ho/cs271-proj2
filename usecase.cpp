//========================================================
// Khoa Ho, Hoang Ngo
// usecase.cpp
// February 2024
// This file contains the solutions for the 
// sliding windows problem using MinQueue
//========================================================

#include <iostream>
#include "minqueue.h"
// #include "minqueue.cpp"
#include <string>
#include <chrono>
#include <sstream> 
#include <algorithm>
using namespace std;

template <class T>
string sliding_window(T arr[], int len, int window) 
{
    T *temp = new T[window];
    stringstream result;
    // string result;

    if (len == 0)
    {
        delete[] temp;
        return result.str();
    }

    if (len == 1 || window == 1)
    {
        for (int i = 0; i < len; i++) 
        {
            result << arr[i];
            if (i < len - 1) 
            {
                result << " ";
            }
        }
        return result.str();
    }

    if (window > len)
    {
        MinQueue<int> mq;
        for (int i = 0; i < len; i++)
        {
            mq.insert(temp[i]);
            result << mq.min();
            if (i < len)
            {
                result << " ";
            }
        }   
    }
    else 
    {
        for (int i = 0; i <= len - window; i++) {
            MinQueue<T> mq;
            for (int j = 0; j < window; j++) {
                temp[j] = arr[i + j];
                mq.insert(temp[j]);
            }
            result << mq.min();
            if (i < len - window) {
                result << " "; 
            }
        }
        delete[] temp; 
    }
    return result.str();
}