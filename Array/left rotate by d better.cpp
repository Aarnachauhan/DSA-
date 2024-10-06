#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[],int n,int d,int temp[]){
  //copy first d elements to temp
   for(int j=0;j<d;j++){
        temp[j]=arr[j];
    }
  // u copy the rest elements after d to ita previous place by d times;
   for(int i=d;i<n;i++){
       arr[i-1]=arr[i];
   }
//n = 5 d =2 
//ip->  [1 2 3 4 5] op->[3 4 5 1 2]
   // for left rotate by 2
  // temp = [ 1 2] arr = [3 4 5 4 5]
  //  u copy the elements to back if u look at ip and op the index from which u wanna fill the d element is nothing but n-d+i
 //[3 4 5 1 2 ] its from 3 then it gets incremented by 1.
 
   for(int i=0;i<d;i++){
      arr[n-d+i] = temp[i];
      //arr[5-2+0] = arr[3] = temp[0] = 1
        // arr[5-2+1] = arr[4] = temp[1] = 2
        
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
