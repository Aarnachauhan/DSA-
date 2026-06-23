lc 4 (hard)

brute:
tc-o(n+m) *(log(n+m)
sc-o(n+m)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums1[i]);
        }
        for(int i=0;i<m;i++){
            temp.push_back(nums2[i]);
        }

        sort(temp.begin(),temp.end());
        if(temp.size()%2==0){
            int ind=temp[temp.size()/2-1];
            int ind2=temp[temp.size()/2];
            return (double)(ind+ind2)/2;
        }
        else{
            return (double)temp[temp.size()/2];
        }
        return 0;
    }
};



better:
