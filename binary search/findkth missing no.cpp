
expected = i + 1
missing numbers before arr[i] =arr[i] - expected = arr[i] - (i+1) = arr[i] - i - 1

return:
    answer = e + k + 1

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            int missing=arr[mid]-mid-1;
            if(missing<k){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return e+k+1;
    }
};
