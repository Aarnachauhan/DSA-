leetcode 1021
brute force 
tc-o(n)
sc-o(n)
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(st.empty()){ // if stack is empty that means its an outer paranthesis.
                    st.push('('); //we dont have to add it in answer string.
                }else{
                    ans+='('; //add in answer as it is not outerstring.
                    st.push('(');
                }
            }
            else if(s[i]==')'){
                st.pop();
                if(!st.empty()){
                    ans+=')'; //add in answer as it is not outerstring.
                }
            }
        }
        return ans;
    }
};

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
