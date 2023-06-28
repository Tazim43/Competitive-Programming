#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

const int N = 3e5+10;

int sparseTable[26][N];
int ar[N];
// O(nlogn)
void build(int n){
    for(int i=0; i<n; i++){
      sparseTable[0][i] = ar[i];
    }
    for(int i=1; i<25; i++){
      for(int j=0; j+(1<<i)<=n; j++){
        int x = sparseTable[i-1][j];
        int y = sparseTable[i-1][j+(1<<(i-1))];
        sparseTable[i][j] = __gcd(x,y); // min, max or gcd
      }
    }
}
// O(1)
int qry(int n, int L, int R){
    int rng = log2(R-L+1);
    int x = sparseTable[rng][L];
    int y = sparseTable[rng][R-(1<<rng)+1];
    return __gcd(x,y); // min, max or gcd
}

int main() {
   FAST_IO;
   // start

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
      cin>>ar[i];
    }

    build(n);
    int l, r;
    cin>>l>>r;
    cout<<qry(n, l, r)<<endl; 
    // returns the min, max or gcd of range l to r in O(1)

   return 0;
}
