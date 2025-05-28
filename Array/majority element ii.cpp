tc-O(2n)
sc-O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){ //O(n)
            if(cnt1==0 && nums[i]!=ele2){
                cnt1+=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1){
                cnt2+=1;
                ele2=nums[i];
            }
            else if(ele1==nums[i]) cnt1++;
            else if(ele2==nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;

            }
        }

        //manually 
        vector<int> ls;
        cnt1=0; cnt2=0;
        for(int i=0;i<n;i++){ //O(n)
            if(ele1==nums[i]) cnt1++;
            if(ele2==nums[i])cnt2++;
        }
        int mini=(int)(n/3) +1;
        if(cnt1>=mini) ls.push_back(ele1);
        if(cnt2>=mini) ls.push_back(ele2);
        //O(1)
        sort(ls.begin(),ls.end());
        return ls;
    }
};
