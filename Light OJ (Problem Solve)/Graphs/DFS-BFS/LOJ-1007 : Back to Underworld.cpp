#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std; 

const int N = 2e4+10;
vector<int> gh[N];
vector<int> vis(N, 0);
int aa = 0, bb =0;

void dfs(int node, bool g=0){
   vis[node] = 1;
   aa+=(g==0);
   bb+=(g==1);
   for(auto child:gh[node]){
      if(vis[child])continue;
      dfs(child, !g);
   }
}

int main() {
   FAST_IO;
   // start
   int t;
   cin >> t;
read:
   int tt = 0;
   while (t--) {
      for(int i=0; i<N; i++){
         gh[i].clear();
         vis[i] = 0;
      }
      int n;
      cin>>n;
      set<int> st;
      for(int i=0; i<n; i++){
         int a, b;
         cin>>a>>b;
         st.insert(a);
         st.insert(b);
         gh[a].push_back(b);
         gh[b].push_back(a);
      }
      int res = 0;
      for(auto i:st){
         if(vis[i])continue;
         aa = 0, bb=0;
         dfs(i);
         if(aa && bb)res+=max(aa, bb);
      }
      cout<<"Case "<<++tt<<": "<<res<<"\n";
      


   }
   return 0;
}

