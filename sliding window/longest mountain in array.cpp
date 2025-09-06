leetcode 845

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int nn=arr.size();
        int ans=0;
        int l=0;
        int n=arr.size();

        while(l<n){
            int r=l;
            
            if(r+1<n && arr[r]<arr[r+1]){
                while(r+1 < n && arr[r]<arr[r+1]) r++;

                if(r+1 < n && arr[r] > arr[r+1]){
                    while(r+1 < n && arr[r] > arr[r+1]) r++;

                    ans=max(ans,r-l+1);
                }
            }

            l=max(r,l+1);
            
        }
        return ans;
    }
};
