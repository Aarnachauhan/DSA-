public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> presum;
        int sum=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                maxlen=max(maxlen,i+1);
            }
            int rem=sum-k;
            if(presum.find(rem)!=presum.end()){
                int len=i-presum[rem];
                maxlen=max(maxlen,len);
            }
            presum[sum]=i;
        }
        return maxlen;
    }
};
