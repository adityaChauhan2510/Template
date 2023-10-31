#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
using namespace std;


pair<int, int> bfs(int src, vector<int> adj[], int n){
    pair<int, int> ans;
    queue<pair<int, int>> q;
    q.push({src, 0});
    vector<int> vis(n+1, 0);
    vis[src] = 1;

    while(!q.empty()){
        ans = q.front();
        int node = ans.first;
        int dis = ans.second;
        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it, dis+1});
            }
        }
    }

    return ans;
}

void solve(){
    int n; cin>>n;
    vector<int> adj[n+1];  // nodes start with 1

    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int, int> end1 = bfs(1, adj, n);
    pair<int, int> end2 = bfs(end1.first,adj, n);

    cout << end2.second << endl;  //diameter of graph
}


int main(){
    solve();
}