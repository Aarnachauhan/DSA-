#include <iostream>
using namespace std;
int maxSumSubarrayOfSizeK(int arr[], int n,int K) {
    
    int maxSum = 0;

    for (int i = 0; i <= n - K; i++) {
        int currentSum = 0;
        for (int j = i; j < i + K; j++) {
            currentSum += arr[j];
        }
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    int arr[] = {100,200,300,400}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    int K = 2;  

    int result = maxSumSubarrayOfSizeK(arr, n,K);
    cout << "Maximum sum of subarrays " << result << endl;

    return 0;
}
