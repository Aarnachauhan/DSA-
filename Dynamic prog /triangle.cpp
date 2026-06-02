leetcode 120

recursion
tc-o(2^(1+2+3+ ....+n))
sc-o(n) // recursive stack space

class Solution {
public:
int f(int i , int j , int n, vector<vector<int>> & a){
     if(i==n-1) return a[n-1][j];
     int down=a[i][j] + f(i+1,j,n,a);
     int diag=a[i][j]+ f(i+1, j+1, n , a);

     return min(down , diag);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        return f(0,0,n,triangle);
    }
};


memo
tc- o(n*n)
sc-o(n*n) //for matrix , no recursive stack space

class Solution {
public:
int f(int i , int j , int n, vector<vector<int>> & a, vector<vector<int>> &dp){
     if(i>n-1) return 0;
     if(dp[i][j]!=INT_MAX)return dp[i][j];
     
     int down=a[i][j] + f(i+1,j,n,a,dp);
     int diag=a[i][j]+ f(i+1, j+1, n,a,dp);

     dp[i][j] = min(down,diag);

     return dp[i][j];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp;
        for(int i=0;i<n;i++){
            int curr=triangle[i].size();
            vector<int> temp(curr,INT_MAX);
            dp.push_back(temp);
        }
        
        return f(0,0,n,triangle,dp);
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
