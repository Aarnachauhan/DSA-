class FindSumPairs {
public:
    vector<int> v1;// O(m)
    vector<int> v2; //O(n)
    unordered_map<int,int> mpp;
    //O(m+n)
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1=nums1;
        v2=nums2;
        for(int &x:v2){ //O(N)
            mpp[x]++;
        }
    }
    //O(1)
    void add(int index, int val) {
        mpp[v2[index]]--;
        v2[index]+=val;
        mpp[v2[index]]++;
    }
    
    int count(int tot) {
        int c=0;
        for(int &x:v1){ //as v1 is max to max 1000 
          c+=mpp[tot-x];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
