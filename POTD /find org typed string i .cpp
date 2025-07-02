leetcode 3330 
class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.length();
        int cnt=1;
        for(int i=1;i<n;i++){
            if(word[i-1]==word[i]) cnt++;
        }
        return cnt;
    }
};
