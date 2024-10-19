#include <bits/stdc++.h>
using namespace std;
int findmissing(int a[],int n){
    for (int i = 1; i <= n; i++) {

        // flag variable to check
        //if an element exists
        int flag = 0;

        //Search the element using linear search:
        for (int j = 0; j < n - 1; j++) {
            if (a[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}

int main(){
    int a[]={1,2,4,5};
    int n;
    cout<<"print n"<<" ";
    cin>>n;
    cout<<" range is from 1 to " <<n;
    int miss=findmissing(a,n);
    cout<<miss;
    return 0;
}
