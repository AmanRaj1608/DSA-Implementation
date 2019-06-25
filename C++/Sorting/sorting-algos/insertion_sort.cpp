/*
C++ implementation of Insertion Sort algorithm:
* Sorts 10000 randomly generated integers (between 1 and 10000).
* Shows time taken (in microseconds) to sort the random sequence of integers.
* Prints the sorted list of integers.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(int *arr, int n)
{
    int i, j, value;
    for(i = 0; i < n; ++i)
    {
        value = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = value;
    }
}

int main()
{
    srand(time(0));
    int n = 10000, i;
    int arr[n];
    for(i = 0; i < n; ++i)
        arr[i] = (rand() % 10000) + 1;
    auto start = high_resolution_clock::now();
    insertionSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast <microseconds> (stop - start);
    cout << "\n\ntime: " << duration.count() << " microseconds\n\n";
    for(i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
