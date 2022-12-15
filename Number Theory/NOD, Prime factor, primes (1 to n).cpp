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

int main() {
   // start
   sieve();


   return 0;
}

