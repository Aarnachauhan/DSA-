gfg
subset sum problem 
recursion
TC-O(2^N)
SC-O(N)
#include <bits/stdc++.h> 
int f(int ind, int k,vector<int> &a){
    if(k==0) return true;
    if(ind==0) return a[0]==k;
    bool nottake=f(ind-1,k,a);
    bool take=false;
    if(k>=a[ind]){
        take=f(ind-1,k-a[ind],a);
    }
    return take|| nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
   
    return f(n-1,k,arr);
}
--------------------------------------------------------------------------------------------------------
memorization 
tc- o(n* target)
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
--------------------------------------------------------------------------------------------
tabulation
tc-o(n*target)
sc-o(n*target)

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
                }
                
                dp[ind][j]= nottake || take;
            }
        }
        return dp[n-1][sum];
        }
};


space optimization 
Tc-O(n*target)
SC-o(target)
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k+1,0) , curr(k+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true; //dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool nottake=prev[target]; //dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target){
                take=prev[target-arr[ind]]; //dp[ind-1][target-arr[i]];
            }

           curr[target]=take || nottake; //dp[ind][target]
        }
        prev=curr;
    }
    return prev[k]; //dp[n-1][sum];
}
