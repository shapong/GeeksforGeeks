#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph {

    int V;
    list<int>* adj;

    public:
        Graph(int v) {
            V = v;
            adj = new list<int>[V];
        }
        void addEdge(int,int);
        void BFS();
        bool isBipartiteUtil(int);
        bool isBipartite(queue<int>&,vector<int>&);
};

void Graph::addEdge(int a, int b) {

    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool Graph::isBipartiteUtil(int start) {

    queue<int> q;
    vector<int> color(V,-1);
    q.push(start);
    color[start] = 1;

    return isBipartite(q,color);
}

bool Graph::isBipartite(queue<int>& q, vector<int>& color) {

    int node,clr;
    while(!q.empty()) {
        node = q.front();
        ///what the color should be of all neighbors...
        clr = (color[node]==1) ? 2 : 1;
        //cout << node << " and its color: " << clr << endl;
        for(list<int>::iterator it=adj[node].begin();it!=adj[node].end();it++) {
            if(color[*it]==-1) {
                color[*it] = clr;
                q.push(*it);
            }
            else if(color[*it]!=clr) return false;
        }
        q.pop();
    }

    return true;
}

int main() {

    ///This is for an undirected graph...

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

    cout << "Where is the start?" << endl;
    cin >> start;

    cout << "Is the graph a Bipartite?" << endl;
    bool ans = g.isBipartiteUtil(start);
    (ans) ? cout << "Yes\n" : cout << "No\n";

}
