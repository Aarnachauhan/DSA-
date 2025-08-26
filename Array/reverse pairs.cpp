leetcode 493
tc-o(n2)
sc-o(1)
brute code done by me!
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              if(nums[i] > (long long)2*nums[j]) cnt++;
            }
        }
        return cnt;
    }
};

optimal approach
tc-o(2nlogn)
sc-o(n) 
see striver video and notes for differnet code 
class Solution {
public:
int cnt=0;
void merge(int low , int mid , int high, vector<int> & nums){
    int n1=mid-low+1;
    int n2=high-mid;

    vector<int> l(n1) , r(n2);
    for(int i=0;i<n1;i++){
        l[i]=nums[low+i];
    }
    for(int i=0;i<n2;i++){
        r[i]=nums[mid+1+i];
    }
    //count reverse pairs
    int j=mid+1;
    for(int i=low ; i<=mid; i++){
        while(j<=high && (long long )nums[i]>2LL* nums[j]){
            j++;
        }
        cnt+=(j-(mid+1));
    }
    // Merge two sorted halves
        int i = 0;
        j = 0;
        int k = low;
        while (i < n1 && j < n2) {
            if (l[i] <= r[j]) {
                nums[k++] = l[i++];
            } else {
                nums[k++] = r[j++];
            }
        }
        while (i < n1) nums[k++] = l[i++];
        while (j < n2) nums[k++] = r[j++];
}
void mergesort(int low , int high, vector<int> &nums){
    if(low>=high) return;
    int mid=(low+high)/2;
    mergesort(low,mid,nums);
    mergesort(mid+1,high,nums);
    merge(low,mid,high,nums);
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergesort(0,n-1,nums);
        return cnt;
    }
};
