#include <iostream>
#include <stack>

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
        void iterative_preorder();
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

void Tree::iterative_preorder() {

    stack<node*> pre;
    pre.push(root);
    node* parent;

    while(!pre.empty()) {
        parent = pre.top();
        pre.pop();
        cout << parent->data << " ";
        if(parent->right) pre.push(parent->right);
        if(parent->left) pre.push(parent->left);
    }

}

int main() {

    Tree t;
    int num,N;

    cout << "Enter a tree:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "The Iterative Preorder Traversal of the tree is:" << endl;
    t.iterative_preorder();

}
