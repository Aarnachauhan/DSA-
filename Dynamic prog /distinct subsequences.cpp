lc 115

recursion:
class Solution {
public:
int f(int i ,int j , string &s , string &t){
    if(j<0) return 1;
    if(i<0) return 0;
   

    if(s[i]==t[j]){
      return   f(i-1,j-1,s,t) + f(i-1,j,s,t);
    }
    else  return f(i-1,j,s,t);
}
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        return f(n-1,m-1,s,t);
    }
};

memoization:
class Solution {
public:
int f(int i ,int j , string &s , string &t , vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;
   
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]){
      return  dp[i][j]= f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
    }
    else  return  dp[i][j]=f(i-1,j,s,t,dp);
}
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};


tabulation 
class Solution {
public:

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector< unsigned long long>> dp(n+1,vector<unsigned long long> (m+1,0));
       
       for(int i=0;i<=n;i++){
             dp[i][0]=1;
       }

       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1] + dp[i-1][j]; //getting runtime error here
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
       }
       return (int)dp[n][m];
    }
};


space optimization  -- 2 d 
class Solution {
public:

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<unsigned long long> prev(m+1,0) ,  curr(m+1,0);
       
       prev[0]=1;
       
       for(int i=1;i<=n;i++){
        curr[0]=1;
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                curr[j]=prev[j-1] + prev[j]; 
            }
            else{
                curr[j]=prev[j];
            }
        
        }
        prev=curr;

       }
       return (int)prev[m];
    }
};
