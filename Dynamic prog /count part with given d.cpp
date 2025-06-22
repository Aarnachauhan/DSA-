naukri.com

count part with given d
tabulation
#include <bits/stdc++.h> 
int mod=(int)1e9+7;
int findways(vector<int>&arr , int target){
    int n=arr.size();
    vector<vector<int>> dp(n , vector<int>(target+1 , 0));

    if(arr[0]==0) dp[0][0] =2 ;  //2 cases of pick and not pick
    else dp[0][0] =1 ; //1 not pick case 

    if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;


    for(int i=1;i<n;i++){
        for(int tar=0;tar <= target ;tar++){
            int nottake = dp[i-1][tar];

            int take=0;
            if(arr[i] <=tar){
                take= dp[i-1][tar-arr[i]];

            }
            dp[i][tar] = (take + nottake) % mod;
        }
    }

 return dp[n-1][target];

}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int total=0;
    //find total sum
    for(auto &it : arr) total+=it;
    //check edges cases 
    if(total - d < 0 ||(total - d)%2 ==1) return 0;
    return findways(arr, (total - d)/2);
}


