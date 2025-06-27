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
