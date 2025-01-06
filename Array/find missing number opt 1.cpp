//tc- o(n);
//sc-O(1);
//but it cant find answer when number will be 10^5;

//go to opt 2 solution


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1=0;
        int sum2=0;

        for(int i=0; i<=nums.size(); i++){
            sum1=sum1+i;
        }

        for(int i=0; i<nums.size(); i++){
            sum2=sum2+nums[i];
        }

        return sum1-sum2;
    }
};
int main(){
    int a[]={1,2,4,5};
    int n;
    cout<<"print n"<<" ";
    cin>>n;
    cout<<" range is from 1 to " <<n <<endl;
    int miss=findmissing(a,n);
    cout<<"missing number is "<<miss;
    return 0;
}
