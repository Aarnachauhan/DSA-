lc 242
tc o(n)
sc o(26)= o(1)
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
            return false;

        vector<int> freq(26,0);

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for(int x : freq){
            if(x != 0)
                return false;
        }

        return true;
    }
};
