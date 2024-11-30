class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s1;
        unordered_map<char,int> s2;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            s1[s[i]]++;
            s2[t[i]]++;
        }
        if(s1==s2) return true;
        else {
            return false;
        }
    }
};
