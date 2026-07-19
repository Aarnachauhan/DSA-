lc 542
tc-o(n*m)
sc-o(n*m)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> dist(n,vector<int> (m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;

        //push all 0 wale
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }


        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};


        
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int row=it.first;
            int col=it.second;

            for(int k=0;k<4;k++){
             int nr=row+dr[k];
             int nc=col+dc[k];

             if(nr>=0 && nr<n && nc>=0 && nc<m &&
                   !vis[nr][nc]){

                    vis[nr][nc]=1;

                    dist[nr][nc]=dist[row][col]+1;

                    q.push({nr,nc});
                }
            }
        }
        return dist;
    }
};


2nd version of same code
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();

        vector<pair<int,int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    mat[i][j]=INT_MAX;

                }
            }
        }

        while(!q.empty()){
            pair<int,int> cell= q.front();
            q.pop();

            int row=cell.first;
            int col=cell.second;

            for(pair<int,int> direction : directions){
                int nrow=row+direction.first;
                int ncol=col+ direction.second;

                if(nrow>=0 && nrow < rows && ncol>=0 && ncol < cols && 
                mat[nrow][ncol] > mat[row][col] + 1
               ){
                 mat[nrow][ncol]=mat[row][col]+1;
                 q.push({nrow,ncol});
               }
            }
        }
        return mat;
    }
};
