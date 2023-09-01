#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

const int N = 2e5+10;

long long segTree[4*N], ar[N], lazy[4*N], notPos = 0;

void propagate(int node, int b, int e){
   if(lazy[node] != 0){
      segTree[node] += lazy[node]; // op
      if(b!=e){
         lazy[2*node] += lazy[node]; //op
         lazy[2*node + 1] += lazy[node]; //op
      }
      lazy[node] = 0;
   }
}

void build(int node, int b, int e){
   if(b==e){
      segTree[node] = ar[b];
      return;
   }
   int mid = (b+e)/2;
   build(2*node, b, mid);
   build(2*node + 1, mid+1, e);
   segTree[node] = segTree[2*node] + segTree[2*node + 1]; // op
}


void upd(int node, int b, int e, int l, int r, long long x){
   if(l>r)return;
   propagate(node, b, e);
   if(e<l || b>r)return; 

   if(b>=l && e<=r){
      segTree[node] += x; // op
      if(l!=r){
         lazy[2*node] += x; // op
         lazy[2*node + 1] +=x; // op
      }
      return;
   }
   int mid = (b+e)/2;
   upd(2*node, b, mid, l, r, x);
   upd(2*node+1, mid+1, e, l, r, x);
   segTree[node] = segTree[2*node] + segTree[2*node + 1]; // op
}

long long qry(int node, int b, int e, int l, int r){
   if(l>r)return notPos;
   propagate(node, b, e);

   if(e<l || b>r)return notPos;
   if(b>=l && e<=r){
      return segTree[node];
   }

   int mid = (b+e)/2;
   return qry(2*node, b, mid, l, r) + qry(2*node+1, mid+1, e, l, r); // op

}


int main() {
   FAST_IO;
   // start

   int n, q;
   cin>>n>>q;
   for(int i=1; i<=n; i++){
      cin>>ar[i];
   }

   build(1, 1, n);

   for(int i=0; i<q; i++){
      int t;
      cin>>t;
      if(t==1){
         long long l, r,x ;
         cin>>l>>r>>x;
         upd(1,1,n, l, r, x);
      }
      else{
         int pos;
         cin>>pos;
         long long res = qry(1, 1, n, pos, pos);
         cout<<res<<"\n";
      }
   }
   



   return 0;
}
