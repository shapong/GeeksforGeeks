#include <iostream>
#include <stack>
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
        node* insert(node*, int);
        void inorder_print(node*);
        void reverse_level_order();
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

void Tree::reverse_level_order() {

    stack<node*> rev_level;
    queue<node*> Q;
    Q.push(root);
    node* parent;

    while(!Q.empty()) {
        parent = Q.front();
        Q.pop();
        rev_level.push(parent);
        if(parent->right) Q.push(parent->right);
        if(parent->left) Q.push(parent->left);
    }

    while(!rev_level.empty()) {
        cout << rev_level.top()->data << " ";
        rev_level.pop();
    }
    cout << endl;

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

    cout << "The Reverse Level Order Traversal of the tree is:" << endl;
    t.reverse_level_order();

}
