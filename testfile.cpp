#include <iostream>
#include "usecase.cpp"
#include "minqueue.h"

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


    // string *string_data = new string[3];
    // string arr2[] = {"airplane", "bus", "coach"};
    // for (int i = 0; i < 3; i++)
    // {
    //     string_data[i] = arr2[i];
    // }

    // try
    // {
    //     MinQueue<string> empty;
    //     empty.insert("bike");
    //     string mq_str = empty.to_string();

    //     if (mq_str != "bike")
    //     {
    //         cout << "Incorrect insert result. Expected bike but got : " << mq_str << endl;
    //     }

    //     MinQueue<string> mq(string_data, 10);
    //     mq.insert("ship");
    //     mq.insert("van");
    //     mq_str = mq.to_string();

    //     if (mq_str != "airplane bus coach ship van")
    //     {
    //         cout << "Incorrect insert result. Expected airplane bus coach ship van but got : " << mq_str << endl;
    //     }
    // }
    // catch (exception &e)
    // {
    //     cerr << "Error inserting into the priority queue : " << e.what() << endl;
    // }
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
    // delete[] char_data;
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
    delete[] char_data;
    delete[] string_data;
    
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

//============================================

int main()
{

    test_minqueue();
    test_insert();
    test_min();
    test_extract_min();
    // test_decrease_key();
    // test_heapify();
    // test_build_min_heap();
    // test_heapsort();

    // test_sliding_window();

    // time_test();

    cout << "Testing completed" << endl;

    return 0;
}