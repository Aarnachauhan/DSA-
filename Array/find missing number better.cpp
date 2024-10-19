//has is used 
//tc- o(2n)
//sc- o(n)
#include <bits/stdc++.h>
using namespace std;
int findmissing(int a[],int n){
    int hash[n+1]={0};
    for(int i=0;i<n-1;i++){
        hash[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return -1;
}

int main(){
    int a[]={1,2,4,5};
    int n;
    cout<<"print n"<<" ";
    cin>>n;
    cout<<" range is from 1 to " <<n <<endl;
    int miss=findmissing(a,n);
    cout<<miss;
    return 0;
}
