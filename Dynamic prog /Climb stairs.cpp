leetcode 
brute force: recursion
tc-o(2^n)
sc-o(N)

class Solution {
public:
    int climbStairs(int n) {
        if(n<0) return 0;
        if(n==0) return 1;
        int one_step=climbStairs(n-1);
        int two_step=climbStairs(n-2);

        return one_step + two_step;
    }
};

mememorization :
tc-o(n)
sc-o(n)
  
class Solution {
public:
    int t[46];
int solve(int n, vector<int> &t){
    if(n<0) return 0;
    if(t[n]!=-1){
        return t[n];
    }
    if(n==0) return 1;
    int one=solve(n-1,t);
    int two= solve(n-2,t);
    return t[n] = one + two;
}
    int climbStairs(int n) {
       vector<int> t(n+1,-1);
       return solve(n,t);
    }
};

my solution for memo
class Solution {
public:
int solve(vector<int> &dp , int n){
    if(n<=2) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(dp,n-1) + solve(dp, n-2);
}
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(dp,n);
    }
};

tabulation 

class Solution {
public:

    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1);
        
        dp[1]=1; 
        dp[2]=2; 
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+ dp[i-2];
        }
        return dp[n];
    }
};


optimal 
tc-o(n)
sc-o(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n; // as ans of 1,2,3 is same 
        
        int prev2=1;
        int prev1=2;
        int curr=3;
        for(int i=3;i<=n;i++){
            curr=prev1+prev2; //3=1+2
            prev2=prev1;
            prev1=curr;
        }
       return curr;
    }
};
