#include <iostream>
#include <list>

using namespace std;

class Graph {

    int V;
    list<int> *adj;     ///= new list<int>[Number...of...vertices#V]

    public:
        Graph(int);
        void addEdge(int,int);
        void DFSUtil(int,vector<bool>&);
        bool isConnected();
        int isEulerian();
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void Graph::DFSUtil(int start, vector<bool>& visited) {

    visited[start] = true;

    for(list<int>::iterator it=adj[start].begin();it!=adj[start].end();it++) {
        if(!visited[*it])
            DFSUtil(*it,visited);
    }

}

bool Graph::isConnected() {

    vector<bool> visited(V,false);

    for(int i=0;i<V;i++) {
        if(adj[i].size() > 0 && !visited[i])
            DFSUtil(i,visited);
    }

    for(int i=0;i<V;i++) {
        if(adj[i].size() > 0 && !visited[i] ) return false;
    }

    return true;
}

int Graph::isEulerian() {

    if(!isConnected()) return -1;


    int odd = 0;
    for(int i=0;i<V;i++) {
        if(adj[i].size()%2==1)
            odd++;
    }

    if(odd==0) return 1;    ///Eulerian cycle
    else if(odd==2) return 0;   ///Eulerian path
    else return -1;             ///Not Eulerian

}

int main () {

    ///This is for an undirected graph...

    int N,a,b,edges;
    cout << "How many nodes/vertices are in the graph:" << endl;
    cin >> N;
    Graph g(N);

    cout << "How many edges are there in the graph:" << endl;
    cin >> edges;

    for(int i=0;i<edges;i++) {
        cin >> a >> b;
        g.addEdge(a,b);
    }

    int ans = g.isEulerian();
    if(ans==1) cout << "Graph is Eulerian: it has an Eulerian Cycle" << endl;
    else if(ans==0) cout << "Graph is Semi-Eulerian: it has an Eulerian Path" << endl;
    else cout << "Graph is not Eulerian/Semi-Eulerian: it has neither a Eulerian cycle nor path" << endl;

}
