#include<iostream>
using namespace std;

void MergeTwoSortedArrays(int arr[], int start, int end){
  int* arr1 = new int[end - start + 1];
  int mid = (start + end)/2;
  int k = 0;
  int i1 = start;
  int i2 = mid + 1;


  while(i1 <= mid && i2 <= end)
  {
    if(arr[i1] <= arr[i2]){
      arr1[k++] = arr[i1++];
    }
    else{
      arr1[k++] = arr[i2++];
    }
  }

  while(i1 <= mid){
    arr1[k++] = arr[i1++];
    }

  while(i2 <= end){
    arr1[k++]= arr[i2++];
  }

  for(int i = 0; i < k; i++){
    arr[start++] = arr1[i];
  }
}

void MergeSort(int arr[], int start, int end){
  if(start>=end)
  {
    return;
  }
  int  mid = (start +  end)/2;

  MergeSort(arr,start,mid);
  MergeSort(arr,mid+1,end);
  MergeTwoSortedArrays(arr,start, end);
}

int main()
{
  int n;
  cin>>n;

  int arr[100];

  for(int i= 0;i<n ;i++){
    cin>>arr[i];
  }

  MergeSort(arr,0,n-1);

  for(int i = 0; i< n;i++){
    cout<<arr[i]<<endl;
  }

}
