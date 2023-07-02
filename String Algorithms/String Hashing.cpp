#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

long long binpow(long long a, long long b, long long _mod){
   long long res = 1;
    while (b>0){
        if(b&1)res = (res*a)%_mod;
        a = (a*a)%_mod;
        b>>=1;
    }
    return res;
}

const int mod1 = 1e9+7, p1=137, mod2 = 1e9+9, p2 = 277, N = 1e6+10; // modify this
vector<pair<int, int> > powers(N), inv_powers(N);

void precal(){
   powers[0] = {1, 1};
   for(int i=1; i<N; i++){
      powers[i].first = 1LL * powers[i-1].first*p1 % mod1;
      powers[i].second = 1LL * powers[i-1].first*p2 % mod2;
   }
   int ip1 = binpow(p1, mod1-2, mod1);
   int ip2 = binpow(p2, mod2-2, mod2);
   inv_powers[0] = {1, 1};
   for(int i=1; i<N; i++){
      inv_powers[i].first = 1LL * inv_powers[i-1].first*p1 % mod1;
      inv_powers[i].second = 1LL * inv_powers[i-1].first*p2 % mod2;
   }
}

// hash of full string 
pair<int, int> forward_hash(string &s){
   pair<int, int> hsh = {0, 0};
   for(int j=0; j<s.length(); j++){
      hsh.first = (hsh.first + 1LL * powers[j].first * s[j] % mod1 ) % mod1;
      hsh.second = (hsh.second + 1LL * powers[j].second * s[j] % mod2) % mod2;
   }
   return hsh;
}

// Hashed array
vector<pair<int, int> > hash_array(string &s){
   vector<pair<int, int> > ar;
   pair<int, int> hsh = {0, 0};
   ar.push_back(hsh);
   for(int j=0; j<s.length(); j++){
      hsh.first = (hsh.first + 1LL * powers[j].first * s[j] % mod1 ) % mod1;
      hsh.second = (hsh.second + 1LL * powers[j].second * s[j] % mod2) % mod2;
      ar.push_back(hsh);
   }
   return ar;
}



int main() {
   FAST_IO;
   // start

   precal();

  



   return 0;
}
