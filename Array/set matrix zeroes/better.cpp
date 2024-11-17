tc - (n*m) + (n*m) = 0( 2nm )
sc- O(n) + O(m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
         vector<int> cols(n,0);
         vector<int> rows(m,0);
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){ //o(n*m)
             if(matrix[i][j]==0){
                rows[i]=1;
                cols[j]=1;
             }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){ //o(n*m)
                if(rows[i]==1 || cols[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
