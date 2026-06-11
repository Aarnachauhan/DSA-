lc 44

recursion
class Solution {
public:
int f(int i , int j , string &s , string &t){
    if(i<0 && j<0) return true;
    if(j<0 && i>=0) return false;
    if(i<0 && j>=0){
        for(int m=0;m<=j;m++){
            if(t[m]!='*') return false;
        }
        return true;
    }

    if(s[i]==t[j] || t[j]=='?'){
        return f(i-1,j-1,s,t);
    } 
    if(t[j]=='*') return f(i-1,j,s,t) || f(i,j-1,s,t);

    else return false;
}
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        return f(n-1,m-1,s,p);
    }
};

memoization
class Solution {
public:
int f(int i , int j , string &s , string &t, vector<vector<int>> &dp){
    if(i<0 && j<0) return true;
    if(j<0 && i>=0) return false;
    if(i<0 && j>=0){
        for(int m=0;m<=j;m++){
            if(t[m]!='*') return false;
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j] || t[j]=='?'){
        return dp[i][j]=f(i-1,j-1,s,t,dp);
    } 
    if(t[j]=='*') return dp[i][j]= (f(i-1,j,s,t,dp) || f(i,j-1,s,t,dp));

    return dp[i][j]=false;
}
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return f(n-1,m-1,s,p,dp);
    }
};

tabulation:
class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(
            n+1, vector<bool>(m+1,false));

        dp[0][0] = true;

        for(int j=1;j<=m;j++){
            bool flag=true;

            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }

            dp[0][j]=flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s[i-1]==p[j-1] ||
                   p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }

                else if(p[j-1]=='*'){
                    dp[i][j]=
                    dp[i-1][j] ||
                    dp[i][j-1];
                }

                else{
                    dp[i][j]=false;
                }
            }
        }

        return dp[n][m];
    }
};


space optimization
class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<bool> prev(m+1,false),
                     curr(m+1,false);

        prev[0]=true;

        for(int j=1;j<=m;j++){

            bool flag=true;

            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }

            prev[j]=flag;
        }

        for(int i=1;i<=n;i++){

            curr[0]=false;

            for(int j=1;j<=m;j++){

                if(s[i-1]==p[j-1] ||
                   p[j-1]=='?'){
                    curr[j]=prev[j-1];
                }

                else if(p[j-1]=='*'){
                    curr[j]=prev[j] ||
                            curr[j-1];
                }

                else{
                    curr[j]=false;
                }
            }

            prev=curr;
        }

        return prev[m];
    }
};
