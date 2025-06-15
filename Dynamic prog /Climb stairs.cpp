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

optimal 
tc-o(n)
sc-o(1)

class Solution {
public:
int climbStairs(int n){
     if (n <= 3) return n; //n=1 then ans=1 , n=2 then ans=2 , n=3 then ans=3

        int prev1 = 3;
        int prev2 = 2;
        int cur = 0;

        for (int i = 3; i < n; i++) { //real game starts from here.
            cur = prev1 + prev2; // for ex i=3 then ans= 2 + 1
            prev2 = prev1; // we will update 
            prev1 = cur;
        }

        return cur;      
    }
};
