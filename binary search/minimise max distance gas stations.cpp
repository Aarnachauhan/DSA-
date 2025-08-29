naukri.com 

brute
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
      vector<int> howmany(arr.size()-1,0);
        for(int i=0;i<k;i++){
            long double currmax=-1;
            int maxiind=-1;
            for(int j=1;j<arr.size();j++){
                long double dist=arr[j]- arr[j-1];
                long double distaftersplit=dist/(howmany[j-1]+1);
                
                if(distaftersplit > currmax){
                    currmax=distaftersplit;
                    maxiind=j;
                }
            }
            howmany[maxiind-1]= howmany[maxiind-1]+1;
        }
        long double maxDist = -1;
        for (int i = 1; i < arr.size(); i++) {
            long double dist = arr[i] - arr[i-1];
            long double splitDist = dist/(howmany[i-1] + 1);
            if(splitDist > maxDist){
                maxDist = splitDist;
            }
        }
        return maxDist;
}

better- priority queue
sc-o(n-1)
tc- o(nlogn + klogn)
#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
    int n=arr.size();
    vector <int> howmany(n-1,0);
    priority_queue<pair<long double,int>> pq;
    for(int i=0;i<n-1;i++){ //nlogn 
        pq.push({arr[i+1]-arr[i], i});
    }
    for(int g=1;g<=k;g++){ //klogn 
        auto tp=pq.top();
        pq.pop();
        int secindex=tp.second;
        howmany[secindex]++;
        long double inidiff=arr[secindex+1]-arr[secindex];
        long double newscreen=inidiff/(long double)(howmany[secindex]+1);
        pq.push({newscreen , secindex});
    }
    return pq.top().first;
}

optimial - 
tc-o(nlogn + n)
sc-o()

int noofgasstation(long double dist , vector<int> &arr){
    int cnt=0;
    for(int i=1;i<arr.size();i++){
        int noinbetween=((arr[i]-arr[i-1])/dist);
        if((arr[i]-arr[i-1])/dist==noinbetween*dist){
            noinbetween--;
        }
        cnt+=noinbetween;
    }
    return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
    int n=arr.size();
    long double low=0 , high=0;
    for(int i=0;i<n-1;i++){ //o(n)
      high=max(high ,(long double) arr[i+1]-arr[i]);
    }	
    long double diff=1e-6;
    while(high-low>diff){ //o(nlogn)
        long double mid=(low+high)/(2.0);
        int cnt=noofgasstation(mid,arr);
        if(cnt>k){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return high;
}

