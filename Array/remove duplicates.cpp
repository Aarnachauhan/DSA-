#include <iostream>
#include <cmath>
using namespace std;
int nodup(int arr[],int n){
    int res=1;
    for(int i=1;i<n;i++){
        if(arr[res-1]!=arr[i]){
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}

int main(){
    int arr[]={1,1,2,3,3,4,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    n=nodup(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
