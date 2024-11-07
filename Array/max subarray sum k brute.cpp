
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            int s = 0;
            for (int K = i; K <= j; K++) {
                s += nums[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
     }
    return len;
    }
};
