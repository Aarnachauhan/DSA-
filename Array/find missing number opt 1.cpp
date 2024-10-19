//tc- o(n);
//sc-O(1);
//but it cant find answer when number will be 10^5;

//go to opt 2 solution


#include <bits/stdc++.h>
using namespace std;
int findmissing(int a[],int n){
    cout<<"sum of first n natural numbers"<<endl;
    int sum1=(n*(n+1))/2;
    int sum=0;
    for(int i=0;i<n-1;i++){
        sum=sum+a[i];
    }
    int diff=sum1-sum;
    return diff;
}

int main(){
    int a[]={1,2,4,5};
    int n;
    cout<<"print n"<<" ";
    cin>>n;
    cout<<" range is from 1 to " <<n <<endl;
    int miss=findmissing(a,n);
    cout<<"missing number is "<<miss;
    return 0;
}
