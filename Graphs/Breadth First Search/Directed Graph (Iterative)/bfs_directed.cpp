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
        void BFS(int,vector<bool>&);
        void bfs_util();
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
}

void Graph::BFS(int start, vector<bool>& visited) {

    visited[start] = true;

    queue<int> q;
    q.push(start);
    int node;

    while(!q.empty()) {
        node = q.front();
        cout << node << " ";

        for(list<int>::iterator it=adj[node].begin();it!=adj[node].end();it++) {
            if(!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
        q.pop();
    }
}

void Graph::bfs_util() {

    vector<bool> visited (V,false);

    for(int i=0;i<V;i++)
        if(visited[i]==false)
            BFS(i,visited);
    cout << endl;
}

int main() {

    ///This is for a DIRECTED GRAPH!!!....for an undirected graph
    ///we would need to add edges src->dest and dest->src as well...

    int N,src,dest,edges;
    cout << "How many nodes/vertices are in the graph:" << endl;
    cin >> N;
    Graph g(N);

    cout << "How many edges are there in the graph:" << endl;
    cin >> edges;

    for(int i=0;i<edges;i++) {
        cin >> src >> dest;
        g.addEdge(src,dest);
    }

    cout << "The Breadth First Traversal of the graph is:" << endl;
    g.bfs_util();

}
