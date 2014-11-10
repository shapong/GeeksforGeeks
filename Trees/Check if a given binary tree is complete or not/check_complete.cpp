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
        node* insert(node*, int);
        void inorder_print(node*);
        bool check_complete();
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

bool Tree::check_complete() {

    queue<node*> Q;
    Q.push(root);
    node* parent;

    bool full_node = true;
    while(!Q.empty()) {
        parent = Q.front();
        Q.pop();

        if(parent->left) {
            if(!full_node) return false;
            Q.push(parent->left);
        }
        else if(!parent->left || !parent->right) full_node = false;

        if(parent->right) {
            if(!full_node) return false;
            Q.push(parent->right);
        }
    }
    return true;
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

    (t.check_complete()) ? cout << "The tree is COMPLETE\n" : cout << "The tree is NOT COMPLETE\n";

}
