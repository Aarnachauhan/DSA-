leetcode 405
tc-o(logn )
sc-o(1)
class Solution {
public:
    string toHex(int num) {
        if(!num) return "0";
        unsigned int ournum=num;

        string res;
        string hex="0123456789abcdef";

        while(ournum){
            res+=hex[ournum %16];
            ournum/=16;

        }

        reverse(res.begin(),res.end());
        return res;
    }
};

