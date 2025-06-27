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

tc-o(n)*(log 256)
sc-o(256)

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int maxi=0,l=0,r=0;
        int n=s.size();
       unordered_map<char,int> mpp;
       while(r<s.size()){
           mpp[s[r]]++;
           if(mpp.size()>k){
               mpp[s[l]]--;
               if(mpp[s[l]]==0){
                   mpp.erase(s[l]);
                 
               }
               l++; 
             
           }
           if(mpp.size()==k){
               maxi=max(maxi,r-l+1);
           }
           r++;
       }
      return maxi==0?-1:maxi;
    }
};
