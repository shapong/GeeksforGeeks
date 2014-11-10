#include <iostream>

using namespace std;

class Graph {

    int E,index,V;
    typedef struct edge_struct {
        int src;
        int dest;
    } edges;
    edges* edge_list;

    public:
        Graph(int,int);
        void addEdge(int,int);
        bool detect_cycle();
        void Union(int*,int,int);
        int Find(int*,int);

};

Graph::Graph(int e, int v) {
    this->E = e;
    this->V = v;
    edge_list = new edges[E];
    index=0;
}

void Graph::addEdge(int s, int d) {
    edges temp;
    temp.src = s;
    temp.dest = d;
    edge_list[index] = temp;
    index++;
}

int Graph::Find(int* parent, int x) {
    if(parent[x]==-1) return x;
    return Find(parent,parent[x]);
}

void Graph::Union(int* parent, int x, int y) {
    int xset = Find(parent,x);
    int yset = Find(parent,y);
    parent[xset] = yset;
}

bool Graph::detect_cycle() {

    int* parent = new int[V];
    for(int i=0;i<V;i++) parent[i] = -1;
    for(int i=0;i<E;i++) {
        int x = Find(parent,edge_list[i].src);
        int y = Find(parent,edge_list[i].dest);
        if (x==y) return true;

        Union(parent,x,y);
    }
    return false;
}

int main () {

    int E,src,dest,V;
    cout << "How many edges does this graph have?" << endl;
    cin >> E;
    cout << "How many vertices does this graph have?" << endl;
    cin >> V;
    Graph g(E,V);
    cout << "Enter the edges:" << endl;

    for(int i=0;i<E;i++) {
        cin >> src >> dest;
        g.addEdge(src,dest);
    }

    cout << "Does the graph have a cycle?" << endl;
    (g.detect_cycle()) ? cout << "Yes\n" : cout << "No\n";

}
