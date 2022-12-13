#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
vector<bool> vis(N, 0); // Only for cyclic graph 
/*
      1
     / \
    2 _ 3
   / \
  4   5
 Traversal = 1 3 3 5 4 or 1 2 3 4 5
 
*/

// For graphs - need a visited array to mark the visited nodes 
void DFS(int vertex) {
   // Take action on the vertex after entering the vertex
   vis[vertex] = 1;
   for (int child : graph[vertex]) {
      // Take action on the child after entering the child
      if (vis[child] != 1)
         DFS(child);
      // Take action on the child after exiting the child node 
   }
   // Take action on the vertex before exiting the vertex 
}

/*
     1
    / \
   2   3
  / \
 4   5

Traversal = 1 2 4 5 3 or 1 3 2 5 4
*/

// For trees - no need any visited mark 
void dfs(int vertex, int parent = -1) {
   //
   for (int child : graph[vertex]) {
      //
      if (child != parent)
         dfs(child, vertex);
      //
   }
   // all same as DFS
}



int main() {
   int n;
   cin >> n;
   // Directed Graph 
   for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }
   // Assuming 1 as root 
   DFS(1);
   dfs(1);


   return 0;
}
