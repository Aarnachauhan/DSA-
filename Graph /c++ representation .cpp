method 1
tc-o(n*m)

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
