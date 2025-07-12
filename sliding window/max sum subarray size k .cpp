gfg
max sum subarray of size k
class Solution { 
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int cursum=0;
        int maxi=0;
        for(int i=0;i<k;i++){
            cursum+=arr[i];
        }
        maxi=cursum;
        for(int i=k;i<n;i++){
            cursum+=arr[i]-arr[i-k];
            maxi=max(maxi,cursum);
        }
        return maxi;
    }
};
