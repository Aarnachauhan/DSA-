leetcode 29
tc- o(log2N)^2

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        long long dvd=llabs((long long) dividend);
        long long div=llabs((long long) divisor);

        long long quo=0;
        while(dvd>=div){
            long long temp=div;
            long long multi=1;

            while((temp<<1)<dvd){
                temp<<=1;
                multi<<=1;
            }
            dvd-=temp;
            quo+=multi;
        }

         bool negative =
            (dividend < 0) ^ (divisor < 0);
         if (negative)
            quo = -quo;
            return (int)quo;
    }
};
