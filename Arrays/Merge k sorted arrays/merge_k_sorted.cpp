#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct Heap_node {
    int num;
    int i;
    int j;
}node;

struct heapCompare {
    bool operator() (node* a, node* b) { return a->num > b->num; }
};

int* merge_k_arrays(int** m, int n, int k) {

    priority_queue<node*, vector<node*>, heapCompare > heap;
    for(int i=0;i<k;i++) {
        node* e = new node;
        e->num = m[i][0];
        e->i = i; e->j = 0;
        heap.push(e);
    }

    node* elem;

    for(int l=0;l<n*k;l++) {
        elem = heap.top();
        heap.pop();
        if(elem->j < n-1) {
            node* e = new node;
            e->num = m[elem->i][elem->j+1]; e->i = elem->i; e->j = elem->j+1;
            heap.push(e);
        }
        cout << elem->num << " ";
    }
    cout << endl;

}

int main() {

    cout << "Enter 'K' arrays with 'N' elements" << endl;
    int K,N;
    cin >> K >> N;

    int** mat = new int*[K];
    for(int i=0;i<K;i++)
        mat[i] = new int[N];

    for(int i=0;i<K;i++) {
        for(int j=0;j<N;j++)
            cin >> mat[i][j];
    }

    int* arr;
    arr = merge_k_arrays(mat,N,K);

}
