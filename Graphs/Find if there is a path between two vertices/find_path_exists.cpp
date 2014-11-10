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
        bool find_path(int,int);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
}

bool Graph::find_path(int v1, int v2) {

    vector<bool> visited (V,false);

    visited[v1] = true;

    ///BFS...
    queue<int> q;
    q.push(v1);
    int node;

    while(!q.empty()) {
        node = q.front();
        for(list<int>::iterator it=adj[node].begin();it!=adj[node].end();it++) {
            if(*it==v2) return true;
            else if(!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
        q.pop();
    }

    return false;
}

int main() {

    ///This is for a DIRECTED GRAPH!!!....for an undirected graph
    ///we would need to add edges src->dest and dest->src as well...

    int N,src,dest,edges,v1,v2;
    cout << "How many nodes/vertices are in the graph:" << endl;
    cin >> N;
    Graph g(N);

    cout << "How many edges are there in the graph:" << endl;
    cin >> edges;

    for(int i=0;i<edges;i++) {
        cin >> src >> dest;
        g.addEdge(src,dest);
    }

    cout << "Enter two nodes to see if a path exists between them:" << endl;
    cin >> v1 >> v2;
    cout << "Does a path exist from node " << v1 << " to node " << v2 << "?" << endl;
    (g.find_path(v1,v2)) ? cout << "Yes" << endl : cout << "No" << endl;

}
