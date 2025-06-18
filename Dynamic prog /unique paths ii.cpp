leetcode path ii

recursion
class Solution {
public:
int rec(int i,int j, int m , int n, vector<vector<int>>&obstacleGrid){
    if(i>=m || j>=n || obstacleGrid[i][j]==1 ) return 0;
    if(i==0 && j==0) return 1;

    //up 
    int up=rec(i-1,j,m,n,obstacleGrid);
    //left
    int left=rec(i,j-1,m,n,obstacleGrid);

    return up+ left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return rec(0,0,m,n,obstacleGrid);
    }
};

memorization
class Solution {
public:
int rec(int i,int j, int m , int n, vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
    if(i>=0 || j>=0 || obstacleGrid[i][j]==1 ) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];

    //up 
    int up=rec(i-1,j,m,n,obstacleGrid,dp);
    //left
    int left=rec(i,j-1,m,n,obstacleGrid,dp);

    return up+ left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return rec(0,0,m,n,obstacleGrid,dp);
    }
};

tabulation
class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=dp[i-1][j];
                   if(j>0) left= dp[i][j-1];
                   dp[i][j]=up + left;
                }
            }   
        }
       return dp[m-1][n-1];
    }
};

space optimization
class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        vector<int> dp(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) continue;
                else if(i==0 && j==0) curr[j]=1;
                else{
                 
                    if(i>0) curr[j]+=dp[j];
                   if(j>0) curr[j]+=curr[j-1];
                  
                }
                
            }   
            dp=curr;
        }
       return dp[n-1];
    }
};
