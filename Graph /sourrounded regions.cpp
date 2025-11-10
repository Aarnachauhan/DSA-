leetcode 130



class Solution {
private:
     int m,n;

     void dfs(int i,int j , vector<vector<char>>& board ,vector<vector<bool>>&vis ){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || board[i][j]=='X') return;

        vis[i][j]=true;
        //dfs on neighbour
         dfs(i + 1, j, board, vis);
        dfs(i - 1, j, board, vis);
        dfs(i, j + 1, board, vis);
        dfs(i, j - 1, board, vis);
     }
public:
    void solve(vector<vector<char>>& board) {
         m=board.size();
         n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        //left and right
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis);
            }
            if(board[i][n-1]=='O' && !vis[i][n-1]) dfs(i,n-1,board,vis);
        }
        //top and bottom 
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0,j,board,vis);
            }
            if(board[m-1][j]=='O' && !vis[m-1][j]){
                dfs(m-1,j,board,vis);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(board[i][j]=='O' && !vis[i][j]){
                board[i][j]='X';
               }
            }
        }
    }
};
