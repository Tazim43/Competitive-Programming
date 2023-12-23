#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

vector<int> build_lps(string &s){
   int n = s.length();
   vector<int> prefix(n, 0);

   for(int i=1, j=0; i<n; i++){
      while (j>0 && s[j]!=s[i]) j = prefix[j-1];
      if(s[i]==s[j])j++;
      prefix[i] = j;
   }
   return prefix;
}


int main() {
   FAST_IO;
   // start
   
   string s;
   cin>>s;

   vector<int> lps = build_lps(s);

   for(auto ii:lps)cout<<ii<<" ";
   cout<<"\n";




   return 0;
}
