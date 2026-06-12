lc 188

recursion
class Solution {
public:
int f(int i , int trans ,int k , vector<int> & prices){
    if(i==prices.size() || trans==2*k) return 0;

    if(trans%2==0){
        int buy=-prices[i]+ f(i+1,trans+1,k,prices);
        int notbuy=0+f(i+1,trans,k,prices);

        return max(buy,notbuy);
    }
    else{
        int sell=prices[i]+ f(i+1,trans+1,k,prices);
        int notsell=0+ f(i+1,trans,k,prices);

        return max(sell,notsell);
    }
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        return f(0,0,k,prices);
    }
};

memoization
TC= O(n * 2k)
class Solution {
public:
int f(int i , int trans ,int k , vector<int> & prices, vector<vector<int>> &dp){
    if(i==prices.size() || trans==2*k) return 0;
    if(dp[i][trans]!=-1) return dp[i][trans];
    if(trans%2==0){
        int buy=-prices[i]+ f(i+1,trans+1,k,prices,dp);
        int notbuy=0+f(i+1,trans,k,prices,dp);

        return dp[i][trans]=max(buy,notbuy);
    }
    else{
        int sell=prices[i]+ f(i+1,trans+1,k,prices,dp);
        int notsell=0+ f(i+1,trans,k,prices,dp);

        return dp[i][trans]=max(sell,notsell);
    }
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2*k,-1));
        return f(0,0,k,prices,dp);
    }
};

tabulation :
class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2*k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int trans=2*k-1;trans>=0;trans--){
                if(trans%2==0){
                  int buy=-prices[i]+ dp[i+1][trans+1];
                  int notbuy=0+dp[i+1][trans];

                   dp[i][trans]=max(buy,notbuy);
              }
               else{
                  int sell=prices[i]+ dp[i+1][trans+1];
                  int notsell=dp[i+1][trans];

                   dp[i][trans]=max(sell,notsell);
                }
            }
        }
        return dp[0][0];
    }
};

space optimization

class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(2*k+1,0) , ahead(2*k+1,0);
        for(int i=n-1;i>=0;i--){
            for(int trans=2*k-1;trans>=0;trans--){
                if(trans%2==0){
                  int buy=-prices[i]+ ahead[trans+1];
                  int notbuy=0+ahead[trans];

                   curr[trans]=max(buy,notbuy);
              }
               else{
                  int sell=prices[i]+ ahead[trans+1];
                  int notsell=ahead[trans];

                   curr[trans]=max(sell,notsell);
                }
            }
            ahead=curr;
        }
        return ahead[0];
    }
};
