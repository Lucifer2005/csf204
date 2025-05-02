#include<bits/stdc++.h>
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

	vector<int> bfsOfGraph(int s)  {
    		vector<int> res;
    		queue<int> q;  
    		vector<bool> visited(V, false);
    		visited[s] = true;
    		q.push(s);
    		while (!q.empty()) {
        		int curr = q.front();
        		q.pop();
        		res.push_back(curr);
        		for (int i=0; i<adj[curr].size();i++) {
            			int x=adj[curr][i];
				if (visited[x]==false) {
                			visited[x] = true;
                			q.push(x);
            			}//End if
        		}//End for
    		}//End while	
    		return res;
	}
};

int main()  {
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(2,4);
	int src = 0;
    	vector<int> ans = g.bfsOfGraph(src);
    	for(int i=0; i<ans.size();i++) {
        	cout<<ans[i]<<" ";
    	}
    	return 0;
}
