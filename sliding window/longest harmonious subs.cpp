leetcode 594
tc-o(nlogn) //logn for sorting 
sc-o(1)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      
        int j=0;
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            while(nums[i]-nums[j]>1) j++;
            if(nums[i]-nums[j]==1){
                maxi=max(maxi,i-j+1);
            }
        }
       return maxi;
    }
};

tc-o(N)
sc-o(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
     unordered_map<int,int> freq;

     for(int num:nums){
        freq[num]++;
     }
     int maxi=0;

     for(auto &[num,count]:freq){
        if(freq.count(num+1)){
            int curr=count+ freq[num+1];
            maxi=max(maxi,curr);
        }
     }
     return maxi;
    }

};

note:✅ What does this do?
freq is an unordered_map<int, int> that stores the frequency of each number in the array nums.

freq.count(num + 1) checks if the map contains the key num + 1.

unordered_map.count(key) returns:

1 if the key exists in the map

0 if it doesn’t

So,

cpp
Copy
Edit
if (freq.count(num + 1)) {
    // do something
}
means:
🔍 "If there is a number in the array that is exactly 1 more than num..."
