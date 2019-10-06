#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
  void bucketSort(double arr[], long long int n) 
{  
    vector<double> b[n]; 
     
    for (int i=0; i<n; i++) 
    { 
       int bi = n*arr[i];  
       b[bi].push_back(arr[i]); 
    } 
   
    for (int i=0; i<n; i++) 
       sort(b[i].begin(), b[i].end()); 
  
       int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
          arr[index++] = b[i][j]; 
} 
  

int main() 
{  
    long long int n;
    cout<<"Enter the no. of elements in the array"<<endl;
    cin>>n;
    double arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
      cin>>arr[i];
    bucketSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    for (int i=0; i<n; i++) 
       cout << arr[i] << " ";  
} 