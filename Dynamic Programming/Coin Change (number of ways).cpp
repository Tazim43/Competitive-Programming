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
   dp[0] = 1;
   int mod = 1e9+7;
   for(int i=1; i<=x; i++){
      dp[i] = 0;
      for(auto coin:Coins){
         if(i-coin>=0)dp[i]=(1LL*dp[i]+dp[i-coin])%mod;
      }
   }
 
   cout<<dp[x]<<"\n";
 
   return 0;
}
 
