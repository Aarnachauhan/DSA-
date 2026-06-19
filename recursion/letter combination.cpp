lc 17

class Solution {
public:
 vector<string> mp = {
        "", "", //0,1
        "abc", //2
        "def",//3
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz" //9
    };
void f(int i , string &digits, string curr, vector<string> & ans){
     if(i==digits.size()){
        ans.push_back(curr);
        return;
     }

     string letters=mp[digits[i]-'0'];

     for(char c: letters){
        f(i+1,digits,curr+c,ans);
     }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        f(0,digits,"",ans);
        return ans;
    }
};
