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
