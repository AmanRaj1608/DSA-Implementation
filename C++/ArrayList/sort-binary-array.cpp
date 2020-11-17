/*
   sort binary array 
   Object oriented code
   author : singhanandVEVO

*/
#include<bits/stdc++.h>
using namespace std;

class BinaryArray {

	public:
		int i,N;
		vector<int> A;

		void setN(int n) {
			N = n;
		}

		void sortBinaryArray() {
			if(N==1)
				return;
			int left = -1;
			for(i=0;i<N;i++) {
				if(A[i]==0) {
					left++;
					swap(A[left], A[i]);
				}
			}

		} 

		void takeInput() {
			A.clear();
			int val;
			for(i=0;i<N;i++) {
				cin>>val;
				A.push_back(val);

			}
		}

		void printArray() {
			for(i=0;i<N;i++) {
				cout<<""<<A[i]<<" ";
			}
			cout<<endl;
		}

		void processTestCase() {
			takeInput();
			sortBinaryArray();
			printArray();
		}

};


int main(){

	int T;
	cin>>T;
	BinaryArray B;
	while(T--) {
		int n;
		cin>>n;
		B.setN(n);
		B.processTestCase();
	}
	return 0;
}