naukri . com
https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM
onlu 25 cases passed

  
int subsets(vector<int>&arr , int k ,int cnt, int sum, int ind ){
	
	if(sum==k){
		cnt++;
		return cnt;
	}
	if(ind==arr.size()){
		return(sum==k);
			
	}

	int l =subsets(arr,k , cnt, sum+arr[ind],ind+1);
	int r= subsets(arr,k , cnt, sum,ind+1);

	return l+r;
}


int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	return subsets(arr,k,0,0,0);
}
