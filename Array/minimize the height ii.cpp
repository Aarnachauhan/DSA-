  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int longest=arr[n-1];
        int shortest=arr[0];
        int ans=longest-shortest;
        for(int i=1;i<n;i++){
            longest=max(arr[n-1]-k,arr[i-1]+k);
            shortest=min(arr[i]-k,arr[0]+k);
            if(shortest<0){
                continue;
            }
            ans=min(longest-shortest,ans);
        }
        return ans;
    }
};
