#include <iostream>
#include <vector>
#include "StringData.h"

using namespace std;

int linear_search(vector<string> container, string element)
{
    for (int index=0; index < container.size(); index++)
    {
        if (container[index] == element) {
            return index;
        }
    }
    return -1;
}

int binary_search(vector<string> container, string element)
{
    int lower = 0;
    int upper = container.size() - 1;
    while(lower <= upper)
    {
        int middle = lower + (upper-lower) / 2;
        if (container[middle] > element)
            upper = middle - 1;
        else if (container[middle] < element)
            lower = middle + 1;
        else
            return middle;
    }
    return -1;
}

int main() {

    vector<string> container = getStringData();

    cout << "Linear Search time for \"not_here\" (nanoseconds): ";
    long long starting_time = systemTimeNanoseconds();
    int index = linear_search(container, "not_here");
    cout << systemTimeNanoseconds() - starting_time << endl;
    cout << "Index of element: " + to_string(index)<< endl;

    cout << "Binary Search time for \"not_here\" (nanoseconds): ";
    starting_time = systemTimeNanoseconds();
    index = binary_search(container, "not_here");
    cout << systemTimeNanoseconds() - starting_time << endl;
    cout << "Index of element: " + to_string(index)<< endl;

    cout << "\nLinear Search time for \"mzzzz\" (nanoseconds): ";
    starting_time = systemTimeNanoseconds();
    index = linear_search(container, "mzzzz");
    cout << systemTimeNanoseconds() - starting_time << endl;
    cout << "Index of element: " + to_string(index)<< endl;

    cout << "Binary Search time for \"mzzzz\" (nanoseconds): ";
    starting_time = systemTimeNanoseconds();
    index = binary_search(container, "mzzzz");
    cout << systemTimeNanoseconds() - starting_time << endl;
    cout << "Index of element: " + to_string(index)<< endl;

    cout << "\nLinear Search time for \"aaaaa\" (nanoseconds): ";
    starting_time = systemTimeNanoseconds();
    index = linear_search(container, "aaaaa");
    cout << systemTimeNanoseconds() - starting_time << endl;
    cout << "Index of element: " + to_string(index)<< endl;

    cout << "Binary Search time for \"aaaaa\" (nanoseconds): ";
    starting_time = systemTimeNanoseconds();
    index = binary_search(container, "aaaaa");
    cout << systemTimeNanoseconds() - starting_time << endl;
    cout << "Index of element: " + to_string(index)<< endl;

    return 0;
}



