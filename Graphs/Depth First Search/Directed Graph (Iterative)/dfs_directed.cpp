#include <iostream>
#include <stack>
#include <list>
#include <vector>

using namespace std;

class Graph {

    int V;
    list<int> *adj;

    public:
        Graph(int);
        void addEdge(int,int);
        void DFS(int,vector<bool>&);
        void dfs_util();
};

Graph::Graph(int v) {
    this->V=v;
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
}

void Graph::DFS(int start, vector<bool>& visited) {

    visited[start] = true;

    int node;
    stack<int> st;
    st.push(start);

    while(!st.empty()) {
        node = st.top();
        cout << node << " ";
        ///Popping here is important!!!!...otherwise you pop the children instead of the node...
        st.pop();
        for(list<int>::iterator it=adj[node].begin();it!=adj[node].end();it++) {
            if(!visited[*it]) {
                st.push(*it);
                visited[*it] = true;
            }
        }
    }
}

void Graph::dfs_util() {

    vector<bool> visited (V,false);

    for(int i=0;i<V;i++)
        if(visited[i]==false)
            DFS(i,visited);

    cout << endl;
}

int main() {

    int N,edges,src,dest;
    cout << "How many nodes/vertices are in the graph:" << endl;
    cin >> N;

    Graph g(N);

    cout << "How many edges are in the graph:" << endl;
    cin >> edges;
    for(int i=0;i<edges;i++) {
        cin >> src >> dest;
        g.addEdge(src,dest);
    }

    cout << "The Depth First Traversal of the graph is:" << endl;
    g.dfs_util();

}
