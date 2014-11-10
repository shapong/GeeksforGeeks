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
        void print_boundary();
        void printLeft(node*);
        void printLeaves(node*);
        void printRight(node*);
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

void Tree::printLeft(node* parent) {

    if(parent->left) {
        cout << parent->data << " ";
        printLeft(parent->left);
    }
    else if(parent->right) {
        cout << parent->data << " ";
        printLeft(parent->right);
    }
    ///else if it has neither left nor right children...dont print it

}

void Tree::printLeaves(node* parent) {

    if(!parent) return;
    if(!parent->left && !parent->right) cout << parent->data << " ";

    printLeaves(parent->left);
    printLeaves(parent->right);
}

void Tree::printRight(node* parent) {

    if(parent->right) {
        printRight(parent->right);
        cout << parent->data << " ";
    }
    else if(parent->left) {
        printRight(parent->left);
        cout << parent->data << " ";
    }

}

void Tree::print_boundary() {

    if(!root) return;

    printLeft(root);
    printLeaves(root);
    printRight(root->right);
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

    cout << "The boundary traversal of the tree is:" << endl;
    t.print_boundary();

}
