#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

deque<pair<int, int> > monq; // value, idx

void add(int value, int idx){
   while (!monq.empty() && monq.back().first>=value)
   {
      monq.pop_back();
   }
   monq.push_back({value, idx});
   
}

void del(int idx){
   if(!monq.empty() && monq.front().second==idx){
      monq.pop_front();
   }
}

int main() {
   FAST_IO;
   // start
   // find sum of min value of subarray i:i+k for all 1<=i<=n-k
   // n = 5, k = 3 | 5 3 4 4 5 1 | res = 11 (3 + 3 + 4 + 1) 
   int n, k;
   cin>>n>>k;
   vector<int> ar(n);
   for(int i=0; i<n; i++){
      cin>>ar[i];
   }
   for(int i=0; i<k; i++){
      add(ar[i], i);
   }
   int res = monq.front().first;

   for(int i = k; i<n; i++){
      del(i-k);
      add(ar[i], i);
      res+=monq.front().first;
   }

   cout<<res<<"\n";


   return 0;
}
