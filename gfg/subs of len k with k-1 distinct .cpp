tc-o(n)
sc-o(1)
class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n=s.length();
        if(k>n) return 0;
        
        unordered_map<char,int>freq;
        int cnt=0;
        int l=0;
        
        for(int r=0;r<n;r++){
            freq[s[r]]++;
            if(r-l+1>k){
                freq[s[l]]--;
                if(freq[s[l]]==0) freq.erase(s[l]);
                l++;
            }
            
            if(r-l+1==k){
                if(freq.size()==k-1){
                    cnt++;
                }
            }
            
        }
        return cnt;
    }
};
