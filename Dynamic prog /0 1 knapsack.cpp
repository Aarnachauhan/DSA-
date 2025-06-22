naukri . com 

recursion 
tc-o(2^n) 
sc-
#include <bits/stdc++.h> 
int f(int ind , int maxi , vector<int> &wt , vector<int> &val){
	if(ind==0){
		if(wt[0]<= maxi) return val[0];
		else return 0;
	}
	int nottake=f(ind-1 , maxi , wt , val);
	int take=INT_MIN;
	if(wt[ind]<=maxi){
		take=val[ind] + f(ind-1 , maxi-wt[ind], wt, val);

	}
	return max(take , nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return f(n-1 , maxWeight , weight , value );
}

memoization 

#include <bits/stdc++.h> 
int f(int ind , int maxi, vector<int> &wt, vector<int> & val , vector<vector<int>>&dp){
	if(ind==0){
		if(wt[0]<=maxi) return val[0];
		else return 0;
	}
	if(dp[ind][maxi]!=-1) return dp[ind][maxi];
	int nottake = 0 + f(ind-1, maxi , wt , val ,dp );
	int take=INT_MIN;
	if(wt[ind]<=maxi){
		take=val[ind] + f(ind-1 , maxi-wt[ind], wt, val , dp);
	}
	return dp[ind][maxi] = max(take , nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp (n, vector<int> (maxWeight +1 , -1));
	return f(n-1 , maxWeight , weight , value , dp);
}

tabulation 
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp (n, vector<int> (maxWeight +1 , 0));

	for(int w=weight[0]; w<=maxWeight; w++) dp[0][w]= value[0];

	for(int ind=1;ind<n;ind++){
		for(int w=0;w<=maxWeight; w++ ){
			
         	int nottake = 0 + dp[ind-1][w];
	        int take=INT_MIN;
	        if(weight[ind]<=w){
		    take=value[ind] + dp[ind-1][w-weight[ind]];
	    }
	       dp[ind][w] = max(take , nottake);
		}
	}
	return dp[n-1][maxWeight];

	}


space optimization 1 
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1,0);
	for(int w=weight[0]; w<=maxWeight; w++) prev[w]= value[0];

	for(int ind=1;ind<n;ind++){
		for(int w=0;w<=maxWeight; w++ ){
			
         	int nottake = 0 + prev[w];
	        int take=INT_MIN;
	        if(weight[ind]<=w){
		    take=value[ind] + prev[w-weight[ind]];
	    }
	       curr[w] = max(take , nottake); //here the curr is updated
		}
		prev=curr;
	}
	return prev[maxWeight];

	}

space optimization 2
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight+1, 0);
	for(int w=weight[0]; w<=maxWeight; w++) prev[w]= value[0];

	for(int ind=1;ind<n;ind++){
		for(int w=maxWeight;w>=0; w-- ){
			
         	int nottake = 0 + prev[w];
	        int take=INT_MIN;
	        if(weight[ind]<=w){
		    take=value[ind] + prev[w-weight[ind]];
	    }
	       prev[w] = max(take , nottake);
		}
	}
		
	return prev[maxWeight];

	}

