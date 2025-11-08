leetcode 1047
tc-o(n)
sc-o(n)

using string as stack . 

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(char c : s){
            if(!ans.empty() && ans.back()==c){
                ans.pop_back();

            }else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};
