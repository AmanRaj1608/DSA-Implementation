//      Bubble Sort - AmanRaj1608

//      Including Libraries
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

//      MACROS
#define ll long long
#define Rand_Max 10000000

void swap(ll int *a, ll int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(ll int arr[],ll int n) {
    for(ll int i=0;i<n-1;i++)
        for(ll int j=0;j<n-i-1;j++)
            if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

int main() {
    ll int n;
    cout << "Enter number of numbers to be added to sort\n";
    cin >> n;
    ll int arr[n];

    //      Adding n random valuse to array
    for(ll int i=0;i<n;++i) {
        ll int random_number = rand() % Rand_Max;
        arr[i] = random_number;
    }

    //      Calculating time of Bubble Sort
    auto start = high_resolution_clock::now();
    BubbleSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
