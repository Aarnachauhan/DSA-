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
