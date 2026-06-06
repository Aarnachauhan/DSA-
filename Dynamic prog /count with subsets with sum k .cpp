gfg -  problem and solved using gfg article - perfect sum problem
recursion
class Solution {
  public:
  
 int f(int i , int curr, int target, vector<int> &a){
     if(i<0){
         return curr==target;
     }
     int notpick=f(i-1,curr,target,a);
     int pick=0;
     if(curr+a[i]<=target){
         
         pick=f(i-1,curr+a[i],target,a);
     }
     
     return pick+notpick;
     
 }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        return f(n-1,0,target,arr);
        
    }
};

--------------------------------------------------------------------------------------------------------------------
memo
tc-O(n*target) 
sc-o(n*target) + o(n)
class Solution {
  public:
  
 int f(int i , int curr, int target, vector<int> &a,
 vector<vector<int>> &dp){
     if(i<0){
         return curr==target;
     }
     if(dp[i][curr]!=-1) return dp[i][curr];
     int notpick=f(i-1,curr,target,a,dp);
     int pick=0;
     if(curr+a[i]<=target){
         
         pick=f(i-1,curr+a[i],target,a,dp);
     }
     
     return dp[i][curr]=pick+notpick;
     
 }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int> (target+1,-1));
        return f(n-1,0,target,arr,dp);
        
    }
};
----------------------------------------------------------------------------------------------------

tabulation 
tc- o(n*target)
sc- o(n* target)

class Solution {
  public:
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int> (target+1,0));
        if(arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if(arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int notpick=dp[i-1][j];
                   int pick=0;
                  if(j>=arr[i]){
                    pick=dp[i-1][j-arr[i]];
                    }
     
                   dp[i][j]=pick+notpick;
            }
            
        }
        return dp[n-1][target];
        
    }
};
--------------------------------------------------------------------------------------------

space opti
tc- o(n*target)
sc- o(n)
  class Solution {
  public:
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
      
        vector<int> prev(target+1,0) , curr(target+1,0);
        if(arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if(arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int notpick=prev[j];
                   int pick=0;
                  if(j>=arr[i]){
                    pick=prev[j-arr[i]];
                    }
     
                   curr[j]=pick+notpick;
            }
            prev=curr;
            
        }
        return  prev[target];
        
    }
};
