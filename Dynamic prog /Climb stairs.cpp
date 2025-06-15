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

