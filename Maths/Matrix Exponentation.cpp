#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

#define MAT vector<vector<int> >

const int MOD = 1e9+7;

MAT multiply(MAT a, MAT b){ // c1 == r2 , multiplying two matrix
   int r1 = a.size(), c1 = a[0].size(), c2 = b[0].size();

   MAT res(r1, vector<int> (c2, 0));

   for(int i=0; i<r1; i++){
      for(int j=0; j<c1; j++){
         for(int k = 0; k<c2; k++){
            res[i][k] += 1LL * a[i][j] * b[j][k] % MOD;
         }
      }
   }
   
   return res;
}

MAT expo_power(MAT a, long long k){ // calculating power 
   int r = a.size(), c = a[0].size();

   MAT res(r, vector<int> (c, 0));

   for(int i=0; i<r; i++)
      for(int j = 0; j<c; j++)
         if(i==j)res[i][j] = 1;
   
   while (k>0)
   {
      if(k%2){
         res = multiply(res, a);
      }
      k/=2;
      a = multiply(a, a);
   
   }
   return res;

}


int main() {
   FAST_IO;
   // start

   // solution for nth (1 - 1e18) fibonacci

   long long n;
   cin>>n;

   MAT X (2, vector<int> (2, 1));
   X[0][0] = 0;

   X = expo_power(X, n);
   MAT R = {{0}, {1}};

   MAT res = multiply(X, R);

   cout<<res[0][0]<<"\n";
  
   return 0;
}
