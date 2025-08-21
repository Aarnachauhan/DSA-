codechef compiler
#include <bits/stdc++.h>
using namespace std;
void recur(int n){
    if(n==0) return ;
    recur(n-1);
    cout<<n<<endl;
}



int main() {
	// your code goes here
	int n;
	cin>>n;
	recur(n);

}

