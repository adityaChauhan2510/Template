#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
using namespace std;

const int N = 200007;
int n, m;
vector<int> adj[N]; 
//node----maxHeight
int jump[N][25];

 
void dfs(int node, int par){
    jump[node][0] = par;
	
	for (int it: adj[node]) 
		if(it != par) 
		    dfs(it, node);
}
 
void preprocess_LCA(){	
	dfs(1, -1);
		
	for(int i=1; i<=20; i++){
        for(int node=1; node<=n; node++){
            int par = jump[node][i-1];
            jump[node][i] = jump[par][i-1];
        }
    }
}
 
int main()
{   int n,q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int x; cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }    
    preprocess_LCA();

    while(q--) {
        int node, k;
        cin >> node >> k;
	
		for(int i=0; i<=20; i++ ){
            if(k & (1<<i)){   //if ith bit in 'k' is set
                node = jump[node][i];
            }
		    
        }
		cout << (node==0 ? -1 : node) << endl;
    }
}