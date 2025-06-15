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
  
