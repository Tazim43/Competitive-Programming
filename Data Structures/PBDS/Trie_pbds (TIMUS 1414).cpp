#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Trie and other PBDS containers
#include <ext/pb_ds/tree_policy.hpp>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 
using namespace __gnu_pbds;  //2 

typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> trie_type;



int main() {
   FAST_IO;
   // start

   trie_type ss;
   ss.insert("sun");
   string x;
   while (cin>>x)
   {
      if(x[0]=='+'){
         ss.insert(x.substr(1));
         continue;
      }
      if(x[0]=='?')cout<<x.substr(1)<<"\n";
      auto res = ss.prefix_range(x.substr(1));
      int i=0;
      for( auto it= res.first; i<20 && it!=res.second; it++, i++){
         cout<<"  "<<*it<<"\n";
      }
      
   }
   
   


   return 0;
}
