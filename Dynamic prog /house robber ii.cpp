leetcode 213 
recursion 
tc- T(n) = T(n-1) + T(n-2) = O(2^N)
sc-o(n)
class Solution {
public:
int solve(int ind, vector<int> &nums){
    if(ind==0) return nums[0];
    if(ind<0) return 0;

    int pick=nums[ind]+solve(ind-2,nums);
    int notpick=solve(ind-1,nums);

    return max(pick , notpick);

}

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(
            solve(temp1.size()-1,temp1), solve(temp2.size()-1, temp2)
        );
    }
};

memoization
tc-O(n)
sc-O(n)
class Solution {
public:
int solve(int ind, vector<int> &nums, vector<int> &dp){
    if(ind==0) return nums[0];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=nums[ind]+solve(ind-2,nums,dp);
    int notpick=solve(ind-1,nums,dp);

    return dp[ind]=max(pick , notpick);

}

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }

        vector<int> dp1(temp1.size(),-1);
        vector<int> dp2(temp2.size(),-1);
        return max(
            solve(temp1.size()-1,temp1,dp1), solve(temp2.size()-1, temp2,dp2)
        );
    }
};


tabulation
class Solution {
public:
int solve( vector<int> &nums){
    vector<int> dp(nums.size(),0);
    int n=nums.size();
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1){
            take+=dp[i-2];
        }
        int nottake=dp[i-1];

        dp[i]=max(nottake,take);
    }

 return dp[n-1];
}

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }

    
        return  max(solve(temp1), solve(temp2) );
    }
};


space optimisation

class Solution {
public:
int f(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp1,temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]); //take everything except first element
            if(i!=n-1) temp2.push_back(nums[i]); //take everything excpet last element
        }
        return max(f(temp1),f(temp2));
    }
};
