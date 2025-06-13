codechef
tc-O(n)
sc-o(n)
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int A[n];
	    for(int i=0;i<n;i++){
	        cin>>A[i];
	    }
	    stack<int> st;
	    for(int a:A){
	        while(!st.empty() && st.top()>=a){
	            st.pop();
	        }
	        cout<<(st.empty()?-1:st.top())<<" ";
	        st.push(a);
	    }
	    cout<<endl;
	}

}
