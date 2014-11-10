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
        node* search(node*,int);
        node* lca(node*,node*,node*);
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

node* Tree::search(node* parent, int n) {

    if(!parent) return NULL;
    if(parent->data==n)
        return parent;

    node* l=NULL,*r=NULL;
    l = search(parent->left,n);
    r = search(parent->right,n);

    return (!l) ? r : l;

}

node* Tree::lca(node* parent, node* a, node* b) {

    if(!parent) return NULL;

    if(parent==a || parent==b)
        return parent;

    node* l=NULL,*r=NULL;
    l = lca(parent->left,a,b);
    r = lca(parent->right,a,b);

    if(l && r) return parent;

    return (!l) ? r : l;

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
    cout << t.lca(t.root,t.search(t.root,a),t.search(t.root,b))->data << endl;

}
