#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V; 
	vector<vector<int>> adj; // adjacency lists
	public:
	Graph(int n){
		V = n;
		adj = vector<vector<int>> (n, vector<int>(0));
	}

	void addEdge(int v, int w){
		adj[v].push_back(w); 
		adj[w].push_back(v);
	}
	bool isBipartite() {
    		vector<int> color(V, -1);
    		queue<int> q;
    		for(int i = 0; i < V; i++) {
        		if(color[i] == -1) {
            			color[i] = 0;
            			q.push(i);
            			while(!q.empty()) {
                			int u = q.front();
                			q.pop();
                			for(int j=0;j<adj[u].size();j++){
						int v=adj[u][j]; 
						if(color[v] == -1) {
                        				color[v] = 1 - color[u];
                        	       			q.push(v);
                    		    		}//End if
		                    		else if(color[v] == color[u]) {
                        				return false;
                    		    		}//End else
                			}//End for
            			}//End while
        		}//End if
    		}//End for
    		// If no conflicts in coloring, graph is bipartite
    		return true;
	}//End function
};
int main() {
    // Graph Structure:
    // 0 - 1
    // |   |
    // 3 - 2
    int V = 4;
    Graph g(V);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    if(g.isBipartite())
        	cout << "It is a bipartite graph";
    else
        	cout << "It is not a bipartite graph";
    
    return 0;
}
