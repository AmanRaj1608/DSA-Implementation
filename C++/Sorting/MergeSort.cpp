//      Merge Sort - AmanRaj1608

//      Including Libraries
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

//      MACROS
#define ll long long
#define Rand_Max 10000000


//  Two sub array - L[l - m] and R[m+1 - r]
void Merge(ll int arr[], ll int l, ll int m, ll int r) {
    ll int n1 = m-l+1;
    ll int n2 = r-m;

    ll int L[n1],R[n2];
    //  Copy array elements to L and R
    for(ll int i=0; i<n1; ++i)
        L[i] = arr[i+l];
    for(ll int i=0; i<n2; ++i)
        R[i] = arr[m+1+i];

    //  Merge elements to orignal array
    ll int i=0 ,j=0, k=1;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) {
            arr[k] = L[i];
            i++; k++;
        }
        else {
            arr[k] = R[j];
            j++; k++;
        }
    }
    //  Check if any array is left empty
    while(i<n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while(j<n2) {
        arr[k] = R[j];
        j++; k++;
    }
}


//  There are two parts - left and rihgt
//  Keep dividing array till r < l
void MergeSort(ll int arr[], ll int l, ll int r) {
    if(l>=r) return;
    if(l < r) {
        ll int m = l + (r-1)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        Merge(arr,l,m,r);
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

        MergeSort(arr,0,n-1);

    //      Stop clock and calculate time
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    for(ll int i=0;i<n;++i)
        cout << arr[i] << " ";
    return 0;
}
