leetcode 1021
class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter=0;
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
         if(s[i]==')') counter--; //last wala hume ans mai add nhi krna
         if(counter!=0) ans.push_back(s[i]); //first wala bhi add nhi krna
         if(s[i]=='(') counter++;
        }
        return ans;
    }
};
