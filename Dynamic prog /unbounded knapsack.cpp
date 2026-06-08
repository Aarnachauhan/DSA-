naukir.com
https://www.naukri.com/code360/problems/unbounded-knapsack_1215029?leftPanelTabValue=PROBLEM

recursion
#include <bits/stdc++.h>
int f(int ind, int totalweight , vector<int> &val ,vector<int> &productweight){
    if(ind==0){
        return (totalweight / productweight[0]) * val[0];
        
    }

    int notpick=f(ind-1, totalweight,val , productweight);
    int pick=INT_MIN;
    if(productweight[ind]<=totalweight){
        pick=val[ind]+f(ind,totalweight-productweight[ind],val , productweight);
    }
    return max(notpick,pick);
}



int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.

    return f(n-1,w,profit,weight);
}

memoization
#include <bits/stdc++.h>
int f(int ind, int totalweight , vector<int> &val ,vector<int> &productweight,
vector<vector<int>> &dp
){
    if(ind==0){
        return (totalweight / productweight[0]) * val[0];
        
    }
    if(dp[ind][totalweight]!=-1) return dp[ind][totalweight];
    int notpick=f(ind-1, totalweight,val , productweight,dp);
    int pick=INT_MIN;
    if(productweight[ind]<=totalweight){
        pick=val[ind]+f(ind,totalweight-productweight[ind],val , productweight,dp);
    }
    return dp[ind][totalweight]=max(notpick,pick);
}



int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int> (w+1,-1));
    return f(n-1,w,profit,weight,dp);
}

tabulation
#include <bits/stdc++.h>


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int> (w+1,0));
    for(int i=weight[0];i<=w;i++){
       dp[0][i]=(i / weight[0]) * profit[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int j=0;j<=w;j++){
             int notpick=dp[ind-1][j];
             int pick=INT_MIN;
             if(weight[ind]<=j){
                 pick=profit[ind]+dp[ind][j-weight[ind]];
             }
             dp[ind][j]=max(pick,notpick);
        }

    }
    return dp[n-1][w];
}
