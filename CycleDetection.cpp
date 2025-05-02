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

	bool bfs(int start, vector<bool>& visited) {
    		queue<pair<int, int>> q;
    		q.push({start, -1});
    		visited[start] = true;
    		while (!q.empty()) {
        		int node = q.front().first;
        		int parent = q.front().second;
        		q.pop();
	        	for (int j=0; j<adj[node].size();j++) {
	        	        int neighbor=adj[node][j];
               			if (visited[neighbor]==false) {
                			visited[neighbor] = true;
                			q.push({neighbor, node});
            			}//End if	 
                		else if (neighbor != parent) {
                			return true;
            			}//End else
        		}//End for
    		}//End while
    	return false;
	}//End

	bool isCycle() {
    		vector<bool> visited(V, false);
    		for (int i = 0; i < V; i++) {
        		if (visited[i]==false){
        		    if(bfs(i, visited)) {
                			return true;
            			}//End if
        		}//End outer if
        	}// End for
    		// If no cycle is found, return false
    		return false;
	}//End function
};
int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(4,2);
    g.addEdge(3,4);
    g.isCycle() ? cout<<"The graph is cyclic": cout<<"The graph is acyclic";
    return 0;
}





