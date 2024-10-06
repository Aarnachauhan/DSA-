#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr,int low,int high,int d){
  while(low<high){
    int temp=arr[low];
    arr[low]=arr[high];
    arr[high]=temp;
    low++;
    high--;
  }
  
}

void rotate(vector <int> &arr,int n, int d){
    reverse(arr,0,d-1,d);
    reverse(arr,d,n-1,d);
    reverse(arr,0,n-1,d);
    
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
