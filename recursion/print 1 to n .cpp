gfg
public:
    // Complete this function
    int c=1;
    void printNos(int n) {
        // Your code here
       if(c>n) return;
       cout<<c<<" ";
       c++;
       printNos(n);
        
    }
