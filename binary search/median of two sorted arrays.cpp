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
tc-o(n+m)
sc-O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int size=n+m;

        int ind1=(size/2)-1;
        int ele1=-1;
        int ind2=(size/2);
        int ele2=-1;

        int i=0, j=0, k=0;
        while(i<n && j<m){
            if(nums1[i]< nums2[j]){
                if(k==ind1){
                    ele1=nums1[i];
                }
                if(k==ind2){
                    ele2=nums1[i];
                }
                i++;
            }
            else{
                if(k==ind1){
                    ele1=nums2[j];
                }
                if(k==ind2){
                    ele2=nums2[j];
                }
                j++;
            }
            k++;
        }
        while(i<n){
           
                if(k==ind1){
                    ele1=nums1[i];
                }
                if(k==ind2){
                    ele2=nums1[i];
                }
                i++;
                k++;
            
        }
        while(j<m){
            if(k==ind1){
                    ele1=nums2[j];
            }
            if(k==ind2){
                    ele2=nums2[j];
            }
            j++;
            k++;

        }

        if(size%2==1){
            return (double) ele2;
        }
        else {
            return (double) (ele1+ele2)/2 ;
        }

      return 0;
    }
};
