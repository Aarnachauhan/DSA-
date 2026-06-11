lc 122

recursion 
class Solution {
public:
int f(int i , vector<int> & prices, int buy){
    if(i==prices.size()) return 0;
    if(buy==1){
       int take=-prices[i] + f(i+1 , prices,0);
       int nottake=f(i+1,prices,1);

       return max(take, nottake);
    }

    else{
        int sell=prices[i]+ f(i+1,prices, 1);
        int notsell=0+ f(i+1,prices,0);

        return max(sell , notsell);
    }
}
    int maxProfit(vector<int>& prices) {
        return f(0,prices,1);
    }
};


memoization

class Solution {
public:
int f(int i , vector<int> & prices, int buy, vector<vector<int>> &dp){
    if(i==prices.size()) return 0;

    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy==1){
       int take=-prices[i] + f(i+1 , prices,0,dp);
       int nottake=f(i+1,prices,1,dp);

       return dp[i][buy]=max(take, nottake);
    }

    else{
        int sell=prices[i]+ f(i+1,prices, 1,dp);
        int notsell=0+ f(i+1,prices,0,dp);

        return dp[i][buy]= max(sell , notsell);
    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return f(0,prices,1,dp);
    }
};


tabulation:

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
       
       for(int ind = n - 1; ind >= 0; ind--) {

            dp[ind][1] =
                max(-prices[ind] + dp[ind + 1][0],
                     dp[ind + 1][1]);

            dp[ind][0] =
                max(prices[ind] + dp[ind + 1][1],
                     dp[ind + 1][0]);
        }

        return dp[0][1];
    }
};

space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> ahead(2, 0),
                    curr(2, 0);

        for(int ind = n - 1; ind >= 0; ind--) {

            curr[1] =
                max(-prices[ind] + ahead[0],
                     ahead[1]);

            curr[0] =
                max(prices[ind] + ahead[1],
                     ahead[0]);

            ahead = curr;
        }

        return ahead[1];
    }
};
