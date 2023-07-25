#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

const int N = 2e5+10;
long long ar[N], divs[500];
int len;
// O(n) 
void build(int n){
   for(int i=0; i<n; i++){
      divs[i/len] += ar[i];
   }
}
// O(sqrt(n)) 
long long qry(int l, int r){
   long long sum = 0;
   for(int i=l; i<=r; ){
      if(i+len-1<=r && i%len==0){
         sum+=divs[i/len];
         i+=len;
      }
      else{
         sum+=ar[i];
         i++;
      }
   }
   return sum;
}
// O(1) 
void upd(int i, int x){
   divs[i/len]-=ar[i];
   divs[i/len]+=x;
   ar[i] = x;
}



int main() {
   FAST_IO;
   // start
   int n, q;
   cin>>n>>q;
   len = sqrtl(n)+1;
   for(int i=0; i<n; i++){
      cin>>ar[i];
   }
   build(n);
   for(int i=0; i<q; i++){
      int t, l, r;
      cin>>t>>l>>r;
      if(t==1){
         upd(l-1, r);
      }
      else{
         long long res = qry(l-1, r-1);
         cout<<res<<"\n";
      }
   }


   return 0;
}

