//tc- O(nlogn)
//sc- o(n)

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> ans;
    int maxi=INT_MIN;
    int n=a.size();
    for(int i=n-1;i>=0;i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
        }
        maxi=max(maxi,a[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;

}
