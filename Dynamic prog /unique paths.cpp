leetcode 

recursion--->
tc- O(2^m*n)
sc-O(path length) = O(m-1) + (n-1)
class Solution {
public:
int f(int i, int j){
    if(i==0 && j==0) return 1;
    if(i<0 ||  j<0) return 0;

    int up=f(i-1,j);
    int left=f(i,j-1);

    return left+up;
}
    int uniquePaths(int m, int n) {
        return f(m-1,n-1);
    }
};


memorization --->
tc-o(m*n)
sc- o(path length ) + o(m*n)
class Solution {
public:
int f(int i, int j,vector<vector<int>> &dp){
    if(i==0 && j==0) return 1;
    if(i<0 ||  j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=f(i-1,j,dp);
    int left=f(i,j-1,dp);

    return dp[i][j]=left+up;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(m-1,n-1,dp);
    }
};

Tabulation --->
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[0][0]=1;
                    continue;

                } 
                else{
                    int up=0, left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up + left;
                }
            }
           
        }
        return dp[m-1][n-1];
        
    }
};



space optimization 
tc- o(n*m)
sc-o(n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=curr[j-1];
                    curr[j]=left+up;
                }

            }
            prev=curr;
        }
        return prev[n-1];
    }

};
