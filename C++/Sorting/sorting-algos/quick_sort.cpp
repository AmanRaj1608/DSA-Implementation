/*
C++ implementation of Quick Sort algorithm:
* Sorts 10000 randomly generated integers (between 1 and 10000).
* Shows time taken (in microseconds) to sort the random sequence of integers.
* Prints the sorted list of integers.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *arr, int start, int end)
{
    int partitionIndex = start, pivot = arr[end], i;
    for(i = start; i < end; ++i)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[partitionIndex], arr[i]);
            ++partitionIndex;
        }
    }
    swap(arr[partitionIndex], arr[end]);
    return partitionIndex;
}

void quickSort(int *arr, int start, int end)
{
    if(start < end)
    {
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
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
    quickSort(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast <microseconds> (stop - start);
    cout << "\n\ntime: " << duration.count() << " microseconds\n\n";
    for(i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
