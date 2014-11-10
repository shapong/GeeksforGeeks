#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <list>

using namespace std;

typedef struct vertex_info {
    int n;
    int dist;
} vertex;

int max_dist = INT_MAX;

class Graph {

    int V;
    list<vertex> *adj;

    public:
        Graph(int);
        void addEdge(int,int,int);
        void Dijkstras();
        bool inHeap(vector<vertex>&,vertex&);
        int getDistUtil(vector<vertex>&,int);
        void updateDist(vector<vertex>&,int,int);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<vertex>[V];
}

void Graph::addEdge(int src, int dest, int wt) {
    vertex newv,newv1;
    newv.n = dest; newv.dist = wt;
    adj[src].push_back(newv);
    newv1.n = src; newv1.dist = wt;
    adj[dest].push_back(newv1);
}

bool mycompare(const vertex& v, const vertex& v1) {
    return v.dist > v1.dist;
}

bool Graph::inHeap(vector<vertex>& heap, vertex& v) {

    int node = v.n;
    for(int i=0;i<heap.size();i++) {
        if (heap[i].n==node) return true;
    }
    return false;
}

int Graph::getDistUtil(vector<vertex>& heap, int node) {
    for(int i=0;i<heap.size();i++) {
        if (heap[i].n==node) return heap[i].dist;
    }
}

void Graph::updateDist(vector<vertex>& heap, int newd, int node) {
    for(int i=0;i<heap.size();i++) {
        if (heap[i].n==node) heap[i].dist = newd;
    }
    return;
}

void Graph::Dijkstras() {
    vector<vertex> minHeap;
    vertex vt;
    for(int i=0;i<V;i++) {
        vt.n = i;
        vt.dist = (i==0) ? 0 : max_dist;
        minHeap.push_back(vt);
    }

    vector<vertex> dist;

    int curr,currDist,destDist;
    while(!minHeap.empty()) {
        ///pick node with smallest distance
        make_heap(minHeap.begin(),minHeap.end(),mycompare);
        dist.push_back(minHeap.front());
        curr = minHeap.front().n;
        pop_heap(minHeap.begin(),minHeap.end(),mycompare); minHeap.pop_back();
        //cout << "curr: " << curr << endl;
        ///update adjacent distances from curr
        for(list<vertex>::iterator i=adj[curr].begin();i!=adj[curr].end();i++) {
            //gMatrix[curr][i] has the edge weights...
            if(inHeap(minHeap,*i)) {
                destDist = getDistUtil(minHeap,(*i).n);
                currDist = getDistUtil(dist,curr);
                if((*i).dist+currDist < destDist && currDist!=INT_MAX) {
                    updateDist(minHeap,(*i).dist+currDist,(*i).n);
                }
            }
        }
    }

    cout << "Source->Vertex          Distance" << endl;
    for(int i=0;i<dist.size();i++) {
        cout << "0->" << dist[i].n << "........................" << dist[i].dist << endl;
    }
}

int main () {

    int N,src,dest,edges,wt;
    cout << "How many nodes/vertices are in the graph:" << endl;
    cin >> N;
    Graph g(N);

    cout << "Enter the number of edges and the <src,dest,weight> in the graph:" << endl;
    cin >> edges;

    for(int i=0;i<edges;i++) {
        cin >> src >> dest >> wt;
        g.addEdge(src,dest,wt);
    }

    cout << "The shortest distance from the source to all the vertices is:" << endl;
    g.Dijkstras();

}
