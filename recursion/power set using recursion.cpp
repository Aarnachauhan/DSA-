gfg


class Solution {
  public:
 void fun(int i , string str , string s, vector<string> &ans){
     if(i==s.length()){
         ans.push_back(str);
         return;
     }
     fun(i+1,str+s[i],s,ans);
     
     fun(i+1,str,s,ans);
 }
    vector<string> powerSet(string s) {
        // code here
        vector<string> ans;
        fun(0,"",s,ans);
        return ans;
    }
};
