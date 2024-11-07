//positive elements only
//tc=o(n^2)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
     int s = 0;
        for (int j = i; j < n; j++) { // ending index
           s+=nums[j];
            if (s == k)
                len = max(len, j - i + 1);
        }
     }
    return len;
    }
};
