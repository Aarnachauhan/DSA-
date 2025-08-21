gfg

1) inbuilt
class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        return __gcd(a,b);
    }
};


2) eculidean algo using substraction
class Solution {
  public:
    int gcd(int a, int b) {
        if(a==0) return a;
        if(b==0) return b;
        
        if(a==b) return a;
        if(a>b){
           return gcd(a-b,b);
        }

        else{
           return gcd(a,b-a);
        }
        
        
    }
};


3) 
