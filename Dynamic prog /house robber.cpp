leetcode 198
tc-o(n)
sc-o(n) * o(N)
memorization 


class Solution {
public:
int f(int ind,vector<int> &nums,vector<int> &dp){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=nums[ind] + f(ind-2,nums,dp);
    int npick=0 + f(ind-1,nums,dp);

    return dp[ind]= max(pick,npick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};

tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        dp[0]=nums[0];
        int pick,npick;
        for(int i=1;i<n;i++){
            if(i>1){
            pick=nums[i]+ dp[i-2];
            }
            else{
             pick=nums[i];
            }

             npick= 0 + dp[i-1];
        dp[i]=max(pick,npick);
        }
        return dp[n-1];
    }
};

space opt
tx-o(n)
sc-o(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int ntake=0 + prev;
            int cur=max(take,ntake);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};


