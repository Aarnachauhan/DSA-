leetcode 88
tc-o(m+n)
sc-o(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1;
       int j=n-1;

       int r=m+n-1;
       while(j>=0){ //-1 aane per khatam loop
        if(i>=0 &&nums1[i]>nums2[j]){
          nums1[r]=nums1[i];
          i--;
       }else{
        nums1[r]=nums2[j];
        j--;
       }
       r--;
    }
    }
};
