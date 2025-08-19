Time complexity: O(log b)
Memory complexity: O(log b) because a function call consumes memory and log b recursive function calls are made

class Solution {
public:
   const int M=1e9+7;
   int findpower(long long a, long long b){
    if(b==0) return 1; //base case
    long long half=findpower(a,b/2);
    long long result=(half*half)%M;

    if(b%2==1) result= (result*a) %M;

    return result;

   }
    int countGoodNumbers(long long n) {
        return (long long)findpower(5,(n+1)/2) * findpower(4,n/2) % M;
    }
};
