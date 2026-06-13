lc 309

recursion:
class Solution {
public:
int f(int i , int buy , vector<int> &prices){
    if(i>=prices.size()) return 0;
    if(buy==1){
        int take=-prices[i] + f(i+1,0,prices);
        int nottake=0+f(i+1,1,prices);

        return max(take,nottake);
    }
    else{
        int sell=prices[i]+ f(i+2,1,prices);
        int notsell=0+ f(i+1,0,prices);

        return max(sell,notsell);
    }
    
}
    int maxProfit(vector<int>& prices) {
        return f(0,1,prices);
    }
};

memoization
class Solution {
public:
int f(int i , int buy , vector<int> &prices,vector<vector<int>> &dp){
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy==1){
        int take=-prices[i] + f(i+1,0,prices,dp);
        int nottake=0+f(i+1,1,prices,dp);

        return dp[i][buy]=max(take,nottake);
    }
    else{
        int sell=prices[i]+ f(i+2,1,prices,dp);
        int notsell=0+ f(i+1,0,prices,dp);

        return dp[i][buy]=max(sell,notsell);
    }
    
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return f(0,1,prices,dp);
    }
};

tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        for(int i=n-1;i>=0;i--){
            
                int take=-prices[i] + dp[i+1][0];
                int nottake=0+dp[i+1][1];

                dp[i][1]=max(take,nottake);
   
                int sell=prices[i]+ dp[i+2][1];
                int notsell=0+ dp[i+1][0];

                dp[i][0]=max(sell,notsell);
        
        }
       return dp[0][1];
    }
};

space optimization

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(2,0) , ahead(2,0) , ahead2(2,0);
        for(int i=n-1;i>=0;i--){
            
                int take=-prices[i] + ahead[0];
                int nottake=0+ahead[1];

                curr[1]=max(take,nottake);
   
                int sell=prices[i]+ ahead2[1];
                int notsell=0+ ahead[0];

                curr[0]=max(sell,notsell);
                ahead2=ahead;
                ahead=curr;
        
        }
       return ahead[1];
    }
};
