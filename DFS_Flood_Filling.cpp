#include<bits/stdc++.h>
using namespace std;


const int N = 1010;
//matrix input
vector<vector<char>> gh(N, vector<char>(N));
int n, m;
// visited check
vector<vector<int> > vis(N, vector<int>(N, 0));

void dfs(int i, int j) {
//   out of bound checking 
   if (i < 0 || j < 0 || i >= n || j >= m)return;
   if (vis[i][j])return;
   vis[i][j] = 1;
//   checking four side 
   dfs(i + 1, j);
   dfs(i - 1, j);
   dfs(i, j + 1);
   dfs(i, j - 1);
}


int main(){
  cin >> n >> m;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> gh[i][j];
      }
   }
//   this is just demo
  dfs(0, 0);
  
  
 
  return 0;
}
