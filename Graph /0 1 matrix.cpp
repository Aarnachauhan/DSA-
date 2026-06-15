lc 542

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
