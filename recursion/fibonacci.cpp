lc 509
tc-O(2n)
sc-0(n)
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int last=fib(n-1);
        int seclast=fib(n-2);

        return last+ seclast;
    }
};
