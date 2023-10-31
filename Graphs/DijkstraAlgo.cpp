#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	vector<pair<int, int>>* adj;

public:
	Graph(int v){
		V = v;
		adj = new vector<pair<int, int>>[V];
		
	}

	void addEdge(int u,int v,int wt,bool undir = true){

		adj[u].push_back({v,wt});
		if(undir){
			adj[v].push_back({u,wt});
		}
	}

	int dijkstra(int src,int dest){

		//Data Structures
		vector<int> dist(V,INT_MAX);
		set<pair<int,int> >  s;

		//1. Init 
		dist[src] = 0;
		s.insert({0,src});

		while(!s.empty()){

			auto it = s.begin();
			int node = it->second;
			int distTillNow = it->first; 
			s.erase(it); //Pop 

			//Iterate over the nbrs of node
			for(auto it : adj[node]){
				int adjNode = it.first;
				int currentEdge = it.second;

				if(distTillNow + currentEdge < dist[adjNode]){
					
                    //remove if adjNode already exist in the set
					auto f = s.find({dist[adjNode],adjNode});
					if(f!=s.end()){
						s.erase(f);
					}

					//insert the updated value with the new dist
					dist[adjNode] = distTillNow + currentEdge;
					s.insert({dist[adjNode],adjNode});
				}
			}
		}
		
		//Single Source Shortest Dist to all other nodes
		for(int i=0;i<V;i++){
			cout<<"Node "<<i <<" Dist "<<dist[i] <<endl;
		}
		return dist[dest];

	}

};

int main(){

	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkstra(0,4)<<endl;
}




/*

QUES ON APPLYING DIJKSTRA TO EVERY NODE AND FINDING ANS

Come Back Quickly
There are n towns numbered 1 through n and m roads numbered 1 through m.
road i is a one-way road from Town ai​ to Town bi​, and it takes ci​ minutes to go through. 
It is possible that ai​=bi​, and there may be multiple roads connecting the same pair of towns.
Alice is thinking about taking a walk in the country. 
We will call a walk valid when it goes through one or more roads and returns to the town it starts at.
For each town, determine whether there is a valid walk that starts at that town. 
Additionally, if there is a valid walk, find the minimum time such a walk requires, otherwise return -1.

Return a vector containing answers for each town from 1 to n respectively.
Constraints:

1<= n, m <= 2000

1<= ai, bi <= n

1<= ci <= 10^5



vector<int> solve(int n,int m, vector<vector<int>> road){
    
    vector<pair<int, int>> adj[n+1];
    for(auto it : road){
        int u = it[0]; int v = it[1]; int wt = it[2];
        adj[u].push_back({v,wt});
    }

    vector<int> ans;

    for(int i=1;i<=n; i++){
        vector<int> dist(n+1, 1e9);
        int val = 1e9;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;

                if(adjNode == i){
                    val = min(val, dis + edW);
                }
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;

                    pq.push({dist[adjNode], adjNode});

                }
            }
        }

        if(val == 1e9){
            ans.push_back(-1);
        }else{
            ans.push_back(val);
        }
    }

    return ans;
}

*/