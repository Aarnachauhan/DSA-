gfg
int setBits(int N){
    // Write your code here.
    int n=N;
    if((n&(n+1))==0) return n;
    else{
        return (n| (n+1));
    }
}
