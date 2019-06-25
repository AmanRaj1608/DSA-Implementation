/*
C++ implementation of Bubble Sort algorithm:
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

void bubbleSort(int *arr, int n)
{
    int i, j;
    bool swapped;
    for(i = 1; i < n; ++i)
    {
        swapped  = false;
        for(j = 0; j < n - i; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
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
    bubbleSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast <microseconds> (stop - start);
    cout << "\n\ntime: " << duration.count() << " microseconds\n\n";
    for(i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
