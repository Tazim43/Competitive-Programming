// This is the easiest way to find bridges in a graph
// source: https://codeforces.com/blog/entry/68138 

#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 


const int N = 1e5+10;
vector<int> gh[N];
vector<int> dp(N, 0), vis(N, 0), Time(N, 0);
vector<pair<int, int> > bridges;

void dfs(int node, int par = -1){
   vis[node] = 1;
  
   for(auto child:gh[node]){
      if(child==par)continue;
     
      if(vis[child]){
         if(Time[child]<Time[node]){
            dp[node]--; // If the back edges going down
         }
         else dp[node]++; // If the back edges going up
         continue;
      }
     
      Time[child] = Time[node]+1;
      dfs(child, node);
      dp[node]+=dp[child]; 
     
     // adding back edges of child. this will be cleared by dp[node]-- when counting down back edges for a node
   }
  
   if(dp[node]==0 && par!=-1){ // dp[node] = 0 : there is a bridge between parent and node
      bridges.push_back({par, node});
   }
}

int main() {
   FAST_IO;
   // start

   int n;
   cin>>n;
   for(int i=0; i<n; i++){
      int a,b;
      cin>>a>>b;
      gh[a].push_back(b);
      gh[b].push_back(a);
   }

   dfs(1);

   cout<<bridges.size()<<"\n";
   for(auto i:bridges){
      cout<<i.first<<" "<<i.second<<"\n";
   }
   



   return 0;
}
