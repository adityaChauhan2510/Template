/*
Tree Distances II

You are given a tree consisting of n nodes.
Your task is to determine for each node the sum of the distances from the node to all other nodes.

Time Complexity:O(n)

It's easy to find the sum of distances from a single node - just root the tree at that node, do a DFS, and add the depths of each other node to the answer.
Unfortunately, n can go up to 2.10^5, so we can't just do this for each node.

If we have the answer for some node (let's say node 1), how can we quickly find the answer for its neighbours?

The key observation is that if we reroot the tree at node 1's neighbour (let's say node 2), then

The depths of all nodes in node 2's subtree decrease by 1.
The depths of all nodes outside of its subtree increase by 1.


This gives us a nice way to transition from node 1's answer to node 2's answer
using only 'n' and the size of node 2's subtree! Observe that the change in the
answer is exactly n - 2*(node 2's subtree size).

We can use DFS to find both the answer for node 1 and the size of each node's
subtree when rooted at node 1, and then DFS again to compute all the answers.

*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
vector<int> adj[200001];
ll numOfSubtreeNodes[200001];
ll ans[200001];

void dfs1(int node = 1, int parent = 0, ll depth = 0) {
	ans[1] += depth;
	numOfSubtreeNodes[node] = 1;
	for (int i : adj[node])
		if (i != parent) {
			dfs1(i, node, depth + 1);
			numOfSubtreeNodes[node] += numOfSubtreeNodes[i];
		}
}

void dfs2(int node = 1, int parent = 0) {
	for (int i : adj[node])
		if (i != parent) {
			ans[i] = ans[node] + n - 2 * numOfSubtreeNodes[i];
			dfs2(i, node);
		}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1();
	dfs2();
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}