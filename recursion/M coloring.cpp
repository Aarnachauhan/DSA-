// Online C++ compiler to run C++ program online
tc-0(n^m)
sc-o(n)

solved by backtracking. and no platfrom to practice this

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool safe(int node, int color[],bool graph[101][101], int N,int col){
    for(int k=0;k<N;k++){
        if(k!=node && graph[k][node]==1 && color[k]==col){ //k!=node because we want to ensure k!=node and k is adjacent to node.
            return false;
        }
    }
    return true;
}




bool solve(int node, int color[],int N,int m, bool graph[101][101]){
    if(node==N) return true;
    for(int i=1;i<=m;i++){
         if(safe(node,color,graph,N,i)){
           color[node]=i; //add the color i to the node  
         }
       if(solve(node+1,color,N,m,graph)) return true; 
         color[node]=0;//while comingg back remove the color of the node
    }
    return false;
}



bool graphcolor(bool graph [101][101], int m , int N){
    int color[N]={0};
    if(solve(0,color,N,m,graph)) return true;
    return false;
}


int main() {
   int N = 4; //no of nodes
  int m = 2; // no of colours

  bool graph[101][101];
  memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphcolor(graph, m, N);

}
