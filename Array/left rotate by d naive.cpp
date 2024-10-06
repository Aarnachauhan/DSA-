#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[],int n,int d,int temp[]){
   for(int j=0;j<d;j++){
        temp.push_back(arr[j]);
    }
   for(int i=1;i<n;i++){
       arr[i-1]=arr[i];
   }
   for(int i=0;i<n;i++){
       arr.push_back(temp[i]);
   }

}
void print(int arr[],int n){
   for(int i=0;i<n;i++){
      cout<<arr[i]<<" "; 
   }
}

int main() 
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int d;
    cout<<"print the no of time u want to rotate the array";
    cin>>d;
    if(d>n){
        d=d-n;
    }
    int temp[d];
    rotate(arr,n,d,temp);
    cout<<"rotated by "<<d<<endl;
    print(arr,n);
    return 0;
}
