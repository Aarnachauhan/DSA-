leetcode 931

recursion - TLE
tc- o(3^n)
sc-o(n)

class Solution {
public:
void recur(int row, int col , int &ans, int val , int n, vector<vector<int>> & matrix ){
    if(row>=n){ // we reached last row 
        ans=min(ans,val);
        return ; 
    }

    val+=matrix[row][col];
    //left 
    if(col>=0) {
        recur(row+1, col-1, ans, val , n ,matrix);
    }
    //middle 
    recur(row+1, col , ans, val , n , matrix);

    //right
    if(col+1<n)
    recur(row+1, col+1, ans , val , n , matrix);
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans= INT_MAX;
      
         for(int i=0;i<n;i++){
            int temp=INT_MAX;
            recur(0,i,temp,0,n,matrix);
            ans=min(temp,ans);
         }
         return ans;
    }
};

memoization 


class Solution {
public:
int recur(int row, int col , int n , vector<vector<int>> & matrix ,vector<vector<int>> &dp ){
    if(row>=n){
        return 0;
    }
    if(dp[row][col]!=INT_MAX) return dp[row][col];
    int val= matrix[row][col];
    // left 
    if(col-1>=0){
    dp[row][col] = min(dp[row][col] , recur(row+1, col-1 , n , matrix , dp));
    }
    //mid
        dp[row][col] = min(dp[row][col], recur(row+1, col, n, matrix, dp));
        //Right
        if(col+1<n)
        dp[row][col] = min(dp[row][col], recur(row+1, col+1, n, matrix, dp));

        dp[row][col] += matrix[row][col];

        return dp[row][col];
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int ans= INT_MAX;

        for(int i=0;i<n;i++){
            vector<vector<int>> dp(n , vector<int>(n,INT_MAX));
            ans=min(ans, recur(0,i, n, matrix,dp));
        }
        return ans;
        
    }
};


tabulation
