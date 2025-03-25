#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr,int low,int high){
  while(low<high){
    int temp=arr[low];
    arr[low]=arr[high];
    arr[high]=temp;
    low++;
    high--;
  }
  
}

void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return; // Handle empty array case
        k = k % n; // Handle cases where k >= n
        if (k == 0) return; // No need to rotate if k is 0

        reverse(nums, 0, n - 1); // Reverse the entire array
        reverse(nums, 0, k - 1); // Reverse the first k elements
        reverse(nums, k, n - 1); // Reverse the remaining elements
    }


void print(vector<int> &arr,int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}

int main() 
{
    vector<int> arr={1,2,3,4,5};
    int n=arr.size();
    int d;
    cout<<"print the no of time u want to rotate the array";
    cin>>d;
    if(d>n){
        d=d-n;
    }
    rotate(arr,n,d);
    cout<<"rotated by "<<d<<endl;
    print(arr,n);
    return 0;
}
