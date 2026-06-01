gfg : https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
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
sc-o(n) //no recursion space.
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        vector<int> dp(n+1,-1);
        dp[0]=0 ;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+ dp[i-2];
        }
        return dp[n];
        
    }
};

//space optimization
tc-o(n)
sc-o(1)
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if(n<=1) return n;
        int prev2=0 , prev=1;
       
        for(int i=2;i<=n;i++){
            int curr=prev2+prev;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
