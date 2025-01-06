class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        
        int largest=-1;
        int secondlargest=-1;
        int n=arr.size();
        if(n<2){
            return -1;
        }
        for(int i=0;i<n;i++){
            if(arr[i]>largest){
                secondlargest=largest;
                largest=arr[i];
            }
            else if(arr[i]>secondlargest && arr[i]<largest){
                secondlargest=arr[i];
            }
        }
        return secondlargest;
    }
