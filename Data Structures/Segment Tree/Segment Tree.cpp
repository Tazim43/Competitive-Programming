#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

const int N = 2e5+10; // change this
int ar[N];
long long segTree[4*N];

void build(int node, int b, int e){
   if(b==e){
      segTree[node] = ar[b];
      return;
   }
   int mid = (b+e)/2;
   int left = 2*node, right = 2*node+1;
   build(left, b, mid);
   build(right, mid+1, e);
   segTree[node] = segTree[left]+segTree[right]; // change this
}

long long qry(int node, int b, int e, int l, int r){
   if(b>r || e<l)return 0; // change this
   if(b>=l && e<=r)return segTree[node];
   
   int mid = (b+e)/2;
   int left = 2*node, right = 2*node + 1;
   long long q_left = qry(left, b, mid, l, r);
   long long q_right = qry(right, mid+1, e, l, r);
   
   return q_left+q_right; // change this
}

void upd(int node, int b, int e, int i, int x){
   if(b>i || e<i)return;
   if(b==i && e==i){
      segTree[node] = x;
      return;
   }
   int mid =  (b+e)/2;
   int left = 2*node, right = 2*node + 1;
   upd(left, b, mid, i, x);
   upd(right, mid+1, e, i, x);

   segTree[node] = segTree[left]+segTree[right]; // change this
}  


int main() {
   FAST_IO;
   // start
   int n, q;
   cin>>n>>q;
   for(int i=1; i<=n; i++){ // 1 -indexed
      cin>>ar[i];
   }
   build(1, 1, n); // build the tree
   for(int i=0; i<q; i++){
      int t;
      cin>>t;
      if(t==1){
         int ind, x;
         cin>>ind>>x;
         upd(1, 1, n, ind, x);
      }
      else{
         int l, r;
         cin>>l>>r;
         long long res = qry(1, 1, n, l, r);
         cout<<res<<"\n";
      }
   }
 

  // problem link : https://cses.fi/problemset/task/1648 


   return 0;
}
