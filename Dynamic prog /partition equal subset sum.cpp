leetcode 416
tc-o(n*target) *(n) //nested loop and sum find 
sc-o(target)
recursion :
Tc-O(2^n)
sc-o(n)
class Solution {
public:
bool f(int ind, int target, vector<int>&nums){
    if(ind==0) return nums[0]==target;
    if(target==0) return true;
    if(ind>=nums.size() || target<0) return false;

    int exclude=f(ind-1,target,nums);
    int include=false;
    if(nums[ind]<=target){
        include=f(ind-1,target-nums[ind],nums);
    }

    return include || exnclude;
}
    bool canPartition(vector<int>& nums) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        if(totalsum%2!=0) return false;
        return f(n-1,totalsum/2,nums);
    }
};
--------------------------------------------------------------------------------
memo:
Time Complexity:o(n*target)
Space Complexity:o(n*target) * o(N)
class Solution {
public:
bool f(int ind, int target, vector<int>&nums , vector<vector<int>> &dp){
    if(ind==0) return nums[0]==target;
    if(target==0) return true;
    if(ind>=nums.size() || target<0) return false;
    if(dp[ind][target]!=-1) return dp[ind][target];
    int exclude=f(ind-1,target,nums,dp);
    int include=false;
    if(nums[ind]<=target){
        include=f(ind-1,target-nums[ind],nums,dp);
    }

    return dp[ind][target]=include || exclude;
}
    bool canPartition(vector<int>& nums) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
         if(totalsum%2!=0) return false;
        int sum=totalsum/2;
        vector<vector<int>> dp(nums.size(),vector<int> (sum+1,-1));
        int n=nums.size();
        return f(n-1,totalsum/2,nums,dp);
    }
};

----------------------------------------------------------------------------------
Tabulation 
Tc-O(n*t)
sc-o(n*t)












    
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total= accumulate(nums.begin(),nums.end(),0);
        if(total %2!=0) return false;

        int target = total/2;
        vector<bool> dp(target+1 , false);
        dp[0] = true;

        for(int n:nums){
            for(int i=target;i>=n;i--){
                if(dp[i]) continue;
                if(dp[i-n]) dp[i]=true;
                if(dp[target]) return true;
            }
        }
        return false;

    }
};
