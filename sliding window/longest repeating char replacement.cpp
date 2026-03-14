lc 424
tc-O(n)
sc-o(26)= o(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int right=0;
        int left=0;
        int maxfreq=INT_MIN;
        int maxlength=INT_MIN;
        while(right<s.length()){
            freq[s[right]-'A']++;
            maxfreq=max(maxfreq,freq[s[right]-'A']);
            while((right-left+1)-maxfreq >k){
                freq[s[left]-'A']--;
                left++;

            }
            maxlength=max(maxlength,right-left+1);
            right++;

        }
        return maxlength;
    }
};
