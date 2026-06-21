lc 215

tc:(nlogk)
sc: o(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int> >pq; //min heap
       for(int num:nums){
        pq.push(num);
        if(pq.size()>k) pq.pop(); //pop removes the smallest element
       }
       return pq.top();
    }
};
