no platform 
tc-o(N)
sc-o(n) + o(n) 
//for recursion stack space and vector 


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
//tabulation 
tc-o(n)
sc-o(1)
    

#include <iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int prev2=0;
  int prev=1;
  for(int i=2;i<=n;i++){
      int cur_i=prev2+prev;
      prev2=prev;
      prev=cur_i;
  }
  cout<<prev;
    return 0;
}
