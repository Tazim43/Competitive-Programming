#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

string s1, s2;
int n, m;
string dp[101][101];
string lcs(int i, int j){
   if(i>=n || j>=m)return "";

   string &ret = dp[i][j];
   if(ret!="-1")return ret;
   ret = "";
   if(s1[i]==s2[j]){
      ret+=string(1, s1[i])+lcs(i+1, j+1);
   }
   else{
      string res1 = lcs(i+1, j);
      string res2 = lcs(i, j+1);
      if(res1.length()>res2.length()){
         ret = res1;
      }
      else if(res1.length()==res2.length()){
         ret = min(res1, res2);
      }
      else ret = res2;
   }

   return ret;

}

int main() {
   FAST_IO;
   // start
   
   int t;
   cin>>t;
   int tt = 0;
   read:
   while (t--) {
      cin>>s1>>s2;
      n = s1.length(), m = s2.length();
      for(int i=0; i<=n; i++){
         for(int j=0; j<=m; j++){
            dp[i][j] = "-1";
         }
      }
      string res = lcs(0, 0);
      
      cout<<"Case "<<++tt<<": ";
      if(res=="")cout<<":(\n";
      else cout<<res<<"\n";
      
   }



   return 0;
}
