lc 11
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxi=INT_MIN;
    
        while(l<r){
            int wid=r-l;
            int h=min(height[l],height[r]);
            int area=wid*h;
            maxi=max(area,maxi);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return maxi;
    }
};
