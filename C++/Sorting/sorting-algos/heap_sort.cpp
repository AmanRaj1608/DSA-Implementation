/*
C++ implementation of Heap Sort algorithm:
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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int *arr, int n, int i)
{
    int largest = i, left = 2*i + 1, right = 2*i + 2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n)
{
    int i;
    for(i = n/2 - 1; i >= 0; --i)
        heapify(arr, n, i);
    for(i = n - 1; i >= 0; --i)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    heapSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast <microseconds> (stop - start);
    cout << "\n\nTime Duration: " << duration.count() << "\n\n";
    for(i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
