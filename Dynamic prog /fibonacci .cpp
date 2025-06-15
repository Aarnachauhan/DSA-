no platform 
tc-
sc-


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f(int n, vector<int> &dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    else {
        return dp[n]=f(n-1,dp) + f(n-2,dp);
    }
    
}

int main() {
    // Write C++ code here
    int n;
    cin>>n;
    vector<int> dp(n+1 , -1);
    cout<<f(n,dp);


    return 0;
}
