gfg

memo
tc-O(n*target) 
sc-o(n*target) + o(n)
class Solution {
  public:
int countsubset(int i , int currsum , int target , vector<int> &arr ,
vector<vector<int>>&dp , int n){
    if(i==n){
        return (currsum == target);
    }
    
    if(dp[i][currsum]!=-1) return dp[i][currsum];
    
    int nottake = countsubset(i+1, currsum ,target , arr, dp , n);
    
    int take=0;
    if(arr[i] + currsum <=target ){
        take= countsubset(i+1 ,currsum +arr[i], target , arr, dp , n);
        
    }
    return dp[i][currsum] = (take + nottake);
    
}
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        
        vector<vector<int>> dp(n+1, vector<int> (target + 1 , -1));
        
        return countsubset(0,0,target,arr,dp, n);
    }
};

tabulation 
tc- o(n*target)
sc- o(n* target)

class Solution {
  public:
   

    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        
        vector<vector<int>> dp(n+1, vector<int> (target + 1 , 0));
        
      dp[0][0] = 1;
      
      for(int i=1;i<=n;i++){
          for(int j=0;j<=target; j++){
              
             //not take
             dp[i][j]= dp[i-1][j];
             
             //take
             if(j>=arr[i-1]){
                  dp[i][j] += dp[i - 1][j - arr[i - 1]];
             }
          }
      }
      return dp[n][target];
    }
};
