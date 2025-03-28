class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
        int n=arr.size();
        if(n==1) return 0;
        sort(arr.begin(),arr.end());
        int ans=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++){
            int mini=min(arr[i+1]-k,arr[0]+k);
            int maxi=max(arr[n-1]-k,arr[i]+k);
            ans=min(ans,abs(mini-maxi));
        }
        return ans;
    }
};
