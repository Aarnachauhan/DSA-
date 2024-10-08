#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int subarray(int arr[],int n,int k){
    int sum=0;
    int maxsum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    maxsum=sum;
    int left=0;
    int right=k-1;
    while(right<n-1){
        sum=sum-arr[left];
        
        left++;
        right++;
        sum=sum+arr[right];
        if(maxsum<sum){
        maxsum=sum;
    }
    }
    //maxsum=max(maxsum,sum);
    return maxsum;
    
}

int main() {
   int arr[]={-1,2,3,3,4,5,-1};
   int n=sizeof(arr)/sizeof(arr[0]);
   int k=4;
   int maximum=subarray(arr,n,k);
   cout<<"maximum sum of the sub array is :"<< maximum;

    return 0;
}
