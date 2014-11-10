#include <iostream>
#include <algorithm>

using namespace std;

typedef struct edge_struct {
        int weight;
        int src;
        int dest;
} edges;

class Graph {

    int E,index,V;
    edges* edge_list;

    public:
        Graph(int,int);
        void addEdge(int,int,int);
        void removeLastEdge();
        bool detect_cycle(edges*,int);
        void Union(int*,int,int);
        int Find(int*,int);
        Graph Kruskal_MST();
        //bool compare(const edges, const edges);
};

Graph::Graph(int e, int v) {
    this->E = e;
    this->V = v;
    edge_list = new edges[E];
    index=0;
}

void Graph::addEdge(int s, int d, int wt) {
    edges temp;
    temp.src = s;
    temp.dest = d;
    temp.weight = wt;
    edge_list[index] = temp;
    index++;
}

void Graph::removeLastEdge() {
    //this->edge_list[index-1] = NULL;
    index--;
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

bool Graph::detect_cycle(edges* edgeList, int n) {

    int* parent = new int[V];
    for(int i=0;i<V;i++) parent[i] = -1;
    for(int i=0;i<n;i++) {
        int x = Find(parent,edgeList[i].src);
        int y = Find(parent,edgeList[i].dest);
        if (x==y) return true;

        Union(parent,x,y);
    }
    return false;
}

bool compare(const edges e1, const edges e2) {
    return (e1.weight < e2.weight) ? true : false;
}

Graph Graph::Kruskal_MST() {

    Graph mst(V-1,V);
    int count=0,ind=0;
    sort(this->edge_list,this->edge_list+E,compare);
    edges* temp_list = new edges[V-1];
    ///Add Edges till we have V-1 edges in the graph...
    ///Only add the edge if it does NOT form a cycle
    while(count < V-1) {
        temp_list[count].src = this->edge_list[ind].src;
        temp_list[count].dest = this->edge_list[ind].dest;
        temp_list[count].weight = this->edge_list[ind].weight;
        if(!mst.detect_cycle(temp_list,count+1)) count++;
        ind++;
    }

    mst.edge_list = temp_list;
    for(int i=0;i<V-1;i++) {
        cout << mst.edge_list[i].src << " " << mst.edge_list[i].dest << " " << mst.edge_list[i].weight << endl;
    }
    return mst;
}

int main () {

    int E,src,dest,V,wt;
    cout << "How many edges does this graph have?" << endl;
    cin >> E;
    cout << "How many vertices does this graph have?" << endl;
    cin >> V;
    Graph g(E,V);
    cout << "Enter the edges:" << endl;

    for(int i=0;i<E;i++) {
        cin >> src >> dest >> wt;
        g.addEdge(src,dest,wt);
    }

    cout << "The edges in Kruskal's MST for this graph are:" << endl;
    Graph MST(V-1,V);
    MST = g.Kruskal_MST();

}
