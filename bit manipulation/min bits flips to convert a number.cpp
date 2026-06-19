tc 2220

tc-o(31)

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^ goal;
        int cnt=0;
        while(x){
            cnt+=(x&1);
            x>>=1;
        }
        return cnt;
    }
};


better approach 
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^ goal;
        int cnt=0;
        while(x){
            x=x&(x-1); //removes rightmost set bits
            cnt++;
        }
        return cnt;
    }
};
