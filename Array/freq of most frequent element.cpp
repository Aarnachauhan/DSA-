leetcode 1838
binary search
tc-o(nlogn)
sc-o(n) because of pre vector

class Solution {
public:
int binary(int target_index, int k , vector<int> &nums, vector<long> &pre){
    int target=nums[target_index];
 int l=0;
 int r=target_index;

 int best_index=target_index;
 while(l<=r){ //binary search-o(logn)
    int mid=l+(r-l)/2;
    long count=(target_index -mid+1);
    long windowsum=count*target;

    long currsum=pre[target_index] - pre[mid] + nums[mid];

    int ops=windowsum-currsum;
    if(ops>k){
        l=mid+1;
    }
    else {
        best_index=mid;
        r=mid-1;
    }
 }
 return target_index - best_index +1;
}
    int maxFrequency(vector<int>& nums, int k) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       vector<long> pre(n);
       pre[0]=nums[0];
       for(int i=1;i<n;i++){ //o(n)
        pre[i]=pre[i-1] + nums[i];
       }

       int ans=0;

       for(int target_index=0;target_index <n;target_index++){
        ans=max(ans,binary(target_index,k,nums,pre));
       }
       return ans;
    
    }
};
