leetcode 1423

Intuition
we will take first k elements and then we will start decrementing it.

Approach
left=0
right=n-1

first we will add all the first k elements
our left will be at k-1

then we will delete k-1 element and add the last element (where right is standing)

do this till we add the last k elements and no first k elements.

return max(las k element , first k element )

Complexity
Time complexity:
O(2k)

Space complexity:
O(1)

Code
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum=0;
        int maxi=INT_MIN;
        for(int i=0;i<k;i++) leftsum+=cardPoints[i];
        maxi=leftsum;
        

        int rightsum=0;
        int curr=leftsum;
        int right=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            leftsum-=cardPoints[i];
            rightsum+=cardPoints[right];
            right--;

            maxi=max(maxi,rightsum+leftsum);
            
        }
        return maxi;
    }
};
