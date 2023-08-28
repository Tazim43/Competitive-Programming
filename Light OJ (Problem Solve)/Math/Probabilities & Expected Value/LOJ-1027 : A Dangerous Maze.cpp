#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 



int main() {
   FAST_IO;
   // start
   int t;
   cin>>t;
   read:
   int tt = 0;
   while (t--) {
      int n;
      cin>>n;
      int sum = 0, neg = 0;
      for(int i=0; i<n; i++){
         int a;
         cin>>a;
         sum+=abs(a);
         if(a<0)neg++;
      }

      int dnom = n-neg;
      cout<<"Case "<<++tt<<": ";
      if(dnom==0)cout<<"inf\n";
      else{
         int gcd = __gcd(sum, dnom);
         cout<<sum/gcd<<"/"<<dnom/gcd<<"\n";
      }
      
   
   }



   return 0;
}
