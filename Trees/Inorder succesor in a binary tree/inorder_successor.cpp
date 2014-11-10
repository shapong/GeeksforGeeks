#include <iostream>
#include <queue>
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
        node* get_node(node*,int);
        int get_successor(node*,node*);
        int get_min(node*);
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

node* Tree::get_node(node* parent, int n) {

    if(parent->data==n) return parent;
    if(n <= parent->data) return get_node(parent->left,n);
    else if(n > parent->data) return get_node(parent->right,n);
}

int Tree::get_min(node* parent) {
    while(parent->left)
        parent = parent->left;
    return parent->data;
}

int Tree::get_successor(node* parent, node* elem) {

    if(elem->right) return get_min(elem->right);

    while(parent->left->data!=elem->data && parent->right->data!=elem->data) {
        if(elem->data <= parent->data) parent = parent->left;
        else if(elem->data >= parent->data) parent = parent->right;
    }
    return parent->data;
}

int main() {

    Tree t;
    int num,N,elem;

    cout << "Enter Tree:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "For which element do you want to find the inorder successor?" << endl;
    cin >> elem;

    cout << "The successor is:" << endl;
    cout << (t.get_successor(t.root,t.get_node(t.root,elem))) << endl;

}
