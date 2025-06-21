gfg
subset sum problem 

memorization 
tc- o(n* sum)
sc- o(n* target) * o(n)
class Solution {
  public:
  bool subsetsum(int ind,vector<vector<int>>  & dp , vector<int>&arr, int sum){
      if(sum==0) return true;
      if(ind==0) return arr[0]==sum ;
      
      if(dp[ind][sum]!=-1){
          return dp[ind][sum];
      }
      
      bool nottake= subsetsum(ind-1, dp , arr, sum);
      
      bool take= false;
      if(arr[ind]<=sum){
      take =subsetsum(ind-1 , dp , arr, sum-arr[ind]);
      }
      
      return dp[ind][sum] = nottake || take;
      
      
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1 , -1));
        return subsetsum(n-1, dp , arr , sum );
    }
};

tabulation
