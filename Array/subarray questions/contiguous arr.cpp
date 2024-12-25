class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int n=nums.size();
      unordered_map<int,int> mp;
      int sum=0;
      int subarrlen=0;
      for(int i=0;i<n;i++){
        sum+=nums[i]==0?-1:1;
        if(sum==0){
            subarrlen=i+1;//0 based indexing
        }
        else if(mp.find(sum)!=mp.end()){ //same sum aa chuka hai phele
           subarrlen=max(subarrlen,i-mp[sum]); //i- aa chuke huye sum ki index
        }else{
            mp[sum]=i; //map mai daldo agar sum nhi aya toh..uski index k saath
        }
      }
      return subarrlen;
    }
};
