naukri.com


#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    map<long long,int> presum;
    long long sum=0;
    int maxlen=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        long long rem=sum-k;
        //remaining sum is present.
        if(presum.find(rem)!=presum.end()){
          int len=i-presum[rem];
          maxlen=max(maxlen,len);
        }
        if(presum.find(sum)==presum.end()){
            presum[sum]=i;
        }
    }
    return maxlen;
}
