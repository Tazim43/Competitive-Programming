#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

string s1, s2, s3;
int n, m, p;
int dp[51][51][51];
int lcs(int i, int j, int k){
   if(i>=n || j>=m || k>=p)return 0;
   if(dp[i][j][k] !=-1 )return dp[i][j][k];
   int res = 0;
   if(s1[i]==s2[j] && s2[j]==s3[k]){
      res = lcs(i+1, j+1, k+1)+1;
   }
   else{
      res = max(res, lcs(i+1, j, k));
      res = max(res, lcs(i+1, j+1, k));
      res = max(res, lcs(i+1, j, k+1));
      res = max(res, lcs(i, j+1, k));
      res = max(res, lcs(i, j+1, k+1));
      res = max(res, lcs(i, j, k+1));
   }
   return dp[i][j][k] = res;

}

int main() {
   FAST_IO;
   // start
   int t;
   cin>>t;
   int tt = 0;
   read:
   while (t--) {
      memset(dp, -1, sizeof(dp));
      cin>>s1>>s2>>s3;
      n = s1.length(), m = s2.length(), p = s3.length();
      int res = lcs(0, 0, 0);
      cout<<"Case "<<++tt<<": ";
      cout<<res<<"\n";
   
   }



   return 0;
}
