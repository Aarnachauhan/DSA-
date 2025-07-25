naukri.com

array partition with minimum difference 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totalsum=0;
	for(int i=0;i<n;i++){
		totalsum+=arr[i];
	}
	int k=totalsum;
	vector<vector<bool>>dp(n,vector<bool>(k+1,0));
	for(int i=0;i<n;i++) dp[i][0] = true;
	if(arr[0]<=k) dp[0][arr[0]] =true;

	for(int ind=1;ind<n;ind++){
		for(int target=1;target<=k;target++){
			bool nottake= dp[ind-1][target];
            bool take=false;
			if(arr[ind]<=target)
		    take= dp[ind-1][target - arr[ind]];

			dp[ind][target] = take | nottake;

		}

	}

	int mini = 1e9;
	for(int s1=0;s1<=totalsum/2;s1++){
		if(dp[n-1][s1]==true){
			mini= min(mini , abs (totalsum - s1) - s1);
		}
	}
	return mini;

}
