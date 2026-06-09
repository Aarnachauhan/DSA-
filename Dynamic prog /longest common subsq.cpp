lc 1143

recursion 

class Solution {
public:
int f(int i1, int i2, string &s1 , string &s2){
    if(i1<0 || i2<0) return 0;
    if(s1[i1]==s2[i2]) return 1 + f(i1-1,i2-1,s1,s2);
    return max(f(i1-1,i2,s1,s2) , f(i1,i2-1, s1,s2));
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        return f(n-1,m-1,text1,text2);
    }
};
------------------------------------------------------------------------------------------------------
memoization 
class Solution {
public:
int f(int i1, int i2, string &s1 , string &s2, vector<vector<int>> & dp){
    if(i1<0 || i2<0) return 0;
    if(dp[i1][i2]!=-1) return dp[i1][i2];
    if(s1[i1]==s2[i2]) return 1 + f(i1-1,i2-1,s1,s2,dp);
    return dp[i1][i2]=max(f(i1-1,i2,s1,s2,dp) , f(i1,i2-1, s1,s2,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
};
---------------------------------------------------------------------------------------------------
build up 
    i= i-1 , and j=j-1;
    i==0 and j==0 return 0
    n-1=n , m-1=m
    

class Solution {
public:
int f(int i1, int i2, string &s1 , string &s2, vector<vector<int>> & dp){
    if(i1==0 || i2==0) return 0;
    if(dp[i1][i2]!=-1) return dp[i1][i2];
    if(s1[i1-1]==s2[i2-1]) return 1 + f(i1-1,i2-1,s1,s2,dp);
    return dp[i1][i2]=max(f(i1-1,i2,s1,s2,dp) , f(i1,i2-1, s1,s2,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        return f(n,m,text1,text2,dp);
    }
};

-------------------------------------------------------------------------------------------------------------------------
tabulation :

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }

                else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        
        }
        return dp[n][m];
    }
};

-------------------------------------------------------------------------------------------------------------------------------
space optimization
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));

        vector<int> prev(m+1,0), curr(m+1,0);
        
        for(int j=0;j<=m;j++) prev[j]=0;
      

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                }

                else  curr[j]=max(prev[j],curr[j-1]);
            }
          prev=curr;
        }
        return prev[m];
    }
};

