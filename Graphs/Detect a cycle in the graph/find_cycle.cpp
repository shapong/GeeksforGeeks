#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {

    int V;
    list<int> *adj;     ///= new list<int>[Number...of...vertices#V]

    public:
        Graph(int);
        void addEdge(int,int);
        bool isCyclic(int,vector<bool>&,vector<bool>&);
        bool isCycle_util();
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
}

bool Graph::isCyclic(int node, vector<bool>& visited, vector<bool>& recStack) {

    if(!visited[node]) {
        visited[node] = true;
        recStack[node] = true;

        for(list<int>::iterator it=adj[node].begin();it!=adj[node].end();it++) {
            if(!visited[*it] && isCyclic(*it,visited,recStack))
                return true;
            else if(recStack[*it])
                return true;
        }
    }
    recStack[node] = false;
    return false;

}

bool Graph::isCycle_util() {

    vector<bool> visited(V,false);
    vector<bool> recStack(V,false);

    for(int i=0;i<V;i++) {
        if(isCyclic(i,visited,recStack))
            return true;
    }

    return false;
}

int main() {

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

    cout << "Is the graph cyclic?" << endl;
    (g.isCycle_util()) ? cout << "Yes\n" : cout << "No\n";

}
