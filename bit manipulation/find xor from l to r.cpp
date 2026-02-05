gfg

this solution will give tle 
tc-o(n)
sc-o(1)
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        // complete the function here
        int ans=0;
        for(int i=l;i<=r;i++){
            ans=ans^i;
            
        }
        return ans;
    }
};

optimal:
tc-o(1)
sc-o(1)
// User function Template for C++

class Solution {
  public:
  int solve(int n){
      if(n%4==1) return 1;
      if(n%4==2) return n+1;
      if(n%4==3) return 0;
      if(n%4==0) return n;
  }
    int findXOR(int l, int r) {
        // complete the function here
        return solve(l-1)^solve(r);
    }
};
