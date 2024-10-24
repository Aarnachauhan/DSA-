Kadane's Algorithm : Maximum Subarray Sum in an Array
long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxsum=LONG_MIN;
    long long sum=0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
    
    if(sum>maxsum){
        maxsum=sum;
    }
    if (sum < 0) {
        sum = 0;
    }
    }
    if(maxsum<0){
        maxsum=0;
    }
    return maxsum;
}
