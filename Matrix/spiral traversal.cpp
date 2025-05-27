difficult
tc- O(n*m)
sc- O(n*m)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         int n=matrix.size();//no of rows
        int m=matrix[0].size(); //no of columns
         int left=0;
         int right=m-1;
         int top=0;
         int bottom=n-1;
         vector<int> ans;

    while(top<=bottom && left<=right){

    
         for(int i=left;i<=right;i++){ //left se right
            ans.push_back(matrix[top][i]); //top will be constant
         }
         top++;
         //top to bottom
         for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]); //right will be constant
         }
         right--;
         //right to left
         if(top<=bottom){
         for(int i=right;i>=left;i--){
            ans.push_back(matrix[bottom][i]); //bottom is constant 
         }
         bottom--;
         }
        //bottom to top
        if(left <=right){

        
         for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
         }
         left++;

        }
      }
      return ans;
    }
};
