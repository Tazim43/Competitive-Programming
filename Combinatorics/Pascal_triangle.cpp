/* Author: Tazim(The_crawler) */
#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
using namespace std;

// change these two values according to your requirement 
const int N = 10000;  // max limit 10^4
ll MOD = 1e9+7;
vector<vector<ll> > pascal(N+1);

void pcal(){
   pascal[0].push_back(1);
   pascal[1].push_back(1);
   pascal[1].push_back(1);
   for(int i=2; i<=N; i++){
      pascal[i].push_back(1);
      for(int j=1; j<pascal[i-1].size(); j++){
         ll val = (pascal[i-1][j-1]%MOD)+(pascal[i-1][j]%MOD);
         val%=MOD;
         pascal[i].push_back(val);
      }
      pascal[i].push_back(1);
   }
}


int main() {
   FAST_IO;
   // start
   pcal(); // precalculating the pascal triangle
   
   int n,r;
   cin>>n>>r;
   if(r>n)return 0;
   cout<<pascal[n][r]<<endl;


   return 0;
}

