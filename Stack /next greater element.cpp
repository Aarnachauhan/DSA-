
leetcode 496
tc-o(n+m)
sc-o(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp; //this will store the ans like 2:-1
        stack<int> st; //this will store the elements which can be someone's greater element
        

        //if the top is smaller than the current element than pop it.
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            //if the stack is empty or last element in the stack is also empty then add it in the map
            //with -1
            if(st.empty() || st.top()< nums2[i]) mp[nums2[i]]=-1;
            //else : add it in map with its greater
            else mp[nums2[i]]=st.top();
            //and push it in stack
            st.push(nums2[i]);
        }
       //add the answer in a vector.
        vector<int> solution;
        for(int i=0;i<nums1.size();i++){
            solution.push_back(mp[nums1[i]]);
        }
        return solution;
    }
};
