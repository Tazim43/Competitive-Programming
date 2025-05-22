#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

const int N = 1e6 + 10;

namespace MOs{
   const int block_size = 450;

   struct Query{
      int l, r, idx;
      bool operator<(Query other){
         return make_pair(l/block_size, r) < make_pair(other.l/block_size, other.r);
      }
   };

   // The DS
   
   void add(int idx){
      //
   }
   void remove(int idx){
      //
   }
   int solve(){
      //
   }

   vector<int> mos_algo(vector<Query> qry){
      vector<int> ans(qry.size());
      sort(qry.begin(), qry.end());
      // reset DS

      int cur_l = 0, cur_r = -1;
      for(Query q:qry){
         while (cur_l>q.l)
         {
            cur_l--;
            add(cur_l);
         }
         while (cur_r<q.r)
         {
            cur_r++;
            add(cur_r);
         }
         while (cur_l<q.l)
         {
            remove(cur_l);
            cur_l++;
         }
         while (cur_r>q.r)
         {
            remove(cur_r);
            cur_r--;
         }
         
         ans[q.idx] = solve();
      
      }

      return ans;

   }
}


signed main() {
   FAST_IO;
   // start


   return 0;
}
