tc-o(m*n)
sc-o(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size() , n=matrix[0].size();
        bool isrow=false, iscol=false;

        //check if 1st row is impacted or not
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0) isrow=true;
        }
       //check if 1st col is impacted or not
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0) iscol=true;
        }
        //set the tester excluding 1st row and 1st col
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //set for that particular index and col
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j]=0;
            }
        }
        //mark 1st row as 0
        if(isrow){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
       //mark 1st col as 0
        if(iscol){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};
