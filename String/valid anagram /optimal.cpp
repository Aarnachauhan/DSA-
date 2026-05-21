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
optimal :
bool areAnagrams(string &s1, string &s2) {
    
    if (s1.length() != s2.length()) return false;
    
    // for lowercase a-z
    vector<int> freq(26, 0);  
    
    // Count frequency of each character in s1
    for(char ch : s1) 
        freq[ch - 'a']++;
    
    // Subtract frequency using characters from s2
    for(char ch : s2) 
        freq[ch - 'a']--;
    
    // If any count is not zero, not an anagram
    for(int count : freq) {
        if (count != 0)
            return false;
    }
    
    return true;
}
