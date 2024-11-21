//tc- o(n);
//sc-O(1);
//but it cant find answer when number will be 10^5;

//go to opt 2 solution


#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& arr) {
        // code here
        int n=arr.size()+1;
        int sum=0;
        int sum1;
        sum1=(n*(n+1))/2;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int miss=sum1-sum;
        return miss;
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
