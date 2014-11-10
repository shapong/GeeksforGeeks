#include <iostream>
#include <queue>

using namespace std;

typedef struct tree_node {
    int data;
    tree_node* right;
    tree_node* left;
}node;

class Tree {

    public:
        node* root;
        Tree() {
            root = new node;
            root = NULL;
        }
        node* create_node(int num) {
            node* n = new node;
            n->data = num;
            n->left = NULL;
            n->right = NULL;
            return n;
        }
        node* insert_complete(node*, int);
        void inorder_print(node*);
};

node* Tree::insert_complete(node* r, int num) {
    node* n = create_node(num);
    if(!root) return n;
    node* parent = root;
    queue<node*> Q;
    Q.push(parent);

    while(!Q.empty()) {
        parent = Q.front(); Q.pop();
        if(!parent->left)  { parent->left = n; return root; }
        else Q.push(parent->left);
        if(!parent->right) { parent->right = n; return root; }
        else Q.push(parent->right);
    }
}

void Tree::inorder_print(node* parent) {
    if(parent==NULL) return;
    inorder_print(parent->left);
    cout << parent->data << " ";
    inorder_print(parent->right);
}

int main () {

    Tree t;
    int N,num;
    cout << "Enter Tree:" << endl;

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert_complete(t.root,num);
    }

    cout << "The inorder traversal of the tree is..." << endl;
    t.inorder_print(t.root);

}
