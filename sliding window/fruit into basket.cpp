gfg
Find length of the longest subarray containing atmost two distinct integers
tc-o(n2)
sc-o(3)

#include <set>
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int maxi=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            set<int>st;
            for(int j=i;j<n;j++){
                st.insert(arr[j]);
                if(st.size()<=2){
                    maxi=max(maxi,j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return maxi;
    }
};

better:
tc-o(n+n)
sc-o(3)
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int l=0,r=0,maxi=0;
        map<int,int>mpp;
        while(r<arr.size()){
            mpp[arr[r]]++;
            if(mpp.size()>2){
                while(mpp.size()>2){
                    mpp[arr[l]]--;
                    if(mpp[arr[l]]==0) {
                        mpp.erase(arr[l]);
                    }
                    l++;
                    
                }
            }
            if(mpp.size()<=2){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};

optimal solution . in worst case better is optimal . see notes
