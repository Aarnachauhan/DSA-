class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()<=k){
            return "0";
        }
        if(k==0) return num;

        string res="";
        stack<char> s;
        s.push(num[0]); //pushing first element into stack

        for(int i=1;i<num.length();i++){ //iterating the string
            while(k>0 && !s.empty() && num[i]<s.top()){
                k--;
                s.pop();
            }
            s.push(num[i]); //after poping the top of the stack we have to push the current element into the stack
            if(s.size() ==1 && num[i]=='0') s.pop(); //this pops preceeding zeroes
    
        }
        while(k && !s.empty()){
            k--;
            s.pop(); //this is for cases is 4568
        }
        while(!s.empty()){
            res.push_back(s.top()); //push the answer into the vector
            s.pop();
        }
        reverse(res.begin(),res.end()); 

        if(res.length()==0) return "0";
        return res;
    }
};
