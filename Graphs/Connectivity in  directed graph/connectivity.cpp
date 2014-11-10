#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {

    int V;
    list<int> *adj;     /// = new list<int>[Number...of...vertices#V]

    public:
        Graph(int);
        void addEdge(int,int);
        void DFS(int,vector<bool>&);
        list<int>* transpose();
        bool isStronglyConnected();
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
}

void Graph::DFS(int start, vector<bool>& visited) {

    visited[start] = true;

    for(list<int>::iterator it=adj[start].begin();it!=adj[start].end();it++) {
        if(!visited[*it])
            DFS(*it,visited);
    }

}

list<int>* Graph::transpose() {

    list<int> *trans = new list<int>[V];
    for(int i=0;i<V;i++) {
        for(list<int>::iterator it=adj[i].begin(); it!=adj[i].end();it++) {
            trans[*it].push_back(i);
        }
    }

    return trans;
}

bool Graph::isStronglyConnected() {

    vector<bool> visited (V,false);

    if(!visited[0]) DFS(0,visited);

    for(int i=0;i<visited.size();i++) if(!visited[i]) return false;

    adj = transpose();

    for(int i=0;i<visited.size();i++) visited[i]=false;

    if(!visited[0]) DFS(0,visited);
    for(int i=0;i<visited.size();i++) if(!visited[i]) return false;

    return true;

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

    cout << "Is the graph strongly connected?" << endl;
    (g.isStronglyConnected()) ? cout << "True" << endl : cout << "False" << endl;


}
