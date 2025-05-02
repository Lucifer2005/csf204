#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph {
public:
    vector<vector<int>> adjList
    = {
    {}, // 1st empty vector (for vertex 0)
    {}, // 2nd empty vector (for vertex 1)
    {}, // 3rd empty vector (for vertex 2)
    {}, // 4th empty vector (for vertex 3)
    {}  // 5th empty vector (for vertex 4)
};
    void add_edge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void print(){
	int n=adjList.size();
        for (int i=0;i<n;i++) {
            cout << i << "->";
	    int m=adjList[i].size();
            for (int j=0;j<m;j++) {
                cout << adjList[i][j] << "->";
            }//End of inner loop
            cout <<"NULL"<<endl;
        }//End of outer loop
    }//End of function
};

int main()
{
    Graph g;
    g.add_edge(1, 0);
    g.add_edge(2, 0);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.print();
    return 0;
}