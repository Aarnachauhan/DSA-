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

tabulation 

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
           int one=dp[i-1];
           int two=dp[i-2];
           dp[i]=one+two;
           
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
