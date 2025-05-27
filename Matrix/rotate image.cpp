//tc- O(n2) + O(n2) 
//sc- O(1)


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //o(n/2 * n/2)
       //transpose
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse 
        //o(n * n/2)
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
