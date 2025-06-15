no patform 

tc-o(2^n * n)
sc-o(n)
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void f(int ind,vector<int> &res,int newsum, int sum, int arr[],int n){
    if(ind==n){ //ind=3
        if(newsum==sum){ //ind=3 and sum=2
            for(auto it: res) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    res.push_back(arr[ind]); //add the element
    newsum+=arr[ind]; //add in the sum
    f(ind+1,res,newsum,sum,arr,n); //take condition
    newsum-=arr[ind]; 
    res.pop_back(); //not take condition
     f(ind+1,res,newsum,sum,arr,n); //not take condition
}
int main()
{
  int arr[]={1,2,1};
  int n=3;
  int sum=2;
  vector<int> res;
  f(0,res,0,sum,arr,n);
}
