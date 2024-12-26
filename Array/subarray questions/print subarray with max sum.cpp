
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int sum=0;
      int start;
      int ansstart;
      int ansend;
        int n=nums.size();
        for(int i=0;i<n;i++){
          if (sum==0) start=i;
         sum+=nums[i];
         if(sum>maxsum) {
           maxsum=sum;
           ansstart=start;
           ansend=i;
         }
         if(sum<0) sum=0;
        }
        return elements from ansstart to ansend;
    }
};
