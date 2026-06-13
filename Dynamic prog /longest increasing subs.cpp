lc 300

recursion
class Solution {
public:
int f(int i , int pindex , vector<int> &nums){
    if(i==nums.size()) return 0;
    int len=f(i+1,pindex,nums);
    int take=INT_MIN;
    if(pindex==-1 || nums[i]>nums[pindex]){
        take=1+f(i+1,i ,nums);
    }

    return max(len,take);
}
    int lengthOfLIS(vector<int>& nums) {
        return f(0,-1,nums);
    }
};

memoization
tc-o(n*n)
sc-o(n*n) + o(n)

class Solution {
public:
int f(int i , int pindex , vector<int> &nums,vector<vector<int>> &dp){
    if(i==nums.size()) return 0;
    if(dp[i][pindex+1]!=-1) return dp[i][pindex+1];
    int len=f(i+1,pindex,nums,dp);
    int take=INT_MIN;
    if(pindex==-1 || nums[i]>nums[pindex]){
        take=1+f(i+1,i ,nums,dp);
    }

    return dp[i][pindex+1]=max(len,take);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return f(0,-1,nums,dp);
    }
};

tabulation
tc-o(n2)
sc-o(n)*2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int i = n - 1; i >= 0; i--) {

            for(int pindex = i - 1; pindex >= -1; pindex--) {

                int notTake = dp[i + 1][pindex + 1];

                int take = 0;
                if(pindex == -1 || nums[i] > nums[pindex]) {
                    take = 1 + dp[i + 1][i + 1];
                }

                dp[i][pindex + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};
space optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            for(int pindex = i - 1; pindex >= -1; pindex--) {

                int notTake = next[pindex + 1];

                int take = 0;
                if(pindex == -1 || nums[i] > nums[pindex]) {
                    take = 1 + next[i + 1];
                }

                curr[pindex + 1] = max(take, notTake);
            }

            next = curr;
        }

        return next[0];
    }
};
