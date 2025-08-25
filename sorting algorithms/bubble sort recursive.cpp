#include <bits/stdc++.h>
using namespace std;
void bubblesort(int input[], int endindex){
    if(endindex==0) return;
    for(int i=0;i<endindex;i++){
        if(input[i]>input[i+1]){
            int temp=input[i];
            input[i]=input[i+1];
            input[i+1]=temp;
        }
    }
    bubblesort(input, endindex-1);
}

int main() {
	// your code goes here
	int arr[]={3,6,2,4,1};
	bubblesort(arr,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

}
