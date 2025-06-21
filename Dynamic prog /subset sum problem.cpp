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


class Solution {
  public:
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1 , false));
        //base case :
        //when target/sum is zero
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        
        //only when arr[0]= sum
        if(arr[0]<=sum){
            dp[0][arr[0]]= true;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int j=1;j<=sum;j++){
                
                bool nottake= dp[ind-1][j];
                
                bool take= false;
                if(arr[ind]<=j){
                    take=dp[ind-1][j-arr[ind]];
                   // take=true;
                }
                
                dp[ind][j]= nottake || take;
            }
        }
        return dp[n-1][sum];
        }
};


space optimization is left
