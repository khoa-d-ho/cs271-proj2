
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

#ifndef MINQUEUE_H
#define MINQUEUE_H

template <class T>
class MinQueue
{
private:
    T* heap; 
    int capacity;
    int heapSize;

    int parent(int i) { return ( i - 1 ) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

public:

                        MinQueue            (void);
                        MinQueue            (T* A, int n);
                        ~MinQueue           (void);
                        
	    string          to_string           (void) const;

        void            insert              (const T& value);
        T               min                 (void) const;
        T               extract_min         (void);
        void            decrease_key        (int i, T newValue);

        void            heapify             (int i);    
        void            build_min_heap      (void);
        void            sort                (T* A);

        void            set                 (int i, T value);
        void            allocate            (int n);



};

#endif 
