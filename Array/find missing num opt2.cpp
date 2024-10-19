#include <bits/stdc++.h>
using namespace std;
int findmissing(int a[],int n){
   int xor1=0;
   int xor2=0;
   for(int i=0;i<n-1;i++){ //this will run from 0 to 3 that is 0,1,2,3
       xor2=xor2^a[i]; //1 , 2 ,4, 5
       xor1=xor1^(i+1); //1,2,3,4
       
   }
   xor1=xor1^n;  //5
   return(xor1^xor2);
}

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
