#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 
#define int long long

const int N = 2e5+10;
vector<int> gh[N], value(N), pos(N);
set<int> st[N];

int cur_pos = 0;
void merge(int a, int b){
   if(st[pos[a]].size() > st[pos[b]].size())swap(a, b);
   for(auto ii:st[pos[a]]){
      st[pos[b]].insert(ii);
   }
   pos[a] = pos[b];
}

vector<int> res(N, 0);
void dfs(int node, int par=-1){
   pos[node] = cur_pos;
   st[cur_pos++].insert(value[node]);

   for(auto v:gh[node]){
      if(v==par)continue;
      dfs(v, node);
      merge(node, v);
   }
   res[node] = st[pos[node]].size();
}


signed main() {
   FAST_IO;
   // start

  // https://cses.fi/problemset/task/1139
  
   int n;
   cin>>n;
   for(int i=1; i<=n; i++){
      cin>>value[i];
   }
   for(int i=0; i<n-1; i++){
      int a, b;
      cin>>a>>b;
      gh[a].push_back(b);
      gh[b].push_back(a);
   }
   dfs(1);

   for(int i=1; i<=n; i++){
      cout<<res[i]<<" ";
   }
   cout<<"\n";

   return 0;
}
