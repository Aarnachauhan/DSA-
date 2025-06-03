naukri.com
tc- O(log2m)*log2n
sc-O(1)

int func(int n,int m , int mid){
 long long ans=1;
 for(int i=1;i<=n;i++){
   ans=ans*mid;
   if(ans>m) return 2;
 }
 if(ans==m) return 1;
 else return 0;
}

//1 ->same
//0 -> small
//2 ->big


int NthRoot(int n, int m) {
  // Write your code here.
  int s=1;
  int h=m;
  while(s<=h){
    int mid=(s+h)/2;
    int midN=func(n,m,mid);
    if(midN==1) return mid;
    else if(midN==2) h=mid-1;
    else s=mid+1;
  }
  return -1;
}
