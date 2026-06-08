lc 322

recursive solution - give tle
class Solution {
public:
int f(int ind , int target , vector<int> & coins){
  if(ind==0){
    if(target%coins[ind]==0) return target/coins[ind];
    else return 1e9;
  }
  int notpick=0+ f(ind-1,target,coins);
  int pick= INT_MAX;
  if(coins[ind]<=target){
    pick=1+ f(ind,target-coins[ind],coins);
  }
  return min(pick,notpick);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans= f(n-1,amount,coins);
        return (ans >= 1e9) ? -1 : ans;

    }
};

memoization
class Solution {
public:
int f(int ind , int target , vector<int> & coins, vector<vector<int>> &dp){
  if(ind==0){
    if(target%coins[ind]==0) return target/coins[ind];
    else return 1e9;
  }
  if(dp[ind][target]!=-1) return dp[ind][target];
  int notpick=0+ f(ind-1,target,coins,dp);
  int pick= INT_MAX;
  if(coins[ind]<=target){
    pick=1+ f(ind,target-coins[ind],coins,dp);
  }
  return dp[ind][target]=min(pick,notpick);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans= f(n-1,amount,coins,dp);
        return (ans >= 1e9) ? -1 : ans;

    }
};

tabulation 
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
       
        for(int target=0; target<=amount; target++){
    if(target % coins[0] == 0)
        dp[0][target] = target / coins[0];
    else
        dp[0][target] = 1e9;
}

        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notpick=0+ dp[ind-1][target];
                 int pick= INT_MAX;
                 if(coins[ind]<=target){
                      pick=1+ dp[ind][target-coins[ind]];
                   } 
                   dp[ind][target]=min(pick,notpick);
            }
        }
        
        return (dp[n-1][amount] >= 1e9) ? -1 : dp[n-1][amount]; 
    }
};


space optimization
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        //vector<vector<int>> dp(n,vector<int> (amount+1,0));
       
       vector<int> prev(amount+1,0) , curr(amount+1,0);
        for(int target=0; target<=amount; target++){
                if(target % coins[0] == 0)
                   prev[target] = target / coins[0];
        else
                prev[target] = 1e9;
        }

        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notpick=0+ prev[target];
                 int pick= INT_MAX;
                 if(coins[ind]<=target){
                      pick=1+ curr[target-coins[ind]];
                   } 
                   curr[target]=min(pick,notpick);
            }
            prev=curr;
        }
        
        return (prev[amount] >= 1e9) ? -1 : prev[amount]; 
    }
};
