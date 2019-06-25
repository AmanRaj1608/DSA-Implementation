/*
C++ implementation of Merge Sort algorithm:
* Sorts 10000 randomly generated integers (between 1 and 10000).
* Shows time taken (in microseconds) to sort the random sequence of integers.
* Prints the sorted list of integers.
*/

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void merge(int *left, int *right, int *arr, int n)
{
    int leftSize = n / 2;
    int rightSize = n - leftSize;
    int i, j, k;
    i = j = k = 0;
    while(i < leftSize && j < rightSize)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            ++i;
        }
        else
        {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }
    while(i < leftSize)
    {
        arr[k] = left[i];
        ++i;
        ++k;
    }
    while(j < rightSize)
    {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}

void mergeSort(int *arr, int n)
{
    if(n == 1)
        return ;
    int i, mid = n / 2;
    int left[mid], right[n - mid];
    for(i = 0; i < mid; ++i)
        left[i] = arr[i];
    for(i = mid; i < n; ++i)
        right[i - mid] = arr[i];
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, right, arr, n);
}

int main()
{
    srand(time(0));
    int len = 10000, i;
    int array[len];
    for(i = 0; i < len; ++i)
        array[i] = (rand() % 10000) + 1;
    auto start = high_resolution_clock::now();
    mergeSort(array, len);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast <microseconds> (stop - start);
    cout << "\n\ntime: " << duration.count() << "\n\n";
    for(i = 0; i < len; ++i)
        cout << array[i] << " ";
    return 0;
}
