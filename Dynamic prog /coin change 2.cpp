lc 518
recursive code
class Solution {
public:
int f(int ind, int target , vector<int> & coins){
    if(ind==0){
       if (target%coins[0]==0) return 1;
       return 0;
    }
    int notpick=f(ind-1,target , coins);
    int pick=0;
    if(coins[ind]<=target){
        pick=f(ind , target-coins[ind],coins);
    }
    return notpick+pick;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return f(n-1,amount, coins);
    }
};

memoization 
class Solution {
public:
int f(int ind, int target , vector<int> & coins, vector<vector<int>> & dp){
    if(ind==0){
       if (target%coins[0]==0) return 1;
       return 0;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notpick=f(ind-1,target , coins,dp);
    int pick=0;
    if(coins[ind]<=target){
        pick=f(ind , target-coins[ind],coins,dp);
    }
    return dp[ind][target]=notpick+pick;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return f(n-1,amount, coins,dp);
    }
};



tabulation 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                dp[0][target]=1;
            }
        }

        for(int ind=1;ind<n;ind++){
            for(int j=0;j<=amount;j++){
                long long notpick=dp[ind-1][j];
                long long pick=0;
                if(coins[ind]<=j){
                    pick=dp[ind][j-coins[ind]];
                }
                dp[ind][j]=notpick+pick;
            }
             
        }
       return dp[n-1][amount];
    }
};

space optimization 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
       
        vector<int> prev(amount+1 ,0) , curr(amount+1,0);
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                prev[target]=1;
            }
        }

        for(int ind=1;ind<n;ind++){
            for(int j=0;j<=amount;j++){
                long long notpick=prev[j];
                long long pick=0;
                if(coins[ind]<=j){
                    pick=curr[j-coins[ind]];
                }
                curr[j]=notpick+pick;
            }
            prev=curr; 
        }
       return prev[amount];
    }
};
