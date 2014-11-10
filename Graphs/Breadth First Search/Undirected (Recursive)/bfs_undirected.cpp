#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph {

    int V;
    list<int> *adj;     ///= new list<int>[Number...of...vertices#V]

    public:
        Graph(int);
        void addEdge(int,int);
        void BFS(vector<bool>&,queue<int>&);
        void bfs_util(int);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void Graph::BFS(vector<bool>& visited,queue<int>& q) {

    if(q.empty()) return;

    int node;
    node = q.front();
    cout << node << " ";

    for(list<int>::iterator it=adj[node].begin();it!=adj[node].end();it++) {
        if(!visited[*it]) {
            visited[*it] = true;
            q.push(*it);
        }
    }
    q.pop();
    BFS(visited,q);
}

void Graph::bfs_util(int start) {

    vector<bool> visited (V,false);
    visited[start] = true;

    queue<int> q;
    q.push(start);
    BFS(visited,q);
    cout << endl;
}

int main() {

    ///This is for an UNDIRECTED GRAPH!!!....for an undirected graph
    ///we would need to add edges src->dest and dest->src as well...

    int N,a,b,edges,start;
    cout << "How many nodes/vertices are in the graph:" << endl;
    cin >> N;
    Graph g(N);

    cout << "How many edges are there in the graph:" << endl;
    cin >> edges;

    for(int i=0;i<edges;i++) {
        cin >> a >> b;
        g.addEdge(a,b);
    }

    cout << "What is the start:" << endl;
    cin >> start;

    cout << "The Breadth First Traversal of the graph is:" << endl;
    g.bfs_util(start);

}
