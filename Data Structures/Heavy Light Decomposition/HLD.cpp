#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 
#define int long long

const int N = 2e5+10;

int ar[N], seg[4*N];

int combine(int a, int b){
   return a + b;
}

void build(int node, int b, int e){
   if(b==e){
      seg[node] = ar[b];
      return;
   }
   int mid = (b+e)/2;
   build(2*node+1, b, mid);
   build(2*node+2, mid+1, e);
   seg[node] = combine(seg[2*node+1], seg[2*node+2]);
}
void upd(int node, int b, int e, int id, int x){
   if(id>e || id<b)return;
   if(id==b && id==e){
      seg[node] = x;
      return;
   }
   int mid = (b+e)/2;
   upd(2*node+1, b, mid, id, x);
   upd(2*node+2, mid+1, e, id, x);
   seg[node] = combine(seg[2*node+1], seg[2*node+2]);
}

int qry(int node, int b, int e, int l, int r){
   if(b>r || e<l)return 0;
   if(b>=l && e<=r)return seg[node];

   int mid = (b+e)/2;
   return combine(qry(2*node+1, b, mid, l, r), qry(2*node+2, mid+1, e, l, r));
}


// Heavy Light Decomposition 

vector<int> gh[N];
vector<int> parent(N), depth(N, 0), heavy(N, -1), head(N), pos(N), tin(N), tout(N), value(N);
int up[25][N];

int TM = 0;

int dfs(int node, int par=-1){
   int sz = 1, mxChild = 0;
   tin[node] = TM++;
   up[0][node] = par;
   for(int i=1; i<21; i++){
      up[i][node] = up[i-1][up[i-1][node]]; 
   }
   for(auto v:gh[node]){
      if(v==par)continue;
      parent[v] = node;
      depth[v] = depth[node] + 1;
      up[0][v] = node;
      
      int chSize = dfs(v, node);
      sz += chSize;

      if(chSize > mxChild){
         mxChild = chSize;
         heavy[node] = v; // child of heavy edge
      }
     
   }
   tout[node] = TM++;
   return sz;
}

int cur_pos = 0; // 0 - based indexing
void decompose(int v, int h){
   ar[cur_pos] = value[v]; // node values to segtree array
   head[v] = h; pos[v] = cur_pos++;
   
   if(heavy[v] !=-1)
      decompose(heavy[v], h);
   
   for(auto ch:gh[v]){
      if(ch != parent[v] && ch != heavy[v])
         decompose(ch, ch);
   }
}


bool is_ancestor(int u, int v){
   return (tin[v]>=tin[u] && tout[v]<=tout[u]);
}

int LCA(int a, int b){
   if(is_ancestor(a, b))return a;
   if(is_ancestor(b, a))return b;

   for(int i=20; i>=0; i--){
      if( up[i][a]>0 && !is_ancestor(up[i][a], b))
         a = up[i][a];
   }
   return up[0][a];
}

int n;
int queryHld(int a, int l){
   int res = 0;
   while (head[a]!=head[l]){
      res += qry(0, 0, n-1, pos[head[a]], pos[a]);
      a = parent[head[a]];
   }
   res += qry(0, 0, n-1, pos[l], pos[a]);
   return res;   
}

int query(int a, int b){
   int lc = LCA(a, b);
   int res = queryHld(a, lc) + queryHld(b, lc) - qry(0, 0, n-1, pos[lc], pos[lc]);
   return res;
}




signed main() {
   FAST_IO;
   // start

  // https://cses.fi/problemset/task/1138 

   int q;
   cin>>n>>q;

   for(int i=1; i<=n; i++){
      cin>>value[i];
   }

   for(int i=0; i<n-1; i++){
      int a, b;
      cin>>a>>b;
      gh[a].push_back(b);
      gh[b].push_back(a);
   }

   dfs(1);
   decompose(1, 1);
   build(0, 0, n-1);

   while (q--)
   {
      int tp;
      cin>>tp;

      if(tp==1){
         int s, x;
         cin>>s>>x;
         upd(0, 0, n-1, pos[s], x);
      }
      else{
         int x;
         cin>>x;
         int res = query(1, x);
         cout<<res<<"\n";
      }
   }
   

   return 0;
}
