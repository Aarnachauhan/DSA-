leetcode 3
using set
tc-o(n)
sc-o(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxi=0;
        int l=0;
        unordered_set<char> charset;
        for(int r=0;r<n;r++){
            while(charset.find(s[r])!=charset.end()){
                charset.erase(s[l]);
                l++;
            }
            charset.insert(s[r]);
            maxi=max(maxi, r-l+1);
        }
        return maxi;
    }
};

using sliding window (hashmap)
tc-o(n)
sc-o(3) = o(1)
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

using last seen
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int l=0;
        int n=s.length();
        unordered_map<char,int> lastseen;

        for(int r=0;r<n;r++){
            char c=s[r];
            if(lastseen.find(c)!=lastseen.end() && lastseen[c]>=l){
                l=lastseen[c]+1;
            }
            maxi=max(maxi,r-l+1);
            lastseen[c]=r;
        
        }
        return maxi;
    }
};
