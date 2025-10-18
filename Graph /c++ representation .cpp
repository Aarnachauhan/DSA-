method 1
sc-o(n*m)
tc-o(n)
  #include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	
	int adj[n+1][m+1];
   for(int i=0;i<m;i++){
	int u,v;
	cin>>u>>v;
	
	adj[u][v]=1;
	adj[v][u]=1; //this will be removed in case of directed graph
   }
	
	return 0;

}


method 2
sc-(2*e)
tc-o(n)
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); //on the u'th index store v
        adj[v].push_back(u); //vice versa
    }
	
	return 0;

}
