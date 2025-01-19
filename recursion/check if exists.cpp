
subset sum naukri.com
check if subsq exits with sum k

bool prints(int ind,int s,int k,vector<int> &a){
    if(s==k){
        return true;
    }
    if(s>k || ind==a.size()){
        return false;
    }
    s+=a[ind];
    if(prints(ind+1,s,k,a)) return true;
    s-=a[ind];
    if(prints(ind+1,s,k,a)) return true;
    return false;
}



bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    
    return prints(0,0,k,a);
}
