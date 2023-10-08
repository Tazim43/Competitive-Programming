#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

const int N = 1e5+10;
vector<int> gh[N], ghr[N];
vector<int> components[N];
vector<int> ar(N);
vector<pair<int, int> > res;
int TM = 0;
vector<int> vis(N, 0);
void trav(int node){
     TM++;
     vis[node] = 1;
     for(auto child:gh[node]){
          if(vis[child])continue;
          trav(child);
     }
     TM++;
     res.push_back({node, TM});
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
     return a.second>b.second;
}

vector<int> seen(N, 0);
void dfs(int node, int cur){
     components[cur].push_back(node);
     seen[node] = 1;
     for(auto child:ghr[node]){
          if(seen[child])continue;
          dfs(child, cur);
     }
}

int main() {
   FAST_IO;
   // start
   int n, m;
   cin>>n>>m;
   for(int i=0; i<m; i++){
     int a,b;
     cin>>a>>b;
     gh[a].push_back(b);
     ghr[b].push_back(a);
   }
   for(int i=1; i<=n; i++){
     if(vis[i])continue;
     trav(i);
   }
   sort(all(res), cmp);
   int comp = 0;
   for(int i=0; i<res.size(); i++){
      if(seen[res[i].first])continue;
      dfs(res[i].first, comp);
      comp++;
   }
   // all strongly connected components
   for(int i=0; i<n; i++){
      if(components[i].size()>0){
          cout<<i<<" - ";
          for(auto ii:components[i])cout<<ii<<" ";
          cout<<"\n";
      }
      else break;
   }


   return 0;
}
