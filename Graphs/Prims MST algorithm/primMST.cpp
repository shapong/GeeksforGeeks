#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

typedef struct vertex_info {
    int n;
    int src;
    int dist;
} vertex;

int max_dist = INT_MAX;

class Graph {

    int V;
    int** gMatrix;

    public:
        Graph(int);
        void create_graph(int**);
        void PrimMST();
};

Graph::Graph(int v) {
    this->V = v;
    gMatrix = new int*[V];
    for(int i=0;i<V;i++) gMatrix[i] = new int[V];
}

void Graph::create_graph(int** m) {
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            gMatrix[i][j] = m[i][j];
        }
    }
}

void Graph::PrimMST() {
    vector<bool> visited (V,false);
    vector<vertex> adj;
    vertex vt;
    for(int i=0;i<V;i++) {
        vt.n = i; vt.src = 0;
        vt.dist = (i==0) ? 0 : max_dist;
        adj.push_back(vt);
    }

    int curr,min;
    bool all_visited = false;
    while(!all_visited) {
        ///pick node with smallest distance
        min = INT_MAX;
        for(int i=0;i<adj.size();i++) {
            if(!visited[adj[i].n] && adj[i].dist < min) {
                min = adj[i].dist;
                curr = adj[i].n;
            }
        }
        visited[curr] = true;
        ///update adjacent distances from curr
        for(int i=0;i<V;i++) {
            //gMatrix[curr][i] has the edge weights...
            if(gMatrix[curr][i]!=0) {
                if(!visited[i] && gMatrix[curr][i] < adj[i].dist && adj[curr].dist!=INT_MAX) {
                    adj[i].dist = gMatrix[curr][i];
                    adj[i].src = curr;
                }
            }
        }
        all_visited = true;
        for(int i=0;i<V;i++) {
            if(!visited[i]) all_visited = false;
        }
    }

    int mstsum = 0;
    cout << "Vertex                 Edge Value" << endl;
    for(int i=0;i<adj.size();i++) {
        cout << adj[i].src << "->" << adj[i].n << "........................" << adj[i].dist << endl;
        mstsum += adj[i].dist;
    }
    cout << "The minimum spanning tree total weight is:" << mstsum << endl;
}

int main () {

    int V;
    cout << "How many vertices does this graph have?" << endl;
    cin >> V;
    Graph g(V);
    cout << "Enter the adjacency matrix:" << endl;

    int** m = new int*[V];
    for(int i=0;i<V;i++) m[i] = new int[V];

    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            cin >> m[i][j];
        }
    }
    g.create_graph(m);

    cout << "The minimum spanning tree (Prim's) is:" << endl;
    g.PrimMST();

}
