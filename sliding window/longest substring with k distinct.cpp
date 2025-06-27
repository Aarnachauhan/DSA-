gfg

tc-o(n2)*log(256)
sc-o(256)


class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int maxi=0;
        int n=s.length();
        map<char,int> mpp;
        for(int i=0;i<n;i++){
          mpp.clear();
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                if(mpp.size()<=k){
                    maxi=max(maxi,j-i+1);
                }
                else break;
            }
        }
        return maxi;
    }
};
