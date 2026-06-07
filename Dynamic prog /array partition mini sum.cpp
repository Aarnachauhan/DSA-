naukri.com

recursion 
Complexity
Time: O(2^N * TotalSum)
Space: O(N) recursion stack

bool solve(int ind , int target , vector<int> &a ){
	if(target==0) return true;
	if(ind==0){
		return a[0]==target;
	}
	bool exclude=solve(ind-1,target,a);
	bool include=false;
	if(a[ind]<=target){
		include=solve(ind-1,target-a[ind],a);
	}

	return exclude || include;
}


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totalsum=accumulate(arr.begin(),arr.end(),0);
	int mini=INT_MAX;
	for(int s1=0;s1<=totalsum;s1++){
		if(solve(n-1,s1,arr)){
			int s2=totalsum-s1;
			mini=min(mini,abs(s1-s2));
		}
	}
return mini;
}

  ---------------------------------------------------------------------------------------------------------
 memoization 
Complexity
Time: O(N × TotalSum)
Space: O(N × TotalSum) + O(N)

  bool solve(int ind , int target , vector<int> &a,
vector<vector<int>> & dp){
	if(target==0) return true;
	if(ind==0){
		return a[0]==target;
	}
	if(dp[ind][target]!=-1) return dp[ind][target];
	bool exclude=solve(ind-1,target,a,dp);
	bool include=false;
	if(a[ind]<=target){
		include=solve(ind-1,target-a[ind],a,dp);
	}

	return dp[ind][target]=exclude || include;
}


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totalsum=accumulate(arr.begin(),arr.end(),0);
	int mini=INT_MAX;
	vector<vector<int>> dp(n,vector<int>(totalsum+1, -1));
	for(int s1=0;s1<=totalsum;s1++){
		if(solve(n-1,s1,arr,dp)){
			int s2=totalsum-s1;
			mini=min(mini,abs(s1-s2));
		}
	}
	return mini;
}
--------------------------------------------------------------------------------------
Tabulation 
Complexity
Time: O(N × TotalSum)
Space: O(N × TotalSum)


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totalsum=accumulate(arr.begin(),arr.end(),0);
	vector<vector<bool>> dp(n,vector<bool>(totalsum+1,false));

	for(int i=0;i<n;i++){
		dp[i][0]=true;
	}
    if(arr[0]<=totalsum){
		dp[0][arr[0]]=true;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=totalsum;j++){
			bool nottake=dp[i-1][j];
			bool take=false;
			if(arr[i]<=j){
				take=dp[i-1][j-arr[i]];
			}
			dp[i][j]=take || nottake;
		}
	}

	int mini=INT_MAX;
	for(int s1=0;s1<=totalsum;s1++){
		if(dp[n-1][s1]){
			int s2=totalsum-s1;
			mini=min(mini,abs(s1-s2));
		}
	}
	return mini;
}
--------------------------------------------------------------------------------------------------
Space optimization :
Complexity
Time: O(N × TotalSum)
Space: O(TotalSum)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minSubsetSumDifference(vector<int>& arr, int n) {

        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        vector<bool> prev(totalSum + 1, false);
        vector<bool> curr(totalSum + 1, false);

        prev[0] = true;

        if(arr[0] <= totalSum)
            prev[arr[0]] = true;

        for(int ind = 1; ind < n; ind++) {

            curr[0] = true;

            for(int target = 1; target <= totalSum; target++) {

                bool notTake = prev[target];

                bool take = false;

                if(arr[ind] <= target)
                    take = prev[target-arr[ind]];

                curr[target] = take || notTake;
            }

            prev = curr;
        }

        int mini = INT_MAX;

        for(int s1 = 0; s1 <= totalSum; s1++) {

            if(prev[s1]) {

                int s2 = totalSum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }

        return mini;
    }
};
