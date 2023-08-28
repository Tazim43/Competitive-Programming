#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 


int main() {
   FAST_IO;
   // start
   int t;
   cin>>t;
   int tt = 0;
   read:
   while (t--) {
      int n, m;
      cin>>n>>m;

      vector<pair<int, int> > gh[n+10];

      for(int i=0; i<m; i++){
         int u, v, w;
         cin>>u>>v>>w;

         gh[u].push_back({v, w});
         gh[v].push_back({u, w});
      }
      int src;
      cin>>src;
      vector<int> dist(n+10, 1e9);
      vector<int> vis(n+10, 0);
      dist[src] = 0;
      priority_queue<pair<int, int> > q; // weight, node
      q.push({0, src});

      while (!q.empty())
      {
         auto node = q.top();
         q.pop();
         node.first *=-1;
         for(auto child:gh[node.second]){
            if(dist[child.first] > max(dist[node.second] , child.second)){
               dist[child.first] = max(dist[node.second] , child.second);
               q.push({-1*dist[child.first], child.first});
            }
         }

      }

      cout<<"Case "<<++tt<<": \n";
      for(int i=0; i<n; i++){
         if(dist[i]==1e9)cout<<"Impossible\n";
         else cout<<dist[i]<<"\n";
      }


   }



   return 0;
}
