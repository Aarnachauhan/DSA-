lc 494

recursion  - accepted
  Tc : O(2^N)
SC  :O(N)
class Solution {
public:
int f(int ind, int req , vector<int> &nums){
    if(ind==0){
        if(req==0 && nums[0]==0) return 2;
        if(req==0 || req==nums[0]) return 1;
        return 0;
    }

    int notpick=f(ind-1,req,nums);
    int pick=0;
    if(nums[ind]<=req){
        pick=f(ind-1,req-nums[ind],nums);
    }
    return pick+notpick;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(totalsum-target<0 ) return 0;
        if((totalsum-target)%2!=0) return 0; //we want even 

        int req=(totalsum-target)/2;

        return f(n-1,req,nums);
    }
};
-------------------------------------------------------------------------------------------
memoization 
tc-o(n*req)
sc-o(n*req)*o(n)

class Solution {
public:
int f(int ind, int req , vector<int> &nums, vector<vector<int>> &dp){
    if(ind==0){
        if(req==0 && nums[0]==0) return 2;
        if(req==0 || req==nums[0]) return 1;
        return 0;
    }
    if(dp[ind][req]!=-1) return dp[ind][req];
    int notpick=f(ind-1,req,nums,dp);
    int pick=0;
    if(nums[ind]<=req){
        pick=f(ind-1,req-nums[ind],nums,dp);
    }
    return dp[ind][req]=pick+notpick;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(totalsum-target<0 ) return 0;
        if((totalsum-target)%2!=0) return 0; //we want even 
       

        int req=(totalsum-target)/2;
         vector<vector<int>> dp(n, vector<int> ( req+1,-1));
        return f(n-1,req,nums,dp);
    }
};
---------------------------------------------------------------------------
tabulation 
tc-o(n*req)
sc-o(n*req)

class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(totalsum-target<0 ) return 0;
        if((totalsum-target)%2!=0) return 0; //we want even 
       

        int req=(totalsum-target)/2;
         vector<vector<int>> dp(n, vector<int> ( req+1,0));

    if(nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if(nums[0] != 0 && nums[0] <= req)  dp[0][nums[0]] = 1;



     for(int ind=1;ind<n;ind++){
      for(int j=0;j<=req;j++){
               
         int notpick=dp[ind-1][j];
          int pick=0;
          if(nums[ind]<=j){
        pick=dp[ind-1][j-nums[ind]];
          }
       dp[ind][j]=pick+notpick;
            }
     }
     return dp[n-1][req];
       
    }
};

--------------------------------------------------------------------
space optimization
int findTargetSumWays(vector<int>& nums,
                      int target)
{
    int totalSum =
        accumulate(nums.begin(),
                   nums.end(), 0);

    if(totalSum-target < 0 ||
       (totalSum-target)%2)
        return 0;

    int req =
        (totalSum-target)/2;

    int n = nums.size();

    vector<int>
        prev(req+1,0);

    if(nums[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if(nums[0] != 0 &&
       nums[0] <= req)
        prev[nums[0]] = 1;

    for(int ind=1;
        ind<n;
        ind++)
    {
        vector<int>
            curr(req+1,0);

        for(int sum=0; sum<=req; sum++)
        {
            int notPick =
                prev[sum];

            int pick = 0;

            if(nums[ind] <= sum)
                pick =
                  prev[sum-nums[ind]];

            curr[sum]
                = pick + notPick;
        }

        prev = curr;
    }

    return prev[req];
}
