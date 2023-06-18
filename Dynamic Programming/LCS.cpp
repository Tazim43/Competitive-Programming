#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

int nxt[3001][3001];
int dp[3001][3001];
int solve(string &s1, string &s2, int pos1, int pos2){
   if(pos1<0 || pos2<0)return 0;
   if(dp[pos1][pos2]!=-1)return dp[pos1][pos2];
   if(s1[pos1]==s2[pos2]){
      nxt[pos1][pos2] = 0;
      return dp[pos1][pos2] = solve(s1, s2, pos1-1, pos2-1)+1;
   }
   else{
      int res1 = solve(s1, s2, pos1-1, pos2);
      int res2 = solve(s1, s2, pos1, pos2-1);
      if(res1>res2){
         nxt[pos1][pos2] = 1;
      }
      else nxt[pos1][pos2] = 2;
      return dp[pos1][pos2] = max(res1, res2);
   }
}
string res = "";
// printing the lcs
void print(string &s1, string &s2, int pos1, int pos2){
   if(pos1<0 || pos2<0)return;

   if(s1[pos1]==s2[pos2]){
      res.push_back(s1[pos1]);
      print(s1, s2, pos1-1, pos2-1);
      return ;
   }

   if(solve(s1, s2, pos1-1, pos2)>solve(s1, s2, pos1, pos2-1)){
      print(s1, s2, pos1-1, pos2);
   }
   else print(s1, s2, pos1, pos2-1);

}


int main() {
   FAST_IO;
   // start
   memset(dp, -1, sizeof(dp));
   string s1, s2;
   cin>>s1>>s2;
   int n1 = s1.length();
   int n2 = s2.length();
   print(s1, s2, n1-1, n2-1);
   reverse(all(res));
   cout<<res<<"\n";



   return 0;
}
