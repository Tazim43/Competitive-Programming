#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int parent[N];
int sz[N];

int find(int v){
    if(v==parent[v])return v;
    return parent[v] = find(parent[v]); // path compression
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(sz[a]<sz[b])swap(a,b); // reduce time 
        parent[b] = a;
        sz[a]+=sz[b];
    }
    // a==b - cycle found 
}

int main(){
    
    for(int i=0; i<N; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    
    

    return 0;
}

