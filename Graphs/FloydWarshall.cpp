/*

FLOYD-WARSHALL ALGORITHM
------------------------

-All pair shortest path?
-Shortest path between all pairs
-Works with negative edges
-can detect negative cycle too, with one exta step
-DP based algorithm 
-TC---------->O(V^3)
-SC---------->O(V^2)

*/

#include<bits/stdc++.h>
using namespace std;
#define INF 100000

vector<vector<int>> floyd_warshall(vector<vector<int>> graph){

	vector<vector<int>> dist(graph);
	int V = graph.size();

	//Phases, in kth phase we included vertices (1,2,...k) as intermediate vertices
	for(int k=0;k<V;k++){
		//Iterate over entire 2D Matrix
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){

				//if vertex k is included, and can we minimise the dist ?
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}

		}
	}

    // If distance of any vertex from itself
    // becomes negative, then there is a negative
    // weight cycle.
    for (int i = 0; i < V; i++){
        if (dist[i][i] < 0){
            cout << "neg cycle detected";
            exit(0);
        }
    }



	return dist;
}


int main(){


	// 4 Vertices (4 X 4 Matrix)

	vector<vector<int>> graph = {
								 {0,INF,-2,INF},
								 {4,0,3,INF},
								 {INF,INF,0,2},
								 {INF,-1,INF,0}
								};

    /*
    graph with negative cycle

    vector<vector<int>> graph = {
								 {0,INF,-2,INF},
								 {4,0,3,INF},
								 {INF,INF,0,2},
								 {INF,-5,INF,0}
								};
    */


	vector<vector<int>> result = floyd_warshall(graph);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[0].size();j++){
			
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

