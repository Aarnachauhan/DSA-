leetcode 

recursion--->
tc- O(2^m*n)
sc-O(path length) = O(m-1) + (n-1)


class Solution {
public:
int rec(int i,int j, int m , int n){
    if(i==0 && j==0) return 1;
    if(i<0 && j<0) return 0;

    //move up 
    int up=rec(i-1,j,m,n);

    //move left 
    int left=rec(i,j-1,m,n);
    return up + left;
}
    int uniquePaths(int m, int n) {
        return rec(0,0,m,n);
    }
};

memorization --->
tc-o(m*n)
sc- o(path length ) + o(m*n)
class Solution {
public:
int rec(int i,int j, int m , int n,vector<vector<int>>&dp){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
    //move up 
    int up=rec(i-1,j,m,n,dp);

    //move left 
    int left=rec(i,j-1,m,n,dp);
    return dp[i][j]=up + left;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return rec(m-1,n-1,m,n,dp);
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
