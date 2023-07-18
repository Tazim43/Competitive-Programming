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

const int N = 1e6+10; // modify this

const int mod1 = 1e9+7, p1=137, mod2 = 1e9+9, p2 = 277;
vector<pair<int, int> > powers(N), inv_powers(N);

void precal(){
   powers[0] = {1, 1};
   for(int i=1; i<N; i++){
      powers[i].first = 1LL * powers[i-1].first*p1 % mod1;
      powers[i].second = 1LL * powers[i-1].second*p2 % mod2;
   }
   int ip1 = binpow(p1, mod1-2, mod1);
   int ip2 = binpow(p2, mod2-2, mod2);
   inv_powers[0] = {1, 1};
   for(int i=1; i<N; i++){
      inv_powers[i].first = 1LL * inv_powers[i-1].first*ip1 % mod1;
      inv_powers[i].second = 1LL * inv_powers[i-1].second*ip2 % mod2;
   }
}

// hash of a full string 
pair<int, int> forward_hash(string &s){
   pair<int, int> hsh = {0, 0};
   for(int j=0; j<s.length(); j++){
      hsh.first = (hsh.first + 1LL * powers[j].first * s[j] % mod1 ) % mod1;
      hsh.second = (hsh.second + 1LL * powers[j].second * s[j] % mod2) % mod2;
   }
   return hsh;
}

// Reverse hash of a full string
pair<int, int> reverse_hash(string &s){
   pair<int, int> hsh = {0, 0};
   for(int j=s.length()-1, i = 0; j>=0; j--, i++){
      hsh.first = (hsh.first + 1LL * powers[i].first * s[j] % mod1 ) % mod1;
      hsh.second = (hsh.second + 1LL * powers[i].second * s[j] % mod2) % mod2;
   }
   return hsh;
}

// Hashed array
vector<pair<int, int> > hash_array(string &s){ // 1 - indexed
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

// substring hash
pair<int, int> sub_hash(vector<pair<int, int> > &ar, int l, int r){ // 1 - indexed
   if(l<=1)return ar[r];
   pair<long long, long long> full = ar[r], del = ar[l-1];
   pair<long long, long long> need;
   need.first = (full.first-del.first+mod1)%mod1;
   need.second = (full.second-del.second+mod2)%mod2;
   need.first = (need.first*inv_powers[l-1].first)%mod1;
   need.second = (need.second*inv_powers[l-1].second)%mod2;
   return need;
}



int main() {
   FAST_IO;
   // start

   precal();

  



   return 0;
}
