
class Solution {
public:
    int ans=0;
    int beautySum(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            unordered_map<char,int> mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;

                int leastfreq=INT_MAX;
                int mostfreq=INT_MIN;
                for(auto it:mpp){
                    leastfreq=min(leastfreq,it.second);
                    mostfreq=max(mostfreq,it.second);
                }
                ans+=mostfreq-leastfreq;
            }
        }
        return ans;
    }
};
