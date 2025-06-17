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
