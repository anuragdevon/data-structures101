// K'th smallest/ Largest Element in unsorted array

// question link is given below

// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// function to find K'th samllest element in a given array
int kthSmallest(int arr[], int n, int k){
    // sort the given array
    sort(arr, arr+n);

    // return kth element int the sorted array
    return arr[k-1];
}

// main code
int main(){
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    // now call the function 

    cout<<"K'th Smallest element is: "<<kthSmallest(arr,n,k);

    return 0;
}
