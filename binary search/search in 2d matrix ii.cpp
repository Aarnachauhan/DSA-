leetcode 240
better
tc-o(nlogm)
sc-o(1)
 class Solution {
public:
int bs(vector<int>& mat, int target){
    int n = mat.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mat[mid] == target) return true;
        else if (target > mat[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
           bool ind=bs(matrix[i],target);
             if(ind) return true;
        }
       
        return false;
    }
};

