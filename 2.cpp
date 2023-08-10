#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
using namespace std;

vector<int> adj[200001];
int ans[200001];
int vis[200001];
int n;

void dfs2(int node, int par=0){
    for(auto it : adj[node]){
        if(!vis[it]){
            for()
        }
    }
}

void dfs(int node=1,int level=0){
    vis[node] = 1;
    ans[1] += level;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, level+1);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    dfs(1, ans, adj, vis);

}


int main(){
    solve();
}