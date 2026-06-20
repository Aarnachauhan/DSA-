gfg

class Solution {
  public:
 void solve(int i , int j ,int n, vector<string> &ans , string s, vector<vector<int>>&vis , 
 vector<vector<int>> &maze){
     if(i==n-1 && j==n-1){
         ans.push_back(s);
         return;
     }
     //down
     if(i+1<n && !vis[i+1][j] && maze[i+1][j]==1){
         vis[i][j]=1;
         solve(i+1,j,n,ans,s+'D',vis,maze);
         vis[i][j]=0;
     }
     //left
     if(j-1>=0 && !vis[i][j-1] && maze[i][j-1]==1){
         vis[i][j]=1;
         solve(i,j-1,n,ans,s+'L',vis,maze);
         vis[i][j]=0;
     }
     //right
     if(j+1<n && !vis[i][j+1] && maze[i][j+1]==1){
         vis[i][j]=1;
         solve(i,j+1,n,ans,s+'R',vis,maze);
         vis[i][j]=0;
     }
     
     //up
     if(i-1>=0 && !vis[i-1][j] && maze[i-1][j]==1){
         vis[i][j]=1;
         solve(i-1,j,n,ans,s+'U',vis,maze);
         vis[i][j]=0;
     }
     
 }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        int n=maze.size();
       
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(maze[0][0]==1){
            solve(0,0,n,ans,"",vis,maze);
        }
        return ans;
    }
};
