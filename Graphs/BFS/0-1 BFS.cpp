#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)

const int N = 2e5+10;

vector<pair<int, int> > gh[N];
vector<int> dist(N, INT_MAX);

// 0-1 BFS . Complexity O(2*(vertex+edges))

void bfs(int source){
    deque<int> q; // at a time there will 2 lvl nodes only (obserbation)
    q.push_back(source);

    dist[source] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop_front();

        for(auto child:gh[node]){
            int v = child.first;
            int w = child.second; // 0 or 1

            if(dist[node]+w<dist[v]){
                dist[v] = dist[node]+w;

                if(w==0)q.push_front(v); // process same lvl nodes first 
                else q.push_back(v);
            }
        }
    }
    
}

int main(){
    FAST_IO;

    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        gh[a].push_back({b, 0});
        gh[b].push_back({a, 1});
    }
    // https://www.codechef.com/problems/REVERSE
    // Implemented for this problem
    bfs(1);
    if(dist[n]==INT_MAX)cout<<-1<<endl;
    else cout<<dist[n]<<endl;
    

    return 0;
}

