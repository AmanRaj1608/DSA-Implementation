//      Insertion Sort - AmanRaj1608

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

void InsertionSort(ll int arr[],ll int n) {
    ll int j,key;
    for(ll int i=1; i<n; i++) {
        key = arr[i];
        j = i-1;
        while(arr[j]>key && j>=0){
            arr[j+1] = arr[j];
            j--;
            arr[j+1] = key;
        }
    }
}

int main() {
    ll int n;
    cout << "Enter number of numbers to be added to sort\n";
    cin >> n;
    cout << "\nOperation to be performed on\n";
    cout << "1. Already Sorted array\n2. Reversed Sorted array\n3. Random Numbers Sorted array\n";
    int choice;
    cin >> choice;
    ll int arr[n];

    //      Filling array as per choice
    if(choice==1) {
        for(ll int i=0;i<n;++i) {
            ll int random_number = rand() % Rand_Max;
            arr[i] = random_number;
        }
        sort(arr,arr+n);
    }
    else if(choice==2) {
        for(ll int i=0;i<n;++i) {
            ll int random_number = rand() % Rand_Max;
            arr[i] = random_number;
        }
        sort(arr,arr+n,greater<ll int>());
    }
    else if(choice==3) {
        for(ll int i=0;i<n;++i) {
            ll int random_number = rand() % Rand_Max;
            arr[i] = random_number;
        }
    }

    //      Started clock
    auto start = high_resolution_clock::now();

        InsertionSort(arr,n);

    //      Stop clock and calculate time
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
