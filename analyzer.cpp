#include <iostream>
#include <vector>
#include <math.h>
#include "StringData.h"
using namespace std;

int linear_search(vector<string> container, string element) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

int binary_search(vector<string> container, string element) {
    int min = 0;
    int max = container.size()- 1;
    int mid = floor((min + max) / 2);
    while (min < max) {
        if(container[mid] == element){
            return mid;
        }
        if(container[min] == element){
            return min;
        }
        if(container[max] == element){
            return max;
        }
        if (element > container[mid]) {
            min = mid + 1;
            mid = floor((min + max) / 2);
        }
        if (element < container[mid]) {
            max = mid - 1;
            mid = floor((min + max) / 2);
        }
        return -1;
    }
    return mid;
}

int main()
{
    long long start_time = systemTimeNanoseconds();
    vector<string> container = getStringData();

    cout << "Word: not_here" << endl;
    cout << "Linear search time: " <<  systemTimeNanoseconds() - start_time << " Index found: " << linear_search(container, "not_here") << endl;
    cout << "Binary search time: " <<  systemTimeNanoseconds() - start_time << " Index found: " << binary_search(container, "not_here") << endl;
    cout << "" << endl;

    start_time = systemTimeNanoseconds();
    cout << "Word: mzzzz" << endl;
    cout << "Linear search time: " <<  systemTimeNanoseconds() - start_time << " Index found: " << linear_search(container, "mzzzz") << endl;
    cout << "Binary search time: " <<  systemTimeNanoseconds() - start_time << " Index found: " << binary_search(container, "mzzzz") << endl;
    cout << "" << endl;

    start_time = systemTimeNanoseconds();
    cout << "aaaaa" << endl;
    cout << "Linear search time: " <<  systemTimeNanoseconds() - start_time << " Index found: " << linear_search(container, "aaaaa") << endl;
    cout << "Binary search time: " <<  systemTimeNanoseconds() - start_time << " Index found: " << binary_search(container, "aaaaa") << endl;
    cout << "" << endl;

    return 0;
}


