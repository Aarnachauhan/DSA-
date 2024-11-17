class Solution {
public:
void rows(vector<vector<int>> &matrix,int m ,int n,int i){ 
    for(int j=0;j<n;j++){ //n
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}
void cols(vector<vector<int>> &matrix,int m,int n,int j){
    for(int i=0;i<m;i++){ //m
      if(matrix[i][j]!=0){
        matrix[i][j]=-1;
      }
    }
}
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){ //n * m
                if(matrix[i][j]==0){
                    rows(matrix,m,n,i);
                    cols(matrix,m,n,j);
                }
            }
        }
        for(int i=0;i<m;i++){  
            for(int j=0;j<n;j++){  //n*m
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }

    }
};
//tc - (n*m) * (n+m) + (n*m)= ( )^3
