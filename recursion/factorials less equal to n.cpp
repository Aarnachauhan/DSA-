gfg


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
      
        vector<long long> ans;
        long long fact=1;
        for(int i=2;fact<=n;i++){
            ans.push_back(fact);
            fact=fact*i;
        }
        return ans;
