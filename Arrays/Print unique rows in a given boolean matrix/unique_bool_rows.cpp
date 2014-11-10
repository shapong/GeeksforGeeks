#include <iostream>
#include <cstring>

using namespace std;

class Trie {

    typedef struct trie_node {
        int value;
        trie_node* child[2];
    }node;
    int count;
    node* root;

    public:
        node* createNode() {
            node* newNode = new node;
            if(newNode) {
                newNode->value = 0;
                for(int i=0;i<2;i++)
                    newNode->child[i] = NULL;
            }
            return newNode;
        }
        Trie() {
            root = createNode();
            count = 0;
        }
        void insert(int*,int);
        void print_trie();

};

void Trie::insert(int* key, int size) {

    count++;
    node* curr = root;

    for(int i=0;i<size;i++) {
        if(!curr->child[key[i]]) {
            curr->child[key[i]] = createNode();
        }
        curr = curr->child[key[i]];
    }

    if(curr && curr->value==0) {
        cout << "Unique: ";
        for(int i=0;i<size;i++)
            cout << key[i] << " ";
        cout << endl;
    }
    curr->value = count;

}

int main() {

    Trie t;
    int N,M;
    bool ans;
    char* elem;
    cout << "What is the size of the matrix <NxM>?" << endl;
    cin >> N >> M;

    int** mat = new int*[N];
    for(int i=0;i<N;i++)
        mat[i] = new int[M];

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++)
            cin >> mat[i][j];
        t.insert(mat[i],M);
    }
}
