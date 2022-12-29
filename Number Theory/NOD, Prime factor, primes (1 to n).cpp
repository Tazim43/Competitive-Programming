/* Author: Tazim(The_crawler) */
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
const int M = 1e4;
vector<int> divisor(N, 0);
vector<int> primes(N, 1);
vector<int> prime_factors[M];

void sieve(){

   // Number of divsor from 1  to n 
   for(int i=1; i<=N; i++){
      for(int j=i; j<=N; j+=i)divisor[j]++;
   }

   // Prime factor of every number from 1 to n 
   for(int i=2; i<=M; i++){
      if(prime_factors[i].size()==0){
         for(int j=i; j<=M; j+=i)prime_factors[j].push_back(i);
      }
   }

   // finding primes 
   primes[1] = 0;
   for(int i=2; i<N; i++){
      if(primes[i]==0)continue;
      for(int j=i*i; j<N; j+=2*i)primes[j] = 0;
   }

}

// finding spf ( smallest prime factor)

const ll N = 5e6+10;
vector<ll> spf(N+1, 0);
vector<ll> nop(N+1, 0);

void sieve2(){
   // pre calculating spf 
   for(ll i=2; i<N; i+=2)spf[i] = 2;
   for(ll i=3; i<N; i+=2){
      if(spf[i]==0){
         spf[i] = i;
         for(ll j=i; (i*j)<N; j+=2){
            ll aa = i*j;
            if(spf[aa]==0)spf[aa] = i;
         }
      }
   }
   // counting number of prime factor using spf
   // also can be used for storing prime factors 
   
   ll cnt =0;
   for(ll i=2; i<N; i++){
      ll n = i;
      cnt =0;
      ll a = spf[i];
      if(a==0){
         debug(i)
      }
      while (n%a==0)
      {
         n/=a;
         a = spf[n];
         cnt++;
         if(a==0)break;
      }
      nop[i] = cnt;
   }

}

int main() {
   // start
   sieve();


   return 0;
}

