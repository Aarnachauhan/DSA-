class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0;
        int left=0;
        unordered_map<char,int> count;
        for(int r=0;r<n;r++){
            char c=s[r];
            count[c]++; //adding it to the hashmap

            while(count[c]>1){
                char leftchar=s[left];
                count[leftchar]--;
                left++;
            }
            maxlen=max(maxlen, r-left+1);
        }
        return maxlen;
    }
};
