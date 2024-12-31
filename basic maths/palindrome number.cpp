class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0 || (x!=0 && x%10==0)) return false;
        int reversed=0;
        while(x>reversed){
            reversed=reversed*10+x%10;
            x/=10;
        }
        return (x==reversed || x==reversed/10);
    }
};

note:
x==reversed/10 is for x=121

at a moment x=1 and reversed=12
so reversed/10=1 so x==reversed.
