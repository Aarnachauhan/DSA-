no platform 

recursion 
tc-o(n*k)
sc-o(n) + o(n)

#include <iostream>
using namespace std;
int f(int ind){
    if(ind==0) return 0;
    minsteps=INT_MAX;
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
            jumps=f(ind-j) + abs(a[ind]- a[ind-j]);
        }
        minsteps=min(minsteps,jumps);
    }
    return minsteps;
}
int main()
{
    cout<<f(ind)<<endl;

    return 0;
}

memorization
