//tc-very mindblowing. see notes
//tc- O(3n)
//sc-o(1)

// if the set takes o(n) as sc then solve it through brute force
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=1;
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){ //o(n)
            st.insert(nums[i]);
        }
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
            
            while(st.find(x+1)!=st.end()){ //O(2n)
                x+=1;
                cnt+=1;
            }
             longest=max(longest,cnt);
            }            
        }
        return longest;
    }
};
