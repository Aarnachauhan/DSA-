sort colors leetcode 75 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
   int low=0; //0->low-1 all zeroes
   int mid=0;  //low to mid-1 all 1s
   int high=n-1; //mid to high all unsorted
   while(mid<=high){ //high+1 to n-1 all 2
    if(nums[mid]==0){
        swap(nums[mid],nums[low]); //1 le ayenge
        low++;
        mid++;
    }else if(nums[mid]==1) mid++; 
    else{ // nums[mid]==2
       swap(nums[mid],nums[high]);
       high--;
    }
   }
    }
};
