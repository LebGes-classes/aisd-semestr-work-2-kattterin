#include "PatienceSort.h"

#include <iostream>

int main() {
    vector<int> numbers = { 4, 3, 7, 8, 6, 2, 5, 1 };

    cout << "Before: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    PatienceSort sorter;
    numbers = sorter.patienceSort(numbers);

    cout << "After: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    return 0;
}