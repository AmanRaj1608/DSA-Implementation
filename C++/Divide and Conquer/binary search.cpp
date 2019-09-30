#include<bits/stdc++.h>
using namespace std;

int bin_search(int a[], int left, int right, int k){
    
    while(left<=right){
        int mid =(left +right)/2;
        
        if(a[mid] >k){
            right =mid-1;
        }
        
        else if(a[mid] <k){
            left =mid+1;
        }
        
        else{
            return mid;
        }
    }
    
    return -1;
}

int main(){
    
    int a []={1,2,3,4,5};
    cout<<bin_search(a,0,4,5);
    return 0;
}