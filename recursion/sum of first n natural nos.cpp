gfg
class Solution {
  public:
int rec(int i, int n , int sum){
    if(i>n) return sum;
    sum+=i;
    return rec(i+1,n,sum);
}
    int findSum(int n) {
        // code here
        //int sum=0;
      return  rec(0,n,0);
    }
};
