lc, naukri.com , gfg

class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int s=0;
        int e=n;
        while(s<=e){
            long long mid=(s+e)/2;
      
            if(mid<=n/mid){ //mid*mid can overflow
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return e; //high will come to the max no and it will break while loop
    }
};
