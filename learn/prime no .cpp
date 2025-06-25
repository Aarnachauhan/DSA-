leetcode 3591
class Solution {
public:
bool isprime(int n){
    if(n<=1) return false;

    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> counts;
        for(int a:nums){
            counts[a]++;
        }
       for(auto &[key,value]:counts){
        if(isprime(value)) return true;
      
       }
      return false;
    }
};
