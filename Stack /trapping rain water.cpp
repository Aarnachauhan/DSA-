leectcode 42
brute 
tc-o(N)
sc-o(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0 ) return 0;
        vector<int> leftmax(n) ,  rightmax(n);
        //we are building left max array
        leftmax[0]=height[0];

        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        //we are building right max array

        rightmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightmax[i]= max(height[i],rightmax[i+1]);
        }

        int water=0;
        for(int i=0;i<n;i++){
            water+=min(leftmax[i],rightmax[i])-height[i];
        }
        return water;
    }
};

optimal :
tc-o(n)
sc-o(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int leftmax=0 , rightmax=0;
        int water=0;

        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=leftmax){
                    leftmax=height[left];
                }
                else{
                    water+=leftmax-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=rightmax){
                    rightmax=height[right];
                }
                else{
                    water+=rightmax-height[right];
                }
                right--;
            }
            
        }
        return water;
    }
};
