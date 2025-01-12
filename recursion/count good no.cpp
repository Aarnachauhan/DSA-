Time complexity: O(log N)
Memory complexity: O(log N) because a function call consumes memory and log N recursive function calls are made


#define ll long long
class Solution {
public:
    // evens  = 0, 2, 4, 6, 8  => 5 evens
    // primes = 2, 3, 5, 7     => 4 primes
  
   int p=1e9 + 7; //mod

long long power(long long x,long long y){
    long long res=1; //result

    x=x%p; //if x is greater than or equal to p
    if(x==0) return 0;

    while(y>0){
        //y bitwise to 1 is 1 in case of odd and 0 in case of even
        if(y&1) res=(res*x) % p; //for odd
         //for even index
        y=y>>1; //y>>1 is same as y/2
        x=(x*x) % p;
    }
    return res;
}

    int countGoodNumbers(long long n) {
        long long odd=n/2; //odd no of indexs
        long long even=n-odd; //even no of indexs
        long long ans=((power(4LL,odd) %p * power(5LL,even) %p)%p);
        return (int)ans;
    }
};
