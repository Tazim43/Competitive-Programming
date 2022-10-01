/* Author: Tazim(The_crawler) */
/* Template for Number Theory , Math , Combinatorics, Modular Arithmetic ... */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define dec greater<int>()
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define prow(n) for(auto i:n)cout<<i<<" ";cout<<"\n";
#define pcol(n) for(auto i:n)cout<<i<<"\n";
#define yes cout<<"YES"<<"\n";
#define no cout<<"NO"<<"\n";
#define all(x) (x).begin(), (x).end()
#define nl "\n"
#define INF 2147483647
#define INFLL 9223372036854775807 
#define debug(x) cout<<#x<<" = ";_print(x); cout<<endl; /// Debug function
using namespace std; ///****
using namespace __gnu_pbds;
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) { return (a.second < b.second); }
template<class T> void _print(T x) { cout << x; }
template<class T> void _print(vector<T>x) { cout << "[ ";for (T i : x)cout << i << " ";cout << "]"; }
template<class T> void _print(set<T>x) { cout << "[ ";for (T i : x)cout << i << " ";cout << "]"; }
template<class T, class V> void _print(pair<T, V>x) { cout << "{" << x.first << "," << x.second << "} "; }
template<class T, class V> void _print(map<T, V>x) { cout << "[ ";for (auto i : x)_print(i);cout << "]"; }
template<class T> void _print(multiset<T>x) { cout << "[ ";for (T i : x)cout << i << " ";cout << "]"; }
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//  less_equal - multiset | greater - decending order unique | less - asc unique | greater_equel - dec multiset

ll MOD = 1e9+7;

// Pascal Triangle for nCr
const int _p_limit = 1; // max_limit 10^4
vector<vector<ll>> pascal(_p_limit+1);  // space n*(n+1)/2

void run_pascal(){
    pascal[0] = {1}; pascal[1]={1,1};
    for(int i=2; i<=_p_limit; i++){
        pascal[i].push_back(1);
        for(unsigned int j=1; j<pascal[i-1].size(); j++){
            ll val = (pascal[i-1][j-1]%MOD)+(pascal[i-1][j]%MOD);
            val%=MOD;
            pascal[i].push_back(val);
        }
        pascal[i].push_back(1);
    }
}

// Binary Exponentiation for a^b - change MOD if needed
ll binpow(ll a, ll b){
    ll res = 1;
    while (b>0){
        if(b&1)res = (res*a)%MOD;
        a = (a*a)%MOD;
        b>>=1;
    }
    return res;
}
// Factorial precalculation 
const int f_limit = 1;
vector<ll> fact(f_limit);
void cal_fact(){
    fact[0] = 0;
    fact[1] = 1;
    for(int i=2; i<=f_limit; i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
}

ll nCr(ll n, ll r){
   if(r==0)return 1;
    if(r>n)return -1;
    // run cal_fact first
    ll nom = fact[n]%MOD;
    ll dnom = (fact[n-r]*fact[r])%MOD;
    nom*=binpow(dnom, MOD-2);
    nom%=MOD;
    return nom;
}

/* Hack My Code. It's Easy to Read :) */


int main() {
   FAST_IO;
    MOD = 1e9+7; //change MOD if needed
    //variables : MOD, _p_limit, f_limit
    //functions : run_pascal(), cal_fact()
    // start 
    cal_fact();
    int t;
    cin>>t;
    while (t--)
    {
        
    }
    

   return 0;
}

