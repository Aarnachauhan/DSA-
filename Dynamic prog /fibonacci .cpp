gfg 
tc-o(N)
sc-o(n) + o(n) 
//for recursion stack space and vector

    
//basic recursion 
  class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if(n<=1) return n;
        
        return nthFibonacci(n-1)+ nthFibonacci(n-2);
    }
};  

 //memoization   
class Solution {
  public:
int solve(int n, vector<int> &dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}
    int nthFibonacci(int n) {
        // code here
        vector<int> dp(n+1,-1);
        return solve(n,dp);
        
    }
};
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
