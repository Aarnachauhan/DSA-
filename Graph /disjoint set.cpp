c++ compiler

  #include <bits/stdc++.h>
using namespace std;

class Disjointset{
    
    vector<int> rank , parent;
    
public:
  Disjointset(int n){
      rank.resize(n+1,0); //what if the rank is 1 based indexing ,so n+1 
      parent.resize(n+1);
      
      for(int i=0;i<=n;i++){
          parent[i]=i;
      }
      
  }
  
  //path compression
  int findpart(int node){
      if( node == parent[node]) return node;
      else {
          return parent[node]= findparent[parent[node]];
      }
  }
  
  void unionbyran(int u , int v){
      int ulp_u=findpart(u);
      int ulp_v=findpart(v);
      
      if(ulp_u==ulp_v) return ; //both belong to the same parent 
      
      if(rank[ulp_u]<rank[ulp_v]){
          parent[ulp_u]= ulp_v;
      }
      else if(rank[ulp_v]<rank[ulp_u]){ // u is bigger than attaching with it will cause nothing in rank size
          parentp[ulp_v]=ulp_u;
      }
      else{
          parent[ulp_v]=ulp_u; //same so one will get bigger .
          rank[ulp_u]++;
      }
  }
}

int main() {
	// your code goes here

}
