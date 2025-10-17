leetcode 884
what is embrace_back
see second solution :
https://leetcode.com/problems/uncommon-words-from-two-sentences/solutions/5797112/bhai-of-cin-stringstream-full-map-concept-chalo-aao-smjhe-beats-100/?envType=problem-list-v2&envId=string
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s= s1+ " " + s2;
        
        unordered_map<string , int> ans;
        string temp="";
        for(auto &val : s){
            if(val==' '){
                ans[temp]++;
                temp="";
            }
            else{
                temp+=val;
            }
        }

        if(temp!=""){
            ans[temp]++;
            temp="";
        }

        vector<string> res;
        for(auto & val : ans){
            if(val.second==1){
                res.emplace_back(val.first);
            }
        }

        return res;
    }
};
