codechef compiler

#include <bits/stdc++.h>
using namespace std;
//n to 1
void recur(int i,int n){
    if(i>n) return;
    recur(i+1,n);
    cout<<i<<endl;
}



int main() {
	// your code goes here
	int n;
	cin>>n;
	recur(1,n);

}
