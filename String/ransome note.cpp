leetcode 383
solution 1:
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> megahash;

        for(char c: magazine){
            megahash[c]++;
        }

        for(char c:ransomNote){
            if(megahash[c]<=0){
                return false;
            }
            megahash[c]--;
        }
        return true;
    }
};

solution 2:
