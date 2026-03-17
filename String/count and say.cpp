lc 38
tc-o(n*l)
sc-o(1)

class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for(int step=1;step<n;step++){
            string temp="";
            int i=0;
            while(i<res.length()){
                char curr=res[i];
                int cnt=0;

                while(i<res.length() && res[i]==curr){
                    cnt++;
                    i++;
                }
                temp+=to_string(cnt)+curr;
            }
            res=temp;
        }
        return res;
    }
};
