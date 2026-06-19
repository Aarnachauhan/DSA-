https://www.naukri.com/code360/problems/subset-sum_3843086?utm_source=chatgpt.com&leftPanelTabValue=PROBLEM


void f(int i , int sum , vector<int> & num , vector<int> &ans){
	if(i==num.size()){
		ans.push_back(sum);
		return;
	}
	f(i+1,sum+num[i], num,ans);
	f(i+1,sum,num,ans);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> ans;
	f(0,0,num,ans);
	sort(ans.begin(),ans.end());
     return ans;	
}
