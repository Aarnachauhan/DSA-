gfg
approach 1:
  class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int ans=0;
        while(n>0){
            if((n&1)==1) ans++;
            n=n>>1;
        }
        return ans;
    }
};
approach 2:
class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int cnt=0;
        while(n!=0){
            n=n&n-1;
            cnt++;
        }
        return cnt;
    }
};
