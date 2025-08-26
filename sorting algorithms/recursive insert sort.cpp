codechef compiler 
#include <bits/stdc++.h>
using namespace std;
void insertsort(int a[], int i , int n){
    if(i==n) return ;
    int j=i;
    while(j > 0 && a[j] < a[j-1]){
        swap(a[j],a[j-1]);
        j--;
    }
    insertsort(a, i+1 , n);
}
int main() {
    int n; 
    cin>>n;
	int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insertsort(a,0 , n);
     for(int i=0;i<n;i++){
        cout<<a[i] <<" ";
    }
}
