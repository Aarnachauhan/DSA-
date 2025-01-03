class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
          if(i>0 && nums[i]==nums[i-1]) continue;
          int j=i+1;
          int k=n-1;
          while(j<k){ //k jaise hi corss karega j ko i++ ho jayega
          int sum=nums[i]+nums[j]+nums[k];
          if(sum<0){ //j ko increase krna padega as sorted array hai
           j++;
          }
          else if(sum>0){
            k--;
          }else{
            vector<int> temp={nums[i],nums[j],nums[k]};
            ans.push_back(temp);
            j++;
   
            while(j<k && nums[j]==nums[j-1]) j++;
            while(j<k && nums[k]== nums[k-1]) k--;

          }
          }
        }
        return ans;
    }
};
