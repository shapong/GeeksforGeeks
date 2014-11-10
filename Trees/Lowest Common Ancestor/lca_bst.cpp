#include <iostream>
#include <cstdlib>

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
        int lca(node*,int,int);
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

int Tree::lca(node* parent, int a, int b) {

    if(!parent) {
        cout << "No common ancestor" << endl;
        return -1;
    }

    if(parent->data > a && parent->data > b)
        return lca(parent->left,a,b);
    else if(parent->data < a && parent->data < b)
        return lca(parent->right,a,b);
    if(parent->data >= min(a,b) && parent->data <= max(a,b))
        return parent->data;

}

int main() {

    Tree t;
    int num,N,a,b;
    cout << "Enter the number of nodes:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "For what two nodes do you want to find the ancestor?" << endl;
    cin >> a >> b;

    cout << "The LCA < Lowest Common Ancestor > for " << a << " and " << b << " is:" << endl;
    cout << t.lca(t.root,a,b) << endl;

}
