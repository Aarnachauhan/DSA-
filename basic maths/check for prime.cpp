gfg
class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n== 3 || n==2 || n==5 || n==7) return true;
        if(n==1) return false;
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
};


very new concept
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
  
    // Check if n is 1 or 0
    if (n <= 1)
        return false;

    // Check if n is 2 or 3
    if (n == 2 || n == 3)
        return true;

    // Check whether n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
int main() {
    int n = 7;  
  	if(isPrime(n)) cout << "true";
  	else cout<<"false";
    return 0;
}
