gfg

vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        int i=0;
        int n=a.size();
        int j=0;
        int m=b.size();
        vector<int> res;
        while(i<n && j<m){
            if(a[i]<=b[j]){
                if(res.size()==0 || res.back()!=a[i]){
                    res.push_back(a[i]);
                }
                i++;
            }else{
                if(res.size()==0 || res.back()!=b[j]){
                    res.push_back(b[j]);
                }
                j++;
            }
        }
        while(j<m){
            if(res.back()!=b[j]){
                res.push_back(b[j]);
            }
            j++;
        }
        while(i<n){
            if(res.back()!=a[i]){
                res.push_back(a[i]);
            }
            i++;
        }
        return res;
    }
