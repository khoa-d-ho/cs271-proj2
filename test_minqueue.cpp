//========================================================
// Khoa Ho, Hoang Ngo
// test_minqueue.cpp
// February 2024
// This file contains the test cases for Min PQ
//========================================================

#include <iostream>
#include "usecase.cpp"
// #include "minqueue.h"

using namespace std;

void test_minqueue()
{
    // int 
    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {
        MinQueue<int> empty;
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect result from empty constructor. Expected an empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq_str = mq.to_string();

        if (mq_str != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    // float 
    float *float_data = new float[10];
    for (int i = 0; i < 10; i++)
    {
        float_data[i] = 10.1 - i;
    }

    try
    {
        MinQueue<float> empty;
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect result from empty constructor. Expected an empty string but got : " << mq_str << endl;
        }

        MinQueue<float> mq(float_data, 10);
        mq_str = mq.to_string();

        if (mq_str != "1.1 2.1 4.1 3.1 6.1 5.1 8.1 10.1 7.1 9.1")
        {
            cout << "Incorrect result from empty constructor. Expected 1.1 2.1 4.1 3.1 6.1 5.1 8.1 10.1 7.1 9.1 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    // char 
    char *char_data = new char[3];
    char arr1[] = {'a','b','c'};
    for (int i = 0; i < 3; i++)
    {
        char_data[i] = arr1[i];
    }

    try
    {
        MinQueue<char> empty;
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect result from empty constructor. Expected an empty string but got : " << mq_str << endl;
        }

        MinQueue<char> mq(char_data, 3);
        mq_str = mq.to_string();

        if (mq_str != "a b c")
        {
            cout << "Incorrect result from empty constructor. Expected a b c but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    // string
    string *string_data = new string[3];
    string arr2[] = {"airplane", "bus", "coach"};
    for (int i = 0; i < 3; i++)
    {
        string_data[i] = arr2[i];
    }

    try
    {
        MinQueue<string> empty;
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect result from empty constructor. Expected an empty string but got : " << mq_str << endl;
        }

        MinQueue<string> mq(string_data, 3);
        mq_str = mq.to_string();

        if (mq_str != "airplane bus coach")
        {
            cout << "Incorrect result from empty constructor. Expected airplane bus coach but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
    delete[] float_data;
    delete[] char_data;
    delete[] string_data;
}

void test_insert()
{
    // int 
    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {
        MinQueue<int> empty;
        empty.insert(0);
        string mq_str = empty.to_string();

        if (mq_str != "0")
        {
            cout << "Incorrect insert result. Expected 0 but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq.insert(25);
        mq.insert(0);
        mq_str = mq.to_string();

        if (mq_str != "0 2 1 3 6 4 8 10 7 9 25 5")
        {
            cout << "Incorrect insert result. Expected 0 2 1 3 6 4 8 10 7 9 25 5 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }

    // float 
    float *float_data = new float[10];
    for (int i = 0; i < 10; i++)
    {
        float_data[i] = 10.1 - i;
    }
    try
    {
        MinQueue<float> empty;
        empty.insert(0.1);
        string mq_str = empty.to_string();

        if (mq_str != "0.1")
        {
            cout << "Incorrect insert result. Expected 0.1 but got : " << mq_str << endl;
        }

        MinQueue<float> mq(float_data, 10);
        mq.insert(25.1);
        mq.insert(0.1);
        mq_str = mq.to_string();

        if (mq_str != "0.1 2.1 1.1 3.1 6.1 4.1 8.1 10.1 7.1 9.1 25.1 5.1")
        {
            cout << "Incorrect insert result. Expected 0.1 2.1 1.1 3.1 6.1 4.1 8.1 10.1 7.1 9.1 25.1 5.1 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }

    char *char_data = new char[3];
    char arr1[] = {'a','b','c'};
    for (int i = 0; i < 3; i++)
    {
        char_data[i] = arr1[i];
    }

    try
    {
        MinQueue<char> empty;
        empty.insert('e');
        string mq_str = empty.to_string();

        if (mq_str != "e")
        {
            cout << "Incorrect insert result. Expected e but got : " << mq_str << endl;
        }

        MinQueue<char> mq(char_data, 10);
        mq.insert('e');
        mq.insert('d');
        mq_str = mq.to_string();

        if (mq_str != "a b c d e")
        {
            cout << "Incorrect insert result. Expected a b c d e but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }


    string *string_data = new string[3];
    string arr2[] = {"airplane", "bus", "coach"};
    for (int i = 0; i < 3; i++)
    {
        string_data[i] = arr2[i];
    }

    try
    {
        MinQueue<string> empty;
        empty.insert("bike");
        string mq_str = empty.to_string();

        if (mq_str != "bike")
        {
            cout << "Incorrect insert result. Expected bike but got : " << mq_str << endl;
        }

        MinQueue<string> mq(string_data, 10);
        mq.insert("ship");
        mq.insert("van");
        mq_str = mq.to_string();

        if (mq_str != "airplane bus coach ship van")
        {
            cout << "Incorrect insert result. Expected airplane bus coach ship van but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }
    // char
    // char *char_data = new char[3];
    // char arr1[] = {'a','b','c'};
    // for (int i = 0; i < 3; i++)
    // {
    //     char_data[i] = arr1[i];
    // }

    // try
    // {

    //     MinQueue<char> empty;
    //     char min = empty.min();
    //     if (min != 0)
    //     {
    //         cout << "Incorrect min result. Expect 0 but got : " << min << endl;
    //     }

    //     MinQueue<char> mq(char_data, 3);
    //     min = mq.min();
    //     if (min != 'a')
    //     {
    //         cout << "Incorrect min result. Expect a but got : " << min << endl;
    //     }
    // }
    // catch (exception &e)
    // {
    //     cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    // }

    // // string 
    // string *string_data = new string[3];
    // string arr2[] = {"apple", "banana", "cat"};
    // for (int i = 0; i < 3; i++)
    // {
    //     string_data[i] = arr2[i];
    // }

    // try
    // {

    //     MinQueue<string> empty;
    //     string min = empty.min();
    //     if (min != "")
    //     {
    //         cout << "Incorrect min result. Expect 0 but got : " << min << endl;
    //     }

    //     MinQueue<string> mq(string_data, 3);
    //     min = mq.min();
    //     if (min != "apple")
    //     {
    //         cout << "Incorrect min result. Expect apple but got : " << min << endl;
    //     }
    // }
    // catch (exception &e)
    // {
    //     cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    // }

    delete[] int_data;
    delete[] float_data;
    delete[] char_data;
    delete[] string_data;
}

void test_min()
{
    // int
    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        int min = empty.min();
        if (min != 0)
        {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        MinQueue<int> mq(int_data, 10);
        min = mq.min();
        if (min != 1)
        {
            cout << "Incorrect min result. Expect 1 but got : " << min << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    // float
    float *float_data = new float[10];
    for (int i = 0; i < 10; i++)
    {
        float_data[i] = 10.1 - i;
    }

    try
    {

        MinQueue<float> empty;
        float min = empty.min();
        if (min != 0)
        {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        MinQueue<float> mq(float_data, 10);
        min = mq.min();
        if (min != 1.1)
        {
            cout << "Incorrect min result. Expect 1.1 but got : " << min << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
    delete[] float_data;
    // delete[] char_data;
    // delete[] string_data;
    
}

void test_extract_min()
{
    // int
    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        int min = empty.extract_min();
        string mq_str = empty.to_string();

        if (min != 0 || mq_str != "")
        {
            cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min << " and a queue of : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        min = mq.extract_min();
        mq_str = mq.to_string();

        if (min != 1 || mq_str != "2 3 4 7 6 5 8 10 9")
        {
            cout << "Incorrect extract min result. Expected 1 and the queue 2 3 4 7 6 5 8 10 9 but got : " << min << " and a queue of : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    // float
    float *float_data = new float[10];
    for (int i = 0; i < 10; i++)
    {
        float_data[i] = 10 - i;
    }

    try
    {
        MinQueue<float> empty;
        float min = empty.extract_min();
        string mq_str = empty.to_string();

        if (min != 0 || mq_str != "")
        {
            cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min << " and a queue of : " << mq_str << endl;
        }

        MinQueue<float> mq(float_data, 10);
        min = mq.extract_min();
        mq_str = mq.to_string();

        if (min != 1.1 || mq_str != "2.1 3.1 4.1 7.1 6.1 5.1 8.1 10.1 9.1")
        {
            cout << "Incorrect extract min result. Expected 1.1 and the queue 2.1 3.1 4.1 7.1 6.1 5.1 8.1 10.1 9.1 but got : " << min << " and a queue of : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    // char
    char *char_data = new char[3];
    char arr1[] = {'a','b','c'};
    for (int i = 0; i < 3; i++)
    {
        char_data[i] = arr1[i];
    }

    try
    {

        MinQueue<char> empty;
        char min = empty.min();
        if (min != 0)
        {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        MinQueue<char> mq(char_data, 3);
        min = mq.min();
        if (min != 'a')
        {
            cout << "Incorrect min result. Expect a but got : " << min << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }


    // string
    string *string_data = new string[3];
    string arr2[] = {"apple", "banana", "cat"};
    for (int i = 0; i < 3; i++)
    {
        string_data[i] = arr2[i];
    }

    try
    {

        MinQueue<string> empty;
        string min = empty.min();
        if (min != "")
        {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        MinQueue<string> mq(string_data, 3);
        min = mq.min();
        if (min != "apple")
        {
            cout << "Incorrect min result. Expect apple but got : " << min << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
    delete[] float_data;
    delete[] char_data;
    delete[] string_data;
}
void test_decrease_key()
{
    // int
    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.decrease_key(0, 0);
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq.decrease_key(0, -6);
        mq.decrease_key(9, -1);
        mq_str = mq.to_string();

        if (mq_str != "-6 -1 4 3 2 5 8 10 7 6")
        {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in decreasing key : " << e.what() << endl;
    }

    delete[] int_data;

    // float
    float *float_data = new float[10];
    for (int i = 0; i < 10; i++)
    {
        float_data[i] = 10.0 - i;
    }

    try
    {

        MinQueue<float> empty;
        empty.decrease_key(0, 0.0);
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }

        MinQueue<float> mq(float_data, 10);
        mq.decrease_key(0, -6.0);
        mq.decrease_key(9, -1.0);
        mq_str = mq.to_string();

        if (mq_str != "-6.0 -1.0 4.0 3.0 2.0 5.0 8.0 10.0 7.0 6.0")
        {
            cout << "Incorrect decrease key result. Expected -6.0 -1.0 4.0 3.0 2.0 5.0 8.0 10.0 7.0 6.0 queue but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in decreasing key : " << e.what() << endl;
    }

    delete[] float_data;

    char *char_data = new char[10];
    for (int i = 0; i < 10; i++) {
        char_data[i] = 'j' - i;
    }

    try {
        MinQueue<char> empty;
        empty.decrease_key(0, 'a');
        string mq_str = empty.to_string();

        if (mq_str != "") {
            cout << "Incorrect decrease key result. Expected empty queue but got: " << mq_str << endl;
        }

        MinQueue<char> mq(char_data, 10);
        mq.decrease_key(0, 'a');
        mq.decrease_key(9, 'b'); 
        mq_str = mq.to_string();

        if (mq_str != "a b c d e f g h i j") {
            cout << "Incorrect decrease key result. Expected a b c d e f g h i j but got: " << mq_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error in decreasing key for char: " << e.what() << endl;
    }

    delete[] char_data;

}

void test_heapify()
{
    // int
    int *empty_data_int = new int[0];

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.min_heapify(1);
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect heapify result. Expected empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        string o_mq_str = mq.to_string();
        mq.set(1, 11);
        mq.min_heapify(1);

        mq_str = mq.to_string();

        if (mq_str != "1 3 4 7 6 5 8 10 11 9")
        {
            cout << "Incorrect heapify result in heapifying index 1 in the minqueue " << o_mq_str << " after setting to 11. Expected 1 3 4 7 6 5 8 10 11 9 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in heapify : " << e.what() << endl;
    }

    delete[] empty_data_int;
    delete[] int_data;

    // float
    float *empty_data_float = new float[0];

    float *float_data = new float[10];
    for (int i = 0; i < 10; i++)
    {
        float_data[i] = 10.0 - i;
    }

    try
    {

        MinQueue<float> empty;
        empty.min_heapify(1);
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect heapify result. Expected empty string but got : " << mq_str << endl;
        }

        MinQueue<float> mq(float_data, 10);
        string o_mq_str = mq.to_string();
        mq.set(1, 11.0);
        mq.min_heapify(1);
 
        mq_str = mq.to_string();

        if (mq_str != "1.0 3.0 4.0 7.0 6.0 5.0 8.0 10.0 11.0 9.0")
        {
            cout << "Incorrect heapify result in heapifying index 1 in the minqueue " << o_mq_str << " after setting to 11. Expected 1.0 3.0 4.0 7.0 6.0 5.0 8.0 10.0 11.0 9.0 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in heapify : " << e.what() << endl;
    }

    delete[] empty_data_float;
    delete[] float_data;
}

void test_build_min_heap()
{
    // int
    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> mq;
        mq.allocate(10);
        for (int i = 0; i < 10; i++)
        {
            mq.set(i, int_data[i]);
        }
        string o_mq_str = mq.to_string();

        mq.build_heap();
        string mq_str = mq.to_string();

        if (mq_str != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect build_heap result from " << o_mq_str << ". Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in building min heap : " << e.what() << endl;
    }

    delete[] int_data;

    // float
    float *float_data = new float[10];
    for (int i = 0; i < 10; i++)
    {
        float_data[i] = 10.0 - i;
    }

    try
    {

        MinQueue<float> mq;
        mq.allocate(10);
        for (int i = 0; i < 10; i++)
        {
            mq.set(i, float_data[i]);
        }
        string o_mq_str = mq.to_string();

        mq.build_heap();
        string mq_str = mq.to_string();

        if (mq_str != "1.0 2.0 4.0 3.0 6.0 5.0 8.0 10.0 7.0 9.0")
        {
            cout << "Incorrect build_heap result from " << o_mq_str << ". Expected 1.0 2.0 4.0 3.0 6.0 5.0 8.0 10.0 7.0 9.0 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in building min heap : " << e.what() << endl;
    }

    delete[] float_data;

    //char
    char *char_data = new char[5];
    char arr1[] = {'a','b','c','d','e'};
    for (int i = 0; i < 5; i++)
    {
        char_data[i] = arr1[i];
    }

    try
    {
        MinQueue<char> mq;
        mq.allocate(10);
        for (int i = 0; i < 5; i++)
        {
            mq.set(i, char_data[i]);
        }

        mq.build_heap();
        string mq_str = mq.to_string();

        if (mq_str != "a b c d e")
        {
            cout << "Incorrect build_heap result from. Expected a b c d e but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in building min heap : " << e.what() << endl;
    }

    delete[] char_data;

    //string
    string *string_data = new string[3];
    string arr2[] = {"apple", "banana", "coconut"};
    for (int i = 0; i < 3; i++)
    {
        string_data[i] = arr2[i];
    }
    try
    {

        MinQueue<string> mq;
        mq.allocate(10);
        for (int i = 0; i < 10; i++)
        {
            mq.set(i, string_data[i]);
        }

        mq.build_heap();
        string mq_str = mq.to_string();

        if (mq_str != "apple banana coconut")
        {
            cout << "Incorrect build_heap result from . Expeceted apple banana coconut but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in building min heap : " << e.what() << endl;
    }

}

void test_heapsort()
{
    // int
    int *empty_data_int = new int[0];

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.sort(empty_data_int);

        MinQueue<int> heap(int_data, 10);
        heap.sort(int_data);

        string sorted_str = to_string(int_data[0]);

        for (int i = 1; i < 10; i++)
        {
            sorted_str += (" " + to_string(int_data[i]));
        }

        if (sorted_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << sorted_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in sorting : " << e.what() << endl;
    }

    delete[] empty_data_int;
    delete[] int_data;

    // float
    float *empty_data_float = new float[0];

    float *float_data = new float[10];
    for (int i = 0; i < 10; i++)
    {
        float_data[i] = 10.0 - i;
    }
    try
    {

        MinQueue<float> empty;
        empty.sort(empty_data_float);

        MinQueue<float> heap(float_data, 10);
        heap.sort(float_data);

        string sorted_str = to_string(float_data[0]);

        for (int i = 1; i < 10; i++)
        {
            sorted_str += (" " + to_string(float_data[i]));
        }

        if (sorted_str != "1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0")
        {
            cout << "Incorrect heapsort result. Expected 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0 but got : " << sorted_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in sorting : " << e.what() << endl;
    }

    delete[] empty_data_float;
    delete[] float_data;
}

void test_sliding_window()
{

    int *empty = new int[0];
    int nums[8] = {1, 3, -1, -3, 5, 3, 6, 7};

    try
    {

        string window_result = sliding_window(empty, 0, 0);

        if (window_result != "")
        {
            cout << "Incorrect sliding window result. Expected and empty string but got : " << window_result << endl;
        }

        window_result = sliding_window(nums, 8, 3);

        if (window_result != "-1 -3 -3 -3 3 3")
        {
            cout << "Incorrect sliding window result. Expected -1 -3 -3 -3 3 3 but got : " << window_result << endl;
        }

        window_result = sliding_window(nums, 1, 1);

        if (window_result != "1")
        {
            cout << "Incorrect sliding window result. Expected 1 but got : " << window_result << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in generating sliding window result : " << e.what() << endl;
    }

    delete[] empty;
}

void time_test()
{
    MinQueue<int> mq;
    // TO-DO: generate large minqueue
    int size = -1; // TO-DO: set size of large minqueue
    int total = 0;

    int val = rand() % 100000;
    auto begin = std::chrono::high_resolution_clock::now();
    mq.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    int _ = mq.min();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "min time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    _ = mq.extract_min();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "extract min time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    int last_index = size - 1;  // indexing starts at 0
    int new_val = mq.min() - 1; // ensure we're decreasing the key
    begin = std::chrono::high_resolution_clock::now();
    mq.decrease_key(last_index, new_val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "decrease key time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();
    cout << "Total time: " << total << endl;
}

//============================================

int main()
{

    test_minqueue();
    // test_insert();
    test_min();
    test_extract_min();
    test_decrease_key();
    test_heapify();
    test_build_min_heap();
    test_heapsort();

    test_sliding_window();

    time_test();

    cout << "Testing completed" << endl;

    return 0;
}