lc 123

recursion
class Solution {
public:
int f(int i , int buy , int cap,vector<int> &prices){
if(cap==0) return 0;
if(i==prices.size())  return 0;

if(buy==1){
    int take= -prices[i] + f(i+1,0,cap,prices);
    int nottake=0+ f(i+1 , 1, cap,prices);

    return max(nottake , take);
}
else{
    int sell=prices[i]+ f(i+1,1, cap-1,prices);
    int notsell=0+ f(i+1,0,cap,prices);
    return max(sell,notsell);
}

}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return f(0,1,2,prices);
    }
};
---------------------------------------------------------------------------
memoization
class Solution {
public:
int f(int i , int buy , int cap,vector<int> &prices,vector<vector<vector<int>>> & dp ){
if(cap==0) return 0;
if(i==prices.size())  return 0;

if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
if(buy==1){
    int take= -prices[i] + f(i+1,0,cap,prices,dp);
    int nottake=0+ f(i+1 , 1, cap,prices,dp);

    return dp[i][buy][cap]=max(nottake , take);
}
else{
    int sell=prices[i]+ f(i+1,1, cap-1,prices,dp);
    int notsell=0+ f(i+1,0,cap,prices,dp);
    return dp[i][buy][cap]=max(sell,notsell);
}

}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};


--------------------------------------------------------------------------------------------------------
tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n+1,
            vector<vector<int>>(2,
                vector<int>(3,0)));

        for(int ind=n-1; ind>=0; ind--) {

            for(int buy=0; buy<=1; buy++) {

                for(int cap=1; cap<=2; cap++) {

                    if(buy) {

                        dp[ind][buy][cap] =
                            max(
                                -prices[ind] + dp[ind+1][0][cap],
                                dp[ind+1][1][cap]
                            );
                    }
                    else {

                        dp[ind][buy][cap] =
                            max(
                                prices[ind] + dp[ind+1][1][cap-1],
                                dp[ind+1][0][cap]
                            );
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

-------------------------------------------------------------------------------------------
space optimization 
  class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<vector<int>> ahead(2,
                                  vector<int>(3,0));

        vector<vector<int>> curr(2,
                                 vector<int>(3,0));

        int n = prices.size();

        for(int ind=n-1; ind>=0; ind--) {

            for(int buy=0; buy<=1; buy++) {

                for(int cap=1; cap<=2; cap++) {

                    if(buy) {

                        curr[buy][cap] =
                            max(
                                -prices[ind] + ahead[0][cap],
                                ahead[1][cap]
                            );
                    }
                    else {

                        curr[buy][cap] =
                            max(
                                prices[ind] + ahead[1][cap-1],
                                ahead[0][cap]
                            );
                    }
                }
            }

            ahead = curr;
        }

        return ahead[1][2];
    }
};
Complexity
Approach	Time	Space
Recursion	O(2ⁿ)	O(n)
Memoization	O(n×2×3)	O(n×2×3)
Tabulation	O(n×2×3)	O(n×2×3)
Space Optimized	O(n×2×3)	O(2×3)
