#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 
#define int long long

const int N = 2e5+10;

int par[N], sz[N], len[N];

pair<int, int> find(int v){
   if(par[v]==v)return {v, 0}; // parent, parity
   auto val = find(par[v]);
   par[v] = val.first;
   len[v] = (len[v] + val.second) % 2;

   return {par[v], len[v]};
}

void unite(int a, int b){
   auto A = find(a);
   auto B = find(b);

   if(A.first != B.first){
      if(sz[A.first]>sz[B.first])swap(A, B);
      
      par[A.first] = B.first;
      len[A.first] = (1 + A.second + B.second) % 2;
      sz[B.first] += sz[A.first];
   }

}


signed main() {
   FAST_IO;
   // start
   
   for(int i=0; i<N; i++)par[i] = i, sz[i] = 1;

   // Problem Link:
   // https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/I
   

   int n, m;
   cin>>n>>m;

   int s = 0;

   while (m--)
   {
      int t, a, b;
      cin>>t>>a>>b;
      a = (a+s) % n;
      b = (b+s) % n;
      if(a==0)a = n;
      if(b==0)b = n;

      if(t==0){
         unite(a, b);
      }
      else{
         auto aa = find(a);
         auto bb = find(b);
         if(aa.second==bb.second){
            s++;
            cout<<"YES\n";
         }
         else cout<<"NO\n";
      }
   }
   
   return 0;
}
