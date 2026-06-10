lc 72
Complexity
Approach   	Time	        Space
Recursion	  O(3^(n+m))	O(n+m)
Memoization	O(n*m)	    O(n*m)
Tabulation	O(n*m)    	O(n*m)
2 Arrays	  O(n*m)	    O(m)
1 Array   	O(n*m)	    O(m)
recursion :
class Solution {
public:
int f(int i , int j , string &s , string &t){
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(s[i]==t[j]){
        return f(i-1,j-1,s,t);
    }
    else{
        int insertop=1+f(i,j-1,s,t);
        int deleteop=1+f(i-1,j,s,t);
        int replaceop =1+f(i-1,j-1,s,t);

        return min({insertop , deleteop , replaceop});
   }
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return f(n-1,m-1,word1,word2);
    }
};

memoization 
class Solution {
public:
int f(int i , int j , string &s , string &t, vector<vector<int>> &dp){
    if(i<0) return j+1;
    if(j<0) return i+1;


    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]=f(i-1,j-1,s,t,dp);
    }
    else{
        int insertop=1+f(i,j-1,s,t,dp);
        int deleteop=1+f(i-1,j,s,t,dp);
        int replaceop =1+f(i-1,j-1,s,t,dp);

        return dp[i][j]=min({insertop , deleteop , replaceop});
   }
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n ,vector<int> (m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};


tabulation :

class Solution {
public:

    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1 ,vector<int> (m+1,0));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) {
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int insertops= 1+ dp[i][j-1];
                    int deleteops=1+  dp[i-1][j];
                    int replaceops=1+ dp[i-1][j-1];

                 dp[i][j]=min({insertops , deleteops, replaceops});
                }
            }
        }
        return dp[n][m];
    }
};


space optimization - 2d
class Solution {
public:

    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> prev(m+1,0) , curr(m+1,0);
         for(int j=0;j<=m;j++){
            prev[j]=j; 
        }

        for(int i=1;i<=n;i++){
             curr[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) {
                    curr[j]=prev[j-1];
                }
                else{
                    int insertops= 1+ curr[j-1];
                    int deleteops=1+  prev[j];
                    int replaceops=1+ prev[j-1];

                curr[j]=min({insertops , deleteops, replaceops});
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};

space optimization -1d

  
