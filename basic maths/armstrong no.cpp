gfg
tc-o(n)
sc-o(1)

// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int original=n;
        long long last=0;
        long long ans=0;
        
        while(n!=0){
            last=n%10;
            ans=ans+ last*last*last;
            n=n/10;
        }
        return original == ans;
    }
};
