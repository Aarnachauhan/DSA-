leetcode 120

recursion
tc-o(2^(1+2+3+ ....+n))
sc-o(n) // recursive stack space
class Solution {
public:
void rec(int row, int col , int val,int ans, int n, vector<vector<int>> & triangle){
    if(row==n-1){ //we reached last row.
       val+=triangle[row][col];
       ans=min(ans,val);
       return ;
    }
    else{
        val+=triangle[row][col]; //store the current
        //down
        rec(row+1,col,val, ans,n, triangle);
        //diagonal
        rec(row+1,col+1,val,ans,n,triangle);

    }
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans=INT_MAX;
        int n=triangle.size();
        rec(0,0,0,ans,n,triangle);
        return ans;
    }
};

memo
tc- o(n*n)
sc-o(n*n) +o(n)
class Solution {
public:
int rec(int row, int col ,int n, vector<vector<int>> & triangle, vector<vector<int>> & dp){
    if(row>n-1) return 0;
    if(dp[row][col]!=INT_MAX) return dp[row][col];

    int val= triangle[row][col];
    int i= rec(row+1,col,n,triangle,dp);
    int j=rec(row+1, col+1, n , triangle,dp);

    dp[row][col] = min(i,j) + val;
    return dp[row][col];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        vector<vector<int>>dp;
        for(int i=0;i<n;i++){
            int cur=triangle[i].size();
            vector<int> temp(cur,INT_MAX);
            dp.push_back(temp);
        }


         return rec(0,0,n,triangle,dp);
        
    }
};

tabulation
tc-o(n*n)
sc-o(n*n) // matrix and no recursive stack space

class Solution {
public:
   int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
     vector<vector<int>> dp(n,vector<int>(n,0));

     for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
     }

     for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down=triangle[i][j] + dp[i+1][j];
            int dia=triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down, dia);

        }
     }
     return dp[0][0];
    }
};



space opt
tc-same
sc-o(n)
class Solution {
public:
   int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
     vector<int> prev(n,0);
     vector<int> curr(n,0);

     for (int j = 0; j < n; j++) {
        prev[j] = triangle[n - 1][j]; //i will  be constant here
    }

        for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + prev[j];
            int diagonal = triangle[i][j] + prev[j + 1];
            
            // Store the minimum of the two possible paths in the current row
            curr[j] = min(down, diagonal);
        }
        // Update the front array with the values from the current row
        prev = curr;
    }
    return prev[0];

    
    }
};
