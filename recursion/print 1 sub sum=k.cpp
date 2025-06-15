no platform

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool f(int ind,vector<int> &res,int newsum, int sum, int arr[],int n){
    if(ind==n){ //ind=3
        if(newsum==sum){ //ind=3 and sum=2
            for(auto it: res) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }
    res.push_back(arr[ind]); //add the element
    newsum+=arr[ind]; //add in the sum
    if(f(ind+1,res,newsum,sum,arr,n)==true) return true; //take condition
    newsum-=arr[ind]; 
    res.pop_back(); //not take condition
    if(f(ind+1,res,newsum,sum,arr,n)==true) return true; //not take condition
   return false;
}
int main()
{
  int arr[]={1,2,1};
  int n=3;
  int sum=2;
  vector<int> res;
  f(0,res,0,sum,arr,n);
}
