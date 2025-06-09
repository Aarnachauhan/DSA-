tc-2(nlogn+ n)
sc-O(1)


gfg

int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end()); 
        sort(dep.begin(),dep.end());
        //dono sorting= 2nlogn
        int a=0,d=0,out=0,accum=0;
        while(a<arr.size()){ //2n - we can traverse both the arrays.
            if(arr[a]<=dep[d]){
                accum++;
                a++;
            }
            else{
                accum--;
                d++;
            }
            out=max(out,accum);
        }
        return out;
    }
