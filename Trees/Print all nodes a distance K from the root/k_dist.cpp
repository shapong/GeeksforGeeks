#include <iostream>

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
        node* insert(node*, int);
        void inorder_print(node*);
        void get_nodes_at_dist(int,node*);
};

node* Tree::insert(node* r, int num) {
    node* n = create_node(num);
    if(r==NULL)
        return n;
    if(num < r->data)
        r->left = insert(r->left,num);
    else
        r->right = insert(r->right,num);
    return r;
}

void Tree::inorder_print(node* parent) {
    if(parent==NULL) return;
    inorder_print(parent->left);
    cout << parent->data << " ";
    inorder_print(parent->right);
}

void Tree::get_nodes_at_dist(int k, node* parent) {

    if(parent==NULL) return;

    if(k==0) {
        cout << parent->data << " ";
        return;
    }

    get_nodes_at_dist(k-1,parent->left);
    get_nodes_at_dist(k-1,parent->right);

}

int main() {

    Tree t;
    int num,N,k;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "Enter a distance from the root:" << endl;
    cin >> k;

    cout << "The nodes that are at a distance " << k << " from the root are:" << endl;
    t.get_nodes_at_dist(k,t.root);

}
