leetcode 29
tc- o(log2N)^2
class Solution {
public:
    int divide(int dividend, int divisor) {
      if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        long long dvd = labs(dividend), dvs = labs(divisor), result = 0;
        int sign = (dividend > 0) ^ (divisor > 0) == 0 ? 1 : -1;
        while(dvd >= dvs){ //log 2 N 
            long long temp = dvs, mul = 1;
            while(temp << 1 <= dvd){ //log 2 N
                temp <<= 1;
                mul <<= 1;
            }
            dvd -= temp;
            result += mul;
        } 
        return sign*result;
    }
};
