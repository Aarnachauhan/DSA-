 // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int cnt=0;
        int n2=n;
        int rem;
        while(n2){
           rem=n2%10;
           
           n2=n2/10;
           if(rem==0)continue;
           if(n%rem==0) cnt++;
        }
        return cnt;
    }
