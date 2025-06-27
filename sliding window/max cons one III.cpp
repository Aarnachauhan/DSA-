leetcode 

brute : time limit exceeded 52/59
tc-o(n^2)
sc-o(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int maxlen=0;
       int len=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        int zero=0;
        for(int j=i;j<n;j++){
            if(nums[j]==0) zero++;
            if(zero<=k){
             len=j-i+1;
             maxlen=max(maxlen,len);
            } 
            else{
                break;
            }

        }

       }
       return maxlen;
    }
};


better 
tc-o(2n)
sc-o(1)


