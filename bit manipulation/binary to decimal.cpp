no platform
tc-o(len)
sc-o(1)

// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int convert(string res){
    int len=res.size();
    int p2=1;
    int num=0;
    for(int i=len-1;i>=0;i--){
        if(res[i]=='1'){
         num=num+p2;   
        } 
        p2=p2*2;
    }
    return num;
}

int main() {
    string res;
    cout<<"enter the no u want to change";
    cin>>res;
    int n;
    
    n=convert(res);
    cout<<"the number is :";
    cout<<n;

    return 0;
}
