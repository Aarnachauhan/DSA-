naukri.com

memorization tc-o(n) sc-o(n) + o(n)
#include <bits/stdc++.h> 
#include <iostream>
int f(int ind, vector<int> &heights , vector<int> &dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
   
    int left=f(ind-1,heights,dp) + abs(heights[ind]- heights[ind-1]);
    int right= INT_MAX; //if there is no right then it will be int_max so we cant choose that path
    if(ind>1) {
        right=f(ind-2,heights,dp) + abs(heights[ind]- heights[ind-2]);
    }
    return dp[ind]= min(right,left);
}




int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1 , -1);
    return f(n-1,heights,dp);
}

tabulation  --> bottom up
tc=O(N)
sc- O(n) //no stack space
#include <bits/stdc++.h> 
#include <iostream>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs=dp[i-1] + abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;

        if(i>1){
            ss=dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(fs,ss);
    }
   return dp[n-1];
}


space opt
tc-o(n)
sc-o(1)
#include <bits/stdc++.h> 
#include <iostream>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
 
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int fs=prev + abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;

        if(i>1){
            ss=prev2 + abs(heights[i]-heights[i-2]);
        }
        int curr=min(fs,ss);
        prev2=prev;
        prev=curr;
    }
   return prev;
}
