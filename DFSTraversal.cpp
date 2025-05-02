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
	
	void DFS(int s){
		vector<bool> visited(V, false);
		stack<int> stack;
		stack.push(s);
		while (!stack.empty()){	
			int s=stack.top();
			stack.pop();
			if (visited[s]==false){
				cout << s << " ";
				visited[s] = true;
			}	
			for(int j=0;j<adj[s].size();j++){
			        int x=adj[s][j];
			        if(visited[x]==false){
			                stack.push(x);
			        }
			}//End for
		}//End while
	}//End function	
};



// Driver program to test methods of graph class
int main()
{
	Graph g(5); // Total 5 vertices in graph
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 4);
	cout << "Following is Depth First Traversal\n";
	g.DFS(0);
	return 0;
}
