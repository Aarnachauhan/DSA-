gfg : https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

recursive code:
TC O(2^N)
SC O(N)
class Solution {
  public:
  
 int f(int ind , vector<int> &arr, int target){
     if(ind==0){
     if(target==0 && arr[0]==0) return 2;
     if(target==0 || target==arr[0]) return 1;
     return 0;
     }
     
     int notpick=f(ind-1 , arr, target);
     int pick=0;
     if(arr[ind]<=target){
         pick=f(ind-1,arr,target-arr[ind]);
     }
     return pick+ notpick;
 }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int totalsum=accumulate(arr.begin(),arr.end(),0);
        if(totalsum-diff <0 ||(totalsum-diff)%2!=0 ) return 0;
        
        int target=(totalsum-diff)/2;
        return f(n-1,arr,target);
    }
};
-------------------------------------------------------------------------
memoization 
tc-o(n*target)
sc- O(N×Target)+O(N)
class Solution {
  public:
  
 int f(int ind , vector<int> &arr, int target,vector<vector<int>> &dp){
     if(ind==0){
     if(target==0 && arr[0]==0) return 2;
     if(target==0 || target==arr[0]) return 1;
     return 0;
     }
     if(dp[ind][target]!=-1) return dp[ind][target];
     int notpick=f(ind-1 , arr, target,dp);
     int pick=0;
     if(arr[ind]<=target){
         pick=f(ind-1,arr,target-arr[ind],dp);
     }
     return dp[ind][target]=pick+ notpick;
 }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int totalsum=accumulate(arr.begin(),arr.end(),0);
        if(totalsum-diff <0 ||(totalsum-diff)%2!=0 ) return 0;
        
        int target=(totalsum-diff)/2;
        vector<vector<int>> dp(n , vector<int> (target+1,-1));
        return f(n-1,arr,target,dp);
    }
};
----------------------------------------------------------------------
Tabulation
class Solution {
  public:
  

    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int totalsum=accumulate(arr.begin(),arr.end(),0);
        if(totalsum-diff <0 ||(totalsum-diff)%2!=0 ) return 0;
        
        int target=(totalsum-diff)/2;
        vector<vector<int>> dp(n , vector<int> (target+1,0));
        //return f(n-1,arr,target,dp);
        if(arr[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
        if(arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;
        
        
        for(int i=1;i<n;i++){
            for(int j=0; j<=target;j++){
                int notpick=dp[i-1][j];
                int pick=0;
                if(arr[i]<=j){
                    pick=dp[i-1][j-arr[i]];
                }
                dp[i][j]=pick+notpick;
            }
            
        }
        
      return dp[n-1][target];  
    }
};

-----------------------------------------------------------------
space optimization 
class Solution {
  public:
  

    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int totalsum=accumulate(arr.begin(),arr.end(),0);
        if(totalsum-diff <0 ||(totalsum-diff)%2!=0 ) return 0;
        
        int target=(totalsum-diff)/2;
        
        vector<int> prev(target+1,0) , curr(target+1,0);
      
        if(arr[0]==0){
            prev[0]=2;
        }
        else{
           prev[0]=1;
        }
        if(arr[0] != 0 && arr[0] <= target)
        prev[arr[0]] = 1;
        
        
        for(int i=1;i<n;i++){
            for(int j=0; j<=target;j++){
                int notpick=prev[j];
                int pick=0;
                if(arr[i]<=j){
                    pick=prev[j-arr[i]];
                }
                curr[j]=pick+notpick;
            }
            prev=curr;
        }
        
      return prev[target];  
    }
};

