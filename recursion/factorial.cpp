gfg - cant submit 

class Solution {
public:
    int rec(int n) {
        if (n == 0 || n == 1) return 1;   // base case
        return n * rec(n - 1);            // recursive case
    }

    void factorial(int n) {
        cout << rec(n);
    }
};
