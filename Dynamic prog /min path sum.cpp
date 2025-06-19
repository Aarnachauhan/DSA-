leetcode 64

recursion 
class Solution {
public:
 int rec(int i,int j, int m , int n , vector<vector<int>> &grid){
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return INT_MAX;

    //up 
    int up= grid[i][j] + rec(i-1,j,m,n,grid);

    //left
    int left=grid[i][j] + rec(i,j-1,m,n,grid);
    return min(up , left);
 }
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();

       return rec(m-1,n-1,m,n,grid);
        
    }
};

memo
class Solution {
public:
 int rec(int i,int j,  vector<vector<int>> &grid,vector<vector<int>>&dp){
    if(i==0 && j==0) return dp[0][0];
    if(i<0 || j<0) return INT_MAX;
    if(dp[i][j]!= -1) return dp[i][j];

    //up 
    int up= grid[i][j] + rec(i-1,j,grid,dp);

    //left
    int left=grid[i][j] + rec(i,j-1,grid,dp);
    return dp[i][j]=min(up , left);
 }
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>> dp(m,vector<int> (n,-1));

       return rec(m-1,n-1,grid,dp);
        
    }
};

tabulation
class Solution {
public:
   int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
     
      vector<vector<int>> dp(m,vector<int>(n,INT_MAX));

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
                continue;
            }
            int val= INT_MAX;
            if(i-1>=0) val= min(val,dp[i-1][j]);
            if(j-1>=0) val= min(val,dp[i][j-1]);

            dp[i][j] = val+ grid[i][j];
        }
      }
      return dp[m-1][n-1];
    }
};

space opt
class Solution {
public:
   int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
     
      vector<int> prev(n,INT_MAX);


      for(int i=0;i<m;i++){
        vector<int> curr(n,INT_MAX);
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                curr[j] = grid[i][j];
                continue;
            }
            int val= INT_MAX;
            if(i-1>=0) val= min(val,prev[j]);
            if(j-1>=0) val= min(val,curr[j-1]);

            curr[j] = val+ grid[i][j];
        }
        prev=curr;
      }
      return prev[n-1];
    }
};
