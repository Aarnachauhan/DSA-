leetcode 2107

DID IT ALL BY MYSELFFFFFFFFFFFFFFFFFFFFFFF

class Solution {
public:
long long sumSubarrayMax(vector<int> & arr){
    int n=arr.size();
    int MOD=1e9+7;;
    //previous greater
    stack<int> st;
    vector<int> left(n);
    left[0]=1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
        if(st.empty()){
            left[i]=i+1;
        }
        else{
            left[i]=i-st.top();
        }
        st.push(i);
    }

    while(!st.empty()) st.pop();

    //next greater element
    vector<int> right(n);
    right[n-1]=1;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
        if(st.empty()){
            right[i]=n-i;
        }
        else{
           right[i]= st.top()-i;
        }
        st.push(i);
    }
    long long ans=0;
        for(int i=0;i<n;i++){
            long long prod=1LL*right[i]*left[i];
            prod=prod*arr[i];
            ans=(ans+prod);
            
        }
        return ans;

}
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int MOD=1e9+ 7;
        //left 
        stack<int> st;
        vector<int> left(n);
        left[0]=1;
        st.push(0);
        for(int i=1;i<n;i++){
           while(!st.empty() && arr[st.top()] >arr[i]) st.pop();

           if(st.empty()){
             left[i]=i+1;
           }
           else{
            left[i]=i-st.top();
           }
           st.push(i);
        }
        
        while(!st.empty()) st.pop();

        vector<int> right(n);
        right[n-1]=1;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

            if(st.empty()){
                right[i]=n-i;
            }
            else{
                right[i]=st.top()-i;
            }
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long prod=right[i]*left[i]*1LL;
            prod=(prod*arr[i]);
            ans=(ans+prod);
            
        }
        
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums)- sumSubarrayMins(nums);  
    }
};
