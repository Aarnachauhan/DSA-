#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    unordered_map<long long, int> prefixSumMap; // Maps prefix sum to its earliest index
    long long prefixSum = 0;
    int maxlen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Check if the subarray from the start to current index sums to k
        if (prefixSum == k) {
            maxlen = max(maxlen, i + 1);
        }

        // Check if there exists a prefixSum - k in the map
        if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
            maxlen = max(maxlen, i - prefixSumMap[prefixSum - k]);
        }

        // Store the prefix sum in the map if it's not already present
        if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
            prefixSumMap[prefixSum] = i;
        }
    }

    return maxlen;
}
