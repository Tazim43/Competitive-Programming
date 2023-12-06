#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

struct node{
    int leaf,cnt; // is leaf , prefix count
    int nxt[26];
    node(){
        leaf = cnt = 0;
        memset(nxt, -1, sizeof nxt);
    }
};

vector<node> Trie(1);

void insert(string &s){
    int root = 0;
    for(int i=0; i<s.length(); i++){
        if(Trie[root].nxt[s[i]-'a']==-1){
            Trie[root].nxt[s[i]-'a'] = Trie.size();
            Trie.emplace_back();
        }
        root = Trie[root].nxt[s[i]-'a'];
        Trie[root].cnt++;
    }
    Trie[root].leaf++;
}

int qry(string &s){
    int root = 0, res = 0;
    for(int i=s.length()-1; i>=0; i--){
        if(Trie[root].nxt[s[i]-'a']==-1)
            break;
        root = Trie[root].nxt[s[i]-'a'];
        res += Trie[root].cnt;
    }
    return res;
}


int main() {
   FAST_IO;
   // start
   



   return 0;
}
