no platform
tc-o(log2n) as the n is getting divided by 2 again and again
sc-o(log2n) as it will only store the no of digits =no of steps/division we did



// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string convert(int n){
    string res="";
    while(n>0){
        if(n%2==1) res+='1';
        else res+='0';
        n=n/2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() {
    int n;
    cout<<"enter the no u want to change";
    cin>>n;
    string ans;
    
    ans=convert(n);
    cout<<ans;

    return 0;
}
