#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {

    int V;
    list<int> *adj;

    public:
        Graph(int);
        void addEdge(int,int);
        void DFS(int,vector<bool>&);
        void dfs_util(int);
};

Graph::Graph(int v) {
    this->V=v;
    adj = new list<int>[V];
}

void Graph::addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void Graph::DFS(int start, vector<bool>& visited) {

    visited[start] = true;
    cout << start << " ";

    for(list<int>::iterator it=adj[start].begin();it!=adj[start].end();it++) {
        if(!visited[*it])
            DFS(*it,visited);
    }
}

void Graph::dfs_util(int start) {

    vector<bool> visited (V,false);

    DFS(start,visited);

    cout << endl;
}

int main() {

    ///This is an UNDRIECTED GRAPH...therefore we only have to call DFS once for the starting node...

    int N,edges,a,b,start;
    cout << "How many nodes/vertices are in the graph:" << endl;
    cin >> N;

    Graph g(N);

    cout << "How many edges are in the graph:" << endl;
    cin >> edges;
    for(int i=0;i<edges;i++) {
        cin >> a >> b;
        g.addEdge(a,b);
    }

    cout << "Where is the start:" << endl;
    cin >> start;

    cout << "The Depth First Traversal of the graph is:" << endl;
    g.dfs_util(start);

}
