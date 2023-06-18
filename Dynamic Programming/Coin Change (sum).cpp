#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 
 
 
 
int main() {
   FAST_IO;
   // start
   int n, x;
   cin>>n>>x;
   vector<int> Coins(n);
   for(int i=0; i<n; i++){
      cin>>Coins[i];
   }
   int dp[x+1];
   dp[0] = 0;
 
   for(int i=1; i<=x; i++){
      dp[i] = 1e9;
      for(auto coin:Coins){
         if(i-coin>=0)dp[i] = min(dp[i-coin]+1, dp[i]);
      }
   }
 
   if(dp[x]==1e9)cout<<-1<<"\n";
   else cout<<dp[x]<<"\n";
   
 
   return 0;
}
 
