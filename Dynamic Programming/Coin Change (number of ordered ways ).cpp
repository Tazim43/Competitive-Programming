#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 
#define debug(x) cout<<#x<<" = ";_print(x); cout<<endl; /// Debug function
template<class T> void _print(T x) { cout << x; }
template<class T> void _print(vector<T>x) { cout << "[ ";for (T i : x)cout << i << " ";cout << "]"; }
template<class T> void _print(set<T>x) { cout << "[ ";for (T i : x)cout << i << " ";cout << "]"; }
template<class T, class V> void _print(pair<T, V>x) { cout << "{" << x.first << "," << x.second << "} "; }
template<class T, class V> void _print(map<T, V>x) { cout << "[ ";for (auto i : x)_print(i);cout << "]"; }
template<class T> void _print(multiset<T>x) { cout << "[ ";for (T i : x)cout << i << " ";cout << "]"; }
 
const int N = 1e6+5;
int dp[N];
int main() {
   FAST_IO;
   // start
   int n, x;
   cin>>n>>x;
   vector<int> Coins(n);
   for(int i=0; i<n; i++){
      cin>>Coins[i];
   }
   dp[0] = 1;
   int mod = 1e9+7;
   // as we traverse the coins first there no chance to use this coin after another
   for(auto coin:Coins){
      for(int i=1; i<=x; i++){
         if(i-coin>=0)dp[i] = (1LL*dp[i]+dp[i-coin])%mod;
      }
   }
   cout<<dp[x]<<"\n";
 
   return 0;
}
