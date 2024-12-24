class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //int n=nums1.size();
        int i=0;
        while(i<n){
          if(nums1[i]==0){
            nums1.push_back(nums2[i]);
            i++;
          }
        }
        sort(nums1.begin(),nums1.end());
    }
};
