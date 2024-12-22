class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        int e=n-1;
       int ans=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[s]<=nums[mid]){ //left half is sorted .
            // = sign here because of only 2 elements in the array
            ans=min(ans,nums[s]);
            s=mid+1; //eliminate left half
            }
            else{ //right half is sorted
           
                ans=min(ans,nums[mid]);
                e=mid-1; //eliminate right half
            } 
        }
        return ans;
    }
};
