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
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int ans=INT_MAX;

        vector<int> dp(n,INT_MAX);
        //first row of dp with first row of matrix
        for(int j=0;j<n;j++){
            dp[j]= matrix[0][j];
        }

        for(int i=0;i<n-1;i++){
            vector<int> temp(n,INT_MAX);
            for(int j=0;j<n;j++){
                //left 
                if(j-1>=0){
                    temp[j-1]=min(temp[j-1], dp[j] + matrix[i+1][j-1]);
                }
                //middle
                temp[j]= min(temp[j], dp[j]+ matrix[i+1][j]);

                //right
                if(j+1<n){
                    temp[j+1] = min( temp[j+1], dp[j] + matrix[i+1][j+1]);
                }
            }
            dp=temp;
        }
        //get the minimum value from last row.
        for(int j=0;j<n;j++){
            ans= min(ans, dp[j]);
        }
        return ans;
    }
};

space optimization 
tc-o(n*n) + o(n)
sc-o(n)
class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;

        vector<int> prev(n, INT_MAX);

        for(int j=0;j<n;j++){ //fill first row 
            prev[j] = matrix[0][j];
        }
        
        for(int i=0;i<n-1;i++){
            vector<int> curr(n,INT_MAX);
            for(int j=0;j<n;j++){
                //left diagonal 
                if(j-1>=0){
                    curr[j-1]= min(curr[j-1] , prev[j] + matrix[i+1][j-1] );
                }

                //middle
                curr[j] = min(curr[j] ,prev[j] + matrix[i+1][j]);

                //right diagonal 
                if(j+1<n){
                    curr[j+1] = min(curr[j+1] , prev[j] + matrix[i+1][j+1]);
                }
            }
            prev=curr;
        }
        for(int j=0;j<n;j++){
            ans= min(ans, prev[j]);
        }

        return ans;
    }
   
    
};
