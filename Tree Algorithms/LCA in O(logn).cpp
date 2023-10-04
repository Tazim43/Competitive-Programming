#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 
 
const int N = 2e5+10;
 
vector<int> gh[N];
int parent[N][21];
vector<int> dep(N, 1);
void dfs(int node, int par = -1){
   for(auto child:gh[node]){
      if(child==par)continue;
      parent[child][0] = node;
      dep[child] = dep[node] + 1;
      dfs(child, node);
   }
}
 
int lca(int a, int b){
   if(dep[a]<dep[b])swap(a,b);
   for(int i=20; i>=0; i--){
      if(dep[parent[a][i]]>=dep[b]) a = parent[a][i];
   }
   if(a==b)return a;
   for(int i = 20; i>=0; i--){
      if(parent[a][i]!=parent[b][i]){
         a = parent[a][i];
         b = parent[b][i];
      }
   }
   return parent[a][0];
}
 
int main() {
   FAST_IO;
   // start
   dep[1] = 1;
   int n, q;
   cin>>n>>q;
   for(int i=2; i<=n; i++){
      int a;
      cin>>a;
      gh[a].push_back(i);
      gh[i].push_back(a);
   }
 
   dfs(1);
   dep[0] = 0;
   for(int i=1; i<21; i++){
      for(int j=1; j<=n; j++){
         parent[j][i] = parent[parent[j][i-1]][i-1];
      }
   }
 
   for(int i=0; i<q; i++){
      int a,b ;
      cin>>a>>b;
      cout<<lca(a,b)<<"\n";
   }
 
 
   return 0;
}
