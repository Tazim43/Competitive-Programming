#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

const int N = 3e5+10;
vector<int> ar(N);
int sparseMin[26][N];
int sparseGcd[26][N];

void build(int n){
   for(int i=0; i<n; i++){
      sparseMin[0][i] = ar[i];
      sparseGcd[0][i] = ar[i];
   }
   for(int i=1; i<25; i++){
      for(int j=0; j + (1<<i)<=n; j++){
         int x = sparseMin[i-1][j];
         int y = sparseMin[i-1][j+(1<<(i-1))];
         sparseMin[i][j] = min(x, y);
         x = sparseGcd[i-1][j];
         y = sparseGcd[i-1][j+(1<<(i-1))];
         sparseGcd[i][j] = __gcd(x,y);
      }
   }
}

int qryMin(int n, int L, int R){
   int rg = log2(R-L+1);
   int x = sparseMin[rg][L];
   int y = sparseMin[rg][R-(1<<rg)+1];
   return min(x,y);
}
int qryGcd(int n, int L, int R){
   int rg = log2(R-L+1);
   int x = sparseGcd[rg][L];
   int y = sparseGcd[rg][R-(1<<rg)+1];
   return __gcd(x,y);
}

bool solve(vector<int> &ar, int mid, int n){
   for(int i=0; i<n-mid; i++){
      int l = i, r = i+mid;
      int cur = qryGcd(n, l, r);
      int mn = qryMin(n, l, r);
      if(mn==cur)return 1;
   }
   return 0;
}  


int main() {
   FAST_IO;
   // start
   int n;
   cin>>n;
   for(int i=0; i<n; i++){
      cin>>ar[i];
   }
   build(n);
   int lo = 0, hi = n;
   while (hi-lo>1)
   {
      int mid = (hi+lo)/2;
      if(solve(ar, mid, n)){
         lo = mid;
      }
      else hi = mid-1;
   }
   int res = 0;
   if(solve(ar, hi, n))res = hi;
   else res = lo;

   if(res==0){
      cout<<n<<" "<<res<<"\n";
      for(int i=0; i<n; i++){
         cout<<i+1<<" ";
      }
      cout<<"\n";
      return 0;
   }
   vector<int> ans;
   for(int i=0; i<n-res; i++){
      int l = i, r = i+res;
      int cur = qryGcd(n, l, r);
      int mn = qryMin(n, l, r);
      if(mn==cur){
         ans.push_back(i+1);
      }
   }
   cout<<ans.size()<<" "<<res<<"\n";
   if(ans.size()>0){
      for(auto i:ans)cout<<i<<" ";
      cout<<"\n";
   }
   



   return 0;
}
