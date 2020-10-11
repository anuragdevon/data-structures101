#include <bits/stdc++.h>
using namespace std;
 int main () {
	 int arr[] = {50, 1, 100, 1000, 12};
	 int n = sizeof(arr)/sizeof(arr[0]);
	 for(int i =0; i<n; i++){
		 for(int j=0; j<n ; j++){
			 if(arr[i]<arr[j]){
				 int temp = arr[i];
				 arr[i] = arr[j];
				 arr[j] = temp;
			 }
		 }
	 }
	 for(int i=0; i<n; i++){
		 cout<<arr[i]<<" ";
	 }
	 cout<<"\n";
	 return 0;
 }
