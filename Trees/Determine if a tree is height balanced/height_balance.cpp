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
        int height(node*);
        bool height_balanced(node*);
        bool betterHeightBalanced(node*,int*);
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

int Tree::height(node* parent) {

    if(!parent) return 0;

    return 1 + max(height(parent->left),height(parent->right));
}

bool Tree::height_balanced(node* parent) {

    if(parent==NULL) return true;

    int lh,rh;
    lh = height(parent->left);
    rh = height(parent->right);

    return (abs(lh-rh)<=1) && height_balanced(parent->left) && height_balanced(parent->right);

}

bool Tree::betterHeightBalanced(node* parent, int* height) {

    bool l=false,r=false;
    int lh=0,rh=0;

    if(!parent) {
        *height = 0;
        return true;
    }

    l = betterHeightBalanced(parent->left,&lh);
    r = betterHeightBalanced(parent->right,&rh);

    *height = max(lh,rh) + 1;

    if(abs(lh-rh) >= 2) return false;

    return l&&r;

}

int main() {

    Tree t;
    int num,N,sum;
    cout << "Enter the number of nodes:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    int h = 0;
    t.height_balanced(t.root) ? cout << "The tree is height-balanced" << endl : cout << "The tree is not height-balanced" << endl;
    t.betterHeightBalanced(t.root,&h) ? cout << "The tree is height-balanced" << endl : cout << "The tree is not height-balanced" << endl;

}
