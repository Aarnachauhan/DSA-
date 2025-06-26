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
        int res=0;
        for(int i=0;i<k;i++) res+=cardPoints[i];

        int curr=res;
        for(int i=k-1;i>=0;i--){
            curr-=cardPoints[i];
            curr+=cardPoints[cardPoints.size()-k+i];

            res=max(res,curr);
        }
        return res;
    }
};
