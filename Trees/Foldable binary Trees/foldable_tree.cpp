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
        bool isFoldable();
        bool isFoldableUtil(node*,node*);
};

node* Tree::insert(node* r, int num) {
    node* n = create_node(num);
    if(r==NULL)
        return n;
    if(num <= r->data)
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

bool Tree::isFoldableUtil(node* l, node* r) {

    if(l==NULL && r==NULL) return true;

    else if((l && !r) || (!l && r)) return false;

    return isFoldableUtil(l->right,r->left) && isFoldableUtil(l->left,r->right);

}

bool Tree::isFoldable() {

    if(root==NULL) return false;

    return isFoldableUtil(root->left,root->right);
}

int main() {

    Tree t;
    int num,N;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "Foldable Tree?" << endl;
    (t.isFoldable()) ? cout << "True" << endl : cout << "False" << endl;

}
