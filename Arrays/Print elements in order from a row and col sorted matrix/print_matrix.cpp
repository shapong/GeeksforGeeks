#include <iostream>
#include <queue>

using namespace std;

typedef struct matNode {
    int num;
    int i;
    int j;
}node;

struct heapCompare{
    bool operator() (node a, node b) { return a.num > b.num; }
};

void print_sorted(int** mat, int n, int m) {

    priority_queue<node, vector<node>, heapCompare> minHeap;
    for(int i=0;i<n;i++) {
        node e;
        e.num = mat[i][0];
        e.i=i; e.j=0;
        minHeap.push(e);
    }

    for(int i=0;i<n*m;i++) {
        node g = minHeap.top();
        cout << g.num << " ";
        minHeap.pop();
        node newElem;
        newElem.num = mat[g.i][g.j+1];
        newElem.i = g.i; newElem.j = g.j + 1;
        minHeap.push(newElem);
    }

    cout << endl;

}

int main() {

    int n,m;
    cout << "Enter the dimensions of a matrix" << endl;
    cin >> n >> m;
    int** mat = new int*[n];
    for(int i=0;i<n;i++) {
        mat[i] = new int[m];
    }
    cout << "Enter a row & column wise sorted matrix:" << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> mat[i][j];
        }
    }

    print_sorted(mat,n,m);

}
